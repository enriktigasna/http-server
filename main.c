#include "socketlisten.h"
#include "createsocket.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* message = "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body>";

    char* response = malloc(1024);
    int socket = create_socket(8080);

    while((response = socketlisten(socket, message)) != NULL){
        printf("%s", response);
    }

    return 0;
}