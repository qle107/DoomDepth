#include "../../include/player.h"
#include <stdio.h>
#include <stdlib.h>
/* Create a new character with initial attributes
*	@param initialHealth set character's base Health
*	@param initialStrength set character's base Strength
*	@param initialIntelligence set character's base Intelligence
*	@param initialAgility set character's base Agility
*	@param initialLuck set character's base Luck
*	@param initialDefend set character's base Defend
*/
Character
createCharacter(int initialHealth, int initialDefend, int initialStrength, int initialIntelligence, int initialAgility,
                int initialLuck) {
    Character character;
    character.maxHealth = initialHealth;
    character.currentHealth = initialHealth;
    character.defend = initialDefend;
    character.turn = 3; // Initialize turn to 0 or any desired value
    character.level = 1; // Base level is 1
    character.maxExp = 7; // Level 1 need 100 exp to level up
    character.currentExp = 0; // Current exp is 0
    character.strength = initialStrength;
    character.intelligence = initialIntelligence;
    character.agility = initialAgility;
    character.luck = initialLuck < 5 ? initialLuck : 5; // Luck is capped at 5
    character.inventory = (Inventory *) malloc(10 * sizeof(Inventory));
    character.weapon = NULL;
    character.armor = NULL;
    return character;
}

Character selectCharacter() {
    int characterType = 0;
    while (characterType < 1 || characterType > 3) {
        printf("Select your character type:\n");
        printf("1. Hunter\n");
        printf("2. Mage\n");
        printf("3. Warrior\n");
        printf("Your choice: ");
        scanf("%d", &characterType);

    }
    printf("\n");
    Character character;
    switch (characterType) {
        case 1:
            // Hunter
            character = createCharacter(100, 20, 15, 10, 25, 3);
            break;
        case 2:
            // Mage
            character = createCharacter(80, 15, 5, 25, 15, 4);
            break;
        default:
            // Warrior
            character = createCharacter(120, 30, 30, 10, 15, 2);
            break;
    }
    return character;

}

/** Update a character's attributes (e.g., after leveling up)
*	@param *character Chacracter's pointer.
*	@param newHealth after levelup, newhealth > currentHealth.
*	@param newDefend after levelup, newDefend > currentDefend.
*	@param newStrength after levelup, newStrength > currentStrength.
*	@param newIntelligence after levelup, newIntelligence > currentIntelligence.
*	@param newLuck after levelup, newLuck > currentLuck. (optional).
*	@param nextLevel after levelup, nextLevel > currentLevel.
*	@param nextMaxExp after levelup, nextMaxExp > currentMaxExp.
*/

void gainExp(Character *character, int exp) {
    character->currentExp += exp;
    printf("Player gain: %d Exp.\n", exp);
    if (character->currentExp >= character->maxExp) {

        printf("\nLEVEL UP +++\n");
        levelUp(character);
    }
}

void levelUp(Character *character) {
    character->maxHealth = character->maxHealth * 1.1;
    character->currentHealth = character->maxHealth;
    character->defend += 3;
    character->strength += 3;
    character->intelligence += 3;
    character->level += 1;
    character->maxExp += 6;
    character->currentExp = 0;
    character->agility += 3;
}

/** Calculate damage that character deal
*   @param *character Call character.
*/
int calculateBasedPlayerDamage(Character *character) {
    int total = 0;
    if (character->weapon == NULL) { //Don't have any weapon
        total += (int) (character->strength * 1.25); // strength + 25%
        total += (int) (character->intelligence * 0.8); // intell - 20%
    } else { //Have weapon
        total += (int) (character->strength * 1.25); // base strength + 25%
        total += (int) (character->intelligence * 0.8); // base intell - 20%
        total += (int) (character->weapon->strength * 1.5); // weapon strength + 50%
        total += (int) (character->weapon->intelligence); // weapon intell
    }
    if ((character->luck * 10 + 20) >= (rand() % 100)) { //Max luck is like 70% to deal crit
        printf("******CRITICAL******\n");
        total *= 1.5;
    }
    return total;
}

/** End player's turn
*   @param *character Call character.
*/
void endTurn(Character *character) {
    character->turn = 0;
    return;
}

/** Reset player's turn
*   @param *character Call character.
*/
void resetTurn(Character *character) {
    character->turn = 3;
    return;
}

/**
 * Equip a weapon to a character
 * @param character the character to equip the weapon
 * @param weaponStats the weapon to equip
 */
void equipWeapon(Character *character, Weapon *weaponStats) {
    // only one weapon at a time for now
    if (character->weapon != NULL) {
        free(character->weapon);
        character->weapon = NULL;
    }

    // make a reservation on memory
    character->weapon = (Weapon *) malloc(sizeof(Weapon));

    // Check if memory allocation was successful
    if (character->weapon == NULL) {
        // check if malloc is a good boy
        printf("Failed to allocate memory for weapon!\n");
        exit(1);
    }

    // transfer information and update the current weapon
    character->weapon = weaponStats;
}

void equipArmor(Character *character, Armor *armorStats) {
    // only one weapon at a time for now
    if (character->armor != NULL) {
        character->currentHealth = character->currentHealth - armorStats->life;
        character->maxHealth = character->maxHealth - armorStats->life;
        free(character->armor);
        character->armor = NULL;
    }

    // make a reservation on memory
    character->armor = (Armor *) malloc(sizeof(Armor));

    // Check if memory allocation was successful
    if (character->armor == NULL) {
        // check if malloc is a good boy
        printf("Failed to allocate memory for weapon!\n");
        exit(1);
    }

    // transfer information and update the current weapon
    character->armor = armorStats;

}

void drop_item(Character *player) {
    int inventorySize = 10;
    for (int i = 0; i < inventorySize; i++) {
        if (player->inventory[i].item_type != 'A' && player->inventory[i].item_type != 'W') {
            int drop_rate = player->luck;
            int rng_time = generateRandomNumber(1,10);
            if(rng_time <= drop_rate){
                if(rng_time%2 == 0){
                    player->inventory[i].item_type = 'A';
                    player->inventory[i].item.armor_data = generateArmor(player->level);
                    printf("\nCongratulations! You found a new armor: %s\n", player->inventory[i].item.armor_data.name);

                } else {
                    player->inventory[i].item_type  = 'W';
                    player->inventory[i].item.weapon_data = createWeapon(player->level);
                    printf("\nCongratulations! You found a new weapon: %s\n", player->inventory[i].item.weapon_data.name);

                }
            }
        }
    }
}