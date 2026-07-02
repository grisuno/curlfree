/*
 * curlfree - Minimal HTTP/HTTPS client library in C
 * Compile: ./build.sh
 */
#include "http.h"
#include "htmlfilter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host = NULL;
    char *path = NULL;
    int use_ssl = 0;
    int port = 0;

    if (strncmp(url, "https://", 8) == 0) {
        use_ssl = 1;
        url += 8;
    } else if (strncmp(url, "http://", 7) == 0) {
        use_ssl = 0;
        url += 7;
    } else {
        fprintf(stderr, "URL must start with http:// or https://\n");
        return 1;
    }

    char *slash = strchr(url, '/');
    if (slash) {
        host = strndup(url, slash - url);
        path = strdup(slash);
    } else {
        host = strdup(url);
        path = strdup("/");
    }
    if (!host || !path) {
        free(host); free(path);
        return 1;
    }

    char *colon = strchr(host, ':');
    if (colon) {
        *colon = '\0';
        port = atoi(colon+1);
        if (port == 0) port = use_ssl ? 443 : 80;
    } else {
        port = use_ssl ? 443 : 80;
    }

    if (http_init() != 0) {
        fprintf(stderr, "HTTP init failed\n");
        free(host); free(path);
        return 1;
    }

    struct http_config cfg;
    http_config_default(&cfg);
    strncpy(cfg.host, host, 255);
    cfg.port = port;
    cfg.use_ssl = use_ssl;
    cfg.follow_redirects = 1;
    cfg.max_redirects = 5;
    cfg.timeout_sec = 15;

    struct http_response *resp = http_request(&cfg, "GET", path, NULL, NULL);
    if (!resp) {
        fprintf(stderr, "HTTP request failed\n");
        free(host); free(path);
        http_cleanup();
        return 1;
    }

    if (resp->status_code != 200) {
        fprintf(stderr, "HTTP status %d\n", resp->status_code);
        http_response_free(resp);
        free(host); free(path);
        http_cleanup();
        return 1;
    }

    struct html_filter_config hcfg;
    html_filter_config_default(&hcfg);
    hcfg.collapse_whitespace = 1;
    hcfg.preserve_newlines = 1;
    hcfg.convert_entities = 1;

    char *plain = html_filter_strip_tags(resp->body, &hcfg);
    if (plain) {
        printf("%s\n", plain);
        free(plain);
    } else {
        fprintf(stderr, "HTML filtering failed\n");
    }

    http_response_free(resp);
    free(host);
    free(path);
    http_cleanup();
    return 0;
}