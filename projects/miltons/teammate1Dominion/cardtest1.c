// tests Smithy card
// int smithyEffect(int player, int handPos, struct gameState *state)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = smithyEffect(0, 0, &testState);
    if (retVal == 0)
    {
        printf("Smithy card: PASS\n");
    }
    else
    {
        printf("Smithy card: FAIL\n");
    }
    return 0;
}
