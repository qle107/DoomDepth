#ifndef WEAPON_H
#define WEAPON_H
#include "random.h"
#include <string.h>
#include <stdio.h>
// Define a weapon
typedef struct {
    char name[69];       // Name of the weapon
    int damage;          // Damage the weapon deals
    int strength;        // Weapon's Strength (Physical damage)
    int intelligence;    // Weapon's Intelligence (Magic damage)
    int defend;          // Weapon's Defense
    int agility;         // Weapon's Speed
    int luck;            // Weapon's Luck (Drop rate / Crit damage - to be determined)
} Weapon;

/* Create a new weapon
*	@param name set weapon's base Name
*	@param damage set weapon's base Damage
*	@param durability set weapon's base Durability
*	@param strength set weapon's base Strength
*	@param intelligence set weapon's base Intelligence
*	@param agility set weapon's base Agility
*	@param luck set weapon's base Luck
*	@param defend set weapon's base Defend
*/
Weapon createWeapon(int level);


#endif

