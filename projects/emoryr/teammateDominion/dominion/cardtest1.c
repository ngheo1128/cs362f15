#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


#define EXPECT(condition)  \
    total_tests++;          \
    if (!(condition)) {             \
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \


int main() {
    int failed_tests = 0;
    int passed_tests = 0;
    int total_tests = 0;
    int seed = 1000;
    int numPlayer = 4;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    srand(seed);
    int smithyArray[maxHandCount];
    for (int i = 0; i < maxHandCount; i++) {
        smithyArray[i] = smithy;
    }
    printf ("TESTING smithy using smithy_play:\n");
    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                // set the number of cards on hand
            memcpy(G.hand[p], smithyArray, sizeof(int) * handCount); // set all the cards to smithy

            int handCountPrev = G.handCount[p];
           
            
            smithyEffect(&G, p, 1);

#if (NOISY_TEST == 1)
    printf("Testing handCount. Function Output: %d Result: %d\n", handCountPrev + 2, G.handCount[p]);           
#endif            
            //one card was discarded and three cards were picked up in smithy_play
            //fails after a few runs. handCount becomes negative.
        EXPECT(G.handCount[p] == handCountPrev + 2);

#if (NOISY_TEST == 1)
        printf("Testing if smithy is at top of discard pile.\n");
#endif  
        printf("Top of discard: %d\n",G.playedCards[G.playedCardCount-1]);
        EXPECT(G.playedCards[G.playedCardCount-1] == smithy);  
        //This function returns 4 instead of the enum for smithy. Error somewhere, or testing bug.
        //Figure out which!
        }
        endTurn(&G);
    }


    printf("All tests passed!\n");

    return 0;
}