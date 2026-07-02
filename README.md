# curlfree

A lightweight, self-contained HTTP/HTTPS client library written in C, with no dependency on libcurl. It includes a companion HTML filtering library to extract plain text from web pages.

## Description

`curlfree` provides a minimal HTTP/1.1 client implementation that supports both HTTP and HTTPS (via OpenSSL). The library is designed to be portable, easy to integrate, and suitable for embedded systems or environments where a full-featured HTTP client is not required. It also includes an HTML filter that strips tags and converts HTML entities to plain text.

The project consists of two main components:

- **HTTP Client (`http.h`, `http.c`)**: Handles HTTP/HTTPS requests, redirects, chunked transfer encoding, and persistent connections.
- **HTML Filter (`htmlfilter.h`, `htmlfilter.c`)**: Strips HTML tags, converts named and numeric entities, and collapses whitespace.

All code is written in C and follows a modular, configurable design.

## Features

- **HTTP/1.1 compliant** with support for GET, POST, and other methods.
- **HTTPS support** using OpenSSL (optional, can be disabled).
- **Automatic redirect handling** (configurable up to a maximum number of redirects).
- **Chunked transfer encoding** decoding.
- **Configurable timeouts** for connection and read operations.
- **HTML filtering**:
  - Strips all HTML tags.
  - Converts named entities (`&amp;`, `&gt;`, `&lt;`, etc.).
  - Converts numeric entities (decimal and hexadecimal).
  - Collapses multiple whitespace characters into single spaces.
  - Preserves newlines for block-level elements (configurable).
- **Minimal dependencies**: Only standard C library and optionally OpenSSL.
- **Single-file core**: Each component is contained in a pair of `.h` and `.c` files for easy integration.

## Building

### Prerequisites

- A C compiler (gcc, clang, etc.)
- GNU Make (optional, but recommended)
- OpenSSL development libraries (for HTTPS support)

### Compilation

To build the library and the example program:

```bash
# Compile each module
gcc -O2 -Wall -Wextra -c http.c -o http.o
gcc -O2 -Wall -Wextra -c htmlfilter.c -o htmlfilter.o
gcc -O2 -Wall -Wextra -c main.c -o main.o

# Link with OpenSSL (for HTTPS)
gcc -o curlfree main.o http.o htmlfilter.o -lssl -lcrypto
```

To disable HTTPS support (HTTP only), omit the `-DUSE_OPENSSL` flag and do not link against OpenSSL:

```bash
gcc -O2 -Wall -Wextra -c http.c -o http.o
gcc -O2 -Wall -Wextra -c htmlfilter.c -o htmlfilter.o
gcc -O2 -Wall -Wextra -c main.c -o main.o
gcc -o curlfree main.o http.o htmlfilter.o
```

Or use our script

```bash
# or just
./build.sh
```

### Using as a Library

To use `curlfree` in your own project, include the header files and link against the compiled object files or a static library.

Example:

```c
#include "http.h"
#include "htmlfilter.h"

int main() {
    struct http_config cfg;
    http_config_default(&cfg);
    strcpy(cfg.host, "example.com");
    cfg.use_ssl = 1;

    struct http_response *resp = http_request(&cfg, "GET", "/", NULL, NULL);
    if (resp && resp->status_code == 200) {
        struct html_filter_config hcfg;
        html_filter_config_default(&hcfg);
        char *plain = html_filter_strip_tags(resp->body, &hcfg);
        if (plain) {
            printf("%s\n", plain);
            free(plain);
        }
        http_response_free(resp);
    }
    return 0;
}
```

## Usage

The example program `main.c` demonstrates how to fetch a URL and extract plain text:

```bash
./curlfree https://example.com
```

The output will be the plain text content of the page, with all HTML tags removed and entities converted.

### Configuration

The HTTP client behavior can be customized via the `http_config` structure:

- `host`: The target server hostname.
- `port`: The port number (defaults to 80 or 443 based on `use_ssl`).
- `timeout_sec`: Connection and read timeout in seconds.
- `use_ssl`: Set to 1 to enable HTTPS (requires OpenSSL).
- `ca_bundle_path`: Path to CA certificates for peer verification.
- `verify_peer`: Set to 0 to disable certificate verification (not recommended for production).
- `follow_redirects`: Set to 1 to automatically follow redirects.
- `max_redirects`: Maximum number of redirects to follow.

The HTML filter is configured via `html_filter_config`:

- `convert_entities`: Set to 1 to convert HTML entities to their character equivalents.
- `collapse_whitespace`: Set to 1 to collapse multiple spaces/newlines into single spaces.
- `preserve_newlines`: Set to 1 to insert newlines for block-level elements (`<p>`, `<div>`, `<h1>`, etc.).

## API Reference

### HTTP Client

- `int http_init(void)`: Initializes the HTTP library (required if using OpenSSL).
- `void http_cleanup(void)`: Cleans up resources used by the HTTP library.
- `void http_config_default(struct http_config *cfg)`: Fills a `http_config` structure with default values.
- `struct http_response *http_request(struct http_config *cfg, const char *method, const char *path, const char *headers, const char *body)`: Performs an HTTP request. Returns a `http_response` structure on success, or `NULL` on failure.
- `void http_response_free(struct http_response *resp)`: Frees a `http_response` structure.

### HTML Filter

- `void html_filter_config_default(struct html_filter_config *cfg)`: Fills a `html_filter_config` structure with default values.
- `char *html_filter_strip_tags(const char *html, const struct html_filter_config *cfg)`: Strips HTML tags from the input string and returns a newly allocated plain text string. The caller is responsible for freeing the returned pointer.

## Error Handling

The library functions return `NULL` or negative values on error. In case of failure, the `errno` variable may be set to indicate the specific error. The HTTP client also logs errors to `stderr` in some cases (this can be disabled by redefining the logging macros).

## Security Considerations

- **Certificate Verification**: By default, peer certificates are verified when using HTTPS. You can disable this by setting `verify_peer = 0`, but this is not recommended for production use.
- **Buffer Overflows**: All string operations are bounded, and dynamic memory allocation is used for variable-length data.
- **Timeouts**: Configurable timeouts prevent the client from hanging indefinitely.

## License

This project is open source and available under the AGPLv2 License. See the `LICENSE` file for details.

## Contributing

Contributions are welcome. Please open an issue or submit a pull request on GitHub.

## Repository

[https://github.com/grisuno/curlfree](https://github.com/grisuno/curlfree)

![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)  [![License: AGPL v3](https://img.shields.io/badge/License-AGPLv3-blue.svg)](https://www.gnu.org/licenses/agpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)
