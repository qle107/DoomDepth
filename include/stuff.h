#ifndef CODE_ARMOR_H
#define CODE_ARMOR_H
#include <string.h>
#include "util.h"

// Define an Armor
typedef struct {
    char name[69];       // Name of the Armor
    int life;
    int defend;          // Armor's Defense
} Armor;

/** Generate an Armor with "balanced" stats
 * @param level
 * @return
 */
Armor generateArmor(int level);  // Add a semicolon here

#endif // CODE_ARMOR_H
