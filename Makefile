PREFIX = /usr/local


INCS = -Iinclude/
LIBS = 

CFLAGS   = -std=c99 -pedantic -Wall -O3 ${INCS}
LDFLAGS  = ${LIBS}
CC = cc

SRC = ${wildcard src/*.c}
OUT = $(SRC:src/%.c=bin/%)

all: coreutils

debug: CFLAGS += -g3 -Og
debug: coreutils

coreutils: $(OUT)

bin/%:src/%.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	@rm -rf $(OUT)

.PHONY: all clean