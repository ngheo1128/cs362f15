#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j;
    int temphand[MAX_HAND];
    int initialTreasure = 0;
    int postTreasure = 0;
    int z = 0;
    int cardDrawn = 0;
    int drawnTreasure = 0;
    int success = 1;
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int randVal;
	srand(time(NULL));
	
    printf ("TESTING runAdventurer():\n");
    for (i = 0; i < 50; i++) {
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
   		r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    	initialTreasure = 0;
    	z = 0;
    	postTreasure = 0;
    	drawnTreasure = 0;
		randVal = rand() % 10;
		for (j = 0; j < G.handCount[p]; j++) {
            if (G.hand[p][j] == copper || G.hand[p][j] == silver || G.hand[p][j] == gold) {
                initialTreasure++;
            }
        }
		initialTreasure += randVal;
		if (initialTreasure % 4 == 0) {
		    initialTreasure = 0;
		    G.handCount[p] = 0;
		}
		else {
			for (j = G.handCount[p]; j < (G.handCount[p] + randVal); j++) {
			    G.hand[p][j] = copper;
			}
			G.handCount[p] += randVal;
		}
        #if (NOISY_TEST == 1)
            printf("Treasures in players hand before adventurer: %d\n", initialTreasure);
        #endif
        runAdventurer(drawnTreasure, &G, p, cardDrawn, z, temphand);
        for (j = 0; j < G.handCount[p]; j++) {
            if (G.hand[p][j] == copper || G.hand[p][j] == silver || G.hand[p][j] == gold) {
                postTreasure++;
            }
        }
        #if (NOISY_TEST == 1)
            printf("Treasures in players hand after adventurer: %d\n", postTreasure);
            printf("Should be: %d\n", initialTreasure + 2);
        #endif
        if (postTreasure != initialTreasure + 2) {
            printf("TEST FAILED\n");
            success = 0;
        }
	}
    if (success) {
        printf("All tests passed!\n");
	}

    return 0;
}