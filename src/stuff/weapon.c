#include "../../include/weapon.h"

/* Create a new weapon
*	@param name set weapon's base Name
*	@param damage set weapon's base Damage
*	@param durability set weapon's base Durability
*	@param strength set weapon's base Strength
*	@param intelligence set weapon's base Intelligence
*	@param agility set weapon's base Agility
*	@param defend set weapon's base Defend
*	@param luck set weapon's base Luck
*/
Weapon createWeapon(int level) {
    Weapon weapon;
    char level_s[2];
    snprintf(level_s, sizeof(level_s), "%d", level);
    strcpy(weapon.name, "Weapon with level ");
    strcat(weapon.name, level_s);
    weapon.damage = generateRandomNumber(10,10+level * 2);
    weapon.strength = generateRandomNumber(5,5+level*2);
    weapon.intelligence = generateRandomNumber(3,3+level*2);
    weapon.defend = generateRandomNumber(2,2+level*2);
    weapon.agility = generateRandomNumber(4,4+level*2);

    weapon.luck = generateRandomNumber(1,3);

    return weapon;
}

