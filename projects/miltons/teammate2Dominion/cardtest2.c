// tests Adventurer card
// void adventurerEffect(struct gameState *state)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[])
{
    struct gameState testState;

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
