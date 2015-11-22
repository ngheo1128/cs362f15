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
	int maxBonus = 20;
	int c = 0,
		i = 0,
		j = 0,
		k = 0,
		m = 0;
	int failedtests = 0;
	int playedCount = 0;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	int temphand[MAX_HAND];// moved above the if statement
	int drawntreasure = 0;
	int cardDrawn = 0;

	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(players, hand, seed, &testState);

	int handCount = testState.handCount[i];
	int buys = testState.numBuys;
	for (i = 0; i < players; i++)
	{	
		printf("------------------------------\n");
		printf("Cards in hand: %d\n", numHandCards(&testState));
		printf("Number of played cards: %d\n", testState.playedCardCount);
		printf("Number of buys: %d\n", testState.numBuys);
		printf("Discard count: %d\n", testState.discardCount[i]);

		printf("Playing Council Room Card\n");
		council_roomEffect(i, j, &testState);
	
		printf("Cards in hand: %d\n", numHandCards(&testState));
		printf("Number of played cards: %d\n", testState.playedCardCount);
		printf("Number of buys: %d\n", testState.numBuys);
		printf("Discard count: %d\n", testState.discardCount[i]);
		printf("------------------------------\n");
		printf("\n");
	}
	return 0;
}