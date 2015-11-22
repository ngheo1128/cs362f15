// tests Adventurer card
// int adventurerEffect(int player, struct gameState *state)
#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[])
{
    struct gameState testState;

    int retVal = adventurerEffect(0, &testState);
    if (retVal == 0)
    {
        printf("Adventurer card: PASS\n");
    }
    else
    {
        printf("Adventurer card: FAIL\n");
    }
    return 0;
}
