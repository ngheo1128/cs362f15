/*
Bug #1:
Using cardtest1.c bug found in smithyEffect at ln 1252. 

Two cards drawn instead of three. This was found as the
handCount after the function was 1 greater instead of 2 greater than before.

Bug #2:

Using cardtest2.c bug found in adventurerEffect at ln 1260.

Adventurer is not discarded at the end of the function. This bug was found by testing
the current player's handCount before and after calling the adventurerEffect function.

Bug #3: 

Using randomtestacdenturer.c bug found in adventurerEffect.

A test to see if there are at least 2 treasure cards in the deck + discard needs to be added.
Right now the test runs forever and has a segmentation fault.

Bug #4: 
Using randomtestcard.c bug found in smithyEffect.

A test to see if there are at least 3 cards available to be drawn. Either in the
deck or discard. If not, not enough cards are added to the hand at the end of the function.


*/
