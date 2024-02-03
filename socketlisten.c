#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* socketlisten(int socket, char* message)
{
    // Format message with HTTP headers
    char* headers = malloc(100);
    sprintf(headers, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\n\n", strlen(message));

    char* response = malloc(strlen(headers) + strlen(message));
    sprintf(response, "%s%s", headers, message);


    char* buffer = malloc(1024);
    read(socket, buffer, 1024 - 1);
    send(socket, response, strlen(response), 0);

    printf("%s\n", buffer);

    return buffer;
}