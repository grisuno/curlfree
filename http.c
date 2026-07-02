#include "http.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <time.h>
#include <ctype.h>

#ifdef USE_OPENSSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#endif

#define HTTP_DEFAULT_PORT_HTTP         80
#define HTTP_DEFAULT_PORT_HTTPS        443
#define HTTP_MAX_HEADER_COUNT          64
#define HTTP_MAX_PATH_LEN              4096
#define HTTP_MAX_HOST_LEN              256
#define HTTP_RECV_BUFFER_SIZE          8192
#define HTTP_TIMEOUT_SEC_DEFAULT       30

struct http_header {
    char *key;
    char *value;
};

struct http_request {
    char method[16];
    char path[HTTP_MAX_PATH_LEN];
    struct http_header headers[HTTP_MAX_HEADER_COUNT];
    int header_count;
    char *body;
    size_t body_len;
};

static int http_socket_create(void);
static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec);
static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec);
static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec);
static void http_socket_close(int sockfd);
static char *http_resolve_host(const char *host);
static char *http_build_request(struct http_request *req);
static void http_free_request(struct http_request *req);
static struct http_response *http_response_new(void);
static int http_append_header(struct http_request *req, const char *key, const char *value);
static void http_set_default_headers(struct http_request *req, const struct http_config *cfg);
static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
                                struct http_request *req, int *redirect_count);

#ifdef USE_OPENSSL
static SSL_CTX *http_ssl_ctx = NULL;
static int http_ssl_init(void);
static void http_ssl_cleanup(void);
static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg);
static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len);
static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize);
static void http_ssl_close(SSL *ssl, int sockfd);
#endif

int http_init(void)
{
#ifdef USE_OPENSSL
    return http_ssl_init();
#else
    return 0;
#endif
}

void http_cleanup(void)
{
#ifdef USE_OPENSSL
    http_ssl_cleanup();
#endif
}

void http_config_default(struct http_config *cfg)
{
    if (!cfg) return;
    memset(cfg, 0, sizeof(*cfg));
    cfg->timeout_sec = HTTP_TIMEOUT_SEC_DEFAULT;
    cfg->port = 0;
    cfg->use_ssl = 0;
    cfg->verify_peer = 1;
    cfg->follow_redirects = 1;
    cfg->max_redirects = 5;
    strcpy(cfg->ca_bundle_path, "/etc/ssl/certs/ca-certificates.crt");
}

