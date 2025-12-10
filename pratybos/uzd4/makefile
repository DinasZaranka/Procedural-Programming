CC = gcc

main: src/main.c src/functions.c src/functions.h
	$(CC) src/main.c src/functions.c -o main

test: tests/test.c src/functions.c src/functions.h
	$(CC) tests/test.c src/functions.c -o test

clean:
	rm -f main test