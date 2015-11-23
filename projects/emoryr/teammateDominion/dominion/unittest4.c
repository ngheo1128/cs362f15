#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define EXPECT(condition)  \
    total_tests++; \
    if (!(condition)) {             \
        failed_tests++;             \                   
    } \
    else { \
        passed_tests++; \
    } \

int main() {
    int failed_tests = 0;
    int total_tests = 0;
    int passed_tests = 0;
    int r;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    

    r = initializeGame(numPlayer, k, seed, &G);

    printf ("TESTING getCost():\n");


    //Testing with values in the set of cards in this game.
    EXPECT(getCost(adventurer) == 6);
    #if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 6, getCost(adventurer));
#endif
 
    EXPECT(getCost(council_room) == 5);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 5,getCost(council_room));
#endif
    EXPECT(getCost(feast) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4, getCost(feast));
#endif
    EXPECT(getCost(gardens) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(gardens));
#endif
    EXPECT(getCost(mine) == 5);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 5,getCost(mine));
#endif
    EXPECT(getCost(remodel) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(remodel));
#endif
    EXPECT(getCost(smithy) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(smithy));
#endif
    EXPECT(getCost(village) == 3);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 3,getCost(village));
#endif

    EXPECT(getCost(baron) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(baron));
#endif
 
    EXPECT(getCost(great_hall) == 3);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n",3 ,getCost(great_hall));
#endif
    
    //If this function is passed a card value that is not in the game,
    //it will still return the value of that card.

    EXPECT(getCost(treasure_map) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. notInDeck OUTPUT: %d RESULT: %d \n", 4, getCost(treasure_map));
#endif

    //Testing if card enum is just a little bit out of range.

    EXPECT(getCost(27) == -1);
#if (NOISY_TEST == 1)
    printf ("PASSED. notInDeck OUTPUT: %d RESULT: %d \n", 4, getCost(27));
#endif
    //Testing if card enum is extremely out of range.
    EXPECT(getCost(999) == -1);
#if (NOISY_TEST == 1)
    printf ("PASSED. outOfRange OUTPUT: %d RESULT: %d \n", -1, getCost(999));
#endif

     printf("Total tests run: %d, Passing: %d Failing: %d\n", total_tests, passed_tests, failed_tests);


    return 0;
}