# Concepts

Second-brain semantic layer: nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

| Concept | Files | Mentions | Top Files |
|---------|-------|----------|-----------|
| `default` | 4 | 8 | `htmlfilter.c`, `htmlfilter.h`, `http.c`, `http.h` |
| `config` | 4 | 6 | `htmlfilter.c`, `htmlfilter.h`, `http.c`, `http.h` |
| `http` | 2 | 45 | `http.c`, `http.h` |
| `filter` | 2 | 5 | `htmlfilter.c`, `htmlfilter.h` |
| `html` | 2 | 5 | `htmlfilter.c`, `htmlfilter.h` |
| `htmlfilter` | 2 | 5 | `htmlfilter.c`, `htmlfilter.h` |
| `request` | 2 | 5 | `http.c`, `http.h` |
| `response` | 2 | 4 | `http.c`, `http.h` |
| `cleanup` | 2 | 3 | `http.c`, `http.h` |
| `free` | 2 | 3 | `http.c`, `http.h` |
| `strip` | 2 | 2 | `htmlfilter.c`, `htmlfilter.h` |
| `tags` | 2 | 2 | `htmlfilter.c`, `htmlfilter.h` |

## Verb Edges

| Source | Verb | Target | Strength |
|--------|------|--------|----------|
| `config` | `consumes` | `default` | 1.00 |
| `config` | `depends_on` | `default` | 1.00 |
| `default` | `consumes` | `config` | 1.00 |
| `default` | `depends_on` | `config` | 1.00 |
| `cleanup` | `consumes` | `config` | 0.50 |
| `cleanup` | `depends_on` | `config` | 0.50 |
| `cleanup` | `consumes` | `default` | 0.50 |
| `cleanup` | `depends_on` | `default` | 0.50 |
| `cleanup` | `consumes` | `free` | 0.50 |
| `cleanup` | `depends_on` | `free` | 0.50 |
| `cleanup` | `consumes` | `http` | 0.50 |
| `cleanup` | `depends_on` | `http` | 0.50 |
| `cleanup` | `consumes` | `request` | 0.50 |
| `cleanup` | `depends_on` | `request` | 0.50 |
| `cleanup` | `consumes` | `response` | 0.50 |
| `cleanup` | `depends_on` | `response` | 0.50 |
| `config` | `consumes` | `cleanup` | 0.50 |
| `config` | `depends_on` | `cleanup` | 0.50 |
| `config` | `consumes` | `filter` | 0.50 |
| `config` | `depends_on` | `filter` | 0.50 |
| `config` | `consumes` | `free` | 0.50 |
| `config` | `depends_on` | `free` | 0.50 |
| `config` | `consumes` | `html` | 0.50 |
| `config` | `depends_on` | `html` | 0.50 |
| `config` | `consumes` | `htmlfilter` | 0.50 |
| `config` | `depends_on` | `htmlfilter` | 0.50 |
| `config` | `consumes` | `http` | 0.50 |
| `config` | `depends_on` | `http` | 0.50 |
| `config` | `consumes` | `request` | 0.50 |
| `config` | `depends_on` | `request` | 0.50 |
| `config` | `consumes` | `response` | 0.50 |
| `config` | `depends_on` | `response` | 0.50 |
| `config` | `consumes` | `strip` | 0.50 |
| `config` | `depends_on` | `strip` | 0.50 |
| `config` | `consumes` | `tags` | 0.50 |
| `config` | `depends_on` | `tags` | 0.50 |
| `default` | `consumes` | `cleanup` | 0.50 |
| `default` | `depends_on` | `cleanup` | 0.50 |
| `default` | `consumes` | `filter` | 0.50 |
| `default` | `depends_on` | `filter` | 0.50 |
| `default` | `consumes` | `free` | 0.50 |
| `default` | `depends_on` | `free` | 0.50 |
| `default` | `consumes` | `html` | 0.50 |
| `default` | `depends_on` | `html` | 0.50 |
| `default` | `consumes` | `htmlfilter` | 0.50 |
| `default` | `depends_on` | `htmlfilter` | 0.50 |
| `default` | `consumes` | `http` | 0.50 |
| `default` | `depends_on` | `http` | 0.50 |
| `default` | `consumes` | `request` | 0.50 |
| `default` | `depends_on` | `request` | 0.50 |

## Dialectic Prompts

- Thesis: `cleanup` centralizes 2 files; Antithesis: `config` pulls 4 files with 2 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `cleanup` centralizes 2 files; Antithesis: `default` pulls 4 files with 2 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `cleanup` centralizes 2 files; Antithesis: `free` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `cleanup` centralizes 2 files; Antithesis: `http` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `cleanup` centralizes 2 files; Antithesis: `request` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `cleanup` centralizes 2 files; Antithesis: `response` pulls 2 files with 2 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `config` centralizes 4 files; Antithesis: `default` pulls 4 files with 4 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `config` centralizes 4 files; Antithesis: `filter` pulls 2 files with 2 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `config` centralizes 4 files; Antithesis: `free` pulls 2 files with 2 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
- Thesis: `config` centralizes 4 files; Antithesis: `html` pulls 2 files with 2 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `consumes` explicit?
