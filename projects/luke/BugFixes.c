/*Kenny Lu
November 21, 2015
CS362
Assignment 5

Documentation of the bug fixes in my dominion.c code

----------------------------------------------------------------------------------------------------------
Teammate Accompanied Bugs Fixed:
----------------------------------------------------------------------------------------------------------

Bug 1 Fixed:  The first bug that was addressed was brought up by both of my teammates
in the smithy card function.  My teammates believed that the for loop that gives the player
three new cards is initalized with i at 1 instead of 0.  This adds only two new cards to the hand.
In addition, the discardCount = 0 when it should be 1 since the smithy card should have been discarded.
Finally, the deckCount = 3 when it should be 2 because the for loop only added two new cards rather than 3
indicating that one extra card is in the deck than the normal amount (one card is missing from the hand).

I addressed this bug by first by changing my first for loop initalizer to 0 instead of 1.  This lets
the smithyCard function draw the normal amount of 3 cards instead of 2 that the current buggy version does.

Bug 2 Fixed: The second bug was addressed by my teammate Ashley Greenacre in which her cardtest3 failed which
found a bug in the village card function. 

I addressed this bug by removing a redundant drawCard method inside of the village card function which finally
yields the correct amount of cards being drawn.  This yields the correct of amount of cards drawn by the correct
version of the village card (+1 card).

Bug 3 Fixed:  The third bug was addressed by my teammate Savannah Giese in which her unit test catered for the
great hall function failed.  She explained that when the card gets to the point to discard a card, it never increases
the discard count.  She further explained that when she checks the pre-discard count vs the post-discard count, the
number would be the exact same.  This means that the discard function never increased the discard count.

I looked at my dominion code for an error in this function but I could not find any fault.  The discardCard method
was called after the correct actions of the great hall function (+1 card, +1 action, then discard the card).

----------------------------------------------------------------------------------------------------------
Bugs Fixed that I Introduced Earlier:
----------------------------------------------------------------------------------------------------------

Bug 1 Fixed: I fixed a bug in the adventurer card function that drew 3 treasures instead of 2.  The reason
for this bug was because in the while loop, the loop persists only when drawntreasure <= 2.  Because drawntreasure
starts at 0, this makes it so that three treasure cards are drawn instead of 2.  I fixed this bug by changing the
while loop conditional to drawntreasure < 2 so that when two treasure are drawn, the loop exits.

Bug 2 Fixed: I fixed a bug in the steward card function that discards the same two cards when it should 
discard two different card choices.  This was fixed by fixing the redundant discardCard(choice2, currentPlayer, state, 1)
method and changing the choice2 parameter to choice 3.  This change yields two different cards to be discarded
instead of the same one.

Bug 3 Fixed:  I fixed a bug in the baron card function where the buggy code increases a current player's handCount
instead of decreasing it after the card is played.  This yielded an incorrect number of hand cards because the played card
yields an opposite effect on the count.  Changing the state->handCount[currentPlayer]; so that it decrements instead of
increments solves this issue.
*/


