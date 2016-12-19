#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "pipe_networking.h"

int server_handshake(int *from_client){
    //create a FIFO(Well Known Pipe)
    int fifo = mkfifo("wkp", 0644);
    if (fifo >= 0)
        printf("[SERVER] WKP created\n");
    else
        printf("[SERVER] error: %s\n", strerror(errno));
    
    //wait for connection
    *from_client = open(wkp, O_RDONLY);
    printf("[SERVER] connected to WKP\n");
    
    //receives client's message (private FIFO name) and removes the WKP
    char msg[MESSAGE_BUFFER_SIZE];
    read(from_client, msg, MESSAGE_BUFFER_SIZE);
    remove(wkp);
    printf("[SERVER] received client's message : %s\n", msg);
    
    //connects to client FIFO, sending an initial acknowledgement message
    int fifo2 = open(msg, O_WRONLY);
    printf("[SERVER] connected to client's WKP\n");
    write(fifo2, "connected to client WKP", 23);
    
    //receive client's message, verifying connection
    char msg2[MESSAGE_BUFFER_SIZE];
    read(from_client, msg2, MESSAGE_BUFFER_SIZE);
    printf("[SERVER] received client's message: %s\n", msg2);
    
    return fifo2;
}

int client_handshake(int *to_server){
}
