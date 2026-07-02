#!/bin/bash
gcc -O2 -Wall -Wextra -DUSE_OPENSSL -c http.c -o http.o
gcc -O2 -Wall -Wextra -c htmlfilter.c -o htmlfilter.o
gcc -O2 -Wall -Wextra -c main.c -o main.o
gcc -o curlfree main.o http.o htmlfilter.o -lssl -lcrypto
