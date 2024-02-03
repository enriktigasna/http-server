#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(char* filename){
    FILE* file = fopen(filename, "r");

    if(file == NULL){
        printf("%s not found\n", filename);
        return NULL;
    }
    char* buf = malloc(1024);
    char* index = malloc(1024);
    while(fgets(buf, 1024, file)){
        strcat(index, buf);
    }

    return index;
}