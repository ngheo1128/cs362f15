#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
    int i, m;
    int actions;
    int inactions;
    int success = 1;
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING villlageCard():\n");
    for (i = 0; i < 10; i++) {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.numActions = i;
        inactions = 0;
        for (m = 0; m < 5; m++) {
        	#if (NOISY_TEST == 1)
                printf("Actions in players hand before village: %d\n", G.numActions);
            #endif
            actions = G.numActions;
            villageCard(p, &G, G.handCount[p]);
            inactions = (i + (m+1)*2);
            #if (NOISY_TEST == 1)
                printf("Actions in players hand after village: %d\n", G.numActions);
                printf("M= %d\n", m);
                printf("Should be: %d\n", inactions);
            #endif
            if (inactions != G.numActions) {
                printf("TEST FAILED\n");
                success = 0;
            }
        }
    }

    if (success) {
        printf("All tests passed!\n");
	}

    return 0;
}