# API

## htmlfilter.c

### html_filter_config_default `void html_filter_config_default(struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:5`
- Doc: include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>

### hexval `static int hexval(char c)`
- Defined: `htmlfilter.c:13`

### decode_entity `static char *decode_entity(const char *entity, size_t len)`
- Defined: `htmlfilter.c:21`

### html_filter_strip_tags `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`
- Defined: `htmlfilter.c:119`

## http.c

### http_init `int http_init(void)`
- Defined: `http.c:66`
- Doc: endif

### http_cleanup `void http_cleanup(void)`
- Defined: `http.c:75`

### http_config_default `void http_config_default(struct http_config *cfg)`
- Defined: `http.c:82`

### http_request `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
- Defined: `http.c:95`

### strcasecmp `strcasecmp(val, "chunked") == 0)`
- Defined: `http.c:259`

### http_response_free `void http_response_free(struct http_response *resp)`
- Defined: `http.c:398`

### http_socket_create `static int http_socket_create(void)`
- Defined: `http.c:406`

### http_socket_connect `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
- Defined: `http.c:415`

### http_socket_send `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
- Defined: `http.c:463`

### http_socket_recv `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
- Defined: `http.c:485`

### http_socket_close `static void http_socket_close(int sockfd)`
- Defined: `http.c:496`

### http_resolve_host `static char *http_resolve_host(const char *host)`
- Defined: `http.c:501`

### http_build_request `static char *http_build_request(struct http_request *req)`
- Defined: `http.c:514`

### http_free_request `static void http_free_request(struct http_request *req)`
- Defined: `http.c:540`

### http_append_header `static int http_append_header(struct http_request *req, const char *key, const char *value)`
- Defined: `http.c:548`

### http_set_default_headers `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
- Defined: `http.c:562`

### http_handle_redirect `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
- Defined: `http.c:575`

### http_response_new `static struct http_response *http_response_new(void)`
- Defined: `http.c:658`

### http_ssl_init `static int http_ssl_init(void)`
- Defined: `http.c:673`
- Doc: ifdef USE_OPENSSL

### http_ssl_cleanup `static void http_ssl_cleanup(void)`
- Defined: `http.c:683`

### http_ssl_connect `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
- Defined: `http.c:693`

### http_ssl_send `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
- Defined: `http.c:713`

### http_ssl_recv `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
- Defined: `http.c:718`

### http_ssl_close `static void http_ssl_close(SSL *ssl, int sockfd)`
- Defined: `http.c:731`

## main.c

### main `int main(int argc, char **argv)`
- Defined: `main.c:10`
- Doc: curlfree - Minimal HTTP/HTTPS client library in C Compile: ./build.sh  include "http.h" include "htmlfilter.h" include <
