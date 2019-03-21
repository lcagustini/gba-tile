.PHONY: run

CC = gcc

CFLAGS = -Wall -lSDL2 -lSDL2_ttf

all:
	@mkdir -p bin
	$(CC) src/main.c $(CFLAGS) -o bin/main

clean:
	rm -rf bin/

run: all
	bin/main asm/title.s 1 0
