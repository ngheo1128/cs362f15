/******************************************************************************
cardtest4.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the council room card, as implemented in
  councilRoomCard(). Draws 4 cards to the player's hand, adds 1 buy, and each
  other player draws 1 card.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_councilRoomCard() {
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  struct gameState game;

  printf("************\nTESTING councilRoomCard():\n************\n");

  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  // set a 2-player game with identical cards in hand, deck, and discard piles
  // have one council room card in each player's hands
  game.handCount[0] = 3;
  game.discardCount[0] = 3;
  game.deckCount[0] = 5;

  int handCount0 = game.handCount[0];
  int discardCount0 = game.discardCount[0];
  int deckCount0 = game.deckCount[0];
  int playedCount = game.playedCardCount;

  game.hand[0][0] = council_room;
  game.hand[0][1] = copper;
  game.hand[0][2] = silver;
  game.discard[0][0] = copper;
  game.discard[0][1] = copper;
  game.discard[0][2] = silver;
  game.deck[0][0] = silver;
  game.deck[0][1] = silver;
  game.deck[0][2] = silver;
  game.deck[0][3] = silver;
  game.deck[0][4] = silver;

  game.handCount[1] = 3;
  game.discardCount[1] = 3;
  game.deckCount[1] = 5;

  int handCount1 = game.handCount[0];
  int discardCount1 = game.discardCount[0];
  int deckCount1 = game.deckCount[0];

  game.hand[1][0] = council_room;
  game.hand[1][1] = copper;
  game.hand[1][2] = silver;
  game.discard[1][0] = copper;
  game.discard[1][1] = copper;
  game.discard[1][2] = silver;
  game.deck[1][0] = silver;
  game.deck[1][1] = silver;
  game.deck[1][2] = silver;
  game.deck[1][3] = silver;
  game.deck[1][4] = silver;

  game.whoseTurn = 0; // set to player 0's turn
  game.numBuys = 1;

  int buys = game.numBuys;

  // play the council room card
  int turn1 = cardEffect(council_room, 0, 0, 0, &game, 1, 0);
  if (turn1)
    printf("FAIL: cardEffect(council_room) returned non-zero value\n");
  else
    printf("PASS: cardEffect(council_room) returned zero value\n");

  // check if player 0 has 4 cards drawn and council room played
  if (game.handCount[0] != handCount0 + 3)
    printf("FAIL: player 0 did not draw 4 cards (expected hand count %d); "
      "actual hand count is %d\n", handCount0 + 3, game.handCount[0]);
  else
    printf("PASS: player 0 drew 4 cards\n");

  // check for played card for player 0
  if (game.playedCardCount != playedCount + 1)
    printf("FAIL: player 0 did not play card correctly (expected %d played "
      "card); actual played card count is %d\n", playedCount + 1,
      game.playedCardCount);
  else
    printf("PASS: player 0 played a card\n");

  // check that discard pile is unchanged for player 0 (not until endTurn())
  if (game.discardCount[0] != discardCount0)
    printf("FAIL: player 0's discard pile count is not same (expected %d); "
      "actual discard pile count is %d\n", discardCount0,
      game.discardCount[0]);
  else
    printf("PASS: player 0's discard pile unchanged\n");

  // check for cards drawn from deck for player 0
  if (game.deckCount[0] != deckCount0 - 4)
    printf("FAIL: player 0's deck is not decreased by 4 (expected deck count "
      "%d); actual deck count is %d\n", deckCount0 - 4, game.deckCount[0]);
  else
    printf("PASS: player 0 drew 4 cards from their deck\n");

  // check for increased actions
  if (game.numBuys != buys + 1)
    printf("FAIL: player 0's buys were not incremented by 1 (expected %d buys)"
      "; actual buy count: %d\n", buys + 1, game.numBuys);
  else
    printf("PASS: player 0's actions incremented by 1\n");

  // check if player 1 drew a card
  if (game.handCount[1] != handCount1 + 1)
    printf("FAIL: player 1 did not draw 1 card (expected hand count %d); "
      "actual hand count is %d\n", handCount1 + 1, game.handCount[1]);
  else
    printf("PASS: player 1 drew a card into the hand\n");

  if (game.discardCount[1] != discardCount1)
    printf("FAIL: player 1's discard count changed (expected %d); actual "
      "count is %d\n", discardCount1, game.discardCount[1]);
  else
    printf("PASS: player 1's discard count is unchanged\n");

  if (game.deckCount[1] != deckCount1 - 1)
    printf("FAIL: player 1 did not draw 1 card (expected deck count %d); "
      "actual deck count is %d\n", deckCount1 - 1, game.deckCount[1]);
  else
    printf("PASS: player 1's drew a card from the deck\n");
}

int main() {
  test_councilRoomCard();
  return 0;
}
