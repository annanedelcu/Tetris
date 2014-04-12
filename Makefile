NUME=Nedelcu
PRENUME=Ana
GRUPA=312CC

CC=gcc
CFLAGS=-Wall -g 
LDFLAGS=-lcurses

.PHONY: build run examples pack clean

build:
	$(CC) $(CFLAGS) $(LDFLAGS) src/*.c -o bin/Tetris

run: build
	./bin/Tetris

examples:
	$(CC) $(CFLAGS) $(LDFLAGS) example/exemplu1.c -o bin/exemplu1
	$(CC) $(CFLAGS) $(LDFLAGS) example/exemplu2.c -o bin/exemplu2

pack: clean
	zip -r $(GRUPA)_$(NUME)_$(PRENUME)_tema3.zip *

clean:
	rm -rf bin/* *.zip
	clear

