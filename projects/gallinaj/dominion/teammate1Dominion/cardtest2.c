#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int testRefSmithy(int currentPlayer, struct gameState *state, int handPos);

int testRefSmithy(int currentPlayer, struct gameState *state, int handPos) {
    int i;

    int tempDeckCount = 0;
    int tempDiscardCount = 0;
    int pass = 0;
    int fail = 0;

    tempDeckCount = state->deckCount[currentPlayer];
    tempDiscardCount = state->discardCount[currentPlayer];

      //+3 Cards
      for(i = 1; i < 3; i++){
          drawCard(currentPlayer, state);
        }

      printf("Testing deck count decrease\n");
      if(state->deckCount[currentPlayer] != (tempDeckCount - 3))
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);

      printf("Testing discard count increase\n");
      if(state->discardCount[currentPlayer] >= (tempDiscardCount + 8)) //Normal discard of 5 plus extra 3
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }
      return 0;

}



int main()
{
    int retValue;
    int seed = 1000;
    int numPlayers = 2;
    int handPos = 1;

    struct gameState G;
    int currentPlayer = whoseTurn(&G);

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing Smithy function*****\n");

    initializeGame(numPlayers, kings, seed, &G);

    retValue = testRefSmithy(currentPlayer, &G, handPos);

    if(retValue == 0)
    {
        printf("Test passed: return value = 0.\n");
    }
    else {
        printf("Test failed: return value = 1.\n");
    }
    printf("\n");

    return 0;
}
