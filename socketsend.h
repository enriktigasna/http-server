struct response_headers
{
    char* status;
    char* content_type;
};

char* socket_send(int socket, char* message);
char* socket_send_headers(int socket, struct response_headers* response_headers, char* message);