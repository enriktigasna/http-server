#include "socketread.h"
#include "socketsend.h"
#include "createsocket.h"
#include "readfile.h"
#include "parseheaders.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOT_DIR "public"
#define MAX_PATH 100

char* notFound(){
    char* path = malloc(MAX_PATH);
    sprintf(path, "%s%s", ROOT_DIR, "/404.html");

    return read_file(path) ? read_file(path) : "HTTP/1.1 404 Not Found\n";
}

int main(){
    char* path = malloc(MAX_PATH);

    char* response = malloc(1024);
    int socket = create_socket(8080);

    // Router
    while((response = socket_read(socket)) != NULL){
        struct headers* headers = parse_headers(response);
        printf("%s %s FROM %s\n", headers->method, headers->path, headers->user_agent);
        printf("Accept: %s\n", headers->accept);

        if(strcmp(headers->path, "/") == 0 || strcmp(headers->path, "/index.html") == 0){
            sprintf(path, "%s%s", ROOT_DIR, "/index.html");
            socket_send(socket, read_file(path));
        } else {
            sprintf(path, "%s%s", ROOT_DIR, headers->path);
            struct response_headers* response_headers = malloc(sizeof(struct response_headers));
            response_headers->status = read_file(path) ? "200 OK" : "404 Not Found";
            response_headers->content_type = "text/html";

            if(read_file(path) && strstr(path, ".html") == NULL){
                if (strstr(path, ".css") != NULL) {
                    response_headers->content_type = "text/css";
                } else if (strstr(path, ".js") != NULL) {
                    response_headers->content_type = "text/javascript";
                } else {
                    response_headers->content_type = "text/plain";
                }
            }

            if(read_file(path) == NULL){
                response_headers->content_type = "text/html";
            }
            
            socket_send_headers(socket, response_headers, read_file(path) ? read_file(path) : notFound());
        }
    }

    return 0;
}