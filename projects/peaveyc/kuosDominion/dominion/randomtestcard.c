/******************************************************************************
randomtestcard.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Radnom testing for the smithy card, as implemented in smithyCard().
  Adds three cards to the player's hand.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void randTest_smithyCard() {
  int i, j, m;   // counter variables
  int tests = 20000;  // number of tests to run
  int seed = 1000;
  int numPlayers;
  int position;
  struct gameState game;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  int passing = 0;
  int failing = 0;

  srand(time(NULL));

  printf("************\nTESTING smithyCard():\n************\n");

  for (i = 0; i < tests; i++) {
    printf("\niteration %d\n", i + 1);
    numPlayers = rand() % 3 + 2;  // 2 to 4 players
    memset(&game, 23, sizeof(struct gameState));  // clear the game state
    initializeGame(numPlayers, k, seed, &game);

    // save initial deck counts for all players
    int startingDeckCounts[] = {0, 0, 0, 0};
    // save initial hand counts for all players
    int startingHandCounts[] = {0, 0, 0, 0};
    // save initial discard counts for all players
    int startingDiscCounts[] = {0, 0, 0, 0};

    // set random cards in players' decks, hands, and discard piles
    for (j = 0; j < numPlayers; j++) {
      // give each player some number of cards in their deck (5 - 30)
      game.deckCount[j] = rand() % 26 + 5;
      startingDeckCounts[j] = game.deckCount[j];
      // give each player some number of cards in their hand (3 - 10)
      game.handCount[j] = rand() % 8 + 3;
      startingHandCounts[j] = game.handCount[j];
      // give each player some number of cards in their discard (3 - 10)
      game.discardCount[j] = rand() % 8 + 3;
      startingDiscCounts[j] = game.discardCount[j];
      // put random cards in k into each player's deck
      for (m = 0; m < game.deckCount[j]; m++) {
        game.deck[j][m] = k[rand() % 10];
      }
      // put random treasures into deck
      for (m = 0; m < game.deckCount[j]; m++) {
        if (rand() % 5 == 0)  // 1 in 5 of changing card to treasure
          game.deck[j][m] = rand() % 3 + 4;
      }
      // put random cards in k into each player's hand
      for (m = 0; m < game.handCount[j]; m++) {
        game.hand[j][m] = k[rand() % 10];
      }
      // put random treasures into hand
      for (m = 0; m < game.handCount[j]; m++) {
        if (rand() % 5 == 0)  // 1 in 5 of changing card to treasure
          game.hand[j][m] = rand() % 3 + 4;
      }
      // put random cards in k into each player's discard
      for (m = 0; m < game.discardCount[j]; m++) {
        game.discard[j][m] = k[rand() % 10];
      }
      // put random treasures into discard
      for (m = 0; m < game.discardCount[j]; m++) {
        if (rand() % 5 == 0)  // 1 in 5 of changing card to treasure
          game.discard[j][m] = rand() % 3 + 4;
      }
    }

    // ensure that at least one copy of smithy is present in player 0's hand
    position = rand() % (game.handCount[0]);  // pick a random position player
      // 0's hand to add adventurer
    game.hand[0][position] = smithy;

    game.whoseTurn = 0; // set to player 0's turn
    // play the smithy card
    int turn1 = cardEffect(smithy, 0, 0, 0, &game, 1, 0);
    if (turn1) {
      printf("FAIL: cardEffect(smithy) returned non-zero value\n");
      failing++;
    }
    else {
      printf("PASS: cardEffect(smithy) returned zero value\n");
      passing++;
    }

    // check if player 0 has 3 cards drawn
    if (game.handCount[0] != (startingHandCounts[0] + 3)) {
      printf("FAIL: player 0 did not draw 3 cards; actual hand count is %d\n",
        game.handCount[0]);
      failing++;
    }
    else {
      printf("PASS: player 0's hand gained 3 cards\n");
      passing++;
    }

    // check for discarded card for player 0
    if (game.discardCount[0] != (startingDiscCounts[0] + 1)) {
      printf("FAIL: player 0's discard pile count is not 4; actual discard pile "
        "count is %d\n", game.discardCount[0]);
      failing++;
    }
    else {
      printf("PASS: player 0 discarded a card\n");
      passing++;
    }

    // check for cards drawn from deck for player 0
    if (game.deckCount[0] != (startingDeckCounts[0] + 2)) {
      printf("FAIL: player 0's deck is not 2; actual deck count is %d\n",
        game.deckCount[0]);
      failing++;
    }
    else {
      printf("PASS: player 0 drew 3 cards from their deck\n");
      passing++;
    }

    // check if each other player's cards are not affected
    for (j = 1; j < numPlayers; j++) {
      if (game.handCount[j] != startingHandCounts[j]) {
        printf("FAIL: player %d's hand count changed; actual count is %d\n",
          j, game.handCount[1]);
        failing++;
      }
      else {
        printf("PASS: player %d's hand count is unchanged\n", j);
        passing++;
      }

      if (game.deckCount[j] != startingDeckCounts[j]) {
        printf("FAIL: player %d's deck count changed; actual count is %d\n",
          j, game.deckCount[j]);
        failing++;
      }
      else {
        printf("PASS: player %d's deck count is unchanged\n", j);
        passing++;
      }

      if (game.discardCount[j] != startingDiscCounts[j]) {
        printf("FAIL: player %d's discard count changed; actual count is %d\n",
          j, game.discardCount[j]);
        failing++;
      }
      else {
        printf("PASS: player %d's discard count is unchanged\n", j);
        passing++;
      }
    }
  }
  printf("Passing tests: %d\n", passing);
  printf("Failing tests: %d\n", failing);
}

int main() {
  randTest_smithyCard();
  return 0;
}
