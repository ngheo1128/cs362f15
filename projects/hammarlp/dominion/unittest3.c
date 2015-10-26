#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testScore(){
	struct gameState* state = malloc(sizeof(struct gameState));
	
	state->numPlayers = 2;

	//set player hands
	int playerHand[MAX_HAND] = {duchy, mine, gold};
	int playerDiscard[MAX_DECK] = {curse, province};
	int playerDeck[MAX_DECK] = {silver, great_hall};
	
	//copy player hand into the game state
	memcpy(state->hand[0], playerHand, sizeof(int)*MAX_HAND);
	memcpy(state->discard[0], playerDiscard, sizeof(int)*MAX_DECK);
	memcpy(state->deck[0], playerDeck, sizeof(int)*MAX_DECK);

	//update count
	state->handCount[0] = 3;
	state->discardCount[0] = 2;
	state->deckCount[0] = 2;
	

	//total should be 9. Print results
	if(scoreFor(0, state) == 9){
		printf("Test passed. Score is 9\n");
	} else {
		printf("Test failed. Score is not 9\n");
	}

	return 0;

}

int main(){
	printf("unittest3 - Testing \n");

	testScore();

	//printf(" test passed\n");
	//printf("---------------\n\n");

	return 0;
}
