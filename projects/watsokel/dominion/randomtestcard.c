/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: randomtestcard.c
* Created: 27 Oct 2015
* Last modified: 27 Oct 2015
* Description: Random tests for embargo case in cardEffect() method
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkEmbargo(struct gameState *post, int choice1) {
	int errCount=0;
	int actualEmbargoTokenCount, oracleEmbargoTokenCount;
	int actualCoinCount, oracleCoinCount;
	
	int c = choice1;
	struct gameState oracle;
	memcpy (&oracle, post, sizeof(struct gameState));
	int bonus=0;
	//  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
	//	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
	
	int r = cardEffect(embargo, choice1, 0, 0, post, 0, &bonus);
	
	
	if(c==7 || c==8 || c==9 || c==10 || c==12 || c==13 || c==14
		|| c==16 || c==21 || c==26){
		if(r != 0){
			printf("  FAIL, return value=%d, expected=%d\n", r, 0);
			errCount++;
		}else{
			printf("  PASS, return value=%d, expected=%d\n", r, 0);
		}
		actualEmbargoTokenCount=post->embargoTokens[c];
		oracleEmbargoTokenCount=++oracle.embargoTokens[c];	
		if(actualEmbargoTokenCount != oracleEmbargoTokenCount){
			printf("  FAIL, embargoTokens=%d, expected=%d\n", actualEmbargoTokenCount, oracleEmbargoTokenCount);
			errCount++;
		} else{
			printf("  PASS, embargoTokens=%d, expected=%d\n", actualEmbargoTokenCount, oracleEmbargoTokenCount);
		}
	
	}else{
		if(r != -1){
			printf("  FAIL, r=%d, expected=%d\n", r, -1);
			errCount++;
		}else{
			printf("  PASS, r=%d, expected=%d\n", r, -1);
		}
	}
	
	actualCoinCount = post->coins;
	oracleCoinCount = oracle.coins+2;
	
	if(actualCoinCount != oracleCoinCount){
		printf("  FAIL, coins=%d, expected=%d\n", actualCoinCount, oracleCoinCount);
		errCount++;
	}else{
		printf("  PASS, coins=%d, expected=%d\n", actualCoinCount, oracleCoinCount);
	}
	
	//assert(memcmp(&oracle, post, sizeof(struct gameState)) == 0);*/
	return errCount;
}

int main () {

	int i, n, p, j, handPos;
	int randDeckCount, randDiscardCount, randHandCount;
	int choice1;
	int errFlag=0;
	//int k[10] = {adventurer, council_room, feast, gardens, cutpurse,
	//	remodel, smithy, village, treasure_map, great_hall};
	//7,8,9,10,12,13,14,16,21,26
	struct gameState G;

	printf ("Testing embargo case in cardEffect().\n");
	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = (int)(Random() * 256);
		}
		p = (int)(Random() * 2);
		randDeckCount = G.deckCount[p] = (int)(Random() * MAX_DECK);
		randDiscardCount = G.discardCount[p] = (int)(Random() * MAX_DECK);
		randHandCount = G.handCount[p] = (int)(Random() * MAX_HAND);
		
		G.playedCardCount = (int)(Random() * (MAX_DECK-10));
		G.whoseTurn = p;
		G.numPlayers = 2;
		
		//randomize coin count
		G.coins = (int)(Random() * 1000);
		
		//randomize hand position
		handPos = (int)(Random()* 5);
		
		//randomize counts of supply cards based on kingdom card k array
		for(j=0; j<treasure_map; j++){	
			if(j==7 || j==8 || j==9 || j==10 || j==12 || j==13 || j==14
			|| j==16 || j==21 || j==26){
				G.supplyCount[j]=(int)(Random()*100);			
			} else {
				G.supplyCount[j]=-1;
			}
		}
		
		//randomize cards in hand
		for(j=0;j<randHandCount;j++){
			G.hand[p][j]=(int)(Random()*26);
		}
		//randomize discard pile
		for(j=0;j<randDiscardCount;j++){
			G.discard[p][j]=(int)(Random()*26);
		}
		//randomize cards in deck
		for(j=0;j<randDeckCount;j++){
			G.deck[p][j]=(int)(Random()*26);
		}
		
		//randomize kingdom card choice
		choice1=((int)(Random()*19))+7;
		
		//check embargo case in cardEffect()
		errFlag = checkEmbargo(&G,choice1);
	}

	if(errFlag != 0){
		printf("Some tests failed.\n");
	} else {
		printf("ALL TESTS PASSED!\n");
	}
	return 0;
}