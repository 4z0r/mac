OBJECTS=list.o
CFLAGS=-g -O2

all: $(OBJECTS) main.c
	gcc -Wall $(CFLAGS) $(OBJECTS) main.c -o main

list.o: list.h list.c
	gcc -Wall $(CFLAGS) -c list.c

clean: 
	rm -f $(OBJECTS) main 2> /dev/null 1>&2
