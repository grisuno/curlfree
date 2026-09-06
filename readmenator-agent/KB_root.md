# Subsystem: root

## htmlfilter.c
- Layer: utility
- Doc: include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>
- Language: c
- Symbols:
  - `html_filter_config_default` (function, line 5) `void html_filter_config_default(struct html_filter_config *cfg)`
  - `hexval` (function, line 13) `static int hexval(char c)`
  - `decode_entity` (function, line 21) `static char *decode_entity(const char *entity, size_t len)`
  - `html_filter_strip_tags` (function, line 119) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`

## htmlfilter.h
- Layer: utility
- Doc: ifndef HTMLFILTER_H define HTMLFILTER_H
- Language: h
- Symbols:
  - `html_filter_config` (struct, line 4)
  - `HTMLFILTER_H` (macro, line 2)

## http.c
- Layer: presentation
- Doc: include "http.h" include <stdio.h> include <stdlib.h> include <string.h> include <unistd.h> include <sys/socket.h> inclu
- Language: c
- Symbols:
  - `http_header` (struct, line 29)
  - `http_request` (struct, line 34)
  - `http_init` (function, line 66) `int http_init(void)`
  - `http_cleanup` (function, line 75) `void http_cleanup(void)`
  - `http_config_default` (function, line 82) `void http_config_default(struct http_config *cfg)`
  - `http_request` (function, line 95) `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
  - `strcasecmp` (function, line 259) `strcasecmp(val, "chunked") == 0)`
  - `http_response_free` (function, line 398) `void http_response_free(struct http_response *resp)`
  - `http_socket_create` (function, line 406) `static int http_socket_create(void)`
  - `http_socket_connect` (function, line 415) `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
  - `http_socket_send` (function, line 463) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
  - `http_socket_recv` (function, line 485) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
  - `http_socket_close` (function, line 496) `static void http_socket_close(int sockfd)`
  - `http_resolve_host` (function, line 501) `static char *http_resolve_host(const char *host)`
  - `http_build_request` (function, line 514) `static char *http_build_request(struct http_request *req)`
  - `http_free_request` (function, line 540) `static void http_free_request(struct http_request *req)`
  - `http_append_header` (function, line 548) `static int http_append_header(struct http_request *req, const char *key, const char *value)`
  - `http_set_default_headers` (function, line 562) `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
  - `http_handle_redirect` (function, line 575) `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
  - `http_response_new` (function, line 658) `static struct http_response *http_response_new(void)`
  - `http_ssl_init` (function, line 673) `static int http_ssl_init(void)`
  - `http_ssl_cleanup` (function, line 683) `static void http_ssl_cleanup(void)`
  - `http_ssl_connect` (function, line 693) `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
  - `http_ssl_send` (function, line 713) `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
  - `http_ssl_recv` (function, line 718) `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
  - `http_ssl_close` (function, line 731) `static void http_ssl_close(SSL *ssl, int sockfd)`
  - `HTTP_DEFAULT_PORT_HTTP` (macro, line 20)
  - `HTTP_DEFAULT_PORT_HTTPS` (macro, line 22)
  - `HTTP_MAX_HEADER_COUNT` (macro, line 23)
  - `HTTP_MAX_PATH_LEN` (macro, line 24)
  - `HTTP_MAX_HOST_LEN` (macro, line 25)
  - `HTTP_RECV_BUFFER_SIZE` (macro, line 26)
  - `HTTP_TIMEOUT_SEC_DEFAULT` (macro, line 27)

## http.h
- Layer: presentation
- Doc: ifndef HTTP_H define HTTP_H  include <stddef.h>
- Language: h
- Symbols:
  - `http_config` (struct, line 6)
  - `http_response` (struct, line 17)
  - `HTTP_H` (macro, line 2)

## main.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 10) `int main(int argc, char **argv)`

## sniffer.py
- Layer: utility
- Language: py
