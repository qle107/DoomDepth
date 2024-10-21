#include "include/map.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/save.h"
#include "include/spell.h"
#include "include/armor.h"
#include "include/fight.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/player.h"
#include "include/weapon.h"
#include "include/util.h"
#include <stdlib.h>
#include <unistd.h>
int main() {

    int selection = introGame();
    clearScreen();
    if (selection == 1) {

        Character myChar = selectCharacter();
        displayCharacterStats(myChar);

        int monster_level = 1;
        int max_monster = 1;

        while (myChar.currentHealth > 0 && monster_level < 15) {
            myChar.turn = 3;
            Monster **monsters = generate_random_monsters(max_monster, monster_level);
            loadingScreen(3);
            clearScreen();
            fight(&myChar, monsters, max_monster);
            sleep(1);
            if(myChar.currentHealth <= 0){
                clearScreen();
                printf("GAME OVER !!!");
                sleep(3);
                break;
            }
            free_monsters(monsters, max_monster);
            monster_level++;
            if (monster_level % 2 == 0) {
                max_monster++;
            }
            if (monster_level == 5 || monster_level == 10) {
                max_monster = 1;
            }

        }
    }

    return 0;
}

