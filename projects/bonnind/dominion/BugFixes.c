Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
BugFixes.c

This file contains documentation of the bug fixes I completed for 
Assignment 5.

**************************
Bugs found by teammates: 
**************************
**
SmithyCard() not drawing enough cards.

The loop was iterating 1 too few times. I adjusted the loop to iterate 3 times
which has fixed the bug. 

**
villageCard() incrementing numActions by more than correct amount when 
numActions is greater than 0. 

I adjusted the line that handles the incrementing of numActions. Now, it 
increments numActions by 2 in every case. 

**
drawCard() does not report an error on empty deck/discard. 

I fixed this bug by adding a check for empty deck and empty discard. 
Now, drawCard returns -1 if both discard and deck are empty. 

**
adventurerCard() does not discard the played Adventurer card.

I fixed this bug be adding a handPos parameter to the function, and calling
discardCard() before returning the function. 

*************************
Bugs introduced by me:
*************************

**
adventurerCard() had a bug that changed every card drawn to copper. The fault 
was in the comparison that checked each card for equality with the 3 types of
treasure card. Instead of comparing (if (cardDrawn == copper)), it assigned 
(if (cardDrawn = copper)). The assignment returns true and sets the card to 
copper. 

I fixed this bug by changing the assignment operator to a comparison operator. 

**
greatHallCard() calls drawCard on the wrong player if the player is not 
player 0. 

This bug causes drawCard() to be invoked on the player number 1 less than the
current player, unless the current player is 0. 

I fixed this bug by changing the first argument in drawCard() to curPlayer 
from the ternary statement it had been. 

**
cutPurseCard() does not show opponents hand when he does not have a copper card.

The for loop that checks each opponents` hand for copper card never gets to 
the condition that triggers the hand to print. 

I fixed this bug by changing the comparison operator from < to <=. 

Now, when the opponent has no copper cards in his hand, the cards are revealed. 

**
adventurerCard() segfaults on empty deck. 

adventurerCard() was unnecessarily calling shuffle(), which is handled 
automatically in drawCard. Also, drawCard() wasn't handling the empty deck/empty
playedCards case. 

I fixed a bug in drawcard in order to return an error in this case, and to 
move played cards back into deck if discard pile and deck are empty. 

I removed the shuffle() call from adventurerCard() since it is redundant. 

**
isGameOver() not returning true with 3 empty card types if 1 type is 
treasure_map. 

The loop does not cover all card types.

I fixed this bug by changing the terminating condition from 25, to treasure_map
+ 1, which equals 27.

