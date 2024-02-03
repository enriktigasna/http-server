#include "socketlisten.h"

int main(){
    char* message = "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body>";

    socketlisten(8080, message);
    return 0;
}