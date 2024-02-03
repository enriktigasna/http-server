#include "socketlisten.h"
#include "createsocket.h"
#include "readfile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* index = read_file("public/index.html");

    char* message = "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body>";

    char* response = malloc(1024);
    int socket = create_socket(8080);

    while((response = socketlisten(socket, index)) != NULL){
        printf("%s", response);
    }

    return 0;
}