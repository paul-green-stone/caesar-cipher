CC = gcc

main: main.o caesar.o
	$(CC) main.o caesar.o -o caesar.out

caesar.o: caesar.c
	$(CC) -c caesar.c -o caesar.o

main.o: main.c
	$(CC) -c main.c -o main.o
