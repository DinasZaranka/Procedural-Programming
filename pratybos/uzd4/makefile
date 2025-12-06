CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: src/main.o src/list.o
	$(CC) $(CFLAGS) -o main src/main.o src/list.o

src/main.o: src/main.c src/list.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/list.o: src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c -o src/list.o

clean:
	rm -f src/*.o main