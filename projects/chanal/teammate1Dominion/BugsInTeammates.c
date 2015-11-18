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

********No other card tests can be ran on my teammate's code since I did not do an Embargo or Steward card test.*******
----------------------------------------------------------------------------------------------------------------------------------------------------

My randomtestAdventurer (tests adventurer) test results:
	My test was able to pick up the same bugs as my cardtest2 as all tests failed. The bug was that adventurer was not discarded from hand after play and
	the number of treasure cards drawn is incorrect. For more info, refer to cardtest2 for some inconsistencies that I noticed in my teammate's code. 
		-Test failed for adventurer card not discarded after play 27093 of 27093 tests
		-Test failed for incorrect drawn treasure in hand 27093 of 27093 tests
------------------------------------------------------------------------------------------------------------------------------------------

My randomtestcard (tests smithy) test results:
	My test had split results where 17340 of 28936 tests, the incorrect amount of cards were drawn after smithy and 17340 of 28936 tests, smithy
	was not discarded from the hand after play. As there was not buggy code introduced into dominion.c for playSmithy, the tests should all have passed,
	however, with random tests, bugs may have been found due to the randomly generated values besides the player's hand containing smithy. 
		-Test failed for incorrect number of cards drawn 17430 of 28936 tests
		-Test failed for smithy not discarded from hand 17430 of 28936 tests