#include <stdlib.h>
#include <unistd.h>

char* socket_read(int socket){
    char* buffer = malloc(1024);
    read(socket, buffer, 1024);
    return buffer;
}