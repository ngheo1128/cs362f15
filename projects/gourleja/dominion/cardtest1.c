/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - cardtest1.c
 * Description : Unit tests for smithy card
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define CARDNAME  "smithy"
#define BASESEED    10

/*
 * Description:     Test the return values of the smithy card
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testCard(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    //Check increase of cards in hand
    expectedValue = state->handCount[state->whoseTurn] + 2;
    cardSmithy(1,0,state);
    if(state->handCount[state->whoseTurn] != expectedValue) {
        printf("  TEST FAIL    : Smithy card added correct number of cards failed\n");
        testsFailed++;
    } else {testsPassed++;}

    printf ("    Tests Passed    : %i\n", testsPassed);
    printf ("    Tests Failed    : %i\n", testsFailed);
    printf ("-------------------------------------------------------------------------------\n\n");

    return 0;
}


/*
 * Preconditions:   The user can pass a seed value for testing or it defaults to a set value
 * Postconditions:  Exit the test program normally
 */
int main (int argc, char** argv)
{

    // Setup Game Seed
    int seed;
    char* currentTest = CARDNAME;
    if(argv[1]) {
        seed = atoi(argv[1]);
    } else {
        seed = BASESEED;
    }

    // Initialize Game State
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, seed, &G);

    testCard(currentTest,seed, &G);

    return 0;
}