struct http_response *http_request(struct http_config *cfg, const char *method,
                                   const char *path, const char *headers,
                                   const char *body)
{
    if (!cfg || !method || !path) return NULL;

    struct http_request req;
    memset(&req, 0, sizeof(req));
    strncpy(req.method, method, sizeof(req.method)-1);
    strncpy(req.path, path, sizeof(req.path)-1);
    req.body = (char *)body;
    req.body_len = body ? strlen(body) : 0;

    http_set_default_headers(&req, cfg);

    if (headers) {
        char *hcopy = strdup(headers);
        if (!hcopy) return NULL;
        char *line = strtok(hcopy, "\r\n");
        while (line) {
            char *sep = strchr(line, ':');
            if (sep) {
                *sep = '\0';
                char *key = line;
                char *val = sep + 1;
                while (*val == ' ') val++;
                http_append_header(&req, key, val);
            }
            line = strtok(NULL, "\r\n");
        }
        free(hcopy);
    }

    char *request_str = http_build_request(&req);
    if (!request_str) {
        http_free_request(&req);
        return NULL;
    }

    int redirect_count = 0;
    struct http_response *resp = NULL;

    while (1) {
        int sockfd = http_socket_create();
        if (sockfd < 0) {
            free(request_str);
            http_free_request(&req);
            return NULL;
        }

        int port = cfg->port;
        if (port == 0) {
            port = cfg->use_ssl ? HTTP_DEFAULT_PORT_HTTPS : HTTP_DEFAULT_PORT_HTTP;
        }

        if (http_socket_connect(sockfd, cfg->host, port, cfg->timeout_sec) < 0) {
            http_socket_close(sockfd);
            free(request_str);
            http_free_request(&req);
            return NULL;
        }

#ifdef USE_OPENSSL
        SSL *ssl = NULL;
        if (cfg->use_ssl) {
            ssl = http_ssl_connect(sockfd, cfg);
            if (!ssl) {
                http_socket_close(sockfd);
                free(request_str);
                http_free_request(&req);
                return NULL;
            }
        }
#endif

        ssize_t sent = 0;
#ifdef USE_OPENSSL
        if (ssl) sent = http_ssl_send(ssl, request_str, strlen(request_str));
        else sent = http_socket_send(sockfd, request_str, strlen(request_str), cfg->timeout_sec);
#else
        sent = http_socket_send(sockfd, request_str, strlen(request_str), cfg->timeout_sec);
#endif
        if (sent < 0) {
#ifdef USE_OPENSSL
            if (ssl) http_ssl_close(ssl, sockfd);
            else http_socket_close(sockfd);
#else
            http_socket_close(sockfd);
#endif
            free(request_str);
            http_free_request(&req);
            return NULL;
        }

        char recv_buf[HTTP_RECV_BUFFER_SIZE + 1];
        char *full_response = NULL;
        size_t full_response_len = 0;
        ssize_t recv_len;
        int header_done = 0;
        size_t content_length = 0;
        int chunked = 0;
        char *body_start = NULL;
        int final_status = 0;
        char *final_headers = NULL;
        size_t final_headers_len = 0;

        while (1) {
#ifdef USE_OPENSSL
            if (ssl) recv_len = http_ssl_recv(ssl, recv_buf, HTTP_RECV_BUFFER_SIZE);
            else recv_len = http_socket_recv(sockfd, recv_buf, HTTP_RECV_BUFFER_SIZE, cfg->timeout_sec);
#else
            recv_len = http_socket_recv(sockfd, recv_buf, HTTP_RECV_BUFFER_SIZE, cfg->timeout_sec);
#endif
            if (recv_len <= 0) break;
            recv_buf[recv_len] = '\0';

            char *new_resp = realloc(full_response, full_response_len + recv_len + 1);
            if (!new_resp) {
                free(full_response);
                full_response = NULL;
                break;
            }
            full_response = new_resp;
            memcpy(full_response + full_response_len, recv_buf, recv_len);
            full_response_len += recv_len;
            full_response[full_response_len] = '\0';

            if (!header_done) {
                char *header_end = strstr(full_response, "\r\n\r\n");
                if (header_end) {
                    header_done = 1;
                    body_start = header_end + 4;
                    size_t header_len = body_start - full_response;
                    char *header_copy = strndup(full_response, header_len);
                    if (!header_copy) {
                        free(full_response);
                        full_response = NULL;
                        break;
                    }
                    char *line = strtok(header_copy, "\r\n");
                    int line_num = 0;
                    while (line) {
                        if (line_num == 0) {
                            char *sp1 = strchr(line, ' ');
                            if (sp1) {
                                char *sp2 = strchr(sp1+1, ' ');
                                if (sp2) {
                                    *sp2 = '\0';
                                    final_status = atoi(sp1+1);
                                } else {
                                    final_status = atoi(sp1+1);
                                }
                            }
                        } else {
                            char *sep = strchr(line, ':');
                            if (sep) {
                                *sep = '\0';
                                char *key = line;
                                char *val = sep + 1;
                                while (*val == ' ') val++;
                                if (strcasecmp(key, "Content-Length") == 0) {
                                    content_length = atol(val);
                                } else if (strcasecmp(key, "Transfer-Encoding") == 0 &&
                                           strcasecmp(val, "chunked") == 0) {
                                    chunked = 1;
                                }
                            }
                        }
                        line = strtok(NULL, "\r\n");
                        line_num++;
                    }
                    free(header_copy);

                    final_headers = strndup(full_response, header_len);
                    final_headers_len = header_len;
                }
            }

            if (header_done && body_start) {
                size_t body_offset = body_start - full_response;
                size_t current_body_len = full_response_len - body_offset;
                if (!chunked && content_length > 0 && current_body_len >= content_length) {
                    break;
                }
                if (chunked && strstr(full_response + body_offset, "0\r\n\r\n")) {
                    break;
                }
            }
        }

#ifdef USE_OPENSSL
        if (ssl) http_ssl_close(ssl, sockfd);
        else http_socket_close(sockfd);
#else
        http_socket_close(sockfd);
#endif

        if (!full_response) {
            free(request_str);
            http_free_request(&req);
            return NULL;
        }

        if (final_status == 0) {
            char *line = strtok(full_response, "\r\n");
            if (line) {
                char *sp1 = strchr(line, ' ');
                if (sp1) {
                    char *sp2 = strchr(sp1+1, ' ');
                    if (sp2) *sp2 = '\0';
                    final_status = atoi(sp1+1);
                }
            }
        }

        char *body_ptr = strstr(full_response, "\r\n\r\n");
        char *final_body = NULL;
        size_t final_body_len = 0;
        if (body_ptr) {
            body_ptr += 4;
            final_body_len = full_response_len - (body_ptr - full_response);
            final_body = strndup(body_ptr, final_body_len);
            if (!final_body) {
                free(full_response);
                free(request_str);
                http_free_request(&req);
                return NULL;
            }
        } else {
            final_body = strdup("");
            final_body_len = 0;
        }

        if (chunked && final_body) {
            char *src = final_body;
            char *dst = final_body;
            size_t new_len = 0;
            while (*src) {
                char *end;
                long chunk_size = strtol(src, &end, 16);
                if (chunk_size <= 0) break;
                if (*end == '\r' && *(end+1) == '\n') {
                    src = end + 2;
                    if (src + chunk_size <= final_body + final_body_len) {
                        memmove(dst, src, chunk_size);
                        dst += chunk_size;
                        new_len += chunk_size;
                        src += chunk_size;
                        if (*src == '\r' && *(src+1) == '\n') {
                            src += 2;
                        } else {
                            break;
                        }
                    } else break;
                } else break;
            }
            *dst = '\0';
            final_body_len = new_len;
        }

        resp = http_response_new();
        if (!resp) {
            free(full_response);
            free(final_body);
            free(request_str);
            http_free_request(&req);
            return NULL;
        }
        resp->status_code = final_status;
        resp->headers = final_headers ? final_headers : strdup("");
        resp->headers_len = final_headers_len;
        resp->body = final_body;
        resp->body_len = final_body_len;
        resp->chunked = chunked;

        free(full_response);

        if (cfg->follow_redirects && (final_status == 301 || final_status == 302 ||
            final_status == 303 || final_status == 307 || final_status == 308)) {
            if (!http_handle_redirect(resp, cfg, &req, &redirect_count)) {
                http_response_free(resp);
                resp = NULL;
                continue;
            }
            http_response_free(resp);
            resp = NULL;
            free(request_str);
            request_str = http_build_request(&req);
            if (!request_str) {
                http_free_request(&req);
                return NULL;
            }
            continue;
        }

        break;
    }

    free(request_str);
    http_free_request(&req);
    return resp;
}

