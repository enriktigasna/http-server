#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct headers
{
    char *method;
    char *path;
    char *version;
    char *host;
    char *connection;
    char *cache_control;
    char *user_agent;
    char *accept;
    char *accept_encoding;
    char *accept_language;
    char *cookie;
};

struct headers *parse_headers(char *request)
{
    struct headers *headers = malloc(sizeof(struct headers));
    if (headers == NULL)
    {
        printf("Error allocating memory for headers\n");
        exit(1);
    }

    headers->method = malloc(8);
    headers->path = malloc(100);
    headers->version = malloc(8);
    headers->host = malloc(100);
    headers->connection = malloc(100);
    headers->cache_control = malloc(100);
    headers->user_agent = malloc(100);
    headers->accept = malloc(100);
    headers->accept_encoding = malloc(100);
    headers->accept_language = malloc(100);
    headers->cookie = malloc(100);

    if (headers->method == NULL || headers->path == NULL || headers->version == NULL || headers->host == NULL || headers->connection == NULL || headers->cache_control == NULL || headers->user_agent == NULL || headers->accept == NULL || headers->accept_encoding == NULL || headers->accept_language == NULL || headers->cookie == NULL)
    {
        printf("Error allocating memory for headers\n");
        exit(1);
    }

    char *line = strtok(request, "\n");

    while (line != NULL) {
        // Only support GET and POST for now
        if (strstr(line, "GET") == line || strstr(line, "POST") == line) {
            sscanf(line, "%s %s %s", headers->method, headers->path, headers->version);
        } else if (strstr(line, "Host:") == line) {
            headers->host = strdup(line + 6); 
        } else if (strstr(line, "Connection:") == line) {
            headers->connection = strdup(line + 12); 
        } else if (strstr(line, "User-Agent:") == line) {
            headers->user_agent = strdup(line + 12); 
        } else if (strstr(line, "Accept:") == line) {
            headers->accept = strdup(line + 8); 
        } else if (strstr(line, "Accept-Encoding:") == line) {
            headers->accept_encoding = strdup(line + 16); 
        } else if (strstr(line, "Accept-Language:") == line) {
            headers->accept_language = strdup(line + 16); 
        } else if (strstr(line, "Cookie:") == line) {
            headers->cookie = strdup(line + 8); 
        } else if (strstr(line, "Cache-Control:") == line) {
            headers->cache_control = strdup(line + 15); 
        }

        line = strtok(NULL, "\n");
    }

    return headers;
}