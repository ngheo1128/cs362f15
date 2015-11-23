#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testKingdomCards(){	

	int* k = kingdomCards(1,2,3,4,5,6,7,8,9,10);

	assert(k[0] == 1);
	assert(k[1] == 2);
	assert(k[2] == 3);
	assert(k[3] == 4);
	assert(k[4] == 5);
	assert(k[5] == 6);
	assert(k[6] == 7);
	assert(k[7] == 8);
	assert(k[8] == 9);
	assert(k[9] == 10);

	return 0;

}

int main(){
	printf("unittest1 - Testing kingdomCards\n");

	testKingdomCards();

	printf("Test passed. Kingdom cards created correctly\n");
	

	return 0;
}