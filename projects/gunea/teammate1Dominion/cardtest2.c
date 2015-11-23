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
	int i = 0;
	int playedCount = 0;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	//int temphand[MAX_HAND];// moved above the if statement

	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(players, hand, seed, &testState);

	int handCount = testState.handCount[i];
	for (i = 0; i < players; i++)
	{	
		printf("------------------------------\n");
		printf("Cards in hand: %d\n", numHandCards(&testState));
		printf("Number of played cards: %d\n", playedCount);
		printf("Discard count: %d\n", testState.discardCount[i]);

		printf("Playing Adventurer Card\n");
		adventurerCard(&testState, i);
		printf("Cards in hand: %d\n", numHandCards(&testState));
		printf("Number of played cards: %d\n", playedCount);
		printf("Discard count: %d\n", testState.discardCount[i]);
		printf("------------------------------\n");
		printf("\n");
	}
	return 0;
}