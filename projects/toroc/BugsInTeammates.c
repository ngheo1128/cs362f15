/* 
Summary: 
	Overall my tests were able to detect bugs in 4 cards for Kevin's implementation
	and 4 cards for Sean's implementation of dominion.c. For Sean's implementation 
	multiple tests failed for the same card, which lead me to believe there are 
	multiple bugs affecting his implementation of the cards.

###################	
Teammate1: Kevin To
###################
	Running my tests against this team-mate's code was fairly easy as I never directly 
	called the functions for the implementation but rather made sure to call the playCard 
	function with the card being tested. As a result of doing this, I didn't need to make
	any changes to my tests. 
	
	For Kevin's implementation of dominion.c, my tests were able to detect bugs for the 
	following cards: Smithy, Village, Council Room, and Great Hall. For the adventurer test, 
	I even used the randomtestadventurer and was still unable to find a bug in the implementation.
	
	
	These are the results from my teammate1results.out:
	
	Smithy
		Starting Test #1 - player only receives 3 cards after playing smithy  
		Game state = 9, Expected state = 7
		Test #1 FAILED! Player did not receive only 3 cards.
		***This test failed as a result of the player receiving more than 3 cards.
		
		Starting Test #2 - smithy card is discarded & replaced by correct card 
		Received card: estate, Expected card: copper 
		Test #2 FAILED! Smithy was not replaced by correct card!
		***This test failed due to the extra cards that were added to the player's hand.
		
	Council Room
		Starting Test #7 - ensure player only receives 1 buy 
		Current buys = 3, Expected buys = 2
		Test #7 FAILED! Player did not receive additional buy. 
		***This test failed because the player received 2 additional buys.
		
	Great Hall
		Starting Test #1 - player receives 1 card after playing Great Hall 
		Game state = 6, Expected state = 5
		Test #1 FAILED! Player did not receive 1 card.
		***This test failed because player received more than 1 card.
	
	Village
		Starting Test #1 - player receives 2 additional actions 
		Current actions = 4, Expected actions = 2
		Test #1 FAILED! Player did not receive 2 actions from Village.
		***This test failed as result of the bug introduced by teammate1.

###########################	
Teammate2: Sean Harrington
###########################	
	Running my card tests against this team mate's code was fairly easy and I did
	not need to make any edits to my tests. However, while my card test for Adventurer was
	able to run the first two tests, the third test kept encountering a segmentation fault.
	To offset this problem, I also ran the randomtestadventurer test against the implementation,
	which kept timing out. I used GDB to figure out if it was my test that was timing out but it
	turns out that it was my teammate's dominion file line 661.
	
	For Sean's implementation of dominion.c, my tests were able to detect multiple bugs for the 
	following cards: Smithy, Adventurer, Village, and Council Room.
	
	These are the results from my teammate2results.out
	
	Smithy
		Starting Test #1 - player only receives 3 cards after playing smithy 
		Game state = 6, Expected state = 7
		Test #1 FAILED! Player did not receive 3 cards.
		***This test failed because the player received less than 3 cards.
		
		Starting Test #3 - player draws cards from own deck 
		Received card: copper, Expected card: copper 
		Received card: curse, Expected card: copper 
		Received card: copper, Expected card: estate 
		Test #3 FAILED! Cards not drawn from player's deck! 
		***This test failed due to the extra cards that were added to the player's hand.
		
		Starting Test #6 - ensure player doesn't receive additional actions 
		Current actions = 1, Expected actions = 0
		Test #6 FAILED! Player had additional actions.
		***This test failed because the player still had an action despite playing the Smithy card.
		Player is receiving additional action after playing Smithy.
		
		Starting Test #7 - ensure player doesn't receive additional buys 
		Current buys = 2, Expected buys = 1
		Test #7 FAILED! Player had additional buys.
		***This test failed since Smithy doesn't grant additional buys and player is receiving
		additional buys after playing Smithy.
	
	Adventurer
		Starting Test #1 - player receives first 2 treasure cards
        Current card = curse, Expected card = silver
        Current card = curse, Expected card = silver
		Test #1 FAILED! Player did not receive expected cards.
		***This test failed because the player did not receive the correct 
		treasure card that was in their deck.

		Starting Test #2 - player receives treasures from own deck
        Current card = 0, Expected card = 4
        Current card = 0, Expected card = 4
		Test #2 FAILED! Player did not receive treasure cards from own deck.
		***This test failed due to the wrong cards that were added to the player's hand.

	Council Room
		Starting Test #1 - player receives 4 cards after playing CouncilRoom 
		Game state = 9, Expected state = 8
		Test #1 FAILED! Player did not receive 4 cards.
		***This test failed because the player received more than 4 cards.

		Starting Test #2 - council room card is discarded & replaced by correct card 
		Received card: estate, Expected card: copper 
		Test #2 FAILED! CouncilRoom was not replaced by correct card!
		***This test failed due to the extra cards that were added to the player's hand.

	Village
		Starting Test #1 - player receives 2 additional actions 
		Current actions = 1, Expected actions = 2
		Test #1 FAILED! Player did not receive 2 actions from Village.
		***This test failed because player did not receive the 2 actions from card.
		
		Starting Test #3 - Village card is discarded & replaced by correct card 
		Received card: silver, Expected card: estate 
		Test #3 FAILED! Village was not replaced by correct card! 
		***This test failed because player's estate is being replaced by a treasure.
		
		Starting Test #7 - ensure player doesn't receive additional buys 
		Current buys = 2, Expected buys = 1
		Test #7 FAILED! Player had additional buys. 
		***This test failed as player is receiving additional buys after playing Village card.
*/ 
