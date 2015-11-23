// tests Council Room card
// int councilEffect(int player, int handPos, struct gameState *state)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = councilEffect(0, 0, &testState);
    if (retVal == 0)
    {
        printf("Council Room card: PASS\n");
    }
    else
    {
        printf("Council Room card: FAIL\n");
    }
    return 0;
}
