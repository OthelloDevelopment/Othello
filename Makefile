CC = gcc
CFLAGS = -Wall
othello: othello.o main.o
	$(CC) main.o othello.o -o qqq_test `pkg-config --libs gtk+-2.0`
main.o: main.c othello.h
	$(CC) -c main.c -o main.o $(CFLAGS) `pkg-config gtk+-2.0 --cflags`
othello.o: othello.c othello.h
	$(CC) -c othello.c -o othello.o $(CFLAGS) `pkg-config gtk+-2.0 --cflags`
clean:
	rm -f *.o othello