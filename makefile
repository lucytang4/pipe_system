compile: client.c server.c pipe_networking.c
	gcc client.c pipe_networking.c -o client
	gcc server.c pipe_networking.c -o server

clean:
	rm client
	rm server
	rm pipe_networking
