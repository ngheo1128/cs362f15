/******************************
Susan Lee
CS 362_400_Fall15
Assignment5 – BugsInTeammates.c
*******************************/


/*********************
NOTES
**********************/
Had to comment out code in my test adventurer random test that relies on a
return value from the adventurer function.  Some of the tests relied on the 
return value indicating the number of cards cycled through.  Since there is 
no way for me to alter my teammates' code and no other way for me to retrieve 
this value on my isolated end, I simply commented out the sections involving 
this check.  This will most likely lessen the coverage of my tests.


/*********************
CARD TEST 1: SMITHY
**********************/
LAMEREB BUGS:
- Discard count always 0, indicating an issue with discarding the smithy card.


RATCLIER BUGS:
-Discard count always 0, indicating an issue with discarding the smithy card.


/*********************
CARD TEST 2: ADVENTURER
**********************/
LAMEREB BUGS:
-Hand count 1 less than expected and adventurer card not discarded, indicating
that there is something wrong with the discard function.
-Treasurer card not added to hand for some cases

RATCLIER BUGS:
-Deck count always 0 and discard count equal to size of deck indicates a problem 
with the exit condition of the while loop for drawn treasure.
-Flags for treasurer card not added to hand, but 1 more card in hand than expected 
indicate that the treasurer card is not in the expected position in the hand.
- Hand count 1 more than expected indicates issue with removing adventurer card
from player's hand after it's played.

/*********************
CARD TEST 3: COUNCIL ROOM
**********************/
LAMEREB BUGS:
-Discard count always 0, indicating an issue with discarding the council room card.

RATCLIER BUGS - NOT A REFACTORED CARD:
-Discard count always 0, indicating an issue with discarding the council room card.

/*********************
CARD TEST 4: VILLAGE
**********************/
LAMEREB BUGS:
-Hand count and deck count 1 less than expected, and unexpected card added to 
hand all indicate that one more card was drawn from the deck and placed in the 
player's hand
-Discard count always 0 indicates that the Village Card was not appropriately 
discarded

RATCLIER BUGS - NOT A REFACTORED CARD:
Discard count always 0, indicating an issue with discarding the council room card.


/*********************
UNIT TESTS: 1-4
**********************/
No failures for either teammate.


/*********************
RANDOM TEST: ADVENTURER
**********************/
LAMEREB BUGS:
-Some tests show unexpected treasure count.  This indicates there is either an 
uncovered case in your code, or a bug having to do with a certain situation in 
the addition of the treasure card to the player's hand.
- Hand count and adventurer card card failures for all random cases indicate 
that there is a problem with removing the adventurer card from the player's 
hand after the card is played.

RATCLIER BUGS:
-Tests ran for some cases, and then eventually seg faulted.  Given what we know 
from the unit tests, there might be an issue with exiting out of the treasure 
while loop in your code.  I tried to isolate the exact cause by manipulating the
gamestate members, but kept running across a seg fault.
-For the cases that did run, it's hard to detect a pattern, but if you make the
bug fixes discovered in the unit tests, these random tests will be able to generate
more meaningful data on any remaining bugs.

/*********************
RANDOM TESTS: COUNCIL ROOM
**********************/
LAMEREB BUGS:
-Discard and Council count failures for all cases indicate that the card is 
not being properly removed from the player's hand.

RATCLIER BUGS - NOT A REFACTORED CARD:
-Council count is 1 more than expected, and discard count is 1 less than expected
for all cases indicates an issue with discarding the council room card.
