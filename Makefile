all:
	mkdir -p bin
	gcc -o bin/main src/main.c -lSDL2 -g

run: all
	bin/main
