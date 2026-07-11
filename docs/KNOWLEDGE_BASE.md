# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM.
> No LLMs. No tokens. Pure static analysis.

**Total Files Parsed:** 6 | **Total Symbols Extracted:** 43 | **Total Imports:** 26

## Structural Knowledge Map
```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray: 5 5,color:#aaa;
    http_c["http.c (c)"]
    class http_c mod;
    http_c_http_header["http_header"]
    class http_c_http_header cls;
    http_c --> http_c_http_header
    http_c_http_request["http_request"]
    class http_c_http_request cls;
    http_c --> http_c_http_request
    http_c_http_init["http_init"]
    class http_c_http_init fn;
    http_c --> http_c_http_init
    http_c_http_cleanup["http_cleanup"]
    class http_c_http_cleanup fn;
    http_c --> http_c_http_cleanup
    http_c_http_config_default["http_config_default"]
    class http_c_http_config_default fn;
    http_c --> http_c_http_config_default
    main_c["main.c (c)"]
    class main_c mod;
    main_c_main["main"]
    class main_c_main fn;
    main_c --> main_c_main
    htmlfilter_c["htmlfilter.c (c)"]
    class htmlfilter_c mod;
    htmlfilter_c_html_filter_config_default["html_filter_config_default"]
    class htmlfilter_c_html_filter_config_default fn;
    htmlfilter_c --> htmlfilter_c_html_filter_config_default
    htmlfilter_c_hexval["hexval"]
    class htmlfilter_c_hexval fn;
    htmlfilter_c --> htmlfilter_c_hexval
    htmlfilter_c_decode_entity["decode_entity"]
    class htmlfilter_c_decode_entity fn;
    htmlfilter_c --> htmlfilter_c_decode_entity
    htmlfilter_c_html_filter_strip_tags["html_filter_strip_tags"]
    class htmlfilter_c_html_filter_strip_tags fn;
    htmlfilter_c --> htmlfilter_c_html_filter_strip_tags
    http_h["http.h (h)"]
    class http_h mod;
    http_h_http_config["http_config"]
    class http_h_http_config cls;
    http_h --> http_h_http_config
    http_h_http_response["http_response"]
    class http_h_http_response cls;
    http_h --> http_h_http_response
    http_h_HTTP_H["HTTP_H"]
    class http_h_HTTP_H fn;
    http_h --> http_h_HTTP_H
    htmlfilter_h["htmlfilter.h (h)"]
    class htmlfilter_h mod;
    htmlfilter_h_html_filter_config["html_filter_config"]
    class htmlfilter_h_html_filter_config cls;
    htmlfilter_h --> htmlfilter_h_html_filter_config
    htmlfilter_h_HTMLFILTER_H["HTMLFILTER_H"]
    class htmlfilter_h_HTMLFILTER_H fn;
    htmlfilter_h --> htmlfilter_h_HTMLFILTER_H
    build_sh["build.sh (sh)"]
    class build_sh mod;
    ext_htmlfilter_h["htmlfilter.h"]
    class ext_htmlfilter_h ext;
    htmlfilter_c -.->|imports| ext_htmlfilter_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    htmlfilter_c -.->|imports| ext_stdlib_h
    ext_string_h["string.h"]
    class ext_string_h ext;
    htmlfilter_c -.->|imports| ext_string_h
    ext_ctype_h["ctype.h"]
    class ext_ctype_h ext;
    htmlfilter_c -.->|imports| ext_ctype_h
    ext_http_h["http.h"]
    class ext_http_h ext;
    http_c -.->|imports| ext_http_h
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    http_c -.->|imports| ext_stdio_h
    http_c -.->|imports| ext_stdlib_h
    http_c -.->|imports| ext_string_h
    ext_unistd_h["unistd.h"]
    class ext_unistd_h ext;
    http_c -.->|imports| ext_unistd_h
    ext_sys_socket_h["socket.h"]
    class ext_sys_socket_h ext;
    http_c -.->|imports| ext_sys_socket_h
    ext_netinet_in_h["in.h"]
    class ext_netinet_in_h ext;
    http_c -.->|imports| ext_netinet_in_h
    ext_arpa_inet_h["inet.h"]
    class ext_arpa_inet_h ext;
    http_c -.->|imports| ext_arpa_inet_h
    ext_netdb_h["netdb.h"]
    class ext_netdb_h ext;
    http_c -.->|imports| ext_netdb_h
    ext_fcntl_h["fcntl.h"]
    class ext_fcntl_h ext;
    http_c -.->|imports| ext_fcntl_h
    ext_errno_h["errno.h"]
    class ext_errno_h ext;
    http_c -.->|imports| ext_errno_h
    ext_sys_select_h["select.h"]
    class ext_sys_select_h ext;
    http_c -.->|imports| ext_sys_select_h
    ext_time_h["time.h"]
    class ext_time_h ext;
    http_c -.->|imports| ext_time_h
    http_c -.->|imports| ext_ctype_h
    ext_openssl_ssl_h["ssl.h"]
    class ext_openssl_ssl_h ext;
    http_c -.->|imports| ext_openssl_ssl_h
    ext_openssl_err_h["err.h"]
    class ext_openssl_err_h ext;
    http_c -.->|imports| ext_openssl_err_h
    ext_stddef_h["stddef.h"]
    class ext_stddef_h ext;
    http_h -.->|imports| ext_stddef_h
    main_c -.->|imports| ext_http_h
    main_c -.->|imports| ext_htmlfilter_h
    main_c -.->|imports| ext_stdio_h
    main_c -.->|imports| ext_stdlib_h
    main_c -.->|imports| ext_string_h
```