void http_response_free(struct http_response *resp)
{
    if (!resp) return;
    free(resp->headers);
    free(resp->body);
    free(resp);
}

static int http_socket_create(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return -1;
    int flag = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    return sock;
}

static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)
{
    char *ip = http_resolve_host(host);
    if (!ip) return -1;

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &addr.sin_addr) <= 0) {
        free(ip);
        return -1;
    }
    free(ip);

    if (timeout_sec > 0) {
        int flags = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    }

    int rc = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (rc < 0 && errno != EINPROGRESS) {
        if (timeout_sec > 0) fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) & ~O_NONBLOCK);
        return -1;
    }

    if (timeout_sec > 0) {
        fd_set wfds;
        FD_ZERO(&wfds);
        FD_SET(sockfd, &wfds);
        struct timeval tv = { timeout_sec, 0 };
        rc = select(sockfd+1, NULL, &wfds, NULL, &tv);
        if (rc <= 0) {
            fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) & ~O_NONBLOCK);
            return -1;
        }
        int err = 0;
        socklen_t len = sizeof(err);
        getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);
        if (err != 0) {
            fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) & ~O_NONBLOCK);
            return -1;
        }
        fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) & ~O_NONBLOCK);
    }
    return 0;
}

static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)
{
    ssize_t total = 0;
    while (total < (ssize_t)len) {
        ssize_t n = send(sockfd, data + total, len - total, 0);
        if (n < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                fd_set wfds;
                FD_ZERO(&wfds);
                FD_SET(sockfd, &wfds);
                struct timeval tv = { timeout_sec, 0 };
                int rc = select(sockfd+1, NULL, &wfds, NULL, &tv);
                if (rc <= 0) return -1;
                continue;
            }
            return -1;
        }
        total += n;
    }
    return total;
}

