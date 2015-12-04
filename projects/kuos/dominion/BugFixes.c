/******************************************************************************
BugFixes.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 5
Description: Notes on bug fixes reported by teammates and fixes for bugs that
  were introduced in assignment 2.
*******************************************************************************
-------------------------------------------------------------------------------
Bug 1
Reported 2015/11/13
Tara Massey (masseyta@oregonstate.edu)

Title: Smithy card is not properly discarded
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Ran a unit test against the refactored smithy function. Compared
the value of playedCardCount to the expected value of one for a discard. After
the card was played the comparison show the was incorrectly handled.

Expected results
----------------
testState.playedCardCount = 1

Actual results
--------------
testState.playedCardCount = 0

Code causing error
--------------
dominion.c line 1271
  discardCard(handPos, player, state, 1);

Code fix
--------------
dominion.c line 1271
  discardCard(handPos, player, state, 0);


-------------------------------------------------------------------------------
Bug 2
Reported 2015/11/13
Tara Massey (masseyta@oregonstate.edu)

Title: Extra card drawn when Adventurer Card is played
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Ran a unit test against the refactored adventurer function. Set players hand to
contain no treasure cards. Set deck to contain treasure cards. Call function.
Loop through player's hand. When a treasure card is found, increase a counter
variable. Counter variable should indicate two treasure cards, but indicates 3.
End handcount indicates 3 cards kept. Repeatable when randomized or set deck is
created, so long as total number drawn is tracked.

Expected results
----------------
afterCount - beforeCount = 2
count = 2

Actual results
--------------
afterCount - beforeCount = 3
count = 2

Code causing error
--------------
dominion.c line 1283
  while (drawnTreasure <= 2) {

Code fix
--------------
dominion.c line 1283
  while (drawnTreasure < 2) {


-------------------------------------------------------------------------------
Bug 3
Reported 2015/11/13
Tara Massey (masseyta@oregonstate.edu)

Title: Adventurer card is not properly discarded, bug in original version as
  well
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Ran a unit test against the refactored adventurer function. Ensure proper
results by creating a deck where the first card drawn is non-treasure, and the
next two are treasure cards. Then Compared the values of playedCardCount to the
expected value of one. After the card was played the comparison show the
discard was incorrectly handled. The playedCardCount of the current player was
not increased for the adventurer card.

Expected results
----------------
testState.playedCardCount == 1

Actual results
--------------
testState.playedCardCount == 0

Code causing error
--------------
dominion.c line 1276
  // no discardCard() call in adventurerCard() function

Code fix
--------------
dominion.c line 1308
  discardCard(handPos, player, state, 0);
dominion_helpers.c line 16
  int adventurerCard(int player, struct gameState* state, int* tempHand,
    int handPos);
dominion.c line 1276
  int adventurerCard(int player, struct gameState* state, int* tempHand,
    int handPos) {
dominion.c line 677
  return adventurerCard(currentPlayer, state, temphand, handPos);


-------------------------------------------------------------------------------
Bug 4
Reported 2015/11/18
Connor Peavey (connorpeavey@gmail.com)

Title: Adventure Card draws three treasure not two
Class: Bug, major
Note: Duplicate of bug 2
-------------------------------------------------------------------------------
Description
----------------
While running unit test on adventureCard it was discovered that instead of
drawing two treasures three were drawn.

Expected results
----------------
Current player draws two treasures

Actual results
--------------
Current player draws three treasures

Code causing error
--------------
dominion.c line 1283
  while (drawnTreasure <= 2) {

Code fix
--------------
dominion.c line 1283
  while (drawnTreasure < 2) {

Note
--------------
Duplicate of bug 2.


-------------------------------------------------------------------------------
Bug 5
Reported 2015/11/18
Connor Peavey (connorpeavey@gmail.com)

Title: Adventure Card discard loss
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
While running unit test on adventureCard it was discovered that instead of
discarding the proper amount of cards, there is one card not being discarded.

Expected results
----------------
All cards that are not treasure cards the are drawn, are discarded

Actual results
--------------
All cards that are not treasure cards the are drawn, are discarded except one
card

Code causing error
--------------
dominion.c line 1302
  while (z - 1 > 0) {
    state->discard[player][state->discardCount[player]++] = tempHand[z - 1];
    z--;
  }

Code fix
--------------
dominion.c line 1302
  while (z - 1 >= 0) {
    state->discard[player][state->discardCount[player]++] = tempHand[z - 1];
    z--;
  }

-------------------------------------------------------------------------------
Bug 6
Reported 2015/11/18
Connor Peavey (connorpeavey@gmail.com)

Title: Incorrect discard in smithy card
Class: Bug, major
Note: Duplicate of bug 1
-------------------------------------------------------------------------------
Description
----------------
While running unit test on cardEffect it was discovered that current players
discard was not increased by 1.

Expected results
----------------
Current player discard is increased by 1

Actual results
--------------
Current player discard is increased by 0

Code causing error
--------------
dominion.c line 1271
  discardCard(handPos, player, state, 1);

Code fix
--------------
dominion.c line 1271
  discardCard(handPos, player, state, 0);

Note
--------------
Duplicate of bug 1.


-------------------------------------------------------------------------------
Bug 7
Reported 2015/11/18
Connor Peavey (connorpeavey@gmail.com)

Title: Infinite loop in Feast card
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
While running unit test on cardEffect it was discovered that the feast case
in cardEffect causes the program to enter an infinite loop. Occurs when the
player attempts to select a card that costs too much.

Expected results
----------------
Gain a curse card

Actual results
--------------
Program enters infinite loop

Code causing error
--------------
dominion.c line 694
  while( x == 1) {//Buy one card
    if (supplyCount(choice1, state) <= 0){
      if (DEBUG)
        printf("None of that card left, sorry!\n");
      if (DEBUG){
        printf("Cards Left: %d\n", supplyCount(choice1, state));
      }
    }
    else if (state->coins < getCost(choice1)){
      printf("That card is too expensive!\n");
      if (DEBUG){
        printf("Coins: %d < %d\n", state->coins, getCost(choice1));
      }
    }
    else{
      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
          state->deckCount[currentPlayer] +
          state->discardCount[currentPlayer]);
      }
      gainCard(choice1, state, 0, currentPlayer);//Gain the card
      x = 0;//No more buying cards
      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
          state->deckCount[currentPlayer] +
          state->discardCount[currentPlayer]);
      }
    }
  }
The while loop condition is never set to x != 1 if there are no cards left or
if the player chooses a card that is too expensive.

Code fix
--------------
dominion.c line 694
  while( x == 1) {//Buy one card
    if (supplyCount(choice1, state) <= 0){
      if (DEBUG)
        printf("None of that card left, sorry!\n");
      if (DEBUG){
        printf("Cards Left: %d\n", supplyCount(choice1, state));
      }
      return -1;
    }
    else if (state->coins < getCost(choice1)){
      printf("That card is too expensive!\n");
      if (DEBUG){
        printf("Coins: %d < %d\n", state->coins, getCost(choice1));
      }
      return -1;
    }
    else{
      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
          state->deckCount[currentPlayer] +
          state->discardCount[currentPlayer]);
      }
      gainCard(choice1, state, 0, currentPlayer);//Gain the card
      x = 0;//No more buying cards
      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
          state->deckCount[currentPlayer] +
          state->discardCount[currentPlayer]);
      }
    }
  }
Changed the two cases to return -1 (signifying an error) so that the while loop
is terminated by the returning of the function.


-------------------------------------------------------------------------------
Bug 8
Reported 2015/11/08
Sharon Kuo (kuos@oregonstate.edu)

Title: scoreFor() does not correctly count score for garden cards
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Used a unit test written for the scoreFor() function to calculate the score for
players based on some generated sets of decks. Compared expected score with
actual score for the following scenarios: empty deck, hand, and discard pile;
15 kingdom and 3 garden cards; 15 treasure and 3 garden cards; 9 estate, 3
duchy, 3 province, and 3 curse cards.

Expected results
----------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 3
15 treasure cards and 3 garden cards (total of 18 cards): score = 3

Actual results
--------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 0
15 treasure cards and 3 garden cards (total of 18 cards): score = 0

Code causing error
--------------
dominion.c line 436
  if (state->hand[player][i] == gardens) { score = score +
    ( fullDeckCount(player, 0, state) / 10 ); };
dominion.c line 447
  if (state->discard[player][i] == gardens) { score = score +
    ( fullDeckCount(player, 0, state) / 10 ); };
dominion.c line 458
  if (state->deck[player][i] == gardens) { score = score +
    ( fullDeckCount(player, 0, state) / 10 ); };

Code fix
--------------
dominion.c line 421
  int cards = 0;
  // count total cards for each player
  cards += state->handCount[player];
  cards += state->deckCount[player];
  cards += state->discardCount[player];
dominion.c line 436
  if (state->hand[player][i] == gardens) { score = score + ( cards / 10 ); };
dominion.c line 447
  if (state->discard[player][i] == gardens) { score = score + ( cards / 10 ); };
dominion.c line 458
  if (state->deck[player][i] == gardens) { score = score + ( cards / 10 ); };


-------------------------------------------------------------------------------
Bug 9
Reported 2015/11/08
Sharon Kuo (kuos@oregonstate.edu)

Title: Village card is not discarded properly
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Used a unit test written for the village card function to compare values of the
player's hand count, deck count, discarded card count, and played card count
from before and after playing the village card. The played card count is not as
expected.

Expected results
----------------
testState.playedCardCount == 1

Actual results
--------------
testState.playedCardCount == 0

Code causing error
--------------
dominion.c line 1344
    discardCard(0, player, state, handPos);

Code fix
--------------
dominion.c line 1344
  discardCard(handPos, player, state, 0);


-------------------------------------------------------------------------------
Bug 10
Reported 2015/11/22
Sharon Kuo (kuos@oregonstate.edu)

Title: Remodel card is not discarded correctly
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Introduced in assignment 2 (documented in refactor.c). Change in the handPos
and trash flags in the call to discardCard() in remodelCard(), which causes the
remodel card to be incorrectly discarded.

Expected results
----------------
Remodel card is played/discarded correctly (playedCardCount = 1)

Actual results
--------------
Remodel card is not played/discarded correctly (playedCardCount = 0)

Code causing error
--------------
dominion.c line 1359
  discardCard(0, player, state, handPos);

Code fix
--------------
dominion.c line 1359
  discardCard(handPos, player, state, 0);


-------------------------------------------------------------------------------
Bug 11
Reported 2015/11/22
Sharon Kuo (kuos@oregonstate.edu)

Title: Remodel card discards all copies of a card instead of trashing just one
Class: Bug, major
-------------------------------------------------------------------------------
Description
----------------
Introduced in assignment 2 (documented in refactor.c). Removed the break line
from the for loop where the trashed card is discarded. Causes all copies of the
card to be trashed to be discarded. Original code base also only discarded the
card (trash flag = 0 instead of 1).

Expected results
----------------
One copy of card to be trashed is trashed

Actual results
--------------
All copies of the card to be trashed are discarded

Code causing error
--------------
dominion.c line 1362
  for (i = 0; i < state->handCount[player]; i++) {
    if (state->hand[player][i] == j) {
      discardCard(i, player, state, 0);
    }
  }

Code fix
--------------
dominion.c line 1362
  for (i = 0; i < state->handCount[player]; i++) {
    if (state->hand[player][i] == j) {
      discardCard(i, player, state, 1);
      break;
    }
  }

******************************************************************************/