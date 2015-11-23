/*

Rachael McConnell
Assignment 5
CS362 Fall 2015

BUGS FIXED

Smithy
	Bug 1: 3 cards are drawn instead of 2. The handCount is incremented by 2, instead of 1 (+3 drawn cards, -1 for discarding smithy card).
	Bug 1 Fix: This was a bug introduced by me. I simply changed the loop that calls drawCard() to draw 2 cards instead of 3
	Bug 2: Smithy card is discarded
	Bug 2 Fix: Added a line to call the discardCard() function
	Bug 3: Discard count is now incremented 
	Bug 3 Fix: I edited the discardCard() function to increment discardCount

Adventurer
	Bug 1: Adventurer card is not discarded from the player's hand.
	Bug 1 Fix: Added discardCard at end of function to discard the adventurer card from the player's hand
	Bug 2: treasureCards increments when an estate card, which is not a treasure card, is found. It should only increment for the treasure cards (copper, silver and gold).
	Bug 2 Fix: This was a bug introduced by me. I simply changed cardDrawn back to copper, SILVER, and gold.
	Bug 3: Discard count did not increment correctly.
	Bug 3 Fix: I edited the discardCard() function to increment discardCount.

Feast
	Bug 1: In the updateCoins function call, bonus is only 4 instead of 5.
	Bug 1 Fix: This is a bug that I introduced. In the updateCoins() function call, I changed the bonus to be equal to 5 instead of 4.

discardCard
	Bug 1: discardCount is not incremented in this function.
	Bug 1 Fix: I edited the discardCard() function to increment discardCount. 

Steward
	Bug 1: If choice = 1, player gets 2 coins. If choice = 2, player draws 2 cards. These options need to be switched.
	Bug 1 Fix: This is a bug that I introduced. I switched the choices in the if, else if statements, so I switched them back to the correct version.

isGameOver
	Bug 1: The function does not account for the last 3 cards.
	Bug 1 Fix: I changed it so the loop goes from 0->27 instead of 0->24. Now all cards are accounted for.


GreatHall
	Bug 1: Once the card is used, it should be discarded and discardCount should increment. It is not incrementing.
	Bug 1 Fix: I edited the discardCard() function to increment discardCount.


*/