static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)
{
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv = { timeout_sec, 0 };
    int rc = select(sockfd+1, &rfds, NULL, NULL, &tv);
    if (rc <= 0) return -1;
    return recv(sockfd, buf, bufsize, 0);
}

static void http_socket_close(int sockfd)
{
    close(sockfd);
}

static char *http_resolve_host(const char *host)
{
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, NULL, &hints, &res) != 0) return NULL;
    struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
    char *ip = strdup(inet_ntoa(addr->sin_addr));
    freeaddrinfo(res);
    return ip;
}

static char *http_build_request(struct http_request *req)
{
    size_t len = 0;
    len += strlen(req->method) + 1 + strlen(req->path) + 1 + 8 + 2;
    for (int i = 0; i < req->header_count; i++) {
        len += strlen(req->headers[i].key) + 2 + strlen(req->headers[i].value) + 2;
    }
    len += 2;
    if (req->body) len += req->body_len;

    char *buf = malloc(len + 1);
    if (!buf) return NULL;
    char *ptr = buf;
    ptr += sprintf(ptr, "%s %s HTTP/1.1\r\n", req->method, req->path);
    for (int i = 0; i < req->header_count; i++) {
        ptr += sprintf(ptr, "%s: %s\r\n", req->headers[i].key, req->headers[i].value);
    }
    ptr += sprintf(ptr, "\r\n");
    if (req->body && req->body_len > 0) {
        memcpy(ptr, req->body, req->body_len);
        ptr += req->body_len;
    }
    *ptr = '\0';
    return buf;
}

static void http_free_request(struct http_request *req)
{
    for (int i = 0; i < req->header_count; i++) {
        free(req->headers[i].key);
        free(req->headers[i].value);
    }
}

static int http_append_header(struct http_request *req, const char *key, const char *value)
{
    if (req->header_count >= HTTP_MAX_HEADER_COUNT) return -1;
    req->headers[req->header_count].key = strdup(key);
    req->headers[req->header_count].value = strdup(value);
    if (!req->headers[req->header_count].key || !req->headers[req->header_count].value) {
        free(req->headers[req->header_count].key);
        free(req->headers[req->header_count].value);
        return -1;
    }
    req->header_count++;
    return 0;
}

static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)
{
    http_append_header(req, "Host", cfg->host);
    http_append_header(req, "User-Agent", "libhttp/1.0");
    http_append_header(req, "Accept", "*/*");
    if (req->body && req->body_len > 0) {
        char clen[32];
        snprintf(clen, sizeof(clen), "%zu", req->body_len);
        http_append_header(req, "Content-Length", clen);
    }
    http_append_header(req, "Connection", "close");
}

static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
                                struct http_request *req, int *redirect_count)
{
    if (!resp || !cfg || !req || !redirect_count) return 0;
    if (*redirect_count >= cfg->max_redirects) return 0;

    char *loc = NULL;
    char *headers = resp->headers;
    if (headers) {
        char *line = strtok(headers, "\r\n");
        while (line) {
            if (strncasecmp(line, "Location:", 9) == 0) {
                loc = line + 9;
                while (*loc == ' ') loc++;
                break;
            }
            line = strtok(NULL, "\r\n");
        }
    }
    if (!loc) return 0;

