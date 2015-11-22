// tests Adventurer card
// void adventurerEffect(struct gameState *state)

#include <stdio.h>
#include <stdlib.h>    // for rand and srand
#include <time.h>      // for time
#include "dominion.h"
#include "dominion_helpers.h"

#define NUM_PLAYERS  2



/*****************************************************************************
 ** Function:         randInt()
 ** Description:      This function generates and returns a psuedo-random number
 **                   in range from min to max, inclusive.
 ** Parameters:       two int values: min, max
 ** Pre-Conditions:   min and max are integer values
 ** Post-Conditions:  returns the random number
 **
 *****************************************************************************/
int randInt(int min, int max);



int main(int argc, char *argv[])
{
    struct gameState testState;
    int j;
    int retVal;
    int seed = 1; // better to make this random too?
    time_t sysClock;

    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};

    // seed the rand() function with system clock to avoid getting same rand #s
    srand((unsigned) time(&sysClock));

    // this loop populates every Byte of the game state with random values
    for (j = 0; j < sizeof(struct gameState); j++)
    {
        ((char*)&testState)[j] = randInt(0, 256);
    }

    // initialize game to prevent segmentation fault errors
    retVal = initializeGame(NUM_PLAYERS, cards, seed, &testState);

    // since Andrew Shen's functions do not return a value,
    // this test cannot check the return value to check for a crash

    // int retVal = adventurerEffect(&testState);
    // if (retVal == 0)
    // {
    //     printf("Adventurer card: PASS\n");
    // }
    // else
    // {
    //     printf("Adventurer card: FAIL\n");
    // }

    adventurerEffect(&testState);
    return 0;
}



/* uses stdlib.h */
int randInt(int min, int max)
{   // returns a random integer between min and max, inclusive
    // (max - min + 1) is the range
    // + min sets the bottom of the range
    return rand() % (max - min + 1) + min;
}
