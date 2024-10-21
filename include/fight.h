#ifndef ATTACK_H
#define ATTACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include "player.h"
#include "monster.h"
#include "random.h"

struct Character;
struct Monster;

/** Function to perform an attack from a Character to a Monster
* @param attacker The attacker (Character)
* @param target The target (Monster)
*/
void humanAttack(Character *attacker,Monster *target);

/** Function to perform an attack
 *  @param attacker The attacker (Monster)
 *  @param target The target (Character)
 */
void monsterAttack(Monster *attacker,Character *target);

/** Function to perform a fight between a Character and a Monster
 *  @param player The player (Character)
 *  @param monsters The monsters (Monster)
 *  @param monster_count The number of monsters
 */
void fight(Character *player, Monster **monsters, int monster_count);
#endif