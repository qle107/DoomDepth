//
// Created by Quang Dat on 04/11/2023.
//

#include "../../include/intro.h"
int introGame(){
    char* intro = readFile("./data/intro.txt");
    int choice = 0;
    if (intro != NULL) {
        printf("%s\n", intro);
        free(intro); // Free the allocated memory
        printf("1. Start game\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
    } else {
        printf("Failed to read the file.\n");
    }
    return choice;
}