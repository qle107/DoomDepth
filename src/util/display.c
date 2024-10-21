//
// Created by lequa on 11/4/2023.
//

#include "../../include/display.h"

void printProgressBar(char *label, int current, int max, int width) {
    int barLength = (int)(((double)current / max) * width);
    printf("%s ", label);
    printf("[");
    for (int i = 0; i < width; i++) {
        if (i < barLength) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("]");

    printf("  %d / %d \n", current, max);
}

void displayCharacterHpMana(Character c) {
    printProgressBar("HP: ", c.currentHealth, c.maxHealth, 50);
    printProgressBar("Exp:", c.currentExp, c.maxExp, 50);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadingScreen(int seconds) {
    int process = 0;
    int step = 100 / seconds;

    for (int i = 0; i < seconds; i++) {
        printf("Loading... %d%%\n", process);
        process += step;
        sleep(1);
        clearScreen();
    }
}

void displayGraphic(Character c, int max_monster, int level) {
    displayCharacterHpMana(c);
    printf("\n");
    printf("Level: %d \n", level);
    if (level == 5 || level == 10 || level == 15) {
        char *display = readFile("data/boss.txt");
        printf("\n");
        for (int i = 0; display[i] != '\0'; i++) {
            printf("%c", display[i]);
        }
    } else {
        if (max_monster == 1) {
            char *display = readFile("data/1_monster.txt");
            printf("\n");
            for (int i = 0; display[i] != '\0'; i++) {
                printf("%c", display[i]);
            }
        } else if (max_monster == 2) {
            char *display = readFile("data/2_monster.txt");
            printf("\n");
            for (int i = 0; display[i] != '\0'; i++) {
                printf("%c", display[i]);
            }
        } else if (max_monster == 3) {
            char *display = readFile("data/3_monster.txt");
            printf("\n");
            for (int i = 0; display[i] != '\0'; i++) {
                printf("%c", display[i]);
            }
        }
    }
}