#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testIsGameOver(){
	struct gameState* state = malloc(sizeof(struct gameState));

	//make sure supply pile is not empty
	int i;
	for(i = 0 ; i < 25 ; i++){
		state->supplyCount[i] = 1;
	}

	printf("Test 1 - game is not over. Province cards not empty.\n");
	state->supplyCount[province] = 1;
	
	if( isGameOver(state) == 0 ){
		printf("Test passed. Game is not over\n");
	} else {
		printf("Test failed. Game is over\n");
	}

	printf("Test 2 - game is over. Province cards empty\n");
	state->supplyCount[province] = 0;

	if( isGameOver(state) == 1 ){
		printf("Test passed. Game is over\n");
	} else {
		printf("Test failed. Game is not over\n");
	}

	printf("Test 3 - game is over. At least 3 supply piles are empty\n");
	state->supplyCount[0] = 0;
	state->supplyCount[1] = 0;
	state->supplyCount[2] = 0;
	state->supplyCount[3] = 0;

	if( isGameOver(state) == 1 ){
		printf("Test passed. Game is over\n");
	} else {
		printf("Test failed. Game is not over\n");
	}


	return 0;
}

int main(){
	printf("unittest4 - Testing isGameOver\n");

	testIsGameOver();

	//printf(" test passed\n");
	//printf("---------------\n\n");

	return 0;
}