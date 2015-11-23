#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testRefAdventurer(int currentPlayer, struct gameState *state, int handPos);


int testRefAdventurer(int currentPlayer, struct gameState *state, int handPos) {

   int drawntreasure=0;
   int cardDrawn;
   int temphand[MAX_HAND];
   int z=0; //coutner for tempHand array

    int tempDeckCount = 0;
    int tempDiscardCount = 0;
    int pass = 0;
    int fail = 0;

    tempDeckCount = state->deckCount[currentPlayer];
    tempDiscardCount = state->discardCount[currentPlayer];

       while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
          drawntreasure=2;
        else{
          temphand[z]=cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
      }

      printf("Testing deck count decrease\n");
      if(state->deckCount[currentPlayer] >= (tempDeckCount - 2))
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

      while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
      }

      printf("Testing discard count increase\n");
      if(state->discardCount[currentPlayer] >= (tempDiscardCount + 7))
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

//      printf("%d tests passed, %d tests failed\n", pass, fail);


      return 0;
}

int main()
{
    int retValue;
    int seed = 1000;
    int numPlayers = 2;
    int handPos = 0;
    struct gameState G;
    int currentPlayer = whoseTurn(&G);

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing Adventurer function*****\n");

    initializeGame(numPlayers, kings, seed, &G);

    retValue = testRefAdventurer(currentPlayer, &G, handPos);

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
