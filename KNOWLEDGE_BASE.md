# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. 6 files, 88 symbols, 26 imports. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Start here:** Statistics Dashboard for scope, God Nodes for blast radius, Architecture Reference for per-file API. Agents: prefer `readmenator-agent/INDEX.md` + `SYMBOLS.md`.

**Total Files Parsed:** 6 | **Total Symbols Extracted:** 88 | **Total Imports:** 26
 | **Resolved Imports:** 4

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:b3ca3bb | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Ranked Context](#ranked-context)
4. [God Nodes](#god-nodes)
5. [Community Analysis](#community-analysis)
6. [Surprising Connections](#surprising-connections)
7. [Suggested Questions](#suggested-questions)
8. [Hotspot Analysis](#hotspot-analysis)
9. [Change Impact Analysis](#change-impact-analysis)
10. [Suggested Linting Rules](#suggested-linting-rules)
11. [Orphans](#orphans)
12. [Query Recipes](#query-recipes)
13. [Structural Knowledge Map](#structural-knowledge-map)
14. [UML Class Diagram](#uml-class-diagram)
15. [Code Property Graph](#code-property-graph)
16. [Architecture Reference](#architecture-reference)
    - [C (3 files)](#c-3-files)
    - [H (2 files)](#h-2-files)
    - [PY (1 files)](#py-1-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 6 |
| Total Symbols | 88 |
| Total Imports | 26 |
| Call Edges | 0 |
| Inheritance Edges | 0 |
| Languages | 3 |
| Avg Symbols/File | 14.7 |
| Avg Imports/File | 4.3 |
| Resolved Imports | 4 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `http.c` | 16 | 61 | c |
| `main.c` | 5 | 9 | c |
| `htmlfilter.c` | 4 | 6 | c |
| `http.h` | 1 | 8 | h |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `htmlfilter.h` | 2 | 4 | h |
| `http.h` | 2 | 8 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 4 |
| presentation | 2 |

### utility

- `htmlfilter.c` (c, 6 symbols)
- `htmlfilter.h` (h, 4 symbols)
- `main.c` (c, 9 symbols)
- `sniffer.py` (py, 0 symbols)

### presentation

- `http.c` (c, 61 symbols)
- `http.h` (h, 8 symbols)

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `htmlfilter.h` | 0.2209 | 0.3013 | 0.3013 | 0.00 | 0.25 |
| 2 | `http.h` | 0.2084 | 0.3013 | 0.3013 | 0.00 | 0.12 |
| 3 | `htmlfilter.c` | 0.1194 | 0.1325 | 0.1325 | 0.00 | 0.33 |
| 4 | `main.c` | 0.0972 | 0.1325 | 0.1325 | 0.00 | 0.11 |
| 5 | `http.c` | 0.0910 | 0.1325 | 0.1325 | 0.00 | 0.05 |
| 6 | `sniffer.py` | 0.0000 | 0.0000 | 0.0000 | 0.00 | 0.00 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `http.c` | 8.1 | | 0.1325 |
| `main.c` | 4.9 | | 0.1325 |
| `http.h` | 4.8 | | 0.3013 |
| `htmlfilter.h` | 4.4 | | 0.3013 |
| `htmlfilter.c` | 2.6 | | 0.1325 |
| `sniffer.py` | 0.0 | | 0.0000 |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root (Cohesion: 0.67)

**3 files** in this community:

- `htmlfilter.c` (c, 6 symbols)
- `htmlfilter.h` (h, 4 symbols)
- `main.c` (c, 9 symbols)

### root (Cohesion: 0.50)

**2 files** in this community:

- `http.c` (c, 61 symbols)
- `http.h` (h, 8 symbols)

---

## Surprising Connections

Files in different communities connected through 3+ indirect hops.

- `htmlfilter.c` <-> `http.c` (4 hops, across 2 communities)
- `htmlfilter.c` <-> `http.h` (3 hops, across 2 communities)
- `htmlfilter.h` <-> `http.c` (3 hops, across 2 communities)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does http.c depend on, and what depends on it? (1 connections)
- What does main.c depend on, and what depends on it? (2 connections)
- What does http.h depend on, and what depends on it? (2 connections)
- How are the 3 files in 'root' related to each other?
- Why are htmlfilter.c and http.c connected through 4 hops across 2 communities?

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `htmlfilter.h` | 0.066 | 0.235 | 0.167 | 4 | 4 |
| `http.h` | 0.131 | 0.294 | 0.229 | 8 | 5 |
| `htmlfilter.c` | 0.098 | 0.294 | 0.216 | 6 | 5 |
| `main.c` | 0.147 | 0.412 | 0.306 | 9 | 7 |
| `http.c` | 1.000 | 1.000 | 1.000 | 61 | 17 |
| `sniffer.py` | 0.000 | 0.000 | 0.000 | 0 | 0 |

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `htmlfilter.h` | 2 | 0 | 2 |
| `http.h` | 2 | 0 | 2 |
| `htmlfilter.c` | 0 | 0 | 0 |
| `http.c` | 0 | 0 | 0 |
| `main.c` | 0 | 0 | 0 |
| `sniffer.py` | 0 | 0 | 0 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 67 total | c | 67 |
| `RM002` | info | Large number of functions in h: 7 total | h | 7 |
| `RM003` | info | Print statement found (consider logging instead) | python | 12 |

---

## Orphans

Files with no documentation or low connectivity. These are candidates for documentation investment or cleanup.

- `sniffer.py` (0 symbols, no doc)

---

## Query Recipes

Example queries you can run against this knowledge base using the ranking engine:

```
# Find files most relevant to a concept
readmenator query "Where is the import resolver implemented?"

# Rank files by relevance to a topic
readmenator query "How does documentation generation work?"

# Explain why a file ranks highly
readmenator query "explain readmenator/_documentation.py"

# Trace dependency paths with ranked context
readmenator query "path from CLI to exporter"
```

The ranking model uses the following signals:

- **Personalized PageRank** (45% weight): query-specific relevance via seed propagation
- **Global Authority** (20% weight): structural importance via standard PageRank
- **Test Coverage** (15% weight): fraction of symbols referenced in test files
- **Doc Coverage** (10% weight): presence of docstrings and file-level docs
- **Freshness** (10% weight): recent modification activity

Results include score decomposition and justification paths for each ranked item.

---

## Structural Knowledge Map

```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    subgraph community_1 ["root"]
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
    end
    subgraph community_0 ["root"]
    main_c["main.c (c)"]
    class main_c mod;
    htmlfilter_c["htmlfilter.c (c)"]
    class htmlfilter_c mod;
    http_h["http.h (h)"]
    class http_h mod;
    htmlfilter_h["htmlfilter.h (h)"]
    class htmlfilter_h mod;
    sniffer_py["sniffer.py (py)"]
    class sniffer_py mod;
    end
    htmlfilter_c -- resolved_imports --> htmlfilter_h
    http_c -- resolved_imports --> http_h
    main_c -- resolved_imports --> http_h
    main_c -- resolved_imports --> htmlfilter_h
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

## UML Class Diagram

Auto-generated Mermaid class diagram from parsed class-level symbols. Shows classes, structs, interfaces, traits, and their methods with inheritance and dependency relationships.

```mermaid
classDiagram
  class htmlfilter_h_html_filter_config {
    <<struct>>
    +html_filter_config_default(struct html_filter_config *cfg);
    +html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);
  }
  class http_c_http_header {
    <<struct>>
    +http_init(void)
    +http_cleanup(void)
    +http_config_default(struct http_config *cfg)
    +http_request(struct http_config *cfg, const char *method,
                 ...
    +strcasecmp(val, "chunked") == 0)
    +http_response_free(struct http_response *resp)
    +http_socket_create(void)
    +http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)
    +http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)
    +http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)
  }
  class http_c_http_request {
    <<struct>>
    +http_init(void)
    +http_cleanup(void)
    +http_config_default(struct http_config *cfg)
    +http_request(struct http_config *cfg, const char *method,
                 ...
    +strcasecmp(val, "chunked") == 0)
    +http_response_free(struct http_response *resp)
    +http_socket_create(void)
    +http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)
    +http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)
    +http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)
  }
  class http_h_http_config {
    <<struct>>
    +http_init(void);
    +http_cleanup(void);
    +http_config_default(struct http_config *cfg);
    +http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);
    +http_response_free(struct http_response *resp);
  }
  class http_h_http_response {
    <<struct>>
    +http_init(void);
    +http_cleanup(void);
    +http_config_default(struct http_config *cfg);
    +http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);
    +http_response_free(struct http_response *resp);
  }
  http_c_http_header --> http_h_http_config : uses
  http_c_http_header --> http_h_http_response : uses
  http_c_http_request --> http_h_http_config : uses
  http_c_http_request --> http_h_http_response : uses
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 0.667, "id": 0, "label": "root", "size": 3}, {"cohesion": 0.5, "id": 1, "label": "root", "size": 2}], "god_nodes": [{"node_id": "http.c", "score": 8.1}, {"node_id": "main.c", "score": 4.9}, {"node_id": "http.h", "score": 4.8}, {"node_id": "htmlfilter.h", "score": 4.4}, {"node_id": "htmlfilter.c", "score": 2.6}, {"node_id": "sniffer.py", "score": 0.0}], "surprising_connections": [{"hops": 4, "source": "htmlfilter.c", "target": "http.c"}, {"hops": 3, "source": "htmlfilter.c", "target": "http.h"}, {"hops": 3, "source": "htmlfilter.h", "target": "http.c"}]}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "htmlfilter.c", "target": "htmlfilter.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "htmlfilter.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "htmlfilter.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "htmlfilter.c", "target": "ctype.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "http.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "unistd.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "sys/socket.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "netinet/in.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "arpa/inet.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "netdb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "fcntl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "errno.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "sys/select.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "time.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "ctype.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "openssl/ssl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.c", "target": "openssl/err.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "http.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "http.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "htmlfilter.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "main.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "htmlfilter.c", "target": "htmlfilter.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "http.c", "target": "http.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "main.c", "target": "http.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "main.c", "target": "htmlfilter.h"}], "generator": "readmenator", "metadata": {"edge_count": 30, "file_count": 6, "language_count": 3, "symbol_count": 88}, "nodes": [{"doc": "include \"htmlfilter.h\" include <stdlib.h> include <string.h> include <ctype.h>", "id": "htmlfilter.c", "kind": "module", "label": "htmlfilter.c", "language": "c", "sha256": "fb47abed7a6e80d3", "symbol_count": 6, "symbols": [{"doc": "include \"htmlfilter.h\" include <stdlib.h> include <string.h> include <ctype.h>", "kind": "function", "line": 5, "name": "html_filter_config_default", "signature": "void html_filter_config_default(struct html_filter_config *cfg)"}, {"kind": "function", "line": 13, "name": "hexval", "signature": "static int hexval(char c)"}, {"kind": "function", "line": 21, "name": "decode_entity", "signature": "static char *decode_entity(const char *entity, size_t len)"}, {"kind": "function", "line": 119, "name": "html_filter_strip_tags", "signature": "char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)"}, {"kind": "function", "line": 66, "name": "strdup", "signature": "return strdup(buf);"}, {"kind": "function", "line": 209, "name": "free", "signature": "free(decoded);"}]}, {"doc": "ifndef HTMLFILTER_H define HTMLFILTER_H", "id": "htmlfilter.h", "kind": "module", "label": "htmlfilter.h", "language": "h", "sha256": "4d5f0f4e98dff589", "symbol_count": 4, "symbols": [{"kind": "struct", "line": 4, "name": "html_filter_config"}, {"kind": "function", "line": 9, "name": "html_filter_config_default", "signature": "void html_filter_config_default(struct html_filter_config *cfg);"}, {"kind": "function", "line": 11, "name": "html_filter_strip_tags", "signature": "char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);"}, {"kind": "macro", "line": 2, "name": "HTMLFILTER_H", "signature": "#define HTMLFILTER_H"}]}, {"doc": "include \"http.h\" include <stdio.h> include <stdlib.h> include <string.h> include <unistd.h> include <sys/socket.h> include <netinet/in.h> include <arpa/inet.h> include <netdb.h> include <fcntl.h> include <errno.h> include <sys/select.h> include <time.h> include <ctype.h>  ifdef USE_OPENSSL include <openssl/ssl.h> include <openssl/err.h> endif  define HTTP_DEFAULT_PORT_HTTP         80 define HTTP_DEFAULT_PORT_HTTPS        443 define HTTP_MAX_HEADER_COUNT          64 define HTTP_MAX_PATH_LEN              4096 define HTTP_MAX_HOST_LEN              256 define HTTP_RECV_BUFFER_SIZE          8192 define HTTP_TIMEOUT_SEC_DEFAULT       30", "id": "http.c", "kind": "module", "label": "http.c", "language": "c", "sha256": "fa5bc7eafc18c9e9", "symbol_count": 61, "symbols": [{"kind": "struct", "line": 29, "name": "http_header"}, {"kind": "struct", "line": 34, "name": "http_request"}, {"doc": "endif", "kind": "function", "line": 66, "name": "http_init", "signature": "int http_init(void)"}, {"kind": "function", "line": 75, "name": "http_cleanup", "signature": "void http_cleanup(void)"}, {"kind": "function", "line": 82, "name": "http_config_default", "signature": "void http_config_default(struct http_config *cfg)"}, {"kind": "function", "line": 95, "name": "http_request", "signature": "struct http_response *http_request(struct http_config *cfg, const char *method,\n                 ..."}, {"kind": "function", "line": 259, "name": "strcasecmp", "signature": "strcasecmp(val, \"chunked\") == 0)"}, {"kind": "function", "line": 398, "name": "http_response_free", "signature": "void http_response_free(struct http_response *resp)"}, {"kind": "function", "line": 406, "name": "http_socket_create", "signature": "static int http_socket_create(void)"}, {"kind": "function", "line": 415, "name": "http_socket_connect", "signature": "static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)"}, {"kind": "function", "line": 463, "name": "http_socket_send", "signature": "static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)"}, {"kind": "function", "line": 485, "name": "http_socket_recv", "signature": "static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)"}, {"kind": "function", "line": 496, "name": "http_socket_close", "signature": "static void http_socket_close(int sockfd)"}, {"kind": "function", "line": 501, "name": "http_resolve_host", "signature": "static char *http_resolve_host(const char *host)"}, {"kind": "function", "line": 514, "name": "http_build_request", "signature": "static char *http_build_request(struct http_request *req)"}, {"kind": "function", "line": 540, "name": "http_free_request", "signature": "static void http_free_request(struct http_request *req)"}, {"kind": "function", "line": 548, "name": "http_append_header", "signature": "static int http_append_header(struct http_request *req, const char *key, const char *value)"}, {"kind": "function", "line": 562, "name": "http_set_default_headers", "signature": "static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)"}, {"kind": "function", "line": 575, "name": "http_handle_redirect", "signature": "static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,\n            ..."}, {"kind": "function", "line": 658, "name": "http_response_new", "signature": "static struct http_response *http_response_new(void)"}, {"doc": "ifdef USE_OPENSSL", "kind": "function", "line": 673, "name": "http_ssl_init", "signature": "static int http_ssl_init(void)"}, {"kind": "function", "line": 683, "name": "http_ssl_cleanup", "signature": "static void http_ssl_cleanup(void)"}, {"kind": "function", "line": 693, "name": "http_ssl_connect", "signature": "static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)"}, {"kind": "function", "line": 713, "name": "http_ssl_send", "signature": "static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)"}, {"kind": "function", "line": 718, "name": "http_ssl_recv", "signature": "static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)"}, {"kind": "function", "line": 731, "name": "http_ssl_close", "signature": "static void http_ssl_close(SSL *ssl, int sockfd)"}, {"kind": "function", "line": 86, "name": "memset", "signature": "memset(cfg, 0, sizeof(*cfg));"}, {"kind": "function", "line": 93, "name": "strcpy", "signature": "strcpy(cfg->ca_bundle_path, \"/etc/ssl/certs/ca-certificates.crt\");"}, {"kind": "function", "line": 104, "name": "strncpy", "signature": "strncpy(req.method, method, sizeof(req.method)-1);"}, {"kind": "function", "line": 126, "name": "free", "signature": "free(hcopy);"}, {"kind": "function", "line": 219, "name": "memcpy", "signature": "memcpy(full_response + full_response_len, recv_buf, recv_len);"}, {"kind": "function", "line": 340, "name": "memmove", "signature": "memmove(dst, src, chunk_size);"}, {"kind": "function", "line": 412, "name": "setsockopt", "signature": "setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));"}, {"kind": "function", "line": 433, "name": "fcntl", "signature": "fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);"}, {"kind": "function", "line": 444, "name": "FD_ZERO", "signature": "FD_ZERO(&wfds);"}, {"kind": "function", "line": 445, "name": "FD_SET", "signature": "FD_SET(sockfd, &wfds);"}, {"kind": "function", "line": 454, "name": "getsockopt", "signature": "getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);"}, {"kind": "function", "line": 494, "name": "recv", "signature": "return recv(sockfd, buf, bufsize, 0);"}, {"kind": "function", "line": 499, "name": "close", "signature": "close(sockfd);"}, {"kind": "function", "line": 511, "name": "freeaddrinfo", "signature": "freeaddrinfo(res);"}, {"kind": "function", "line": 570, "name": "snprintf", "signature": "snprintf(clen, sizeof(clen), \"%zu\", req->body_len);"}, {"kind": "function", "line": 675, "name": "SSL_library_init", "signature": "SSL_library_init();"}, {"kind": "function", "line": 676, "name": "OpenSSL_add_all_algorithms", "signature": "OpenSSL_add_all_algorithms();"}, {"kind": "function", "line": 677, "name": "SSL_load_error_strings", "signature": "SSL_load_error_strings();"}, {"kind": "function", "line": 680, "name": "SSL_CTX_set_options", "signature": "SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);"}, {"kind": "function", "line": 687, "name": "SSL_CTX_free", "signature": "SSL_CTX_free(http_ssl_ctx);"}, {"kind": "function", "line": 690, "name": "EVP_cleanup", "signature": "EVP_cleanup();"}, {"kind": "function", "line": 691, "name": "ERR_free_strings", "signature": "ERR_free_strings();"}, {"kind": "function", "line": 698, "name": "SSL_set_fd", "signature": "SSL_set_fd(ssl, sockfd);"}, {"kind": "function", "line": 700, "name": "SSL_CTX_set_verify", "signature": "SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);"}, {"kind": "function", "line": 702, "name": "SSL_CTX_load_verify_locations", "signature": "SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);"}, {"kind": "function", "line": 708, "name": "SSL_free", "signature": "SSL_free(ssl);"}, {"kind": "function", "line": 716, "name": "SSL_write", "signature": "return SSL_write(ssl, data, (int)len);"}, {"kind": "function", "line": 735, "name": "SSL_shutdown", "signature": "SSL_shutdown(ssl);"}, {"kind": "macro", "line": 20, "name": "HTTP_DEFAULT_PORT_HTTP", "signature": "#define HTTP_DEFAULT_PORT_HTTP"}, {"kind": "macro", "line": 22, "name": "HTTP_DEFAULT_PORT_HTTPS", "signature": "#define HTTP_DEFAULT_PORT_HTTPS"}, {"kind": "macro", "line": 23, "name": "HTTP_MAX_HEADER_COUNT", "signature": "#define HTTP_MAX_HEADER_COUNT"}, {"kind": "macro", "line": 24, "name": "HTTP_MAX_PATH_LEN", "signature": "#define HTTP_MAX_PATH_LEN"}, {"kind": "macro", "line": 25, "name": "HTTP_MAX_HOST_LEN", "signature": "#define HTTP_MAX_HOST_LEN"}, {"kind": "macro", "line": 26, "name": "HTTP_RECV_BUFFER_SIZE", "signature": "#define HTTP_RECV_BUFFER_SIZE"}, {"kind": "macro", "line": 27, "name": "HTTP_TIMEOUT_SEC_DEFAULT", "signature": "#define HTTP_TIMEOUT_SEC_DEFAULT"}]}, {"doc": "ifndef HTTP_H define HTTP_H  include <stddef.h>", "id": "http.h", "kind": "module", "label": "http.h", "language": "h", "sha256": "e07c69deb2092f98", "symbol_count": 8, "symbols": [{"kind": "struct", "line": 6, "name": "http_config"}, {"kind": "struct", "line": 17, "name": "http_response"}, {"kind": "function", "line": 25, "name": "http_init", "signature": "int http_init(void);"}, {"kind": "function", "line": 27, "name": "http_cleanup", "signature": "void http_cleanup(void);"}, {"kind": "function", "line": 28, "name": "http_config_default", "signature": "void http_config_default(struct http_config *cfg);"}, {"kind": "function", "line": 29, "name": "http_request", "signature": "struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);"}, {"kind": "function", "line": 32, "name": "http_response_free", "signature": "void http_response_free(struct http_response *resp);"}, {"kind": "macro", "line": 2, "name": "HTTP_H", "signature": "#define HTTP_H"}]}, {"id": "main.c", "kind": "module", "label": "main.c", "language": "c", "sha256": "14d0038779ae5204", "symbol_count": 9, "symbols": [{"doc": "curlfree - Minimal HTTP/HTTPS client library in C Compile: ./build.sh  include \"http.h\" include \"htmlfilter.h\" include <stdio.h> include <stdlib.h> include <string.h>", "kind": "function", "line": 10, "name": "main", "signature": "int main(int argc, char **argv)"}, {"kind": "function", "line": 14, "name": "fprintf", "signature": "fprintf(stderr, \"Usage: %s <URL>\\n\", argv[0]);"}, {"kind": "function", "line": 44, "name": "free", "signature": "free(host);"}, {"kind": "function", "line": 64, "name": "http_config_default", "signature": "http_config_default(&cfg);"}, {"kind": "function", "line": 65, "name": "strncpy", "signature": "strncpy(cfg.host, host, 255);"}, {"kind": "function", "line": 76, "name": "http_cleanup", "signature": "http_cleanup();"}, {"kind": "function", "line": 82, "name": "http_response_free", "signature": "http_response_free(resp);"}, {"kind": "function", "line": 89, "name": "html_filter_config_default", "signature": "html_filter_config_default(&hcfg);"}, {"kind": "function", "line": 96, "name": "printf", "signature": "printf(\"%s\\n\", plain);"}]}, {"id": "sniffer.py", "kind": "module", "label": "sniffer.py", "language": "py", "sha256": "4bd531cc0eae2249", "symbol_count": 0, "symbols": []}], "type": "CodePropertyGraph", "version": "1.0"}
```

---

## Architecture Reference

### C (3 files)

#### `htmlfilter.c`
**Path:** `htmlfilter.c`
**File Doc:** *include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>*

**Functions:**
- `html_filter_config_default` (line 5) `void html_filter_config_default(struct html_filter_config *cfg)` - *include "htmlfilter.h" include <stdlib.h> include <string.h> include <ctype.h>*
- `hexval` (line 13) `static int hexval(char c)`
- `decode_entity` (line 21) `static char *decode_entity(const char *entity, size_t len)`
- `html_filter_strip_tags` (line 119) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`
- `strdup` (line 66) `return strdup(buf);`
- `free` (line 209) `free(decoded);`

#### `http.c`
**Path:** `http.c`
**File Doc:** *include "http.h" include <stdio.h> include <stdlib.h> include <string.h> include <unistd.h> include <sys/socket.h> include <netinet/in.h> include <arpa/inet.h> include <netdb.h> include <fcntl.h> include <errno.h> include <sys/select.h> include <time.h> include <ctype.h>  ifdef USE_OPENSSL include <openssl/ssl.h> include <openssl/err.h> endif  define HTTP_DEFAULT_PORT_HTTP         80 define HTTP_DEFAULT_PORT_HTTPS        443 define HTTP_MAX_HEADER_COUNT          64 define HTTP_MAX_PATH_LEN              4096 define HTTP_MAX_HOST_LEN              256 define HTTP_RECV_BUFFER_SIZE          8192 define HTTP_TIMEOUT_SEC_DEFAULT       30*

**Functions:**
- `http_init` (line 66) `int http_init(void)` - *endif*
- `http_cleanup` (line 75) `void http_cleanup(void)`
- `http_config_default` (line 82) `void http_config_default(struct http_config *cfg)`
- `http_request` (line 95) `struct http_response *http_request(struct http_config *cfg, const char *method,
                 ...`
- `strcasecmp` (line 259) `strcasecmp(val, "chunked") == 0)`
- `http_response_free` (line 398) `void http_response_free(struct http_response *resp)`
- `http_socket_create` (line 406) `static int http_socket_create(void)`
- `http_socket_connect` (line 415) `static int http_socket_connect(int sockfd, const char *host, int port, int timeout_sec)`
- `http_socket_send` (line 463) `static ssize_t http_socket_send(int sockfd, const char *data, size_t len, int timeout_sec)`
- `http_socket_recv` (line 485) `static ssize_t http_socket_recv(int sockfd, char *buf, size_t bufsize, int timeout_sec)`
- `http_socket_close` (line 496) `static void http_socket_close(int sockfd)`
- `http_resolve_host` (line 501) `static char *http_resolve_host(const char *host)`
- `http_build_request` (line 514) `static char *http_build_request(struct http_request *req)`
- `http_free_request` (line 540) `static void http_free_request(struct http_request *req)`
- `http_append_header` (line 548) `static int http_append_header(struct http_request *req, const char *key, const char *value)`
- `http_set_default_headers` (line 562) `static void http_set_default_headers(struct http_request *req, const struct http_config *cfg)`
- `http_handle_redirect` (line 575) `static int http_handle_redirect(struct http_response *resp, struct http_config *cfg,
            ...`
- `http_response_new` (line 658) `static struct http_response *http_response_new(void)`
- `http_ssl_init` (line 673) `static int http_ssl_init(void)` - *ifdef USE_OPENSSL*
- `http_ssl_cleanup` (line 683) `static void http_ssl_cleanup(void)`
- `http_ssl_connect` (line 693) `static SSL *http_ssl_connect(int sockfd, const struct http_config *cfg)`
- `http_ssl_send` (line 713) `static ssize_t http_ssl_send(SSL *ssl, const char *data, size_t len)`
- `http_ssl_recv` (line 718) `static ssize_t http_ssl_recv(SSL *ssl, char *buf, size_t bufsize)`
- `http_ssl_close` (line 731) `static void http_ssl_close(SSL *ssl, int sockfd)`
- `memset` (line 86) `memset(cfg, 0, sizeof(*cfg));`
- `strcpy` (line 93) `strcpy(cfg->ca_bundle_path, "/etc/ssl/certs/ca-certificates.crt");`
- `strncpy` (line 104) `strncpy(req.method, method, sizeof(req.method)-1);`
- `free` (line 126) `free(hcopy);`
- `memcpy` (line 219) `memcpy(full_response + full_response_len, recv_buf, recv_len);`
- `memmove` (line 340) `memmove(dst, src, chunk_size);`
- `setsockopt` (line 412) `setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));`
- `fcntl` (line 433) `fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);`
- `FD_ZERO` (line 444) `FD_ZERO(&wfds);`
- `FD_SET` (line 445) `FD_SET(sockfd, &wfds);`
- `getsockopt` (line 454) `getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);`
- `recv` (line 494) `return recv(sockfd, buf, bufsize, 0);`
- `close` (line 499) `close(sockfd);`
- `freeaddrinfo` (line 511) `freeaddrinfo(res);`
- `snprintf` (line 570) `snprintf(clen, sizeof(clen), "%zu", req->body_len);`
- `SSL_library_init` (line 675) `SSL_library_init();`
- `OpenSSL_add_all_algorithms` (line 676) `OpenSSL_add_all_algorithms();`
- `SSL_load_error_strings` (line 677) `SSL_load_error_strings();`
- `SSL_CTX_set_options` (line 680) `SSL_CTX_set_options(http_ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);`
- `SSL_CTX_free` (line 687) `SSL_CTX_free(http_ssl_ctx);`
- `EVP_cleanup` (line 690) `EVP_cleanup();`
- `ERR_free_strings` (line 691) `ERR_free_strings();`
- `SSL_set_fd` (line 698) `SSL_set_fd(ssl, sockfd);`
- `SSL_CTX_set_verify` (line 700) `SSL_CTX_set_verify(http_ssl_ctx, SSL_VERIFY_PEER, NULL);`
- `SSL_CTX_load_verify_locations` (line 702) `SSL_CTX_load_verify_locations(http_ssl_ctx, cfg->ca_bundle_path, NULL);`
- `SSL_free` (line 708) `SSL_free(ssl);`
- `SSL_write` (line 716) `return SSL_write(ssl, data, (int)len);`
- `SSL_shutdown` (line 735) `SSL_shutdown(ssl);`

**Macros:**
- `HTTP_DEFAULT_PORT_HTTP` (line 20) `#define HTTP_DEFAULT_PORT_HTTP`
- `HTTP_DEFAULT_PORT_HTTPS` (line 22) `#define HTTP_DEFAULT_PORT_HTTPS`
- `HTTP_MAX_HEADER_COUNT` (line 23) `#define HTTP_MAX_HEADER_COUNT`
- `HTTP_MAX_PATH_LEN` (line 24) `#define HTTP_MAX_PATH_LEN`
- `HTTP_MAX_HOST_LEN` (line 25) `#define HTTP_MAX_HOST_LEN`
- `HTTP_RECV_BUFFER_SIZE` (line 26) `#define HTTP_RECV_BUFFER_SIZE`
- `HTTP_TIMEOUT_SEC_DEFAULT` (line 27) `#define HTTP_TIMEOUT_SEC_DEFAULT`

**Structs:**
- `http_header` (line 29)
- `http_request` (line 34)

#### `main.c`
**Path:** `main.c`

**Functions:**
- `main` (line 10) `int main(int argc, char **argv)` - *curlfree - Minimal HTTP/HTTPS client library in C Compile: ./build.sh  include "http.h" include "htmlfilter.h" include <stdio.h> include <stdlib.h> include <string.h>*
- `fprintf` (line 14) `fprintf(stderr, "Usage: %s <URL>\n", argv[0]);`
- `free` (line 44) `free(host);`
- `http_config_default` (line 64) `http_config_default(&cfg);`
- `strncpy` (line 65) `strncpy(cfg.host, host, 255);`
- `http_cleanup` (line 76) `http_cleanup();`
- `http_response_free` (line 82) `http_response_free(resp);`
- `html_filter_config_default` (line 89) `html_filter_config_default(&hcfg);`
- `printf` (line 96) `printf("%s\n", plain);`

### H (2 files)

#### `htmlfilter.h`
**Path:** `htmlfilter.h`
**File Doc:** *ifndef HTMLFILTER_H define HTMLFILTER_H*

**Imported by:** `htmlfilter.c`, `main.c`

**Functions:**
- `html_filter_config_default` (line 9) `void html_filter_config_default(struct html_filter_config *cfg);`
- `html_filter_strip_tags` (line 11) `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);`

**Macros:**
- `HTMLFILTER_H` (line 2) `#define HTMLFILTER_H`

**Structs:**
- `html_filter_config` (line 4)

#### `http.h`
**Path:** `http.h`
**File Doc:** *ifndef HTTP_H define HTTP_H  include <stddef.h>*

**Imported by:** `http.c`, `main.c`

**Functions:**
- `http_init` (line 25) `int http_init(void);`
- `http_cleanup` (line 27) `void http_cleanup(void);`
- `http_config_default` (line 28) `void http_config_default(struct http_config *cfg);`
- `http_request` (line 29) `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body);`
- `http_response_free` (line 32) `void http_response_free(struct http_response *resp);`

**Macros:**
- `HTTP_H` (line 2) `#define HTTP_H`

**Structs:**
- `http_config` (line 6)
- `http_response` (line 17)

### PY (1 files)

#### `sniffer.py`
**Path:** `sniffer.py`

*No symbols extracted*
