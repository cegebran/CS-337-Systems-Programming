main: queue.o main.o
	gcc queue.o main.o -o main

main.o: main.c
	gcc -Wall -c main.c

queue.o: queue.c queue.h
	gcc -Wall -c queue.c

clean:
	rm *.o
	rm main
