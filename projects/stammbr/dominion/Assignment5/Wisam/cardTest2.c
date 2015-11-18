/*****************
 * Author:  Brian Stamm
 * Title:  cardTest2.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Unit tests for the Adventurer card, adventurer_refactor().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Function setHand - set up to quickly set the deck for various situations
//Runs through, and depending, fills deck with cards user passes in
int setHand(struct gameState *g, int card, int r, int choice){
  int i, newCard;
  //Fills deck completely
  if(choice == 1){
    for(i=0;i<MAX_HAND; i++){
      g->deck[1][i] = card;
    }
    g->deckCount[1] = MAX_HAND;
    return 0;
  }
  //Fills deck with (card -1), except the last 3 cards, which is filled
  //with card
  else if(choice == 2){
    for(i=0;i<(MAX_HAND-3);i++){
      g->deck[1][i] = (card -1);
    }
    for(;i<MAX_HAND;i++){
      g->deck[1][i] = card;
    }
    g->deckCount[1]= MAX_HAND;
    return 0;
  }
  //Fills deck with random cards
  else if(choice == 3){
    for(i=0;i<MAX_HAND;i++){
      r = rand();
      newCard = r % 27;
      g->hand[1][i] = newCard;
    }
    g->deckCount[1] = MAX_HAND;
    return 0;
  }
  //ONLY HAND FILLING SITUATION
  //fills hand with 5 cards
  else{
    for(i=0;i<5;i++){
      g->hand[1][i] = card;
    }
    g->handCount[1] = 5;
    return 0;    
  }
  return 1;
}

//Actual test
void test(){
  struct gameState g;
  struct gameState *game = &g;
	int player = 1;
  int counter = 1;
  int treasureCounter, i;
  int tempHand[MAX_HAND];
  srand(time(NULL));
  int r = rand();

  //ADDED for WISAM tests
  int drawntreasure = 0;
  int z = 0;
  int cD = 0;

  //Initial check
  if(setHand(game, copper, r, 1)){
    printf("%d:  Error setting DECK.\n", counter);
  }
  if(setHand(game, estate, r, 0)){
    printf("%d:  Error setting HAND.\n", counter);
  }
  
  if(adventurer_refactor(drawntreasure, game, tempHand, z, cD, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount[player];i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, error initial, tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurer_refactor():  PASSED initial.\n", counter);
    }
    counter++;
  }

  //ADDED for WISAM tests
  drawntreasure = 0;
  z = 0;
  cD = 0;

  //Second check, large deck, only last cards are copper
  if(setHand(game, copper, r, 2)){
    printf("%d:  Error setting DECK.\n", counter);
  }
  if(setHand(game, estate, r, 0)){
    printf("%d:  Error setting HAND.\n", counter);
  }
  
  if(adventurer_refactor(drawntreasure, game, tempHand, z, cD, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount[player];i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, large deck, last are copper, tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurer_refactor():  PASSED large deck.\n", counter);
    }
    counter++;
  }

  //ADDED for WISAM tests
  drawntreasure = 0;
  z = 0;
  cD = 0;

  //Third check, random deck, only last cards are copper
  if(setHand(game, copper, r, 3)){
    printf("%d:  Error setting DECK.\n", counter);
  }
  if(setHand(game, estate, r, 0)){
    printf("%d:  Error setting HAND.\n", counter);
  }
  
  if(adventurer_refactor(drawntreasure, game, tempHand, z, cD, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount[player];i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, random deck.  tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurer_refactor():  PASSED random.\n", counter);
    }
    counter++;
  }

  //ADDED for WISAM tests
  drawntreasure = 0;
  z = 0;
  cD = 0;

  //Fourth check, no treasure in deck, only last cards are copper
  if(setHand(game, curse, r, 1)){
    printf("%d:  Error setting DECK.\n", counter);
  }
  if(setHand(game, estate, r, 0)){
    printf("%d:  Error setting HAND.\n", counter);
  }
  
  if(adventurer_refactor(drawntreasure, game, tempHand, z, cD, player) != 0){
    printf("%d:  Error unknown.  NO TREASURE.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount[player];i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter > 0){
      printf("%d:  adventureMethod():  FAIL, no treasure deck.  tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurer_refactor():  PASSED no treasure?.\n", counter);
    }
    counter++;
  }

}

int main(int argc, char **argv){

	printf("This is the tests for the Adventurer card, adventurer_refactor().\n");
	
	test();

	return 0;
}

/**********************
Method being tested.

int adventurer_refactor(struct gameState *state, int *temphand, int currentPlayer){
  int cardDrawn;
  int z = 0;// this is the counter for the temp hand
  int drawntreasure = 0;
  while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while(z>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
  return 0;
}
*************************/
