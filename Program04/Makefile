main: list.o main.o
	gcc list.o main.o -o main

main.o: main.c
	gcc -Wall -c main.c

list.o: list.c list.h
	gcc -Wall -c list.c

clean:
	rm *.o
	rm main
