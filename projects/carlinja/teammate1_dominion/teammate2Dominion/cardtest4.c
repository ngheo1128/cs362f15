#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	int seed = 2500;
	int players = 2;
	int i = 0,
		j = 0;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	
	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(players, hand, seed, &testState);

	int handCount = testState.handCount[i];
	for (i = 0; i < players; i++)
	{	
		printf("------------------------------\n");
		printf("Number of actions available: %d\n", testState.numActions);
		printf("Discard count: %d\n", testState.discardCount[i]);
		printf("Number of buys: %d\n", testState.numBuys);
		printf("Number of coins: %d\n", testState.coins);

		printf("Playing Baron Card\n");
		baronEffect(i, j, i, &testState);
	
		printf("Number of actions available: %d\n", testState.numActions);
		printf("Number of buys: %d\n", testState.numBuys);
		printf("Number of coins: %d\n", testState.coins);
		printf("Discard count: %d\n", testState.discardCount[i]);
		printf("------------------------------\n");
		printf("\n");
	}
	return 0;
}