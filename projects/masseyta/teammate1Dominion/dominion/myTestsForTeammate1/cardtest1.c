#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i; 					 	// counter
	int p, p2;					// indicating which player
	int pos;					// position
	int played;					// number of cards played from deck
	int deckSize;				// size of deck
	int odecksize;				// other player's deck size
	int pileSize;				// pile of usable cards
	int numPlayers = 2;  		// players for valid gamestate
	int numTests = 1; 		// large testing spread
	struct gameState g;			// gamestate, original
	struct gameState testState;		// gamestate under test
	int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	char testCard[] = "Smithy";	 // card under test



	printf("---     TESTING CARD: %s   ---\n\n", testCard);
	
	for(i = 0; i < numTests; i++){
		
		// set hand basics for each game so the function can be called
		pos = -1;
		p = 0;
		p2 = 1;

		// copy into a test state so I don't destroy the world
		initializeGame(numPlayers, k, 1000, &g);
		memcpy(&testState, &g, sizeof(struct gameState));


		// begin test
		deckSize = testState.handCount[p];										// how many are originally in hand before play
		odecksize = testState.deckCount[p2];									// how many are originall in other's hand before play
		played = testState.handCount[p] - testState.discardCount[p];			// how many cards were played
		pileSize = testState.deckCount[p];										// pile of non-trashed cards before play
		
		// play the smithy card, changes to counts will occur from this point out
		cardEffect(smithy, 0, 0, 0, &testState, 0, 0);
		
		// test to make sure player is at +3 cards
		printf("\nTest 1: Play Smithy and gain 3 cards:\n");
		if(testState.handCount[p] == g.handCount[p] + 2) // lose smithy (-1) and gain 3 more (+3) = 2
			printf("Passed. Expected hand count: %d   Hand count finish: %d\n", g.handCount[p] +2, testState.handCount[p]);
		else
			printf("FAILED. Deck size start: %d   Deck size finish: %d\n", g.handCount[p] +2, testState.handCount[p]);

		//test to make sure the other player's hand didn't change. No cards given, none taken from
		printf("\nTest 2: Other player's deck size unchanged when smithy is drawn:\n");
		if(testState.deckCount[p2] == g.deckCount[p2])
			printf("Passed. Deck size start: %d   Deck size finish: %d\n", g.deckCount[p2], testState.deckCount[p2]);
		else
			printf("FAILED. Deck size start: %d   Deck size finish: %d\n", g.deckCount[p2], testState.deckCount[p2]);

		//test to make sure the other player's hand didn't change. No cards given, none taken from
		printf("\nTest 2b: Other player's hand size unchanged when smithy is drawn:\n");
		if(testState.handCount[p2] == g.handCount[p2])
			printf("Passed. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);
		else
			printf("FAILED. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);

		//test to make sure the cards come from own player's pile, and is not stealing from elsewhere
		printf("\nTest 3: Player is drawing from own pile:\n");
		if(g.deckCount[p] - 3 == testState.deckCount[p]) //  5 in deck, - 3 taken from it
			printf("Passed. Expected: %d   Deck size finish: %d\n", g.deckCount[p] - 3, testState.deckCount[p]);
		else
			printf("FAILED. Expected: %d   Deck size finish: %d\n", g.deckCount[p] - 3, testState.deckCount[p]);

		//test to make sure the card is going to the played pile after use. Already established other players deck is unchanged
		printf("\nTest 4: Smithy card added to played pile after use:\n");
		if(testState.playedCardCount == 1)
			printf("Passed. Expected increase in played pile: %d     To played pile: %d\n", 1, testState.playedCardCount);
		else
			printf("FAILED. Expected increase in played pile: %d   To played pile: %d\n", 1, testState.playedCardCount);
		
		//test for world state changes, will indicate if any victory cards have been given out inappropriately
		printf("\nTest 5: : Test supply counts for points and curses that should not have been distributed: \n ");
		if(g.supplyCount[estate] != testState.supplyCount[estate])
			printf("FAILED. Estate Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[estate], testState.supplyCount[estate]);
		if(g.supplyCount[duchy] != testState.supplyCount[duchy])
			printf("FAILED. Duchy Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[duchy], testState.supplyCount[duchy]);
		if(g.supplyCount[province] != testState.supplyCount[province])
			printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[province], testState.supplyCount[province]);
		if(g.supplyCount[curse] != testState.supplyCount[curse])
			printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[curse], testState.supplyCount[curse]);
		else
			printf("Passed. Supply counts for curses and victory cards are the same\n");

		// test for changes in money supply that shouldn't have been activated, will test for money being given to players
		printf("\nTest 6: Test supply counts for treasure that should have been distributed: \n");
		if(g.supplyCount[copper] != testState.supplyCount[copper])
			printf("FAILED. Estate Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[copper], testState.supplyCount[copper]);
		if(g.supplyCount[silver] != testState.supplyCount[silver])
			printf("FAILED. Duchy Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[silver], testState.supplyCount[silver]);
		if(g.supplyCount[gold] != testState.supplyCount[gold])
			printf("FAILED. Duchy Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[gold], testState.supplyCount[gold]);
		else
			printf("Passed. Supply counts for treasure cards are the same\n");

	}

	return 0;
}