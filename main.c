#include "socketread.h"
#include "socketsend.h"
#include "createsocket.h"
#include "readfile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* index = read_file("public/index.html");

    if(index == NULL){
        printf("index.html not found\n");
        return 1;
    }

    char* response = malloc(1024);
    int socket = create_socket(8080);

    while((response = socket_read(socket)) != NULL){
        printf("%s", response);
        socket_send(socket, index);
    }

    return 0;
}