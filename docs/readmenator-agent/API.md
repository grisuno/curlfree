# API

## htmlfilter.c
Depends on: `htmlfilter.h`
- `html_filter_config_default` (function) `htmlfilter.c:6` `void html_filter_config_default(struct html_filter_config *cfg)`
- `hexval` (function) `htmlfilter.c:14` `static int hexval(char c)`
- `decode_entity` (function) `htmlfilter.c:22` `static char *decode_entity(const char *entity, size_t len)`
- `html_filter_strip_tags` (function) `htmlfilter.c:120` `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`

## htmlfilter.h
Imported by: `htmlfilter.c`, `main.c`
- `html_filter_config_default` (function) `htmlfilter.h:10` `void html_filter_config_default(struct html_filter_config *cfg);`
- `html_filter_strip_tags` (function) `htmlfilter.h:11` `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`

## http.c
Depends on: `http.h`
- `http_init` (function) `http.c:67` `int http_init(void)`
- `http_cleanup` (function) `http.c:76` `void http_cleanup(void)`
- `http_config_default` (function) `http.c:83` `void http_config_default(struct http_config *cfg)`
- `http_request` (function) `http.c:96` `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
- `strcasecmp` (function) `http.c:259` `strcasecmp(val, "chunked") == 0)`
- `http_response_free` (function) `http.c:399` `void http_response_free(struct http_response *resp)`
- `http_socket_create` (function) `http.c:407` `static int http_socket_create(void)`
- `http_socket_connect` (function) `http.c:416` `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
- `http_socket_send` (function) `http.c:464` `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
- `http_socket_recv` (function) `http.c:486` `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
- `http_socket_close` (function) `http.c:497` `static void http_socket_close(int sockfd)`
- `http_resolve_host` (function) `http.c:502` `static char *http_resolve_host(const char *host)`
- `http_build_request` (function) `http.c:515` `static char *http_build_request(struct http_request *req)`
- `http_free_request` (function) `http.c:541` `static void http_free_request(struct http_request *req)`
- `http_append_header` (function) `http.c:549` `static int http_append_header(struct http_request *req, const char *key, const char *value)`
- `http_set_default_headers` (function) `http.c:563` `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
- `http_handle_redirect` (function) `http.c:576` `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
- `http_response_new` (function) `http.c:659` `static struct http_response *http_response_new(void)`
- `http_ssl_init` (function) `http.c:673` `static int http_ssl_init(void)` -- ifdef USE_OPENSSL
- `http_ssl_cleanup` (function) `http.c:684` `static void http_ssl_cleanup(void)`
- `http_ssl_connect` (function) `http.c:694` `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
- `http_ssl_send` (function) `http.c:714` `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
- `http_ssl_recv` (function) `http.c:719` `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
- `http_ssl_close` (function) `http.c:732` `static void http_ssl_close(SSL *ssl, int sockfd)`

## http.h
Imported by: `http.c`, `main.c`
- `http_init` (function) `http.h:26` `int http_init(void);`
- `http_cleanup` (function) `http.h:27` `void http_cleanup(void);`
- `http_config_default` (function) `http.h:28` `void http_config_default(struct http_config *cfg);`
- `http_request` (function) `http.h:29` `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char...`
- `http_response_free` (function) `http.h:32` `void http_response_free(struct http_response *resp);`

## main.c
Depends on: `htmlfilter.h`, `http.h`
- `main` (function) `main.c:11` `int main(int argc, char **argv)`
