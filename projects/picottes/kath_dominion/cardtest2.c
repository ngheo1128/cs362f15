#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j, m;
    int actions;
    int success = 1;
    int failed = 0;
    int seed = 1000;
    int count = 0;
    int numPlayer = 2;
    int maxBonus = 10;
    int p = 0, r, deckC;
    int shuffled = 0;
    int originalDeck[100];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING villlageCard():\n");
    for (i = 0; i < 10; i++) {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.numActions = i;
        for (m = 0; m < 5; m++) {
        	#if (NOISY_TEST == 1)
                printf("Actions in players hand before village: %d\n", G.numActions);
            #endif
            actions = G.numActions;
            villageEffect(&G, p, G.handCount[p] - 1);
            #if (NOISY_TEST == 1)
                printf("Actions in players hand after village: %d\n", G.numActions);
                printf("Should be: %d\n", (m+1)*2 + m);
            #endif
            if ((m+1)*2 + m != G.numActions) {
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