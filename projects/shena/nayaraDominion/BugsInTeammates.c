/*
Nayara Test Results
===================

cardtest1.c
	This tested the Smithy Card. Test ran without a hitch. No bugs were found.

cardtest2.c
	This tested the Adventurer Card. Test ran without a hitch.
	Bugs found:
		1. Deck is not properly resized
		2. Cards are not properly discarded
		
cardtest3.c
	This tested the Village Card. Test ran without a hitch.
	Bugs found:
		1. numActions not properly increased when card is played
	
cardtest4.c
	This tested the Great Hall card. Test ran without a hitch.
	Bugs found:
		1. Card count not properly adjusted
		
unittest1.c
	This tested the isGameOver() function. Test ran without a hitch. No bugs were found.
	
unittest2.c
	This tested the supplyCount() funciton. Test ran without a hitch. No bugs were found.
	
unittest3.c
	This tested the shuffle() function. Test ran without a hitch. No bugs were found.
	
unittest4.c
	This tested the newGame() function. Test ran without a hitch. No bugs were found.
	
randomtestadventurer.c
	This was a random test for the Adventurer Card. The test was never able to run completely.
	Bugs caught before segmentation fault:
		1. Adventurer Effect failed to increase number of cards

randomtestcard.c
	This was a random card test for the Steward Card.
	1000/1000 tests failed.
	Bugs caught:
		1. Failed to increase number of coins by 2.
		2. Failed to trash 2 cards.
*/