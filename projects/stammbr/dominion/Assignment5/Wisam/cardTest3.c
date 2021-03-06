/*****************
 * Author:  Brian Stamm
 * Title:  cardTest3.c
 * Assignment:  5
 * Date:  11.22.15
 * Notes:  Tests the Council card, in the council_room_refactor - for Wisam's dominion.c
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
  int testBuys;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  srand(time(NULL));
  int r = rand();
  int i, counter, card, total, failNum;
  int testHandCount, testDeckCount, testPlayedCardCount;
  int testTrialCard;

  initializeGame(4, k, r, game);

  //to hold each player's hand amounts.
  int groupHand[4];

  //same tests as smithy card
  //Also, every player beside current player gets card, need to check them too
  //Max players is 4
  testBuys = game->numBuys + 1;
  testHandCount = game->handCount[player] + 3;
  testPlayedCardCount = game->playedCardCount + 1;
  testDeckCount = game->deckCount[player] - 4;
  for(i=0; i<4;i++){
    groupHand[i] = game->handCount[i] + 1;
  }

  printf("This is first initial test for council_room_refactor.\n");

  if(council_room_refactor(player, game, 0) == 0){
    if(testPlayedCardCount != game->playedCardCount){
      printf("council_room_refactor() Test 1:  FAIL, played card amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testPlayedCardCount, game->playedCardCount);
    }

    if((testHandCount) != game->handCount[player]){
      printf("council_room_refactor() Test 1:  FAIL, handCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
    }

    if(testDeckCount != game->deckCount[player]){
      printf("council_room_refactor() Test 1:  FAIL, deckCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
    }
    if(game->numBuys != testBuys){
      printf("Council Test :  FAILED - buy number NOT correct\n");
      printf("\tTest:  %d\tSaved:  %d\n", testBuys, game->numBuys);
    }
    for(i=0; i<4; i++){
      if(i != player){
        if(groupHand[i] != game->handCount[i]){
          printf("council_room_refactor Test 1:  FAIL, other players' hand not increased\n");
          printf("\tTest:  %d\tSaved:  %d\n", groupHand[i], game->handCount[i]);
        }
      }
    }
  }
  else{
    printf("council_room_refactor() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

  /*
  printf("This is random testing.\n");
  printf("Random Testing to Start\n");
  counter = 1;
  failNum = 0;
  int j;
  while(counter < 501){
    for(i=0; i < 10; i++){
      r = rand();
      card = r % treasure_map;
      for(j=0;j<4;j++){
        game->deck[j][i] = card;
      }
    }
    for(i=0;i<4;i++){
      game->deckCount[i] = 10;
    }
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    for(i=0; i<total; i++){
      r = rand();
      card = r % treasure_map;
      for(j=0;j<4;j++){
        game->hand[j][i] = card;
      }
    }
    for(i=0;i<4;i++){
      game->handCount[player] = total;
    }
    testBuys = game->numBuys + 1;
    testHandCount = game->handCount[player] + 4;
    testPlayedCardCount = game->playedCardCount + 1;
    testDeckCount = game->deckCount[player] - 4;

    if(council_room_refactor(player, game, 0) == 0){
      if(testPlayedCardCount != game->playedCardCount){
        printf("council_room_refactor() Random Test %d:  FAIL, discard amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testPlayedCardCount, game->playedCardCount);
        failNum++;
      }

      if(testHandCount != game->handCount[player]){
        printf("council_room_refactor() Test %d:  FAIL, handCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("council_room_refactor() Test %d:  FAIL, deckCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
        failNum++;
      }
      if(game->numBuys != testBuys){
        printf("council_room_refactor() Test %d:  FAILED - buy number NOT correct\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testBuys, game->numBuys);
        failNum++;
      }
    }
    else{
      printf("council_room_refactor() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
    }
    counter++;
  }
  printf("smithyMethod() Random Test fail number:  %d\n", failNum);
  */
}


int main(int argc, char **argv){

	printf("This is the tests for the Council card, in council_room_refactor().\n");
	
	test();

	return 0;
}

/*******************
Method being tested:

int council_room_refactor(struct gameState *state, int currentPlayer, int handPos){
  //+4 Cards
  int i;
  for (i = 0; i < 4; i++)
  {
    drawCard(currentPlayer, state);
  }
        
  //+1 Buy
  state->numBuys++;
        
  //Each other player draws a card
  for (i = 0; i < state->numPlayers; i++)
  {
    if ( i == currentPlayer )
    {
      drawCard(i, state);
    }
  }
        
  //put played card in played card pile
  discardCard(handPos, currentPlayer, state, 0);
        
  return 0;
}
*********************/
