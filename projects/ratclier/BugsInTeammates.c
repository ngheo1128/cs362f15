Erik Ratcliffe
November 22, 2015
Assignment 5 - BugsIn Teammates.txt
CS 362 (Fall 2015)



-----------------------------------------------------------------------
Teammate 1 (Susan) bugs:
-----------------------------------------------------------------------


Unit Test 1: discardCard()

>>> TESTING: discardCard(), non-trashed card...
discardCard: FAIL non-trashed card did not incremenet discardCount
discardCard: FAIL non-trashed card not added to discarded card pile

----------------------------------------------------

Card Test 1: smithyAction()

>>> TESTING: smithy card, player 0 & 1...
smithyAction: FAIL three cards not removed from deck
smithyAction: FAIL three cards not added to hand

----------------------------------------------------

Random Test: adventurerAction()

FAIL incorrect number of cards discarded
- Worth noting: if deck size was tiny, discard tests occasionally passed.



-----------------------------------------------------------------------
Teammate 2 (Brian) bugs:
-----------------------------------------------------------------------


Unit Test 1: discardCard()

>>> TESTING: discardCard(), non-trashed card...
discardCard: FAIL non-trashed card did not incremenet discardCount
discardCard: FAIL non-trashed card not added to discarded card pile

----------------------------------------------------

Card Test 1: playSmithyCard()

>>> TESTING: smithy card, player 0...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

>>> TESTING: smithy card, player 1...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

----------------------------------------------------

Random Test: playAdventureCard()

FAIL incorrect number of cards discarded
- Worth noting: if deck size was tiny, discard tests occasionally passed.





-----------------------------------------------------------------------
Supplemental information for Teammate 1 bugs:
-----------------------------------------------------------------------


Unit Test 1: discardCard()

>>> TESTING: discardCard(), non-trashed card...
discardCard: FAIL non-trashed card did not incremenet discardCount
discardCard: FAIL non-trashed card not added to discarded card pile

>>> STATE CHANGES: for all players:
playedCardCount changed! Orig: 0, New: 1
playedCards[0] changed! Orig: 0, New: 4

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 5, New: 4
hand[0][4] changed! Orig: 4, New: -1

----------------------------------------------------

Card Test 1 : smithyAction()

>>> TESTING: smithy card, player 0...
smithyAction: FAIL three cards not removed from deck
smithyAction: FAIL three cards not added to hand

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 5, New: 8
deckCount[0] changed! Orig: 5, New: 1
hand[0][5] changed! Orig: 0, New: 4
hand[0][6] changed! Orig: 0, New: 4
hand[0][7] changed! Orig: 0, New: 1
hand[0][8] changed! Orig: 0, New: -1

>>> STATE CHANGES: specific to player 1:

>>> TESTING: smithy card, player 1...
smithyAction: FAIL three cards not removed from deck
smithyAction: FAIL three cards not added to hand

>>> STATE CHANGES: for all players:
playedCardCount changed! Orig: 1, New: 2
playedCards[1] changed! Orig: 0, New: 4

>>> STATE CHANGES: specific to player 0:

>>> STATE CHANGES: specific to player 1:
handCount[1] changed! Orig: 0, New: 3
deckCount[1] changed! Orig: 10, New: 6
hand[1][0] changed! Orig: 0, New: 4
hand[1][1] changed! Orig: 0, New: 4
hand[1][2] changed! Orig: 0, New: 4
hand[1][3] changed! Orig: 0, New: -1

----------------------------------------------------

Random Test: adventurerAction()

FAIL incorrect number of cards discarded
- Worth noting: if deck size was tiny, discard tests occasionally passed:
  Size 9: fail
  Size 8: fail
  Size 7: pass
  Size 6: pass
  Size 5: pass
  Size 4: pass player 0, fail player 1 
      >>> STATE CHANGES: specific to player 1:
      handCount[1] changed! Orig: 0, New: 1
      deckCount[1] changed! Orig: 4, New: 0
      hand[1][0] changed! Orig: 5, New: 4
      hand[1][1] changed! Orig: 4, New: 12
  Size 3: fail
  Size 2: pass
  Size 1: fail
  Size 0: fail
- Also, if the deck size is not manipulated and the tests are run with
  default states, discard tests passed for player 0 but failed for player
  1.




-----------------------------------------------------------------------
Supplemental information for Teammate 2 bugs:
-----------------------------------------------------------------------


Unit Test 1: discardCard()

>>> TESTING: discardCard(), non-trashed card...
discardCard: FAIL non-trashed card did not incremenet discardCount
discardCard: FAIL non-trashed card not added to discarded card pile

>>> STATE CHANGES: for all players:
playedCardCount changed! Orig: 0, New: 1
playedCards[0] changed! Orig: 0, New: 4

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 5, New: 4
hand[0][4] changed! Orig: 4, New: -1

----------------------------------------------------

Card Test 1: playSmithyCard()

>>> TESTING: smithy card, player 0...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

>>> STATE CHANGES: for all players:

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 5, New: 7
deckCount[0] changed! Orig: 5, New: 2
hand[0][3] changed! Orig: 4, New: 1
hand[0][5] changed! Orig: 0, New: 4
hand[0][6] changed! Orig: 0, New: 4
hand[0][7] changed! Orig: 0, New: -1

>>> STATE CHANGES: specific to player 1:

>>> TESTING: smithy card, player 1...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

>>> STATE CHANGES: for all players:
whoseTurn changed! Orig: 0, New: 1

>>> STATE CHANGES: specific to player 0:

>>> STATE CHANGES: specific to player 1:
handCount[1] changed! Orig: 0, New: 2
deckCount[1] changed! Orig: 10, New: 7
hand[1][0] changed! Orig: 0, New: 4
hand[1][1] changed! Orig: 0, New: 4
hand[1][2] changed! Orig: 0, New: -1

----------------------------------------------------

Random Test: playAdventureCard()

FAIL incorrect number of cards discarded
- Worth noting: if deck size was tiny, discard tests occasionally passed:
  Size 9: fail
  Size 8: fail
  Size 7: pass
  Size 6: pass
  Size 5: pass
  Size 4: pass player 0, fail player 1 
      >>> STATE CHANGES: specific to player 1:
      handCount[1] changed! Orig: 0, New: 1
      deckCount[1] changed! Orig: 4, New: 0
      hand[1][0] changed! Orig: 5, New: 4
      hand[1][1] changed! Orig: 4, New: 12
  Size 3: fail
  Size 2: pass
  Size 1: fail
  Size 0: fail
- Also, if the deck size is not manipulated and the tests are run with
  default states, discard tests passed for player 0 but failed for player
  1.

