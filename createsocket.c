#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <asm-generic/socket.h>
#include <unistd.h>
#include <string.h>

int create_socket(int port){
    int serverfd;
    int opt = 1;

    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverfd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    socklen_t address_size = sizeof(address);

    if (bind(serverfd,  (struct sockaddr*)&address, address_size))
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverfd, 3) < 0)
    {   
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    int new_socket = accept(serverfd, (struct sockaddr *)&address, &address_size);
    if (new_socket < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
}