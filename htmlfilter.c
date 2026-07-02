#include "htmlfilter.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void html_filter_config_default(struct html_filter_config *cfg)
{
    if (!cfg) return;
    cfg->convert_entities = 1;
    cfg->collapse_whitespace = 1;
    cfg->preserve_newlines = 1;
}

static int hexval(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

static char *decode_entity(const char *entity, size_t len)
{
    /* entity includes the leading '&' and may end with ';' */
    if (len < 2) return NULL;
    if (entity[0] != '&') return NULL;
    if (entity[1] == '#') {
        /* Numeric entity: &#dd; or &#xHH; */
        int is_hex = 0;
        const char *num_start = entity + 2;
        if (*num_start == 'x' || *num_start == 'X') {
            is_hex = 1;
            num_start++;
        }
        unsigned long val = 0;
        const char *p = num_start;
        while (*p && *p != ';') {
            int d = is_hex ? hexval(*p) : (*p - '0');
            if (d < 0) return NULL;
            val = val * (is_hex ? 16 : 10) + d;
            p++;
        }
        if (*p != ';') return NULL; /* malformed */
        if (val <= 0x10FFFF) {
            /* Convert to UTF-8 (simple 1-4 bytes) */
            static char buf[5];
            if (val < 0x80) {
                buf[0] = (char)val;
                buf[1] = '\0';
            } else if (val < 0x800) {
                buf[0] = 0xC0 | (val >> 6);
                buf[1] = 0x80 | (val & 0x3F);
                buf[2] = '\0';
            } else if (val < 0x10000) {
                buf[0] = 0xE0 | (val >> 12);
                buf[1] = 0x80 | ((val >> 6) & 0x3F);
                buf[2] = 0x80 | (val & 0x3F);
                buf[3] = '\0';
            } else {
                buf[0] = 0xF0 | (val >> 18);
                buf[1] = 0x80 | ((val >> 12) & 0x3F);
                buf[2] = 0x80 | ((val >> 6) & 0x3F);
                buf[3] = 0x80 | (val & 0x3F);
                buf[4] = '\0';
            }
            return strdup(buf);
        }
        return NULL;
    } else {
        /* Named entity */
        char name[64];
        size_t i;
        for (i = 1; i < len && i < sizeof(name); i++) {
            name[i-1] = entity[i];
        }
        name[i-1] = '\0';
        /* Remove trailing ';' if present */
        size_t namelen = strlen(name);
        if (namelen > 0 && name[namelen-1] == ';') {
            name[namelen-1] = '\0';
        }
        /* Table of common entities (case-sensitive) */
        struct { const char *name; const char *repl; } entities[] = {
            {"amp", "&"},
            {"lt", "<"},
            {"gt", ">"},
            {"quot", "\""},
            {"apos", "'"},
            {"nbsp", " "},
            {"copy", "©"},
            {"reg", "®"},
            {"euro", "€"},
            {"pound", "£"},
            {"yen", "¥"},
            {"cent", "¢"},
            {"deg", "°"},
            {"para", "¶"},
            {"sect", "§"},
            {"hellip", "…"},
            {"mdash", "—"},
            {"ndash", "–"},
            {"lsquo", "‘"},
            {"rsquo", "’"},
            {"ldquo", "“"},
            {"rdquo", "”"},
            {"bull", "•"},
            {"trade", "™"},
            /* Add more as needed */
            {NULL, NULL}
        };
        for (int j = 0; entities[j].name; j++) {
            if (strcmp(name, entities[j].name) == 0) {
                return strdup(entities[j].repl);
            }
        }
        return NULL; /* unknown entity, keep as is */
    }
}

char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)
{
    if (!html) return NULL;
    size_t len = strlen(html);
    char *out = malloc(len * 4 + 1); /* enough for expansions */
    if (!out) return NULL;
    char *p = out;
    int in_tag = 0;
    int in_comment = 0;
    int in_entity = 0;
    char entity_buf[64];
    int entity_pos = 0;
    int last_was_space = 0;
    int add_newline = 0;

    for (size_t i = 0; i < len; i++) {
        char c = html[i];

        if (in_comment) {
            if (c == '-' && i+2 < len && html[i+1] == '-' && html[i+2] == '>') {
                i += 2;
                in_comment = 0;
            }
            continue;
        }
        if (!in_tag && c == '<' && i+3 < len && html[i+1] == '!' && html[i+2] == '-' && html[i+3] == '-') {
            in_comment = 1;
            i += 3;
            continue;
        }

        if (c == '<' && !in_tag) {
            in_tag = 1;
            if (cfg->preserve_newlines) {
                char *tag_start = (char *)html + i + 1;
                if (strncasecmp(tag_start, "br", 2) == 0 ||
                    strncasecmp(tag_start, "p", 1) == 0 ||
                    strncasecmp(tag_start, "div", 3) == 0 ||
                    strncasecmp(tag_start, "h1", 2) == 0 ||
                    strncasecmp(tag_start, "h2", 2) == 0 ||
                    strncasecmp(tag_start, "h3", 2) == 0 ||
                    strncasecmp(tag_start, "h4", 2) == 0 ||
                    strncasecmp(tag_start, "h5", 2) == 0 ||
                    strncasecmp(tag_start, "h6", 2) == 0 ||
                    strncasecmp(tag_start, "li", 2) == 0 ||
                    strncasecmp(tag_start, "tr", 2) == 0) {
                    add_newline = 1;
                }
            }
            continue;
        }
        if (c == '>' && in_tag) {
            in_tag = 0;
            if (add_newline) {
                *p++ = '\n';
                add_newline = 0;
                last_was_space = 1;
            }
            continue;
        }
        if (in_tag) continue;

        /* Entity handling */
        if (c == '&' && !in_entity) {
            in_entity = 1;
            entity_pos = 0;
            entity_buf[entity_pos++] = c;
            continue;
        }
        if (in_entity) {
            if (c == ';' && entity_pos > 1) {
                entity_buf[entity_pos] = '\0';
                in_entity = 0;
                if (cfg->convert_entities) {
                    char *decoded = decode_entity(entity_buf, entity_pos + 1);
                    if (decoded) {
                        /* If decoded string itself contains entities, decode again (recursive) */
                        char *tmp = decoded;
                        while (1) {
                            char *nested = strchr(tmp, '&');
                            if (!nested) break;
                            /* We need to decode nested entities, but to avoid infinite loops,
                               we simply recurse by passing through a temporary filter? */
                            /* For simplicity, we'll just copy the decoded string as is,
                               but we can do a second pass if needed. */
                            /* Since decode_entity returns a plain string, we assume it's fully decoded. */
                            break;
                        }
                        for (char *q = decoded; *q; q++) *p++ = *q;
                        free(decoded);
                    } else {
                        /* Unknown entity: copy as is */
                        for (int j = 0; j < entity_pos; j++) *p++ = entity_buf[j];
                        *p++ = ';';
                    }
                } else {
                    for (int j = 0; j < entity_pos; j++) *p++ = entity_buf[j];
                    *p++ = ';';
                }
                last_was_space = 0;
                continue;
            }
            if (entity_pos < (int)sizeof(entity_buf)-1) {
                entity_buf[entity_pos++] = c;
            } else {
                /* Entity too long, abort */
                in_entity = 0;
                for (int j = 0; j < entity_pos; j++) *p++ = entity_buf[j];
                *p++ = c;
                last_was_space = 0;
                continue;
            }
            continue;
        }

        /* Normal character */
        if (cfg->collapse_whitespace) {
            if (isspace((unsigned char)c)) {
                if (!last_was_space) {
                    *p++ = ' ';
                    last_was_space = 1;
                }
                continue;
            }
            last_was_space = 0;
        }
        *p++ = c;
    }
    *p = '\0';

    /* Trim trailing whitespace */
    char *end = p - 1;
    while (end >= out && isspace((unsigned char)*end)) end--;
    *(end+1) = '\0';

    return out;
}