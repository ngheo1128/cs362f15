/******BUGSINTEAMMATES.c******

Teammate 1 - James Carlin

Bug 1
Test: cardtest2.c
Location: Adventurer Card
Description: 
			Calling this function increases drawntreasure by 2 rather than one if a treasure is drawn. 
			Also, the loop for discarding temphand starts at z rather than z-1.
Conditions to reproduce:
			At least 1 treasure drawn

Bug 2
Test: cardtest1.c
Location: Smithy Card
Description:
			Since the loop is set to i > 3, it never executes, and cards are never drawn.
Conditions to reproduce:
			Smithy card played

Bug 3
Test: cardtest3.c
Location: Village Card
Description: 
			Displayed no observable bugs on testing. However, inspection of the source code revealed
			that the function returns 1 instead of 0, leading to effects further in the program
Conditions to reproduce
			Village card played
			playCard() requires a value from cardEffect()

Bug 4
Test: cardtest4.c
Location: Great Hall
Description: 
			Calling this function increases the number of actions by 2 instead of 1
Conditions to reproduce:
			Great Hall card played

------------------------------------

Teammate 2 - Brian Tiegs

Bug 1
Test: cardtest1.c
Location: Smithy Card
Description:
			Calling smithy() never results in the player drawing cards.
			The player's hand count and discard count stays the same.
Conditions to reproduce:
			Smithy card played
			Hand count and discard count both 0

Bug 2
Test: cardtest2.c
Location: Adventurer Card
Description: 
			Calling the function removes 3 cards from the player's
			hand, even if the player has no cards (shows -3 cards in hand)
Conditions to reproduce:
			Player's hand has 0 cards

Bug 3
Test: cardtest3.c
Location: Council Room Card
Description: 
			Calling the function results in Player 0's hand
			increasing by 4 cards. Player 1's hand never increases
Conditions to reproduce:
			Player 0's hand has at least 1 card
			At least 2 players exist

Bug 4
Test: cardtest4.c
Location: Baron Card
Description: 
			The number of coins does not increase. It's always at 4.
Conditions to reproduce:
			Baron card played
*/

//end of BugsInTeammates.c