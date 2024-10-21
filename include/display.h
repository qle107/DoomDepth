//
// Created by lequa on 11/4/2023.
//

#ifndef CODE_DISPLAY_H
#define CODE_DISPLAY_H
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "monster.h"
#include "unistd.h"
#include "util.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void displayCharacterHpMana(Character c);
void displayGraphic(Character c, int max_monster, int level);
void printProgressBar(char* label, int current, int max, int width);
void clearScreen();
void loadingScreen(int seconds);
#endif //CODE_DISPLAY_H
