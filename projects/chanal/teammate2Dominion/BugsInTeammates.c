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

*******No other cardtest can be ran on teammate's code since I did not do great_hall or villager cardtest*********
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
		