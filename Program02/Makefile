main: histo.o main.o
	gcc histo.o main.o -o main

main.o: main.c
	gcc -Wall -c main.c

histo.o: histo.c histo.h
	gcc -Wall -c histo.c

clean:
	rm *.o
	rm main
