#ifndef HTTP_H
#define HTTP_H

#include <stddef.h>

struct http_config {
    char host[256];
    int port;
    int timeout_sec;
    int use_ssl;
    char ca_bundle_path[256];
    int verify_peer;
    int follow_redirects;
    int max_redirects;
};

struct http_response {
    int status_code;
    char *headers;
    char *body;
    size_t body_len;
    size_t headers_len;
    int chunked;
};

int http_init(void);
void http_cleanup(void);
void http_config_default(struct http_config *cfg);
struct http_response *http_request(struct http_config *cfg, const char *method,
                                   const char *path, const char *headers,
                                   const char *body);
void http_response_free(struct http_response *resp);

#endif