// tests Smithy card
// void smithyEffect(struct gameState *state, int handPos)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;

    // since Andrew Shen's functions do not return a value,
    // this test cannot check the return value to check for a crash

    // int retVal = smithyEffect(&testState, 0);
    // if (retVal == 0)
    // {
    //     printf("Smithy card: PASS\n");
    // }
    // else
    // {
    //     printf("Smithy card: FAIL\n");
    // }

    smithyEffect(&testState, 0);
    return 0;
}
