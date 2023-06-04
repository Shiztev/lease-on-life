# Makefile for lease-on-life
# Author: Stevie Alvarez

#
# Definitions
#

CC = gcc
CFLAGS ?= -g -Wall -Wextra -pedantic
OBJFILES = expenser.o

#
# Targets
#

all: lol

lol: main.o $(OBJFILES)
	$(CC) $(CFLAGS) -o lol main.o $(OBJFILES)

#
# Dependancies
#

expenser.o: src/expenser.c src/expenses.h
	$(CC) $(CFLAGS) -c src/expenser.c

main.o: src/main.c src/expenses.h
	$(CC) $(CFLAGS) -c src/main.c

clean:
	rm lol

.PHONY: clean