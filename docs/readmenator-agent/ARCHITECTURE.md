# Architecture

## Internal Dependencies

- `htmlfilter.c` -> `htmlfilter.h`
- `http.c` -> `http.h`
- `main.c` -> `htmlfilter.h`
- `main.c` -> `http.h`

## External Imports

- `htmlfilter.c` -> ctype.h, stdlib.h, string.h
- `http.c` -> arpa/inet.h, ctype.h, errno.h, fcntl.h, netdb.h, netinet/in.h, openssl/err.h, openssl/ssl.h, stdio.h, stdlib.h, string.h, sys/select.h, sys/socket.h, time.h, unistd.h
- `http.h` -> stddef.h
- `main.c` -> stdio.h, stdlib.h, string.h
