cmake_minimum_required(VERSION 3.23)
project(Code C)

set(CMAKE_C_STANDARD 11)
include_directories(include/fight include/map include/monster include/player include/save include/spell include/stuff include/util)#For the H file
add_executable(Code main.c src/fight/fight.c src/map/map.c src/monster/monster.c src/player/player.c src/save/save.c src/spell/spell.c src/stuff/armor.c src/stuff/weapon.c src/util/random.c
        src/util/displayCharacterStats.c
        include/displayCharacterStats.h
        include/readFile.h
        src/util/readFile.c
        include/util.h
        src/util/display.c
        include/display.h
        src/util/intro.c include/intro.h  )
