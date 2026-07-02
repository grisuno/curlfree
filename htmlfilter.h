#ifndef HTMLFILTER_H
#define HTMLFILTER_H

struct html_filter_config {
    int convert_entities;
    int collapse_whitespace;
    int preserve_newlines;
};

void html_filter_config_default(struct html_filter_config *cfg);
char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg);

#endif