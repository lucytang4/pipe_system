#define MESSAGE_BUFFER_SIZE 1000
#define HANDSHAKE_BUFFER_SIZE 1000

int server_handshake(int *from_client);
int client_handshake(int *to_server);
int server_handshake1(char *buf);
int server_handshake2(char *buf, int from_client);
