
all: server client  check_pid

check_pid: check_pid.c
	gcc -Wall check_pid.c -g -o check_pid

server: server.c
	gcc -Wall server.c -g -o server

client: client.c
	gcc -Wall client.c -g -o client

.PHONY: clean
clean:
	rm -f *.o *.a *.so server client  
