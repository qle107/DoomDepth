#include "../../include/stuff.h"

/**
* Generate Armor for player
 * @param level the level of Armor
 *
*/

Armor generateArmor(int level) {
    Armor armor;

    char level_s[2];
    snprintf(level_s, sizeof(level_s), "%d", level);
    strcpy(armor.name, "Armor with level ");
    strcat(armor.name, level_s);
    armor.defend = generateRandomNumber(3, 4 + level * 2);
    armor.life = generateRandomNumber(level * 3, level * 4 + 10);
    return armor;
}