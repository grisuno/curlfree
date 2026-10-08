# Concepts

Nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

- `default` | files=4 | mentions=8 | `htmlfilter.c`, `htmlfilter.h`, `http.c`, `http.h`
- `config` | files=4 | mentions=6 | `htmlfilter.c`, `htmlfilter.h`, `http.c`, `http.h`
- `http` | files=2 | mentions=45 | `http.c`, `http.h`
- `filter` | files=2 | mentions=5 | `htmlfilter.c`, `htmlfilter.h`
- `html` | files=2 | mentions=5 | `htmlfilter.c`, `htmlfilter.h`
- `htmlfilter` | files=2 | mentions=5 | `htmlfilter.c`, `htmlfilter.h`
- `request` | files=2 | mentions=5 | `http.c`, `http.h`
- `response` | files=2 | mentions=4 | `http.c`, `http.h`
- `cleanup` | files=2 | mentions=3 | `http.c`, `http.h`
- `free` | files=2 | mentions=3 | `http.c`, `http.h`
- `strip` | files=2 | mentions=2 | `htmlfilter.c`, `htmlfilter.h`
- `tags` | files=2 | mentions=2 | `htmlfilter.c`, `htmlfilter.h`

## Verb Edges

- `config` --consumes--> `default` (strength 1.00)
- `config` --depends_on--> `default` (strength 1.00)
- `default` --consumes--> `config` (strength 1.00)
- `default` --depends_on--> `config` (strength 1.00)
- `cleanup` --consumes--> `config` (strength 0.50)
- `cleanup` --depends_on--> `config` (strength 0.50)
- `cleanup` --consumes--> `default` (strength 0.50)
- `cleanup` --depends_on--> `default` (strength 0.50)
- `cleanup` --consumes--> `free` (strength 0.50)
- `cleanup` --depends_on--> `free` (strength 0.50)
- `cleanup` --consumes--> `http` (strength 0.50)
- `cleanup` --depends_on--> `http` (strength 0.50)
- `cleanup` --consumes--> `request` (strength 0.50)
- `cleanup` --depends_on--> `request` (strength 0.50)
- `cleanup` --consumes--> `response` (strength 0.50)
- `cleanup` --depends_on--> `response` (strength 0.50)
- `config` --consumes--> `cleanup` (strength 0.50)
- `config` --depends_on--> `cleanup` (strength 0.50)
- `config` --consumes--> `filter` (strength 0.50)
- `config` --depends_on--> `filter` (strength 0.50)
- `config` --consumes--> `free` (strength 0.50)
- `config` --depends_on--> `free` (strength 0.50)
- `config` --consumes--> `html` (strength 0.50)
- `config` --depends_on--> `html` (strength 0.50)
- `config` --consumes--> `htmlfilter` (strength 0.50)
- `config` --depends_on--> `htmlfilter` (strength 0.50)
- `config` --consumes--> `http` (strength 0.50)
- `config` --depends_on--> `http` (strength 0.50)
- `config` --consumes--> `request` (strength 0.50)
- `config` --depends_on--> `request` (strength 0.50)
- `config` --consumes--> `response` (strength 0.50)
- `config` --depends_on--> `response` (strength 0.50)
- `config` --consumes--> `strip` (strength 0.50)
- `config` --depends_on--> `strip` (strength 0.50)
- `config` --consumes--> `tags` (strength 0.50)
- `config` --depends_on--> `tags` (strength 0.50)
- `default` --consumes--> `cleanup` (strength 0.50)
- `default` --depends_on--> `cleanup` (strength 0.50)
- `default` --consumes--> `filter` (strength 0.50)
- `default` --depends_on--> `filter` (strength 0.50)
- `default` --consumes--> `free` (strength 0.50)
- `default` --depends_on--> `free` (strength 0.50)
- `default` --consumes--> `html` (strength 0.50)
- `default` --depends_on--> `html` (strength 0.50)
- `default` --consumes--> `htmlfilter` (strength 0.50)
- `default` --depends_on--> `htmlfilter` (strength 0.50)
- `default` --consumes--> `http` (strength 0.50)
- `default` --depends_on--> `http` (strength 0.50)
- `default` --consumes--> `request` (strength 0.50)
- `default` --depends_on--> `request` (strength 0.50)

## Dialectic

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
