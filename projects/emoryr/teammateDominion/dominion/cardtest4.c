
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1
#define EXPECT(condition)  \
    total_tests++;  \
    if (!(condition)) {             \
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \


int deckCreate(struct gameState*);

int main() {
    int failed_tests = 0;
    int total_tests = 0;
    int passed_tests = 0;
    int seed = 1000;
    int numPlayer = 4;
    int p, r, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    int villageArray[maxHandCount];
    for (int i = 0; i < maxHandCount; i++) {
        villageArray[i] = village;

    }


    initializeGame(numPlayer, k, seed, &G);     //initialize a new game
    deckCreate(&G);
    printf ("TESTING village using village_play function:\n");
    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            
            G.handCount[p] = handCount;                // set the number of cards on hand
            memcpy(G.hand[p], villageArray, sizeof(int) * handCount); // set all the cards to smithy

            int handCountPrev = G.handCount[p];
            int numActionsPrev = G.numActions;
            
            for (int pos = 0; pos < 5; pos++) {
            	if (G.hand[p][pos] == village) {
                	villageEffect(&G, p, pos);
                	break;
            	}
            	else {
                	continue;
            	}
            }


#if (NOISY_TEST == 1)
        printf("Testing numActions. Expected: %d Actual: %d \n", numActionsPrev + 2, G.numActions);
#endif
         
        EXPECT(numActionsPrev + 2 == G.numActions);

#if (NOISY_TEST == 1)
        printf("Testing if player turn is correct. Expected: %d Actual: %d \n", p, G.whoseTurn);
#endif  

        EXPECT(G.whoseTurn == p);

#if (NOISY_TEST == 1)
            printf("Testing handCount. Expected: %d Actual: %d\n", handCountPrev, G.handCount[p]);
#endif
        
        EXPECT(handCountPrev == G.handCount[p]);
            
#if (NOISY_TEST == 1)
            printf("Testing if village was discarded. Expected: 14 Actual: %d", G.playedCards[G.playedCardCount-1]);
#endif
        EXPECT(G.playedCards[G.playedCardCount-1] == 14);
        
        printf("\n");
    }
        endTurn(&G);
    }



    printf("Passed Tests: %d Failed Tests: %d Total Tests: %d \n", passed_tests, failed_tests, total_tests);

    return 0;
}

int deckCreate (struct gameState *G) {
    
    enum CARD deck[] = {gold, silver, smithy, gold, village, feast, silver, copper, estate, council_room};
    for (int i = 0; i < G->numPlayers; i++) {
        memcpy(G->deck[i], &deck, sizeof (deck));
        G->deckCount[i] = sizeof(deck) / sizeof(enum CARD);
    }
    return 0;
}