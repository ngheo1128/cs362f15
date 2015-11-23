-----------------------------------------------------------------------
Teammate 2 (Brian) bugs:
-----------------------------------------------------------------------

Card Test 1: playSmithyCard()

>>> TESTING: smithy card, player 0...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

>>> TESTING: smithy card, player 1...
playSmithyCard: FAIL discarded card did not end up on played pile (not incremented)

----------------------------------------------------

Card Test 3: cardEffect(treasure_map)
Random Test: cardEffect(treasure_map)

>>> TESTING: one treasure map card...
treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck

----------------------------------------------------

Random Test: playAdventureCard()

FAIL incorrect number of cards discarded
- Worth noting: if deck size was tiny, discard tests occasionally passed.

-----------------------------------------------------------------------
Supplemental information for Teammate 2 bugs:
-----------------------------------------------------------------------


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

Card Test 3: cardEffect(treasure_map)

>>> TESTING: one treasure map card...
treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck

>>> STATE CHANGES: for all players:
supplyCount[6] changed! Orig: 30, New: 26

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 6, New: 4
deckCount[0] changed! Orig: 5, New: 9
hand[0][4] changed! Orig: 4, New: -1
deck[0][5] changed! Orig: 4, New: 6
deck[0][6] changed! Orig: 4, New: 6
deck[0][7] changed! Orig: 4, New: 6
deck[0][8] changed! Orig: 1, New: 6

>>> STATE CHANGES: specific to player 1:

>>> TESTING: two treasure map cards...
treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck

>>> STATE CHANGES: for all players:
supplyCount[6] changed! Orig: 30, New: 26

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 7, New: 5
deckCount[0] changed! Orig: 5, New: 9
hand[0][4] changed! Orig: 4, New: 26
hand[0][5] changed! Orig: 26, New: -1
hand[0][6] changed! Orig: 26, New: -1
deck[0][5] changed! Orig: 4, New: 6
deck[0][6] changed! Orig: 4, New: 6
deck[0][7] changed! Orig: 4, New: 6
deck[0][8] changed! Orig: 1, New: 6



Random Test: cardEffect(treasure_map) (A SAMPLE OF STATE CHANGES)

treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck

>>> STATE CHANGES: for all players:
supplyCount[6] changed! Orig: 30, New: 26

>>> STATE CHANGES: specific to player 0:
handCount[0] changed! Orig: 6, New: 4
deckCount[0] changed! Orig: 327, New: 331
hand[0][4] changed! Orig: 4, New: -1
deck[0][327] changed! Orig: 0, New: 6
deck[0][328] changed! Orig: 0, New: 6
deck[0][329] changed! Orig: 0, New: 6
deck[0][330] changed! Orig: 0, New: 6

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

