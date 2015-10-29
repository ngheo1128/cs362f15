//Test smithy card
//What it does: draw three cards and put in the discard pile

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main() {

	printf("Test smithy card:\n");

	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int newHand;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);


	int handCount = G.handCount[player1];

	//play smithyCard()

	smithyCard(player1, adventurer, &G);

	newHand = G.handCount[player1];

	//expect newHand to be 2 more cards than the original 
	//hand because 3 are drawn from the smithy card and
	//and also the smithy card was played.

	printf("****************************************************\n");

	printf("Test case: expect newHand to be 2 more cards than the original\n");
	printf("hand because 3 are drawn from the smithy card and\n");
	printf("and also the smithy card was played.\n");

	printf("****************************************************\n");

	if(newHand == (handCount+2)) {
		printf("TEST PASSED.\n");
	} else {
		printf("TEST FAILED:\n");
		printf("Old hand has %d cards\n", handCount);
		printf("New hand has %d cards\n", newHand);

	}

	return 0;


}
