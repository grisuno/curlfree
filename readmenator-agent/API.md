# API

## htmlfilter.c

### html_filter_config_default (function) `void html_filter_config_default(struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:5`
- Doc: include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>
- Depends on: `htmlfilter.h`

### hexval (function) `static int hexval(char c)`
- Defined: `htmlfilter.c:13`
- Depends on: `htmlfilter.h`

### decode_entity (function) `static char *decode_entity(const char *entity, size_t len)`
- Defined: `htmlfilter.c:21`
- Depends on: `htmlfilter.h`

### html_filter_strip_tags (function) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:119`
- Depends on: `htmlfilter.h`

### strdup (function) `return strdup(buf);`
- Defined: `htmlfilter.c:66`
- Depends on: `htmlfilter.h`

### free (function) `free(decoded);`
- Defined: `htmlfilter.c:209`
- Depends on: `htmlfilter.h`

## htmlfilter.h

### html_filter_config_default (function) `void html_filter_config_default(struct html_filter_config *cfg);`
- Defined: `htmlfilter.h:9`
- Imported by: `htmlfilter.c`, `main.c`

### html_filter_strip_tags (function) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`
- Defined: `htmlfilter.h:11`
- Imported by: `htmlfilter.c`, `main.c`

## http.c

### http_init (function) `int http_init(void)`
- Defined: `http.c:66`
- Doc: endif
- Depends on: `http.h`

### http_cleanup (function) `void http_cleanup(void)`
- Defined: `http.c:75`
- Depends on: `http.h`

### http_config_default (function) `void http_config_default(struct http_config *cfg)`
- Defined: `http.c:82`
- Depends on: `http.h`

### http_request (function) `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
- Defined: `http.c:95`
- Depends on: `http.h`

### strcasecmp (function) `strcasecmp(val, "chunked") == 0)`
- Defined: `http.c:259`
- Depends on: `http.h`

### http_response_free (function) `void http_response_free(struct http_response *resp)`
- Defined: `http.c:398`
- Depends on: `http.h`

### http_socket_create (function) `static int http_socket_create(void)`
- Defined: `http.c:406`
- Depends on: `http.h`

### http_socket_connect (function) `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
- Defined: `http.c:415`
- Depends on: `http.h`

### http_socket_send (function) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
- Defined: `http.c:463`
- Depends on: `http.h`

### http_socket_recv (function) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
- Defined: `http.c:485`
- Depends on: `http.h`

### http_socket_close (function) `static void http_socket_close(int sockfd)`
- Defined: `http.c:496`
- Depends on: `http.h`

### http_resolve_host (function) `static char *http_resolve_host(const char *host)`
- Defined: `http.c:501`
- Depends on: `http.h`

### http_build_request (function) `static char *http_build_request(struct http_request *req)`
- Defined: `http.c:514`
- Depends on: `http.h`

### http_free_request (function) `static void http_free_request(struct http_request *req)`
- Defined: `http.c:540`
- Depends on: `http.h`

### http_append_header (function) `static int http_append_header(struct http_request *req, const char *key, const char *value)`
- Defined: `http.c:548`
- Depends on: `http.h`

### http_set_default_headers (function) `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
- Defined: `http.c:562`
- Depends on: `http.h`

### http_handle_redirect (function) `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
- Defined: `http.c:575`
- Depends on: `http.h`

### http_response_new (function) `static struct http_response *http_response_new(void)`
- Defined: `http.c:658`
- Depends on: `http.h`

### http_ssl_init (function) `static int http_ssl_init(void)`
- Defined: `http.c:673`
- Doc: ifdef USE_OPENSSL
- Depends on: `http.h`

### http_ssl_cleanup (function) `static void http_ssl_cleanup(void)`
- Defined: `http.c:683`
- Depends on: `http.h`

### http_ssl_connect (function) `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
- Defined: `http.c:693`
- Depends on: `http.h`

### http_ssl_send (function) `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
- Defined: `http.c:713`
- Depends on: `http.h`

### http_ssl_recv (function) `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
- Defined: `http.c:718`
- Depends on: `http.h`

### http_ssl_close (function) `static void http_ssl_close(SSL *ssl, int sockfd)`
- Defined: `http.c:731`
- Depends on: `http.h`

### memset (function) `memset(cfg, 0, sizeof(*cfg));`
- Defined: `http.c:86`
- Depends on: `http.h`

### strcpy (function) `strcpy(cfg->ca_bundle_path, "/etc/ssl/certs/ca-certificates.crt");`
- Defined: `http.c:93`
- Depends on: `http.h`

### strncpy (function) `strncpy(req.method, method, sizeof(req.method)-1);`
- Defined: `http.c:104`
- Depends on: `http.h`

### free (function) `free(hcopy);`
- Defined: `http.c:126`
- Depends on: `http.h`

### memcpy (function) `memcpy(full_response + full_response_len, recv_buf, recv_len);`
- Defined: `http.c:219`
- Depends on: `http.h`

### memmove (function) `memmove(dst, src, chunk_size);`
- Defined: `http.c:340`
- Depends on: `http.h`

