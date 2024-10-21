#include "../../include/fight.h"

void humanAttack(Character *attacker,Monster *target) {
    if (target->life <= 0) {
        printf("The monster has been defeated!\n");
        return;
    }else {
        target->life -= calculateBasedPlayerDamage(attacker);
        printf("The monster's health is now %d\n", target->life);
        if(target->life <= 0){
            gainExp(attacker,target->exp);
            drop_item(attacker);
            sleep(2);
        }
    }
    printf("\n ------------------------------------ \n");
}

void monsterAttack(Monster *attacker,Character *target) {
    for(int turn = 0; turn < 3; turn ++){

        target->currentHealth -= generateRandomNumber(attacker->min_attack, attacker->max_attack);
        printf("Player's health is now %d\n", target->currentHealth);
    }

    printf("#################################### \n");

}
/*
 * Function to perform a fight between a Character and Monsters\
 * Stop conditions: All the monsters is dead or the player is dead -> Game Over
 * Stop conditions: All the monsters is dead or the player is alive -> call another function to generate more monsters.
 * @param player The player (Character)
 * @param monsters The monsters (Monster)
 */
//Monsters = [Monster1, Monster2, Monster3]
void fight(Character *player, Monster **monsters, int monster_count) {
    int level = monsters[0]->level;
    bool allMonstersAreKilled = false; // Set to true when all monsters are killed
    while (!allMonstersAreKilled && player->currentHealth > 0) {
        // Player's turn
        for (int turn = 0; turn < 3; turn++) {
            displayGraphic(*player,monster_count,level);
            printf("\n-----------------------------\n");

            if (isAnyMonsterAlive(monsters, monster_count)) {
                for (int i = 0; i < monster_count; i++) {
                    printf("Monster %d: - Life: %d - Defend: %d  \n", i + 1, monsters[i]->life, monsters[i]->defense);
                }
                printf("Which monster do you want to attack? ");
                int monster_index;
                scanf("%d", &monster_index);
                clearScreen();
//                displayGraphic(*player,monster_count,level);
//                printf("\n-----------------------------\n");

                while (monster_index < 1 || monster_index > monster_count) {
                    displayGraphic(*player,monster_count,level);
                    printf("\n-----------------------------\n");
                    printf("Please choose a monster between 1 and %d: ", monster_count);
                    scanf("%d", &monster_index);
                }
                // Player attacks
                humanAttack(player, monsters[monster_index - 1]);
                if (!isAnyMonsterAlive(monsters, monster_count)) {
                    allMonstersAreKilled = true;
                    player->currentHealth = player->maxHealth;
                    break; // All monsters are killed, break out of the loop
                }
            }
        }

        // Monsters' turn
        for (int i = 0; i < monster_count; i++) {
            if (monsters[i]->life > 0) {
                monsterAttack(monsters[i], player);
            }
            monsters[i]->turn = 3;
        }
    }
}
