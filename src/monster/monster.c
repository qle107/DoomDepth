#include "../../include/monster.h"

// Demo jsut for testing I will update them later to fit the terminal size

char *monster_art[] = {
        "teddy_1.txt",
        "teddy_2.txt",
        "unknow.txt"
};

// On the base game you are fighting between 1 and 3 mobs
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Monster** generate_random_monsters(int max_monsters, int level) {
    int monster_count = max_monsters;

    if (level == 5 || level == 10 || level == 15) {
        monster_count = 1;
    }
    Monster **monsters = (Monster **)malloc(monster_count * sizeof(Monster *));
    for (int i = 0; i < monster_count; i++) {

        monsters[i] = (Monster *)malloc(sizeof(Monster));

        // Adjust the monster's stats based on the level
        monsters[i]->level = level;

        if(level == 5 || level == 10 || level == 15){
            monsters[i]->life = random_number(35 + level * 15, 50 + level * 15);
            monsters[i]->min_attack = random_number(1 + level*3, 3 + level*3);
            monsters[i]->max_attack = random_number(3 + level*3, 5 + level*3);
            monsters[i]->defense = random_number(1 + level*3, 5 + level*3);
            monsters[i]->exp = level * 15;
        } else {
            monsters[i]->life = random_number(35 + level * 5, 50 + level * 5);
            monsters[i]->min_attack = random_number(1 + level, 3 + level);
            monsters[i]->max_attack = random_number(3 + level, 5 + level);
            monsters[i]->defense = random_number(1 + level, 5 + level);
            monsters[i]->exp = level *3;
        }
        monsters[i]->turn = 3;
    }
    return monsters;
}

/**
 * Display the monsters
 * @param monsters
 * @param monster_count
 */
void display_monsters(Monster monsters[], int monster_count) {
    for (int i = 0; i < monster_count; i++) {
        printf("Monster %d:\n", i + 1); //I have to update it later to set a name instead
        printf("Life: %d\n", monsters[i].life);
        printf("Attack: %d - %d\n", monsters[i].min_attack, monsters[i].max_attack);
        printf("Defense: %d\n", monsters[i].defense);
    }
}

/**
 * Calculate the damage based on the monster's attack
 * @param monster
 * @return the damage
 */
int calculateBasedMonsterDamage(Monster *monster) {
    return random_number(monster->min_attack, monster->max_attack);
}


void free_monsters(Monster **monsters,int max_monster) {
    for (int i = 0; i < max_monster; i++) {
        free(monsters[i]);
    }
    free(monsters);
}


bool isAnyMonsterAlive(Monster **monsters,int max_monster) {
    for (int i = 0; i< max_monster; i++) {
        if (monsters[i]->life > 0) {
            return true; // At least one monster is alive
        }
    }
    return false; // All monsters are dead
}