//
// Created by lequa on 11/4/2023.
//
#include "../../include/readFile.h"

char* readFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    rewind(file);

    char* fcontent = (char*)malloc(fsize + 1); // Allocate space for the content and null-terminator
    if (fcontent == NULL) {
        fclose(file);
        printf("Memory allocation error\n");
        exit(1);
    }

    fread(fcontent, fsize, 1, file);
    fcontent[fsize] = '\0'; // Null-terminate the string

    fclose(file);
    return fcontent;
}
