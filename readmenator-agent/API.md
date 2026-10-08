# API

## htmlfilter.c

### html_filter_config_default (function) `void html_filter_config_default(struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:6`
- Depends on: `htmlfilter.h`

### hexval (function) `static int hexval(char c)`
- Defined: `htmlfilter.c:14`
- Depends on: `htmlfilter.h`

### decode_entity (function) `static char *decode_entity(const char *entity, size_t len)`
- Defined: `htmlfilter.c:22`
- Depends on: `htmlfilter.h`

### html_filter_strip_tags (function) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:120`
- Depends on: `htmlfilter.h`

## htmlfilter.h

### html_filter_config_default (function) `void html_filter_config_default(struct html_filter_config *cfg);`
- Defined: `htmlfilter.h:10`
- Imported by: `htmlfilter.c`, `main.c`

### html_filter_strip_tags (function) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`
- Defined: `htmlfilter.h:11`
- Imported by: `htmlfilter.c`, `main.c`

## http.c

### http_init (function) `int http_init(void)`
- Defined: `http.c:67`
- Depends on: `http.h`

### http_cleanup (function) `void http_cleanup(void)`
- Defined: `http.c:76`
- Depends on: `http.h`

### http_config_default (function) `void http_config_default(struct http_config *cfg)`
- Defined: `http.c:83`
- Depends on: `http.h`

### http_request (function) `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
- Defined: `http.c:96`
- Depends on: `http.h`

### strcasecmp (function) `strcasecmp(val, "chunked") == 0)`
- Defined: `http.c:259`
- Depends on: `http.h`

### http_response_free (function) `void http_response_free(struct http_response *resp)`
- Defined: `http.c:399`
- Depends on: `http.h`

### http_socket_create (function) `static int http_socket_create(void)`
- Defined: `http.c:407`
- Depends on: `http.h`

### http_socket_connect (function) `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
- Defined: `http.c:416`
- Depends on: `http.h`

### http_socket_send (function) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
- Defined: `http.c:464`
- Depends on: `http.h`

### http_socket_recv (function) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
- Defined: `http.c:486`
- Depends on: `http.h`

### http_socket_close (function) `static void http_socket_close(int sockfd)`
- Defined: `http.c:497`
- Depends on: `http.h`

### http_resolve_host (function) `static char *http_resolve_host(const char *host)`
- Defined: `http.c:502`
- Depends on: `http.h`

### http_build_request (function) `static char *http_build_request(struct http_request *req)`
- Defined: `http.c:515`
- Depends on: `http.h`

### http_free_request (function) `static void http_free_request(struct http_request *req)`
- Defined: `http.c:541`
- Depends on: `http.h`

### http_append_header (function) `static int http_append_header(struct http_request *req, const char *key, const char *value)`
- Defined: `http.c:549`
- Depends on: `http.h`

### http_set_default_headers (function) `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
- Defined: `http.c:563`
- Depends on: `http.h`

### http_handle_redirect (function) `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
- Defined: `http.c:576`
- Depends on: `http.h`

### http_response_new (function) `static struct http_response *http_response_new(void)`
- Defined: `http.c:659`
- Depends on: `http.h`

### http_ssl_init (function) `static int http_ssl_init(void)`
- Defined: `http.c:673`
- Doc: ifdef USE_OPENSSL
- Depends on: `http.h`

### http_ssl_cleanup (function) `static void http_ssl_cleanup(void)`
- Defined: `http.c:684`
- Depends on: `http.h`

### http_ssl_connect (function) `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
- Defined: `http.c:694`
- Depends on: `http.h`

### http_ssl_send (function) `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
- Defined: `http.c:714`
- Depends on: `http.h`

### http_ssl_recv (function) `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
- Defined: `http.c:719`
- Depends on: `http.h`

### http_ssl_close (function) `static void http_ssl_close(SSL *ssl, int sockfd)`
- Defined: `http.c:732`
- Depends on: `http.h`

## http.h

### http_init (function) `int http_init(void);`
- Defined: `http.h:26`
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
- Defined: `main.c:11`
- Depends on: `htmlfilter.h`, `http.h`
