.PHONY: run

CC = gcc

LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGS = -Wall -c -DRESDIR=\"res/\"

all: bin/main.o bin/kiss_widgets.o bin/kiss_draw.o bin/kiss_general.o bin/kiss_posix.o
	$(CC) $^ $(LDFLAGS) -o bin/$@

bin/main.o: src/main.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

bin/kiss_widgets.o: src/kiss_widgets.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

bin/kiss_draw.o: src/kiss_draw.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

bin/kiss_general.o: src/kiss_general.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

bin/kiss_posix.o: src/kiss_posix.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf bin/

run: all
	bin/all asm/title.s 1 0
