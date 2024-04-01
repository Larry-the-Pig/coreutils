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
	$(CC) -o $@ $^ $(LDFLAGS)

bin/%:src/%.c
	@mkdir bin/
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf bin/

.PHONY: all clean