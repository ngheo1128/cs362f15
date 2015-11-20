Dustin Dinh
CS 362 Assignment 5

Bug Report For Jason Flaig 
***********************************  Adventurer Card  ***********************************
1)	Description: Adventurer card did not go into discard pile after being played. 
	Card remains in hand.

	How to replicate: Play Adventurer card from any position in hand. 

2) 	Description: Wrong type and number of coins drawn into hand.

	How to replicate: Randomly populate deck with cards including all three coin types.
	Peek into top cards of deck until 2 coins are discovered. Record the value of those
	coins. Compare the expected value to the actual value of coins in hand


***********************************  Smithy Card  ***********************************

1) 	Description: Received 1 extra card. In test, hand size was 8 instead of 7.

	How to replicate: Call Smithy from any position in hand.

2)	Description: Card drawn hand does not match the first 3 cards on top of deck.

	How to replicate: Peek at the top 3 cards of the deck. Make note of the cards.
	Call Smithy and examine cards drawn in hand. 


***********************************  Mine Card  ***********************************
1) 	Description: Cannot swap a higher costing coin for a lower or equivalent
	costing coin.

	How to replicate: Swap a silver for a copper. 

2)	Description: Mine card remains in hand when played.
	
	How to replicate: Play mine card from last position in hand. 	

3)	Description: Swapped coin is missing from played area.

	How to replicate: Play mine card from last position with a legal treasure card.

4) 	Description: Mine card missing from played. 

	How to replicate: Play mine card from last position in hand.

***********************************  Minion Card  ***********************************

1)	Description: Bonus coins not received when choice 1 made.

	How to replicate: for parameters choice1 = 1, and choice2 = 0 when playing card. 

2)	Description: Player 2 does not discard their cards when minion is played.

	How to replicate: for parameters choice1 = 0, and choice2 = 1 when playing card. Player 2
	must have 5 or more cards.

***********************************  isGameOver  ***********************************

1)	Description: Depletion of Sea Hag plus 2 other piles does not end the game.

	How to replicate: Deplete Curse and Estate, then deplete Sea Hag supply. Call isGameOver.

2)	Description: Depletion of Treasure Map plus 2 other piles does not end the game.

	How to replicate: Deplete Curse and Estate, then deplete Treasure Map supply. Call isGameOver.


***********************************  scoreFor  ***********************************

1)	Description: Deck points are not scored correctly. 

	How to replicate: Add a known quantity of victory point cards to deck. The hand and discard should
	not have any victory points in them. Then call scoreFor.

2) Description: Discard points are not scored correctly.

	How to replicate: Add a known quantity of victory point cards to discard. The hand and deck should
	not have any victory points in them. Then call scoreFor.

Bug Report For Kelvin Watson

***********************************  Adventurer Card  ***********************************
1)	Description: Adventurer card did not go into discard pile after being played. 
	Card remains in hand.

	How to replicate: Play Adventurer card from any position in hand. 