    char *new_host = NULL;
    char *new_path = NULL;
    int new_port = 0;
    int new_ssl = 0;

    if (strncmp(loc, "http://", 7) == 0) {
        loc += 7;
        new_ssl = 0;
        new_port = HTTP_DEFAULT_PORT_HTTP;
    } else if (strncmp(loc, "https://", 8) == 0) {
        loc += 8;
        new_ssl = 1;
        new_port = HTTP_DEFAULT_PORT_HTTPS;
    } else {
        new_host = strdup(cfg->host);
        new_path = strdup(loc);
        new_port = cfg->port;
        new_ssl = cfg->use_ssl;
        if (!new_host || !new_path) {
            free(new_host); free(new_path);
            return 0;
        }
        strncpy(cfg->host, new_host, HTTP_MAX_HOST_LEN-1);
        strncpy(req->path, new_path, HTTP_MAX_PATH_LEN-1);
        cfg->port = new_port;
        cfg->use_ssl = new_ssl;
        free(new_host); free(new_path);
        (*redirect_count)++;
        return 1;
    }

    char *slash = strchr(loc, '/');
    if (slash) {
        new_host = strndup(loc, slash - loc);
        new_path = strdup(slash);
    } else {
        new_host = strdup(loc);
        new_path = strdup("/");
    }
    if (!new_host || !new_path) {
        free(new_host); free(new_path);
        return 0;
    }

    char *colon = strchr(new_host, ':');
    if (colon) {
        *colon = '\0';
        new_port = atoi(colon+1);
        if (new_port == 0) new_port = new_ssl ? HTTP_DEFAULT_PORT_HTTPS : HTTP_DEFAULT_PORT_HTTP;
    }

    strncpy(cfg->host, new_host, HTTP_MAX_HOST_LEN-1);
    strncpy(req->path, new_path, HTTP_MAX_PATH_LEN-1);
    cfg->port = new_port;
    cfg->use_ssl = new_ssl;

    free(new_host);
    free(new_path);
    (*redirect_count)++;
    return 1;
}

static struct http_response *http_response_new(void)
{
    struct http_response *resp = calloc(1, sizeof(*resp));
    if (!resp) return NULL;
    resp->headers = NULL;
    resp->body = NULL;
    resp->status_code = 0;
    resp->body_len = 0;
    resp->headers_len = 0;
    resp->chunked = 0;
    return resp;
}

#ifdef USE_OPENSSL
static int http_ssl_init(void)
{
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    http_ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    if (!http_ssl_ctx) return -1;
    SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
    return 0;
}

static void http_ssl_cleanup(void)
{
    if (http_ssl_ctx) {
        SSL_CTX_free(http_ssl_ctx);
        http_ssl_ctx = NULL;
    }
    EVP_cleanup();
    ERR_free_strings();
}

static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)
{
    SSL *ssl = SSL_new(http_ssl_ctx);
    if (!ssl) return NULL;
    SSL_set_fd(ssl, sockfd);
    if (cfg->verify_peer) {
        SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);
        if (cfg->ca_bundle_path[0]) {
            SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);
        }
    } else {
        SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_NONE, NULL);
    }
    if (SSL_connect(ssl) != 1) {
        SSL_free(ssl);
        return NULL;
    }
    return ssl;
}

static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)
{
    return SSL_write(ssl, data, (int)len);
}

static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)
{
    int rc = SSL_read(ssl, buf, (int)bufsize);
    if (rc <= 0) {
        int err = SSL_get_error(ssl, rc);
        if (err == SSL_ERROR_WANT_READ || err == SSL_ERROR_WANT_WRITE) {
            return 0;
        }
        return -1;
    }
    return rc;
}

static void http_ssl_close(SSL *ssl, int sockfd)
{
    if (ssl) {
        SSL_shutdown(ssl);
        SSL_free(ssl);
    }
    close(sockfd);
}
#endif