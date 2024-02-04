#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct response_headers
{
    char* status;
    char* content_type;
};

int socket_send(int socket, char* message)
{
    // Format message with HTTP headers
    char* headers = malloc(100);
    sprintf(headers, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\n\n", strlen(message));

    char* response = malloc(strlen(headers) + strlen(message));
    sprintf(response, "%s%s", headers, message);
    
    send(socket, response, strlen(response), 0);

    return 0;
}

int socket_send_headers(int socket, struct response_headers* response_headers, char* message)
{
    char* headers = malloc(100);
    sprintf(headers, "HTTP/1.1 %s\nContent-Type: %s\nContent-Length: %d\n\n", response_headers->status, response_headers->content_type, strlen(message));

    char* response = malloc(strlen(headers) + strlen(message));
    sprintf(response, "%s%s", headers, message);

    send(socket, response, strlen(response), 0);

    return 0;
}