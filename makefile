C = gcc -g3
CFLAGS = -g3

all: Project1

Project1: main.o scanner.o
        $(CC) $(CFLAGS) -o Project1 main.o scanner.o

main.o: main.c token.h scanner.h
        $(CC) $(CFLAGS) -c main.c

scanner.o: scanner.c token.h scanner.h
        $(CC) $(CFLAGS) -c scanner.c

clean:
        rm -f Project1 *.o