---

## Architecture Reference

### C (3 files)

#### `htmlfilter.c`
**Path:** `htmlfilter.c`

**Functions:**
- `html_filter_config_default` (line 5) - *include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>*
- `hexval` (line 13)
- `decode_entity` (line 21)
- `html_filter_strip_tags` (line 119)

#### `http.c`
**Path:** `http.c`

**Functions:**
- `http_init` (line 66) - *endif*
- `http_cleanup` (line 75)
- `http_config_default` (line 82)
- `http_request` (line 95)
- `strcasecmp` (line 259)
- `http_response_free` (line 398)
- `http_socket_create` (line 406)
- `http_socket_connect` (line 415)
- `http_socket_send` (line 463)
- `http_socket_recv` (line 485)
- `http_socket_close` (line 496)
- `http_resolve_host` (line 501)
- `http_build_request` (line 514)
- `http_free_request` (line 540)
- `http_append_header` (line 548)
- `http_set_default_headers` (line 562)
- `http_handle_redirect` (line 575)
- `http_response_new` (line 658)
- `http_ssl_init` (line 673) - *ifdef USE_OPENSSL*
- `http_ssl_cleanup` (line 683)
- `http_ssl_connect` (line 693)
- `http_ssl_send` (line 713)
- `http_ssl_recv` (line 718)
- `http_ssl_close` (line 731)

**Macros:**
- `HTTP_DEFAULT_PORT_HTTP` (line 20)
- `HTTP_DEFAULT_PORT_HTTPS` (line 22)
- `HTTP_MAX_HEADER_COUNT` (line 23)
- `HTTP_MAX_PATH_LEN` (line 24)
- `HTTP_MAX_HOST_LEN` (line 25)
- `HTTP_RECV_BUFFER_SIZE` (line 26)
- `HTTP_TIMEOUT_SEC_DEFAULT` (line 27)

**Structs:**
- `http_header` (line 29) - *ifdef USE_OPENSSL include <openssl/ssl.h> include <openssl/err.h> endif define HTTP_DEFAULT_PORT_HTTP         80 define HTTP_DEFAULT_PORT_HTTPS    ...*
- `http_request` (line 34)

#### `main.c`
**Path:** `main.c`

**Functions:**
- `main` (line 10) - *curlfree - Minimal HTTP/HTTPS client library in C Compile: ./build.sh  include "http.h" include "htmlfilter.h" include <stdio.h> include <stdlib.h>...*

### H (2 files)

#### `htmlfilter.h`
**Path:** `htmlfilter.h`

**Macros:**
- `HTMLFILTER_H` (line 2)

**Structs:**
- `html_filter_config` (line 4) - *ifndef HTMLFILTER_H define HTMLFILTER_H*

#### `http.h`
**Path:** `http.h`

**Macros:**
- `HTTP_H` (line 2)

**Structs:**
- `http_config` (line 6) - *ifndef HTTP_H define HTTP_H include <stddef.h>*
- `http_response` (line 17)

### SH (1 files)

#### `build.sh`
**Path:** `build.sh`

*No symbols extracted*
