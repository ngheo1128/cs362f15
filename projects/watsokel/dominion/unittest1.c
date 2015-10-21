/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: unittest1.c
* Created: 10 Oct 2015
* Last modified: 14 Oct 2015
* Description: Unit tests for dominion.c 's fullDeckCount() function
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


int supplyCheck(struct gameState *S, int cardType, const char* cardName, int expectedCount){
	int err=0;
	if(S->supplyCount[cardType] != expectedCount){
		#if (NOISY_TEST==1)
		printf("      FAIL: number of %s cards=%d, expected=%d\n",cardName,S->supplyCount[cardType],expectedCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("      PASS: number of %s=%d, expected=%d\n",cardName,S->supplyCount[cardType],expectedCount);
		#endif 
	}
	return err;
}


int main() {
	int i,p,r;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine
		, remodel, smithy, baron, salvager};
	struct gameState G;
	int handCount, deckCount, discardCount; //use as oracle
	int maxHandCount = 5;
	int maxDeckCount = 5;
	int maxDiscardCount = 5;
	int fullDeck;
	int estatesInHand, estatesInDeck, estatesInDiscard;
	int coppersInHand, coppersInDeck, coppersInDiscard;
	int estates[MAX_HAND];
	int coppers[MAX_HAND];
	int errFlag = 0;
	for (i = 0; i < MAX_HAND; i++){
		estates[i] = estate;
	}
	for (i = 0; i < MAX_HAND; i++){
		coppers[i] = copper;
	}

	printf ("TESTING fullDeckCount():\n");

	for (p = 0; p < numPlayers; p++){
		for (handCount = 1; handCount <= maxHandCount; handCount++){
			for(deckCount = 1; deckCount <= maxDeckCount; deckCount++){
				for(discardCount=1; discardCount <=maxDiscardCount; discardCount++){
					printf("Testing player %d with %d card(s) in hand and discardCount of %d:\n", p, handCount, discardCount);
					memset(&G, 23, sizeof(struct gameState));   // clear game state
					r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
					/* standardize hand and deck counts */
					G.handCount[p] = handCount;
					G.deckCount[p] = deckCount;
					G.discardCount[p] = discardCount;
					memcpy(G.hand[p], estates, sizeof(int) * handCount); //set all cards to estate
					memcpy(G.deck[p], estates, sizeof(int) * deckCount); //set all cards to estate
					memcpy(G.discard[p], estates, sizeof(int) * discardCount); //set all cards to estate
					estatesInHand = handCount;
					estatesInDeck = deckCount;
					estatesInDiscard = discardCount; 
					
					/* test the function */
					fullDeck = fullDeckCount(p, estate, &G);
					if(fullDeck != estatesInHand+estatesInDeck+estatesInDiscard){
						errFlag++;
						#if (NOISY_TEST==1)
						printf("  fullDeckCount(): FAIL, Estate: fullDeckCount=%d, expected=%d\n",fullDeck, estatesInHand+estatesInDeck+estatesInDiscard);
						#endif
					} else{
						#if (NOISY_TEST==1)
						printf("  fullDeckCount(): PASS, Estate: fullDeckCount=%d, expected=%d\n",fullDeck, estatesInHand+estatesInDeck+estatesInDiscard);  
						#endif
					}
					//assert(fullDeck == (estatesInHand+estatesInDeck+estatesInDiscard));
					memcpy(G.hand[p], coppers, sizeof(int) * handCount); //set all cards to copper
					memcpy(G.deck[p], coppers, sizeof(int) * deckCount); //set all cards to copper
					memcpy(G.discard[p], coppers, sizeof(int) * discardCount); //set all cards to copper
					coppersInHand = handCount;
					coppersInDeck = deckCount;
					coppersInDiscard = discardCount; 
					fullDeck = fullDeckCount(p, copper, &G);
					if(fullDeck != (estatesInHand+estatesInDeck+estatesInDiscard)){
						errFlag++;  
						#if (NOISY_TEST==1)
						printf("  fullDeckCount(): FAIL, Copper: fullDeckCount=%d, expected=%d\n",fullDeck, coppersInHand+coppersInDeck+coppersInDiscard);
						#endif
					} else{
						#if (NOISY_TEST==1)
						printf("  fullDeckCount(): PASS, Copper: fullDeckCount=%d, expected=%d\n",fullDeck, coppersInHand+coppersInDeck+coppersInDiscard);    
						#endif
					}
					//assert(fullDeck == (coppersInHand+coppersInDeck+coppersInDiscard));
					
					/*Check for unexpected transactions*/
					printf("  Testing for unexpected transactions. Checking supply counts...\n");
					errFlag += supplyCheck(&G,curse,"curse",10);
					printf("    Checking Victory cards in supply:\n");
					errFlag += supplyCheck(&G,estate,"estate",8);
					errFlag += supplyCheck(&G,duchy,"duchy",8);
					errFlag += supplyCheck(&G,province,"province",8);
					printf("    Checking Treasure cards in supply:\n");	
					errFlag += supplyCheck(&G,copper,"copper",60-(7*2));
					errFlag += supplyCheck(&G,silver,"silver",40);
					errFlag += supplyCheck(&G,gold,"gold",30);
				}
			}
		}    
	}      

	if(errFlag != 0){
		printf("Some tests failed. See bug1.c for details.\n");  
	}else{
		printf("All tests passed!\n");
	}



	return 0;
}