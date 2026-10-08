# root

*Community 0 | 5 files | cohesion 1.00*

## Definition

This community groups 5 file(s) rooted at `root` with dominant language c (cohesion 1.00). Central symbols: `HTMLFILTER_H`, `HTTP_DEFAULT_PORT_HTTP`, `HTTP_DEFAULT_PORT_HTTPS`, `HTTP_H`, `HTTP_MAX_HEADER_COUNT`, `HTTP_MAX_HOST_LEN`, `HTTP_MAX_PATH_LEN`, `HTTP_RECV_BUFFER_SIZE`. Core file: `http.c` (33 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `htmlfilter.c` | c | utility | 4 | no |
| `htmlfilter.h` | h | utility | 4 | no |
| `http.c` | c | presentation | 33 | no |
| `http.h` | h | presentation | 8 | no |
| `main.c` | c | utility | 1 | no |

## Key Symbols

- `html_filter_config_default` (function, `htmlfilter.c:6`) `void html_filter_config_default(struct html_filter_config *cfg)`
- `hexval` (function, `htmlfilter.c:14`) `static int hexval(char c)`
- `decode_entity` (function, `htmlfilter.c:22`) `static char *decode_entity(const char *entity, size_t len)`
- `html_filter_strip_tags` (function, `htmlfilter.c:120`) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *`
- `HTMLFILTER_H` (macro, `htmlfilter.h:2`) `#define HTMLFILTER_H`
- `html_filter_config` (struct, `htmlfilter.h:4`)
- `html_filter_config_default` (function, `htmlfilter.h:10`) `void html_filter_config_default(struct html_filter_config *cfg);`
- `html_filter_strip_tags` (function, `htmlfilter.h:11`) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *`
- `HTTP_DEFAULT_PORT_HTTP` (macro, `http.c:21`) `#define HTTP_DEFAULT_PORT_HTTP`
- `HTTP_DEFAULT_PORT_HTTPS` (macro, `http.c:22`) `#define HTTP_DEFAULT_PORT_HTTPS`
- `HTTP_MAX_HEADER_COUNT` (macro, `http.c:23`) `#define HTTP_MAX_HEADER_COUNT`
- `HTTP_MAX_PATH_LEN` (macro, `http.c:24`) `#define HTTP_MAX_PATH_LEN`
- `HTTP_MAX_HOST_LEN` (macro, `http.c:25`) `#define HTTP_MAX_HOST_LEN`
- `HTTP_RECV_BUFFER_SIZE` (macro, `http.c:26`) `#define HTTP_RECV_BUFFER_SIZE`
- `HTTP_TIMEOUT_SEC_DEFAULT` (macro, `http.c:27`) `#define HTTP_TIMEOUT_SEC_DEFAULT`
- `http_header` (struct, `http.c:29`)
- `http_request` (struct, `http.c:34`)
- `http_init` (function, `http.c:67`) `int http_init(void)`
- `http_cleanup` (function, `http.c:76`) `void http_cleanup(void)`
- `http_config_default` (function, `http.c:83`) `void http_config_default(struct http_config *cfg)`
- `http_request` (function, `http.c:96`) `struct http_response *http_request(struct http_config *cfg, const char *method,`
- `strcasecmp` (function, `http.c:259`) `strcasecmp(val, "chunked") == 0)`
- `http_response_free` (function, `http.c:399`) `void http_response_free(struct http_response *resp)`
- `http_socket_create` (function, `http.c:407`) `static int http_socket_create(void)`
- `http_socket_connect` (function, `http.c:416`) `static int http_socket_connect(int sockfd, const char *host, int port, int timeo`
- `http_socket_send` (function, `http.c:464`) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int ti`
- `http_socket_recv` (function, `http.c:486`) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeo`
- `http_socket_close` (function, `http.c:497`) `static void http_socket_close(int sockfd)`
- `http_resolve_host` (function, `http.c:502`) `static char *http_resolve_host(const char *host)`
- `http_build_request` (function, `http.c:515`) `static char *http_build_request(struct http_request *req)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 4
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 1 (strength 0.5): Inferred shared context (layer utility) with no import path between community 0 (root) and community 1 (orphans).

## Risks

- [dataflow DEAD_STORE] `http.c:135` `http_request` `redirect_count`: `redirect_count` assigned at line 135 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:136` `http_request` `resp`: `resp` assigned at line 136 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:196` `http_request` `chunked`: `chunked` assigned at line 196 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:199` `http_request` `final_headers`: `final_headers` assigned at line 199 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:200` `http_request` `final_headers_len`: `final_headers_len` assigned at line 200 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:305` `strcasecmp` `sp2`: `sp2` assigned at line 305 but never read afterwards.
- [dataflow DEAD_STORE] `http.c:352` `strcasecmp` `dst`: `dst` assigned at line 352 but never read afterwards.
- [dataflow UNCHECKED_ALLOC] `http.c:510` `http_resolve_host` `ip`: Result of allocator stored in `ip` is never checked against NULL.
- [dataflow DEAD_STORE] `http.c:537` `http_build_request` `ptr`: `ptr` assigned at line 537 but never read afterwards.

## Open Questions

- Why do 5 file(s) lack file-level docs (e.g. `htmlfilter.c`)? What purpose do they serve?
- What would break if the most connected file in root changed?
- Should root be split, given cohesion 1.00?

## Sources

- `htmlfilter.c`
- `htmlfilter.h`
- `http.c`
- `http.h`
- `main.c`
