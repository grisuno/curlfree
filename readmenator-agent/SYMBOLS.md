# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `decode_entity` | function | `htmlfilter.c:22` | `static char *decode_entity(const char *entity, size_t len)` |
| `hexval` | function | `htmlfilter.c:14` | `static int hexval(char c)` |
| `html_filter_config_default` | function | `htmlfilter.c:6` | `void html_filter_config_default(struct html_filter_config *cfg)` |
| `html_filter_strip_tags` | function | `htmlfilter.c:120` | `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)` |
| `HTMLFILTER_H` | macro | `htmlfilter.h:2` | `#define HTMLFILTER_H` |
| `html_filter_config` | struct | `htmlfilter.h:4` | `` |
| `html_filter_config_default` | function | `htmlfilter.h:10` | `void html_filter_config_default(struct html_filter_config *cfg);` |
| `html_filter_strip_tags` | function | `htmlfilter.h:11` | `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);` |
| `HTTP_DEFAULT_PORT_HTTP` | macro | `http.c:21` | `#define HTTP_DEFAULT_PORT_HTTP` |
| `HTTP_DEFAULT_PORT_HTTPS` | macro | `http.c:22` | `#define HTTP_DEFAULT_PORT_HTTPS` |
| `HTTP_MAX_HEADER_COUNT` | macro | `http.c:23` | `#define HTTP_MAX_HEADER_COUNT` |
| `HTTP_MAX_HOST_LEN` | macro | `http.c:25` | `#define HTTP_MAX_HOST_LEN` |
| `HTTP_MAX_PATH_LEN` | macro | `http.c:24` | `#define HTTP_MAX_PATH_LEN` |
| `HTTP_RECV_BUFFER_SIZE` | macro | `http.c:26` | `#define HTTP_RECV_BUFFER_SIZE` |
| `HTTP_TIMEOUT_SEC_DEFAULT` | macro | `http.c:27` | `#define HTTP_TIMEOUT_SEC_DEFAULT` |
| `http_append_header` | function | `http.c:549` | `static int http_append_header(struct http_request *req, const char *key, const char *value)` |
| `http_build_request` | function | `http.c:515` | `static char *http_build_request(struct http_request *req)` |
| `http_cleanup` | function | `http.c:76` | `void http_cleanup(void)` |
| `http_config_default` | function | `http.c:83` | `void http_config_default(struct http_config *cfg)` |
| `http_free_request` | function | `http.c:541` | `static void http_free_request(struct http_request *req)` |
| `http_handle_redirect` | function | `http.c:576` | `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,             ...` |
| `http_header` | struct | `http.c:29` | `` |
| `http_init` | function | `http.c:67` | `int http_init(void)` |
| `http_request` | struct | `http.c:34` | `` |
| `http_request` | function | `http.c:96` | `struct http_response *http_request(struct http_config *cfg, const char *method,                  ...` |
| `http_resolve_host` | function | `http.c:502` | `static char *http_resolve_host(const char *host)` |
| `http_response_free` | function | `http.c:399` | `void http_response_free(struct http_response *resp)` |
| `http_response_new` | function | `http.c:659` | `static struct http_response *http_response_new(void)` |
| `http_set_default_headers` | function | `http.c:563` | `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)` |
| `http_socket_close` | function | `http.c:497` | `static void http_socket_close(int sockfd)` |
| `http_socket_connect` | function | `http.c:416` | `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)` |
| `http_socket_create` | function | `http.c:407` | `static int http_socket_create(void)` |
| `http_socket_recv` | function | `http.c:486` | `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)` |
| `http_socket_send` | function | `http.c:464` | `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)` |
| `http_ssl_cleanup` | function | `http.c:684` | `static void http_ssl_cleanup(void)` |
| `http_ssl_close` | function | `http.c:732` | `static void http_ssl_close(SSL *ssl, int sockfd)` |
| `http_ssl_connect` | function | `http.c:694` | `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)` |
| `http_ssl_init` | function | `http.c:673` | `static int http_ssl_init(void)` |
| `http_ssl_recv` | function | `http.c:719` | `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)` |
| `http_ssl_send` | function | `http.c:714` | `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)` |
| `strcasecmp` | function | `http.c:259` | `strcasecmp(val, "chunked") == 0)` |
| `HTTP_H` | macro | `http.h:2` | `#define HTTP_H` |
| `http_cleanup` | function | `http.h:27` | `void http_cleanup(void);` |
| `http_config` | struct | `http.h:6` | `` |
| `http_config_default` | function | `http.h:28` | `void http_config_default(struct http_config *cfg);` |
| `http_init` | function | `http.h:26` | `int http_init(void);` |
| `http_request` | function | `http.h:29` | `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char...` |
| `http_response` | struct | `http.h:17` | `` |
| `http_response_free` | function | `http.h:32` | `void http_response_free(struct http_response *resp);` |
| `main` | function | `main.c:11` | `int main(int argc, char **argv)` |
