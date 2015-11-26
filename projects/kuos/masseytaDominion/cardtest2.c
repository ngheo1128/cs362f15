/******************************************************************************
cardtest2.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the adventurer card, as implemented in
  adventurerCard(). Reveals adventure cards in the player's deck until 2 are
  shown. The revealed treasure cards are placed in the player's hand and the
  other revealed cards are discarded.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_adventurerCard() {
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  struct gameState game;

  printf("************\nTESTING adventurerCard():\n************\n");

  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  // set a 2-player game with identical cards in hand, deck, and discard piles
  // have one adventurer card in each player's hands
  game.handCount[0] = 3;
  game.discardCount[0] = 3;
  game.deckCount[0] = 5;

  int handCount0 = game.handCount[0];
  int discardCount0 = game.discardCount[0];
  int deckCount0 = game.deckCount[0];
  int playedCount = game.playedCardCount;

  game.hand[0][0] = adventurer;
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

  game.hand[1][0] = adventurer;
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
  // play the adventurer card
  int turn1 = cardEffect(adventurer, 0, 0, 0, &game, 1, 0);
  if (turn1)
    printf("FAIL: cardEffect(adventurer) returned non-zero value\n");
  else
    printf("PASS: cardEffect(adventurer) returned zero value\n");

  // check if player 0 has 2 cards drawn, and adventurer played
  if (game.handCount[0] != handCount0 + 1)
    printf("FAIL: player 0 did not draw 2 cards and play 1 (expected hand "
      "count %d); actual hand count is %d\n", handCount0 + 1,
      game.handCount[0]);
  else
    printf("PASS: player 0's hand gained 2 cards\n");

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
  if (game.deckCount[0] != deckCount0 - 2)
    printf("FAIL: player 0's deck is not decremented by 2 (expected deck "
      "count %d); actual deck count is %d\n", deckCount0 - 2,
      game.deckCount[0]);
  else
    printf("PASS: player 0 drew 2 cards from their deck\n");

  // check if player 1's cards are not affected
  if (game.handCount[1] != handCount1)
    printf("FAIL: player 1's hand count changed (expected %d); actual count "
      "is %d\n", handCount1, game.handCount[1]);
  else
    printf("PASS: player 1's hand count is unchanged\n");

  if (game.discardCount[1] != discardCount1)
    printf("FAIL: player 1's discard count changed (expected %d); actual "
      "count is %d\n", discardCount1, game.discardCount[1]);
  else
    printf("PASS: player 1's discard count is unchanged\n");

  if (game.deckCount[1] != deckCount1)
    printf("FAIL: player 1's deck count changed (expected %d); actual count "
      "is %d\n", deckCount1, game.deckCount[1]);
  else
    printf("PASS: player 1's deck count is unchanged\n");
}

int main() {
  test_adventurerCard();
  return 0;
}
