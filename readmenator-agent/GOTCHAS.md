# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `http.c` (score: 5.30)
- `http.h` (score: 4.80, imported by 2 files)
- `htmlfilter.h` (score: 4.40, imported by 2 files)
- `main.c` (score: 4.10)
- `htmlfilter.c` (score: 2.40)
- `sniffer.py` (score: 0.00)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `htmlfilter.h` -- 2 direct, 2 total dependents
- `http.h` -- 2 direct, 2 total dependents

## Hotspots (complexity + centrality)

- `http.c` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `http.h` -- complexity: 0.2, centrality: 0.3, combined: 0.3
- `main.c` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `htmlfilter.c` -- complexity: 0.1, centrality: 0.3, combined: 0.2
- `htmlfilter.h` -- complexity: 0.1, centrality: 0.2, combined: 0.2
- `sniffer.py` -- complexity: 0.0, centrality: 0.0, combined: 0.0

## Dataflow Issues (INFERRED, review each lead)

- `http.c:135` `http_request` [DEAD_STORE] `redirect_count`: `redirect_count` assigned at line 135 but never read afterwards.
- `http.c:136` `http_request` [DEAD_STORE] `resp`: `resp` assigned at line 136 but never read afterwards.
- `http.c:196` `http_request` [DEAD_STORE] `chunked`: `chunked` assigned at line 196 but never read afterwards.
- `http.c:199` `http_request` [DEAD_STORE] `final_headers`: `final_headers` assigned at line 199 but never read afterwards.
- `http.c:200` `http_request` [DEAD_STORE] `final_headers_len`: `final_headers_len` assigned at line 200 but never read afterwards.
- `http.c:305` `strcasecmp` [DEAD_STORE] `sp2`: `sp2` assigned at line 305 but never read afterwards.
- `http.c:352` `strcasecmp` [DEAD_STORE] `dst`: `dst` assigned at line 352 but never read afterwards.
- `http.c:510` `http_resolve_host` [UNCHECKED_ALLOC] `ip`: Result of allocator stored in `ip` is never checked against NULL.
- `http.c:537` `http_build_request` [DEAD_STORE] `ptr`: `ptr` assigned at line 537 but never read afterwards.
