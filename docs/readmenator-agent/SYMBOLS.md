# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `decode_entity` | function | `htmlfilter.c:21` | `static char *decode_entity(const char *entity, size_t len)` |
| `free` | function | `htmlfilter.c:209` | `free(decoded);` |
| `hexval` | function | `htmlfilter.c:13` | `static int hexval(char c)` |
| `html_filter_config_default` | function | `htmlfilter.c:5` | `void html_filter_config_default(struct html_filter_config *cfg)` |
| `html_filter_strip_tags` | function | `htmlfilter.c:119` | `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)` |
| `strdup` | function | `htmlfilter.c:66` | `return strdup(buf);` |
| `HTMLFILTER_H` | macro | `htmlfilter.h:2` | `#define HTMLFILTER_H` |
| `html_filter_config` | struct | `htmlfilter.h:4` | `` |
| `html_filter_config_default` | function | `htmlfilter.h:9` | `void html_filter_config_default(struct html_filter_config *cfg);` |
| `html_filter_strip_tags` | function | `htmlfilter.h:11` | `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);` |
| `ERR_free_strings` | function | `http.c:691` | `ERR_free_strings();` |
| `EVP_cleanup` | function | `http.c:690` | `EVP_cleanup();` |
| `FD_SET` | function | `http.c:445` | `FD_SET(sockfd, &wfds);` |
| `FD_ZERO` | function | `http.c:444` | `FD_ZERO(&wfds);` |
| `HTTP_DEFAULT_PORT_HTTP` | macro | `http.c:20` | `#define HTTP_DEFAULT_PORT_HTTP` |
| `HTTP_DEFAULT_PORT_HTTPS` | macro | `http.c:22` | `#define HTTP_DEFAULT_PORT_HTTPS` |
| `HTTP_MAX_HEADER_COUNT` | macro | `http.c:23` | `#define HTTP_MAX_HEADER_COUNT` |
| `HTTP_MAX_HOST_LEN` | macro | `http.c:25` | `#define HTTP_MAX_HOST_LEN` |
| `HTTP_MAX_PATH_LEN` | macro | `http.c:24` | `#define HTTP_MAX_PATH_LEN` |
| `HTTP_RECV_BUFFER_SIZE` | macro | `http.c:26` | `#define HTTP_RECV_BUFFER_SIZE` |
| `HTTP_TIMEOUT_SEC_DEFAULT` | macro | `http.c:27` | `#define HTTP_TIMEOUT_SEC_DEFAULT` |
| `OpenSSL_add_all_algorithms` | function | `http.c:676` | `OpenSSL_add_all_algorithms();` |
| `SSL_CTX_free` | function | `http.c:687` | `SSL_CTX_free(http_ssl_ctx);` |
| `SSL_CTX_load_verify_locations` | function | `http.c:702` | `SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);` |
| `SSL_CTX_set_options` | function | `http.c:680` | `SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 \| SSL_OP_NO_SSLv3);` |
| `SSL_CTX_set_verify` | function | `http.c:700` | `SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);` |
| `SSL_free` | function | `http.c:708` | `SSL_free(ssl);` |
| `SSL_library_init` | function | `http.c:675` | `SSL_library_init();` |
| `SSL_load_error_strings` | function | `http.c:677` | `SSL_load_error_strings();` |
| `SSL_set_fd` | function | `http.c:698` | `SSL_set_fd(ssl, sockfd);` |
| `SSL_shutdown` | function | `http.c:735` | `SSL_shutdown(ssl);` |
| `SSL_write` | function | `http.c:716` | `return SSL_write(ssl, data, (int)len);` |
| `close` | function | `http.c:499` | `close(sockfd);` |
| `fcntl` | function | `http.c:433` | `fcntl(sockfd, F_SETFL, flags \| O_NONBLOCK);` |
| `free` | function | `http.c:126` | `free(hcopy);` |
| `freeaddrinfo` | function | `http.c:511` | `freeaddrinfo(res);` |
| `getsockopt` | function | `http.c:454` | `getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);` |
| `http_append_header` | function | `http.c:548` | `static int http_append_header(struct http_request *req, const char *key, const char *value)` |
| `http_build_request` | function | `http.c:514` | `static char *http_build_request(struct http_request *req)` |
| `http_cleanup` | function | `http.c:75` | `void http_cleanup(void)` |
| `http_config_default` | function | `http.c:82` | `void http_config_default(struct http_config *cfg)` |
| `http_free_request` | function | `http.c:540` | `static void http_free_request(struct http_request *req)` |
| `http_handle_redirect` | function | `http.c:575` | `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...` |
| `http_header` | struct | `http.c:29` | `` |
| `http_init` | function | `http.c:66` | `int http_init(void)` |
| `http_request` | struct | `http.c:34` | `` |
| `http_request` | function | `http.c:95` | `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...` |
| `http_resolve_host` | function | `http.c:501` | `static char *http_resolve_host(const char *host)` |
| `http_response_free` | function | `http.c:398` | `void http_response_free(struct http_response *resp)` |
| `http_response_new` | function | `http.c:658` | `static struct http_response *http_response_new(void)` |
| `http_set_default_headers` | function | `http.c:562` | `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)` |
| `http_socket_close` | function | `http.c:496` | `static void http_socket_close(int sockfd)` |
| `http_socket_connect` | function | `http.c:415` | `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)` |
| `http_socket_create` | function | `http.c:406` | `static int http_socket_create(void)` |
| `http_socket_recv` | function | `http.c:485` | `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)` |
| `http_socket_send` | function | `http.c:463` | `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)` |
| `http_ssl_cleanup` | function | `http.c:683` | `static void http_ssl_cleanup(void)` |
| `http_ssl_close` | function | `http.c:731` | `static void http_ssl_close(SSL *ssl, int sockfd)` |
| `http_ssl_connect` | function | `http.c:693` | `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)` |
| `http_ssl_init` | function | `http.c:673` | `static int http_ssl_init(void)` |
| `http_ssl_recv` | function | `http.c:718` | `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)` |
| `http_ssl_send` | function | `http.c:713` | `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)` |
| `memcpy` | function | `http.c:219` | `memcpy(full_response + full_response_len, recv_buf, recv_len);` |
| `memmove` | function | `http.c:340` | `memmove(dst, src, chunk_size);` |
| `memset` | function | `http.c:86` | `memset(cfg, 0, sizeof(*cfg));` |
| `recv` | function | `http.c:494` | `return recv(sockfd, buf, bufsize, 0);` |
| `setsockopt` | function | `http.c:412` | `setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));` |
| `snprintf` | function | `http.c:570` | `snprintf(clen, sizeof(clen), "%zu", req->body_len);` |
| `strcasecmp` | function | `http.c:259` | `strcasecmp(val, "chunked") == 0)` |
| `strcpy` | function | `http.c:93` | `strcpy(cfg->ca_bundle_path, "/etc/ssl/certs/ca-certificates.crt");` |
| `strncpy` | function | `http.c:104` | `strncpy(req.method, method, sizeof(req.method)-1);` |
| `HTTP_H` | macro | `http.h:2` | `#define HTTP_H` |
| `http_cleanup` | function | `http.h:27` | `void http_cleanup(void);` |
| `http_config` | struct | `http.h:6` | `` |
| `http_config_default` | function | `http.h:28` | `void http_config_default(struct http_config *cfg);` |
| `http_init` | function | `http.h:25` | `int http_init(void);` |
| `http_request` | function | `http.h:29` | `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, c` |
| `http_response` | struct | `http.h:17` | `` |
| `http_response_free` | function | `http.h:32` | `void http_response_free(struct http_response *resp);` |
| `fprintf` | function | `main.c:14` | `fprintf(stderr, "Usage: %s <URL>\n", argv[0]);` |
| `free` | function | `main.c:44` | `free(host);` |
| `html_filter_config_default` | function | `main.c:89` | `html_filter_config_default(&hcfg);` |
| `http_cleanup` | function | `main.c:76` | `http_cleanup();` |
| `http_config_default` | function | `main.c:64` | `http_config_default(&cfg);` |
| `http_response_free` | function | `main.c:82` | `http_response_free(resp);` |
| `main` | function | `main.c:10` | `int main(int argc, char **argv)` |
| `printf` | function | `main.c:96` | `printf("%s\n", plain);` |
| `strncpy` | function | `main.c:65` | `strncpy(cfg.host, host, 255);` |
