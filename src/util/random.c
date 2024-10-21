#include "../../include/random.h"
#include <stdlib.h> 
#include <time.h>   

/**
* Generate a random integer between min and max
* @param min the first value no matter min or max.
* @param max the second value no matter min or max.
*/
int generateRandomNumber(int min, int max) {
    //!Swap if min < max
    if (max < min) {     
        int temp = min;
        min = max;
        max = temp;
    }

    srand((unsigned int)time(NULL));

    int range = max - min + 1;

    int randomNum = (rand() % range) + min;

    return randomNum;
}
