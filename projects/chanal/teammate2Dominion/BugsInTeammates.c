//Author: Allan Chan
//ONID: chanal
//Class: CS362
//Filename: BugsInTeammates.c
//Description: Contains bugs discovered from teammate's choiwoo dominion code
-------------------------------------------------------------------------

My cardtest1 (tests smithy) test results:
	In the test results for cardtest1, I was able to discover some bugs for smithy. After analyzing their dominion.c code and their refactor.c,
	the bug discovered is one that my teammate introduced.	
		-The test failed in that an improper amount of cards was drawn
		-The test passes in that after playing smithy, the card was discarded from the player's hand
-----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest2 (tests adventurer) test results:
	In the test results for cardtest2, I was able to discover some bugs for adventurer. After analyzing their dominion.c code and their refactor.c,
	the bug discovered is one that my teammate introduced.
		-The test failed in that after playing adventurer, the card was not discarded
		-The test failed in that an improper amount of treasure cards are added to the player's hand
-----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest3 (tests council room) test results:
	In the test results for my cardtest3, I was able to discover a bug for council room. After analyzing their dominion.c code and their refactor.c,
	the bug discovered is one that my teammate introduced. 
		-The test passed in where the player discarded council room after playing the card. 
		-The test failed in the number of cards drawn by the player that played council room
		-The test passed for the number of numBuys incremented (+1)
		-The test passed in where the council room card is in the played pile
-----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest4 (tests salvager) test results:
	-Test passed, card is not present in player's hand after player
	-Test passed for the correct number of numBuys incremented
	-Test passed for discarding salvager after player
	-Test failed for state of current coins
		Although there was one failed test, I believe that my cardtest is not properly testing the card as the results of current coins varies after
		each run even when I originally tested on my own dominion.

-----------------------------------------------------------------------------------------------------------------------------------------------------


My randomtestadventurer (tests adventurer) test results:
	In the test results for randomtestadventurer, I was able to discover the same bugs as described in cardtest2.
		-The test all failed for not discarding adventurer card 23869 or 23869 tests
		-The test all failed for incorrect drawn treasure in hand 23869 of 23869 tests
-----------------------------------------------------------------------------------------------------------------------------------------------------

My randomtestcard (tests smithy) test results:
	In the test results for randomtestcard, I was able to discover the same bugs as described in cardtest1.
		-All 24655 tests failed for incorrect number of cards drawn by player
		-All 24655 tests passed in that after playing smithy, the card was discarded from the player's hand
-----------------------------------------------------------------------------------------------------------------------------------------------------

My unittest1 passed all tests for update coins method.
My unittest2 passed all tests for isGameOver method.
My unittest3 passed all tests for shuffle method.
My unittest4 passed tests for draw card. Tests results were:
	-Tests passed for when player has a non-empty deck
	-Tests passed for when player has an empty deck and non-empty discard pile
	-Some tests failed for where the player had an empty deck and an empty discard pile (this test was to test boundaries when I originally implemented it and does not provide useful information)