//Author: Allan Chan
//ONID: chanal
//Class: CS362
//Filename: BugsInTeammates.c
//Description: Bug report for teammate1Dominion brandej's dominion code
//-------------------------------------------------------------------------

My cardtest1 (tests smithy) test results:
	All my tests passed for smithy where I tested if the handcount was correct after drawing +3 cards, and if smithy was discarded. 
	I noticed some inconsistencies where refactor.c contained a bug introduced where the card drawn should have been +4 with a <= for the for loop,
	however, the bugs were not there in dominion.c and resulted in my tests running with a bug-free smithy code. 
		-Test passed where the player received +3 cards after playing smithy
		-Test passed where smithy is discarded from the player's hand

	**After notifying my teammate, he reuploaded his original dominion.c file that contained the bug in smithy. The test results after running the code were:
		-Test passed, card is present in player 0's hand
		-Test failed, player 0's hand did not receive +3 cards
		-Test passed, smithy is dicarded from player 0's hand after use

----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest2 (tests adventurer) test results:
	I have noticed some bugs in my teammate's code for playAdventurer. For my cardtest2, one of the bugs found was that adventurer was not discarded
	from the player's hand after play. The second bug is that an improper amount of treasure cards is drawn. 

	I double checked to see if their refactor.c/dominion.c if the descriptions match up. I noticed some inconsistencies in the reported number of
	bugs that were introduced and the function definition as well. I noticed that the number of drawn treasure loop was modified, but was not reported in 
	the refactor.c, however, my cardtest2 was able to pick up this bug. 
		-Test failed where adventurer is still in player's hand after playing
		-Test failed for not having the correct number of treasure cards

----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest3 (tests council_room) test results:
	Noticed some inconsistencies in the refactor.c and dominion.c in how playCouncil_Room was defined. 
		playCouncil_Room(int i, int handPos, int currentPlayer, struct gameState *state) //rotated int handPos with int currentPlayer in func definition in refactor.c
		int playCouncil_Room(struct gameState *state, int handPos) 	//in dominion.c

	I have noticed that my teammate was unable to complete his cardtest for this particular card (as noted in their coverage1.c file). For my card test,
	I was unable to find a bug because NO bug was properly introduced to council room as seen in dominion.c.

	My unit test results show that all tests passed in showing that the handcount was correct, the number of cards drawn was correct, the number of
	numBuys is correct and that council room was discarded from hand after play since it was tested with a bug-free council room code.
		-Test passed for council room being discarded from hand after played
		-Test passed for player drawing correct number of cards
		-Test passed for correct incrementation of numBuys (+1)
		-Test passed for council room for being in the played pile

----------------------------------------------------------------------------------------------------------------------------------------------------

My cardtest4 (tests salvager) test results:
	Salvager was not a card my teammate refactored and I called cardeffect to invoke playing salager. The test results for salvager were:
		-Test passed, card is not present in player 0's hand after playing salvager
		-Test passed, player 0 has +1 numBuys
		-Testing passed, 4 cards left in player 0's hand
		-Test failed, current coins is 4.
	Although there was one failed test, I believe that my cardtest is not properly testing the card as the results of current coins varies after
	each run even when I originally tested on my own dominion.
	
----------------------------------------------------------------------------------------------------------------------------------------------------

My randomtestAdventurer (tests adventurer) test results:
	My test was able to pick up the same bugs as my cardtest2 as all tests failed. The bug was that adventurer was not discarded from hand after play and
	the number of treasure cards drawn is incorrect. For more info, refer to cardtest2 for some inconsistencies that I noticed in my teammate's code. 
		-Test failed for adventurer card not discarded after play 27093 of 27093 tests
		-Test failed for incorrect drawn treasure in hand 27093 of 27093 tests
------------------------------------------------------------------------------------------------------------------------------------------

My randomtestcard (tests smithy) test results:
	My test had split results from 25332 tests, the incorrect amount of cards were drawn after smithy and 25332 of 25332 tests, smithy
	was not discarded from the hand after play 16940 of 25332 tests. As there was not buggy code introduced into dominion.c for playSmithy, the tests should all have passed,
	however, with random tests, the randomly generated values besides the player's hand containing smithy may have created test scenarios where discarding was not possible. 
		-Test failed for incorrect number of cards drawn 25332 of 25332 tests
		-Test failed for smithy not discarded from hand 16940 of 25332 tests

------------------------------------------------------------------------------------------------------------------------------------------

My unittest1 passed for update coins method for all my scenarios. 
My unittest2 passed for gameIsOver function for all my scenarios.
My unittest3 passed for shuffle function for all my scenarios.
My unittest4 passed for drawCard function. The test results were:
	-All Tests passed for draw card with non-empty deck
	-All tests passed for draw card with empty deck and non-empty discard pile
	-Some tets failed in draw card for an empty deck and empty discard pile (this was just a boundary test that I originally implmented and doesn't necessarily provide useful information)



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//




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