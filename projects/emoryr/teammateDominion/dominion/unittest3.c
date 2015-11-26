#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

#define EXPECT(condition)  \
    total_tests++;  \
    if (!(condition)) {             \
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \


int main() {
    int failed_tests = 0;
    int total_tests = 0;
    int passed_tests = 0;
    int seed = 1000;
    int numPlayer = 4;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int trashFlag = 0;
    srand(seed);
    int card;

    printf ("TESTING discardCard():\n");
    r = initializeGame(numPlayer, k, seed, &G);
      
    for (p = 0; p < numPlayer; p++)
    {
        for (int handPos = 5; handPos > 0; handPos--) {
                   
            //trashFlag = 0: card is not trashed
            //trashFlag >= 1: card is trashed
                trashFlag = (trashFlag + 1) %2;
 
            int handPrev = numHandCards(&G);                                    


            int k = discardCard(handPos, p, &G, trashFlag);             //testing randomly drawn cards from deck
                
#if (NOISY_TEST == 1)
            printf("PASSED. whoseTurn OUTPUT: %d RESULT: %d\n", p, whoseTurn(&G));
#endif         
            EXPECT(whoseTurn(&G) == p);
 

 #if (NOISY_TEST == 1)
            printf("PASSED. handNumTest OUTPUT: %d RESULT: %d \n", handPrev -1, numHandCards(&G)); 
 #endif              
            EXPECT(handPrev - 1 == numHandCards(&G));
 
#if (NOISY_TEST == 1)
            printf("PASSED. functionTest OUTPUT: 0 RESULT %d \n", k);
#endif
            EXPECT(k == 0);
                
        }
        endTurn(&G);
    }            

    
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 0; handCount < maxHandCount; handCount++) {
                int handPos = 999;
                while (handPos > numHandCards(&G)) {
                    handPos = rand() % 4;              
                }
            //trashFlag = 0: card is not trashed
            //trashFlag >= 1: card is trashed
                trashFlag = (trashFlag + 1) %2;

                
                int handPrev = numHandCards(&G);
                int prevCardCount = G.playedCardCount;
                int curCard = G.hand[p][handPos];
                int cntPrev = 0;


                for (int i = 0; i < numHandCards(&G); i++){
                    if (G.hand[p][i] == curCard)
                        cntPrev += 1;
                }
                                                       //
                int k = discardCard(handPos, p, &G, trashFlag);

#if (NOISY_TEST == 1)
            printf("PASSED. whoseTurn OUTPUT: %d RESULT: %d\n", p, whoseTurn(&G));
#endif
            EXPECT(whoseTurn(&G) == p); 


#if (NOISY_TEST == 1)
           printf("PASSED. handNumTest OUTPUT: %d RESULT: %d \n", handPrev -1, numHandCards(&G));       
#endif
           EXPECT(handPrev - 1 == numHandCards(&G));
                
#if (NOISY_TEST == 1)
            printf("PASSED. functionTest OUTPUT: 0 RESULT %d \n", k); 
#endif         
           EXPECT(k == 0);

    
            if (trashFlag == 0) {
                EXPECT(prevCardCount + 1 == G.playedCardCount);
                EXPECT(curCard == G.playedCards[G.playedCardCount-1]);
                printf("PASSED. cardTest OUTPUT: %d RESULT: %d \n", prevCardCount + 1, G.playedCardCount);
                printf("PASSED. playedTest OUTPUT: %d RESULT: %d \n", curCard, G.playedCards[G.playedCardCount-1]);
            }

            int cnt = 0;          
            for (int i = 0; i < numHandCards(&G); i++){
                if (G.hand[p][i] == curCard)
                    cnt += 1;    
            }

            if (cntPrev != 0)
                EXPECT (cntPrev - cnt == 1);
                printf("PASSED. countTest OUTPUT: %d RESULT: %d \n",cntPrev, cnt + 1);
            }  
        endTurn(&G);
    } 

    printf("Passed Tests: %d Failed Tests: %d Total Tests: %d \n", passed_tests, failed_tests, total_tests);

    return 0;
}
