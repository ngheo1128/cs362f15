#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output


#define EXPECT(condition)  \
    total_tests++;  \
    if (!(condition)) {             \
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \

#define NOISY_TEST 1
#if NOISY_TEST
#define DEBUG_PRINTF printf
#else
#define DEBUG_PRINTF(...)
#endif


int main() {
    int failed_tests = 0;
    int total_tests = 0;
    int passed_tests = 0;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);

    printf ("TESTING gainCard():\n");
    r = initializeGame(numPlayer, k, seed, &G);
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (int toFlag = 0; toFlag < 3; toFlag++) {   
            //toFlag = 0 : add to discard
            //toFlag = 1 : add to deck
            //toFlag = 2 : add to hand
                int card = rand() % 9 + 7;
                 // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
               int k = gainCard(sea_hag, &G, toFlag, p);    //trying to gain a card that is not in the deck

        DEBUG_PRINTF("PASSED. Testing gainCard() for card not in deck. OUTPUT: -1 RESULT: %d \n", k);

                EXPECT(-1 == k);
                int deckPrev = fullDeckCount(p, card, &G);
                int handPrev = numHandCards(&G);                                    //
                int supplyPrev = supplyCount(card, &G);


                gainCard(card, &G, toFlag, p);              //testing randomly drawn cards from deck
                

        DEBUG_PRINTF("PASSED. whoseTurn OUTPUT: %d RESULT: %d\n", p, whoseTurn(&G));
         
                EXPECT(whoseTurn(&G) == p);

        
                if (supplyCount(card, &G) == 0) {  
                    DEBUG_PRINTF("PASSED. supplyOut OUTPUT: -1 RESULT %d\n", gainCard(card, &G, toFlag, p));                 //if there are no more of the passed card in supply,
                    EXPECT(gainCard(card, &G, toFlag, p) == -1);
                    continue;    //make sure the function returns -1
                }

        DEBUG_PRINTF("PASSED. deckCount OUTPUT: %d RESULT: %d\n", deckPrev + 1, fullDeckCount(p, card, &G));
                EXPECT(deckPrev + 1 == fullDeckCount(p, card, &G));     //check deckCount against previous
                
        DEBUG_PRINTF("PASSED. supplyCount OUTPUT: %d RESULT: %d\n", supplyPrev - 1, supplyCount(card, &G));
                EXPECT(supplyPrev - 1 == supplyCount(card, &G));        //check supply count against previous
                

                if (toFlag == 2) {
                    EXPECT(handPrev + 1 == numHandCards(&G));
                    EXPECT(G.hand[p][G.handCount[p]-1] == card);
                    DEBUG_PRINTF("PASSED. handCount FLAG_2 OUTPUT: %d RESULT: %d\n", handPrev, numHandCards(&G));
                    DEBUG_PRINTF("PASSED. handPos FLAG_2 OUTPUT: %d RESULT: %d\n", card, G.hand[p][G.handCount[p]-1]);
                }
                else if (toFlag == 1) {
                    EXPECT(G.deck[p][G.deckCount[p]-1] == card);
                    DEBUG_PRINTF("PASSED. deckCount FLAG_1 OUTPUT: %d RESULT: %d\n", card, G.deck[p][G.deckCount[p]-1]);
                }

                else {
                    EXPECT(G.discard[p][G.discardCount[p]-1] == card);
                    DEBUG_PRINTF("PASSED. discardCount FLAG_0 OUTPUT: %d RESULT: %d\n", card, G.discard[p][G.discardCount[p]-1]);
                }      
            }
        }
        endTurn(&G);
    }

    printf("Passed Tests: %d Failed Tests: %d Total Tests: %d \n", passed_tests, failed_tests, total_tests);

    return 0;

    return 0;
}