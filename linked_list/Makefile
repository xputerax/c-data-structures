all: linkedlist.a
	cc -g -Wall -Wextra linkedlist_main.c -L. -l:linkedlist.a -o linkedlist_main

linkedlist.a: linkedlist.o
	ar rcs linkedlist.a linkedlist.o

linkedlist.o: linkedlist.c
	cc -g -c -Wall -Wextra linkedlist.c -o linkedlist.o

clean:
	rm -rf *.o *.a linkedlist_main
