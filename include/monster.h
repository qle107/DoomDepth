#ifndef MONSTER_H
#define MONSTER_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef struct Monster {
    int level;
    int life;
    int min_attack;
    int max_attack;
    int defense;
    int turn;
    int exp;
} Monster;

/**
 * Generate a random integer between min and max
 * @param min the first value no matter min or max.
 * @param max the second value no matter min or max.
 */
Monster** generate_random_monsters(int max_monsters, int level) ;

/**
 * Display the monsters
 * @param monsters
 * @param monster_count
 */
void display_monsters(Monster monsters[], int monster_count);

/**
 * Calculate the damage based on the monster's attack
 * @param monster
 * @return the damage
 */
int calculateBasedMonsterDamage (Monster *monster);

void free_monsters(Monster **monsters,int max_monster);

bool isAnyMonsterAlive(Monster **monsters,int max_monster);
#endif
