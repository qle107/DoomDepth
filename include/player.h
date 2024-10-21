#ifndef PLAYER_H
#define PLAYER_H
#include "weapon.h"
#include "stuff.h"
#include "random.h"
typedef struct {
    char item_type;  // 'A' for armor, 'W' for weapon
    union {         // Only 1
        Weapon weapon_data;
        Armor armor_data;
    } item;
} Inventory;
// Define a character structure
typedef struct {
    // Character attributes
    int maxHealth;
    int currentHealth;
    int turn;
    int strength;
    int intelligence;
    int defend;
    int agility;
    int luck;
    int level;
    int maxExp;
    int currentExp;
    Weapon* weapon;
    Armor* armor;
    Inventory* inventory;
}Character;

// Function declarations related to character
Character createCharacter(int initialHealth, int initialDefend, int initialStrength, int initialIntelligence, int initialAgility, int initialLuck);
void levelUp(Character *character);
int calculateBasedPlayerDamage(Character *character);
void endTurn(Character *character);
void resetTurn(Character *character);
void equipWeapon(Character *character, Weapon *weaponStats);
Character selectCharacter();
void gainExp(Character *character, int exp);
void drop_item(Character *player);

#endif