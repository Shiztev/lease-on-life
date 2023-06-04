# Makefile for lease-on-life
# Author: Stevie Alvarez

CFLAGS ?= -g -Wall -Wextra

lol: src/main.c
	gcc -o lol src/main.c $(CFLAGS)

clean:
	rm lol

.PHONY: clean