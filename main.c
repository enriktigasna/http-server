#include "socketread.h"
#include "socketsend.h"
#include "createsocket.h"
#include "readfile.h"
#include "parseheaders.h"

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
        struct headers* headers = parse_headers(response);
        printf("%s %s FROM %s\n", headers->method, headers->path, headers->user_agent);

        socket_send(socket, index);
    }

    return 0;
}