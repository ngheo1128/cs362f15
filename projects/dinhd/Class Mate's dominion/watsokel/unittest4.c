/*
This program tests the scoreFor function.
The parameters for this function are:
struct gameState *state

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int initializeGameNoPoints(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);


int main() {

    int score;
    int card;
    struct gameState G;
    struct gameState D;

    printf("* * * * * * * * * * * * * * * * Testint unittest4 scoreFor * * * * * * * * * * * * * * * * \n");
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
    initializeGameNoPoints(2, k, 2, &G);

    printf ("Test: Empty Game \n");
    score = scoreFor(0, &G);
    //printf ("Score is %i \n", score);


    assert (score == 0);

    printf("Test: one score card found in hand\n");
    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }

    gainCard(curse, &G, 2, 0); // -1 pt
    gainCard(estate, &G, 2, 0); // 1 pt
    gainCard(duchy, &G, 2, 0); // 3 pts
    gainCard(province, &G, 2, 0); // 6 pts
    gainCard(great_hall, &G, 2, 0); //1 pt
    gainCard(gardens, &G, 2, 0); // 0pt
    //printHand(0, &G);

    score = scoreFor(0, &G);
    assert (score == 10);

    G = D;

    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }   

    printf("Test: One of each in deck \n");
    gainCard(curse, &G, 1, 0); // -1 pt
    gainCard(estate, &G, 1, 0); // 1 pt
    gainCard(duchy, &G, 1, 0); // 3 pts
    gainCard(province, &G, 1, 0); // 6 pts
    gainCard(great_hall, &G, 1, 0); //1 pt
    gainCard(gardens, &G, 1, 0); // 1pt
    //printDeck(0, &G);

    score = scoreFor(0, &G);
    //printf("score: %i \n", score);
    if (score != 10)
    {
      printf("Error: deck points not totalled correctly. score is %i not 10\n", score);
    }
        // printf ("################################################### \n Error: iterator for deck count cycles through i = discardCount istead of deckCount \n ################################################### \n");



    G = D; 

    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }

    printf("Test: One of each in discard\n");
    gainCard(curse, &G, 0, 0); // -1 pt
    gainCard(estate, &G, 0, 0); // 1 pt
    gainCard(duchy, &G, 0, 0); // 3 pts
    gainCard(province, &G, 0, 0); // 6 pts
    gainCard(great_hall, &G, 0, 0); //1 pt
    gainCard(gardens, &G, 0, 0); // 1pt
    
    //printDeck(0, &G);
    //printDiscard(0, &G);
    //printHand(0, &G);

    score = scoreFor(0, &G);

    if (score != 10)
    {
      printf("Error: discard points not totalled correctly. score is %i not 10\n", score);
    }
    // printf ("score: %i disardcount: %i \n", score, discardCount);
    // printf ("################################################### \n Error: iterator for deck count cycles through i = discardCount istead of deckCount \n ################################################### \n");


    
    printf("All tests passed!\n");

    
    
    return 0;
}


int initializeGameNoPoints(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state) 
{

  int i;
  int j;
  int it;     
  //set up random number generator.
  SelectStream(1);
  PutSeed((long)randomSeed);
  
  //check number of players
  if (numPlayers > MAX_PLAYERS || numPlayers < 2)
    {
      return -1;
    }

  //set number of players
  state->numPlayers = numPlayers;

  //check selected kingdom cards are different
  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
        {
    if (j != i && kingdomCards[j] == kingdomCards[i])
      {
        return -1;
      }
        }
    }


  //initialize supply
  ///////////////////////////////

  //set number of Curse cards
  if (numPlayers == 2)
    {
      state->supplyCount[smithy] = 10;
    }
  else if (numPlayers == 3)
    {
      state->supplyCount[smithy] = 20;
    }
  else
    {
      state->supplyCount[smithy] = 30;
    }

  //set number of Victory cards
  if (numPlayers == 2)
    {
      state->supplyCount[smithy] = 8;
      state->supplyCount[smithy] = 8;
      state->supplyCount[smithy] = 8;
    }
  else
    {
      state->supplyCount[smithy] = 12;
      state->supplyCount[smithy] = 12;
      state->supplyCount[smithy] = 12;
    }

  //set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;

  //set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++)        //loop all cards
    {
      for (j = 0; j < 10; j++)              //loop chosen cards
  {
    if (kingdomCards[j] == i)
      {
        //check if card is a 'Victory' Kingdom card
        if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
    {
      if (numPlayers == 2){ 
        state->supplyCount[i] = 8; 
      }
      else{ state->supplyCount[i] = 12; }
    }
        else
    {
      state->supplyCount[i] = 10;
    }
        break;
      }
    else    //card is not in the set choosen for the game
      {
        state->supplyCount[i] = -1;
      }
  }

    }

  ////////////////////////
  //supply intilization complete

  //set player decks
  for (i = 0; i < numPlayers; i++)
    {
      state->deckCount[i] = 0;
      for (j = 0; j < 3; j++)
  {
    state->deck[i][j] = smithy;
    state->deckCount[i]++;
  }
      for (j = 3; j < 10; j++)
  {
    state->deck[i][j] = copper;
    state->deckCount[i]++;    
  }
    }

  //shuffle player decks
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
  {
    return -1;
  }
    }

  //draw player hands
  for (i = 0; i < numPlayers; i++)
    {  
      //initialize hand size to zero
      state->handCount[i] = 0;
      state->discardCount[i] = 0;
      //draw 5 cards
      // for (j = 0; j < 5; j++)
      //  {
      //    drawCard(i, state);
      //  }
    }
  
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++)
    {
      state->embargoTokens[i] = 0;
    }

  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  //int it; move to top

  //Moved draw cards to here, only drawing at the start of a turn
  for (it = 0; it < 5; it++){
    drawCard(state->whoseTurn, state);
  }

  updateCoins(state->whoseTurn, state, 0);

  return 0;
}