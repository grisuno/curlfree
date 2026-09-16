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
  - `strdup` (function, line 66) `return strdup(buf);`
  - `free` (function, line 209) `free(decoded);`
- Depends on: `htmlfilter.h`

## htmlfilter.h
- Layer: utility
- Doc: ifndef HTMLFILTER_H define HTMLFILTER_H
- Language: h
- Symbols:
  - `html_filter_config` (struct, line 4)
  - `html_filter_config_default` (function, line 9) `void html_filter_config_default(struct html_filter_config *cfg);`
  - `html_filter_strip_tags` (function, line 11) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`
  - `HTMLFILTER_H` (macro, line 2) `#define HTMLFILTER_H`
- Imported by: `htmlfilter.c`, `main.c`

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
  - `memset` (function, line 86) `memset(cfg, 0, sizeof(*cfg));`
  - `strcpy` (function, line 93) `strcpy(cfg->ca_bundle_path, "/etc/ssl/certs/ca-certificates.crt");`
  - `strncpy` (function, line 104) `strncpy(req.method, method, sizeof(req.method)-1);`
  - `free` (function, line 126) `free(hcopy);`
  - `memcpy` (function, line 219) `memcpy(full_response + full_response_len, recv_buf, recv_len);`
  - `memmove` (function, line 340) `memmove(dst, src, chunk_size);`
  - `setsockopt` (function, line 412) `setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));`
  - `fcntl` (function, line 433) `fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);`
  - `FD_ZERO` (function, line 444) `FD_ZERO(&wfds);`
  - `FD_SET` (function, line 445) `FD_SET(sockfd, &wfds);`
  - `getsockopt` (function, line 454) `getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);`
  - `recv` (function, line 494) `return recv(sockfd, buf, bufsize, 0);`
  - `close` (function, line 499) `close(sockfd);`
  - `freeaddrinfo` (function, line 511) `freeaddrinfo(res);`
  - `snprintf` (function, line 570) `snprintf(clen, sizeof(clen), "%zu", req->body_len);`
  - `SSL_library_init` (function, line 675) `SSL_library_init();`
  - `OpenSSL_add_all_algorithms` (function, line 676) `OpenSSL_add_all_algorithms();`
  - `SSL_load_error_strings` (function, line 677) `SSL_load_error_strings();`
  - `SSL_CTX_set_options` (function, line 680) `SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);`
  - `SSL_CTX_free` (function, line 687) `SSL_CTX_free(http_ssl_ctx);`
  - `EVP_cleanup` (function, line 690) `EVP_cleanup();`
  - `ERR_free_strings` (function, line 691) `ERR_free_strings();`
  - `SSL_set_fd` (function, line 698) `SSL_set_fd(ssl, sockfd);`
  - `SSL_CTX_set_verify` (function, line 700) `SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);`
  - `SSL_CTX_load_verify_locations` (function, line 702) `SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);`
  - `SSL_free` (function, line 708) `SSL_free(ssl);`
  - `SSL_write` (function, line 716) `return SSL_write(ssl, data, (int)len);`
  - `SSL_shutdown` (function, line 735) `SSL_shutdown(ssl);`
  - `HTTP_DEFAULT_PORT_HTTP` (macro, line 20) `#define HTTP_DEFAULT_PORT_HTTP`
  - `HTTP_DEFAULT_PORT_HTTPS` (macro, line 22) `#define HTTP_DEFAULT_PORT_HTTPS`
  - `HTTP_MAX_HEADER_COUNT` (macro, line 23) `#define HTTP_MAX_HEADER_COUNT`
  - `HTTP_MAX_PATH_LEN` (macro, line 24) `#define HTTP_MAX_PATH_LEN`
  - `HTTP_MAX_HOST_LEN` (macro, line 25) `#define HTTP_MAX_HOST_LEN`
  - `HTTP_RECV_BUFFER_SIZE` (macro, line 26) `#define HTTP_RECV_BUFFER_SIZE`
  - `HTTP_TIMEOUT_SEC_DEFAULT` (macro, line 27) `#define HTTP_TIMEOUT_SEC_DEFAULT`
- Depends on: `http.h`

## http.h
- Layer: presentation
- Doc: ifndef HTTP_H define HTTP_H  include <stddef.h>
- Language: h
- Symbols:
  - `http_config` (struct, line 6)
  - `http_response` (struct, line 17)
  - `http_init` (function, line 25) `int http_init(void);`
  - `http_cleanup` (function, line 27) `void http_cleanup(void);`
  - `http_config_default` (function, line 28) `void http_config_default(struct http_config *cfg);`
  - `http_request` (function, line 29) `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);`
  - `http_response_free` (function, line 32) `void http_response_free(struct http_response *resp);`
  - `HTTP_H` (macro, line 2) `#define HTTP_H`
- Imported by: `http.c`, `main.c`

## main.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 10) `int main(int argc, char **argv)`
  - `fprintf` (function, line 14) `fprintf(stderr, "Usage: %s <URL>\n", argv[0]);`
  - `free` (function, line 44) `free(host);`
  - `http_config_default` (function, line 64) `http_config_default(&cfg);`
  - `strncpy` (function, line 65) `strncpy(cfg.host, host, 255);`
  - `http_cleanup` (function, line 76) `http_cleanup();`
  - `http_response_free` (function, line 82) `http_response_free(resp);`
  - `html_filter_config_default` (function, line 89) `html_filter_config_default(&hcfg);`
  - `printf` (function, line 96) `printf("%s\n", plain);`
- Depends on: `htmlfilter.h`, `http.h`

## sniffer.py
- Layer: utility
- Language: py
