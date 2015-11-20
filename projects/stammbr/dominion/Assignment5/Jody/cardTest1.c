/*****************
 * Author:  Brian Stamm
 * Title:  cardTest1.c
 * Assignment:  5
 * Date:  11.22.15
 * Notes:  Unit Test for callSmithy(), the Smithy card - Jody.
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
  struct gameState g;
  struct gameState *game = &g;
	int player = 1;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  srand(time(NULL));
  int r = rand();
  int i, counter, card, total, failNum;
  int testHandCount, testDeckCount, testDiscardCount, testPlayedCardCount;
  int testTrialCard;

  initializeGame(2, k, r, game);

  testPlayedCardCount = game->playedCardCount + 1;
  testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player] + 2;
  testDiscardCount = game->discardCount[player] + 1;
  testDeckCount = game->deckCount[player] - 3;
  /*testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player] + 3;
  testDiscardCount = game->discardCount[player] + 1;
  testDeckCount = game->deckCount[player] - 1;*/

  if(callSmithy(player, 0, game) == 0){
    if(testDiscardCount != game->discardCount[player]){
      printf("smithy_refactor() Test 1a:  FAIL, discard amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDiscardCount, game->discardCount[player]);
    }

    if(testHandCount != game->handCount[player]){
      printf("Test 1b:  FAIL, handCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]); 
    }

    if(testDeckCount != game->deckCount[player]){
      printf("Test 1c:  FAIL, deckCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);      
    }
    if(testPlayedCardCount != game->playedCardCount){
      printf("Test 1d:  FAIL, playedCardCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testPlayedCardCount, game->playedCardCount);      
    }
  }
  else{
    printf("callSmithy() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

//Then do random decks, similar to shuffle test.
  /*
  printf("\nRandom Testing to Start\n");
  counter = 1;
  failNum = 0;
  while(counter < 501){
    for(i=0; i < 10; i++){
      card = r % treasure_map;
      game->deck[player][i] = card;
    }
    game->deckCount[player] = 10;
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    for(i=0; i<total; i++){
      card = r % treasure_map;
      game->hand[player][i] = card;
    }
    game->handCount[player] = total;

    testTrialCard = game->hand[player][0];
    testHandCount = game->handCount[player] + 3;
    testDiscardCount = game->discardCount[player] + 1;
    testDeckCount = game->deckCount[player] - 1;
    printf("\n");
    if(callSmithy(player, 0, game) == 0){
      if(testDiscardCount != game->discardCount[player]){
        printf("callSmithy() Random Test %da:  FAIL, discard amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDiscardCount, game->discardCount[player]);
        failNum++;
      }

      if(testHandCount != game->handCount[player]){
        printf("Random Test %db:  FAIL, handCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("Test %dc:  FAIL, deckCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);   
        failNum++;
      }
    }
    else{
      printf("callSmithy() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
    }
    counter++;      
  }
  printf("\ncallSmithy() Random Test fail number:  %d\n", failNum);
  */
}

int main(int argc, char **argv){

	printf("This is the tests the Smithy card - callSmithy().\n");
	
	test();

	return 0;
}

/*****************
Method being tested

int callSmithy(struct gameState *state, int currentPlayer, int handPos){
  //+3 Cards
  int i;
  for (i = 0; i <= 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
*******************/