### setsockopt (function) `setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));`
- Defined: `http.c:412`
- Depends on: `http.h`

### fcntl (function) `fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);`
- Defined: `http.c:433`
- Depends on: `http.h`

### FD_ZERO (function) `FD_ZERO(&wfds);`
- Defined: `http.c:444`
- Depends on: `http.h`

### FD_SET (function) `FD_SET(sockfd, &wfds);`
- Defined: `http.c:445`
- Depends on: `http.h`

### getsockopt (function) `getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);`
- Defined: `http.c:454`
- Depends on: `http.h`

### recv (function) `return recv(sockfd, buf, bufsize, 0);`
- Defined: `http.c:494`
- Depends on: `http.h`

### close (function) `close(sockfd);`
- Defined: `http.c:499`
- Depends on: `http.h`

### freeaddrinfo (function) `freeaddrinfo(res);`
- Defined: `http.c:511`
- Depends on: `http.h`

### snprintf (function) `snprintf(clen, sizeof(clen), "%zu", req->body_len);`
- Defined: `http.c:570`
- Depends on: `http.h`

### SSL_library_init (function) `SSL_library_init();`
- Defined: `http.c:675`
- Depends on: `http.h`

### OpenSSL_add_all_algorithms (function) `OpenSSL_add_all_algorithms();`
- Defined: `http.c:676`
- Depends on: `http.h`

### SSL_load_error_strings (function) `SSL_load_error_strings();`
- Defined: `http.c:677`
- Depends on: `http.h`

### SSL_CTX_set_options (function) `SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);`
- Defined: `http.c:680`
- Depends on: `http.h`

### SSL_CTX_free (function) `SSL_CTX_free(http_ssl_ctx);`
- Defined: `http.c:687`
- Depends on: `http.h`

### EVP_cleanup (function) `EVP_cleanup();`
- Defined: `http.c:690`
- Depends on: `http.h`

### ERR_free_strings (function) `ERR_free_strings();`
- Defined: `http.c:691`
- Depends on: `http.h`

### SSL_set_fd (function) `SSL_set_fd(ssl, sockfd);`
- Defined: `http.c:698`
- Depends on: `http.h`

### SSL_CTX_set_verify (function) `SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);`
- Defined: `http.c:700`
- Depends on: `http.h`

### SSL_CTX_load_verify_locations (function) `SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);`
- Defined: `http.c:702`
- Depends on: `http.h`

### SSL_free (function) `SSL_free(ssl);`
- Defined: `http.c:708`
- Depends on: `http.h`

### SSL_write (function) `return SSL_write(ssl, data, (int)len);`
- Defined: `http.c:716`
- Depends on: `http.h`

### SSL_shutdown (function) `SSL_shutdown(ssl);`
- Defined: `http.c:735`
- Depends on: `http.h`

## http.h

### http_init (function) `int http_init(void);`
- Defined: `http.h:25`
- Imported by: `http.c`, `main.c`

### http_cleanup (function) `void http_cleanup(void);`
- Defined: `http.h:27`
- Imported by: `http.c`, `main.c`

### http_config_default (function) `void http_config_default(struct http_config *cfg);`
- Defined: `http.h:28`
- Imported by: `http.c`, `main.c`

### http_request (function) `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);`
- Defined: `http.h:29`
- Imported by: `http.c`, `main.c`

### http_response_free (function) `void http_response_free(struct http_response *resp);`
- Defined: `http.h:32`
- Imported by: `http.c`, `main.c`

## main.c

### main (function) `int main(int argc, char **argv)`
- Defined: `main.c:10`
- Doc: curlfree - Minimal HTTP/HTTPS client library in C Compile: ./build.sh  include "http.h" include "htmlfilter.h" include <
- Depends on: `htmlfilter.h`, `http.h`

### fprintf (function) `fprintf(stderr, "Usage: %s <URL>\n", argv[0]);`
- Defined: `main.c:14`
- Depends on: `htmlfilter.h`, `http.h`

### free (function) `free(host);`
- Defined: `main.c:44`
- Depends on: `htmlfilter.h`, `http.h`

### http_config_default (function) `http_config_default(&cfg);`
- Defined: `main.c:64`
- Depends on: `htmlfilter.h`, `http.h`

### strncpy (function) `strncpy(cfg.host, host, 255);`
- Defined: `main.c:65`
- Depends on: `htmlfilter.h`, `http.h`

### http_cleanup (function) `http_cleanup();`
- Defined: `main.c:76`
- Depends on: `htmlfilter.h`, `http.h`

### http_response_free (function) `http_response_free(resp);`
- Defined: `main.c:82`
- Depends on: `htmlfilter.h`, `http.h`

### html_filter_config_default (function) `html_filter_config_default(&hcfg);`
- Defined: `main.c:89`
- Depends on: `htmlfilter.h`, `http.h`

### printf (function) `printf("%s\n", plain);`
- Defined: `main.c:96`
- Depends on: `htmlfilter.h`, `http.h`
