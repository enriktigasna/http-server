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

struct headers* parse_headers(char* request);