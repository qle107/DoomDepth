//
// Created by lequa on 11/4/2023.
//
#include <conio.h>
#include "../../include/displayCharacterStats.h"
void displayCharacterStats(Character c) {
    printf("Health: %d\n", c.maxHealth);
    printf("Strength: %d\n", c.strength);
    printf("Intelligence: %d\n", c.intelligence);
    printf("Defend: %d\n", c.defend);
    printf("Agility: %d\n", c.agility);
    printf("Luck: %d\n", c.luck);
    printf("Level: %d\n", c.level);
    if (c.weapon != NULL) {
        printf("Weapon Strength: %d\n", c.weapon->strength);
        printf("Weapon Intelligence: %d\n", c.weapon->intelligence);
    }
    printf("\n");
}