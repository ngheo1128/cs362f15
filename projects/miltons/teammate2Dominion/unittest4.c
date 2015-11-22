// tests gainCard() function
// int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = gainCard(1, &testState, 0, 0);
    if (retVal == 0)
    {
        printf("gainCard(): PASS\n");
    }
    else
    {
        printf("gainCard(): FAIL\n");
    }
    return 0;
}
