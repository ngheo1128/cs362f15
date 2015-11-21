**shena dominion

* Smithy Card
Bug found: Hand count is increased by 4 cards instead of 3
Unit/Random testing output:

Hand count. Expected 3, received 4
Assertion failed: (G.handCount[p] == handCount + 2), function main, file cardtest1.c, line 100.


Bug found: Deck count is decreased by 4 cards instead of 3
Unit/Random testing output:
Deck Count. Expected 7, received 6
Assertion failed: (G.deckCount[p] == 7), function main, file cardtest1.c, line 110.

* Adventurer card

Bug found: Gold card is not recognized by function
Unit/Random testing output:

(Gold card not found in hand)
Checking for first gold card. Expected 6, received 5
Assertion failed: (G.hand[p][G.handCount[p] -2] == gold), function main, file cardtest2.c, line 190.

(Gold card not found in hand)
Checking for second gold card. Expected 6, received 1
Assertion failed: (G.hand[p][G.handCount[p] -2] == gold), function main, file cardtest2.c, line 198

(Two cards were not added to hand when testing for gold)
Checking for new hand count:  Expected -1, received 3
Assertion failed: (G.handCount[p] == handCount+2), function main, file cardtest2.c, line 207.

(Deck count was not incremented correctly when testing for gold)
Deck Count. Expected 497, received 0
Assertion failed: (G.deckCount[p] == MAX_DECK-3), function main, file cardtest2.c, line 216.

* Village card:

Actions are only increased by 1
Num actions. Expected 7, received 6
FAILURE: Number of actions do not match







**miltons dominion

*Smithy card 

Bug found: Hand count is increased by 4 cards instead of 3
Unit/Random testing output:

Hand count. Expected 3, received 4
Assertion failed: (G.handCount[p] == handCount + 2), function main, file cardtest1.c, line 100.


Bug found: Deck count is decreased by 4 cards instead of 3
Unit/Random testing output:

Deck Count. Expected 7, received 6
Assertion failed: (G.deckCount[p] == 7), function main, file cardtest1.c, line 110.

*Adventurer Card

First, there was a compilation warning:

    if (cardDrawn = copper || cardDrawn == silver || cardDrawn == gold)


Bug found: This is leading to false positives when testing for treasure cards. The deck is not decreased correctly and the treasure cards are not added to the hand.

Unit/Random testing output:
Failure: Deck Count. Expected 497, received 498
FAILURE: Checking for first copper card. Expected 4, received 8

*Council room

No bugs found
