/*

Rachael McConnell
Assignment 5
CS362 Fall 2015

Both teammates' code passed unittest1 (shuffle), unittest2 (updateCoins), and cardtest3 (council room), and failed parts of the remaining tests. For the
tests that failed, here are the bugs found:
	
	
Teammate 1 (Jeff Moss)

isGameOver: 
	-The test failed when cards #25, 26, &/or 27 were selected.

discardCard: 
	-The discardCount did not increase by 1.

Smithy: 
	-The handCount is incorrect. It should increase by 2 (+3 cards drawn, -1 from discarding the smithy card).
	-The smithy card is not discarded.
	-The deckCount decreases by 4 instead of 3.

Adventurer: 
	-The adventurerCard is not discarded.
	-The playedCard count did not increase by 1. 
	-The discardCount did not increase as expected.
	
Village:
	-The number of actions did not decrease by 1 as was expected.
	

Teammate 2 (Wilson Chan)

isGameOver: 
	-The test failed when cards #25, 26, &/or 27 were selected.

discardCard:
	-The discardCount did not increase by 1.

Adventurer:
	-The adventurerCard is not discarded.	
	-The number of treasure cards in the player's hand did not increase by 2.

Village:
	-The number of actions did not increase by 1 as was expected.

*/