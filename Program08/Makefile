all: server client

server: server.o
	gcc server.o -o server

server.o: server.c
	gcc -Wall -c server.c

client: client.o
	gcc client.o -o client

client.o: client.c
	gcc -Wall -c client.c

clean:
	rm .o
	rm server
