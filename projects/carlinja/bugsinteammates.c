James Carlin
Assignment 5


Brian Tiegs' Bugs:

Cardtest1.c

	This card tests the smithy card function. 
	Bug:
		Found bug where card are not added to hand. Supposed to add 3.

	My test finds this bug by placing a static amount of cards in a player's hand, then goes through if statements
	to see if cards were added, and then the smithy card discarded
	I use the handCount of the player to see changes
CardTest4.c

	This card tests the adventurer function.
	Bug:
		Found bug where handCount is not being updated
	My test finds this bug by placing a static amount of cards into a player's hand. Since I know the amount
	Of cards that should be in the player's hand, I test to see if they are being added.
	There should be 2 added cards to the player's hand, it fails the test to see if that works




Aditya Gunea Bugs:

CardTest1.c
	This tests the Smithy Card

	Bug:
		Found bug where cards are not being added correctly to player's hand.
		This is the same bug that I found in Brian's cards. My test places a static amount of cards
		input a player's hand, which allows me to test the outcomes of the cards.
		Knowing how many cards there should be, the Smithy card was found to not add the correct amount of player's hands

CardTest4.c
	This card tests the adventurer card

Bug:	
	FOund bug where handcount is not updated correctly.

	THis bug is slightly different than Brian's bug. Cards were never placed in discard pile, they just stayed in player's hands.

	Same method found this card. With a static hand count, it is easy to see how many cards should be in a player's hand after playing this card. The card failed all iterations of my tests

	