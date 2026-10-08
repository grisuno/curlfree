# Subsystem: root

## htmlfilter.c
- Layer: utility
- Language: c
- Symbols:
  - `html_filter_config_default` (function, line 6) `void html_filter_config_default(struct html_filter_config *cfg)`
  - `hexval` (function, line 14) `static int hexval(char c)`
  - `decode_entity` (function, line 22) `static char *decode_entity(const char *entity, size_t len)`
  - `html_filter_strip_tags` (function, line 120) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`
- Depends on: `htmlfilter.h`

## htmlfilter.h
- Layer: utility
- Language: h
- Symbols:
  - `html_filter_config` (struct, line 4)
  - `html_filter_config_default` (function, line 10) `void html_filter_config_default(struct html_filter_config *cfg);`
  - `html_filter_strip_tags` (function, line 11) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`
  - `HTMLFILTER_H` (macro, line 2) `#define HTMLFILTER_H`
- Imported by: `htmlfilter.c`, `main.c`

## http.c
- Doc: http_ssl_init: ifdef USE_OPENSSL
- Layer: presentation
- Language: c
- Symbols:
  - `http_header` (struct, line 29)
  - `http_request` (struct, line 34)
  - `http_init` (function, line 67) `int http_init(void)`
  - `http_cleanup` (function, line 76) `void http_cleanup(void)`
  - `http_config_default` (function, line 83) `void http_config_default(struct http_config *cfg)`
  - `http_request` (function, line 96) `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
  - `strcasecmp` (function, line 259) `strcasecmp(val, "chunked") == 0)`
  - `http_response_free` (function, line 399) `void http_response_free(struct http_response *resp)`
  - `http_socket_create` (function, line 407) `static int http_socket_create(void)`
  - `http_socket_connect` (function, line 416) `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
  - `http_socket_send` (function, line 464) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
  - `http_socket_recv` (function, line 486) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
  - `http_socket_close` (function, line 497) `static void http_socket_close(int sockfd)`
  - `http_resolve_host` (function, line 502) `static char *http_resolve_host(const char *host)`
  - `http_build_request` (function, line 515) `static char *http_build_request(struct http_request *req)`
  - `http_free_request` (function, line 541) `static void http_free_request(struct http_request *req)`
  - `http_append_header` (function, line 549) `static int http_append_header(struct http_request *req, const char *key, const char *value)`
  - `http_set_default_headers` (function, line 563) `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
  - `http_handle_redirect` (function, line 576) `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
  - `http_response_new` (function, line 659) `static struct http_response *http_response_new(void)`
  - `http_ssl_init` (function, line 673) `static int http_ssl_init(void)`
  - `http_ssl_cleanup` (function, line 684) `static void http_ssl_cleanup(void)`
  - `http_ssl_connect` (function, line 694) `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
  - `http_ssl_send` (function, line 714) `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
  - `http_ssl_recv` (function, line 719) `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
  - `http_ssl_close` (function, line 732) `static void http_ssl_close(SSL *ssl, int sockfd)`
  - `HTTP_DEFAULT_PORT_HTTP` (macro, line 21) `#define HTTP_DEFAULT_PORT_HTTP`
  - `HTTP_DEFAULT_PORT_HTTPS` (macro, line 22) `#define HTTP_DEFAULT_PORT_HTTPS`
  - `HTTP_MAX_HEADER_COUNT` (macro, line 23) `#define HTTP_MAX_HEADER_COUNT`
  - `HTTP_MAX_PATH_LEN` (macro, line 24) `#define HTTP_MAX_PATH_LEN`
  - `HTTP_MAX_HOST_LEN` (macro, line 25) `#define HTTP_MAX_HOST_LEN`
  - `HTTP_RECV_BUFFER_SIZE` (macro, line 26) `#define HTTP_RECV_BUFFER_SIZE`
  - `HTTP_TIMEOUT_SEC_DEFAULT` (macro, line 27) `#define HTTP_TIMEOUT_SEC_DEFAULT`
- Depends on: `http.h`

## http.h
- Layer: presentation
- Language: h
- Symbols:
  - `http_config` (struct, line 6)
  - `http_response` (struct, line 17)
  - `http_init` (function, line 26) `int http_init(void);`
  - `http_cleanup` (function, line 27) `void http_cleanup(void);`
  - `http_config_default` (function, line 28) `void http_config_default(struct http_config *cfg);`
  - `http_request` (function, line 29) `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char...`
  - `http_response_free` (function, line 32) `void http_response_free(struct http_response *resp);`
  - `HTTP_H` (macro, line 2) `#define HTTP_H`
- Imported by: `http.c`, `main.c`

## main.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 11) `int main(int argc, char **argv)`
- Depends on: `htmlfilter.h`, `http.h`

## sniffer.py
- Layer: utility
- Language: py
