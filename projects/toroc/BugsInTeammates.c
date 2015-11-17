/* 

	Teammate1

	Teammate1 introduced bugs into the following card implementations: 
	Smithy, Adventurer, Village, Council Room, and Great Hall. Of the 5 implementations, 
	at least 1 test failed for the following four cards: Smithy, Village, Council Room, 
	and Great Hall.
	
	Running my tests against this team mate's code was fairly easy as I never directly 
	called the functions for the implementation but rather made sure to call the playCard 
	function with the card being tested. 
	
	
	These are the results from my teammate1results.out:
	
	Smithy
		Starting Test #1 - player only receives 3 cards after playing smithy  
		Game state = 9, Expected state = 7
		Test #1 FAILED! Player did not receive only 3 cards.
		***This test failed as a result of the bug introduced by teammate1.
		
		Starting Test #2 - smithy card is discarded & replaced by correct card 
		Received card: estate, Expected card: copper 
		Test #2 FAILED! Smithy was not replaced by correct card!
		***This failure is due to the extra cards that were added to the player's hand.
		
	Council Room
		Starting Test #7 - ensure player only receives 1 buy 
		Current buys = 3, Expected buys = 2
		Test #7 FAILED! Player did not receive additional buy. 
		***This test failed as result of the bug introduced by teammate1.
	Great Hall
		Starting Test #1 - player receives 1 card after playing Great Hall 
		Game state = 6, Expected state = 5
		Test #1 FAILED! Player did not receive 1 card.
		***This test failed as result of the bug introduced by teammate1.
	
	Village
		Starting Test #1 - player receives 2 additional actions 
		Current actions = 4, Expected actions = 2
		Test #1 FAILED! Player did not receive 2 actions from Village.
		***This test failed as result of the bug introduced by teammate1.

	Teammate2
	
	Teammate2 introduced bugs into the following card implementations: 
	Smithy, Adventurer, Village, Council Room, and Gardens. Of the 5 implementations, 
	at least 1 test failed for the following four cards: Smithy, Adventurer, Village, 
	and Council Room.
	
	Running my card tests against this team mate's code was fairly easy and I did
	not need to make any edits to my tests. While my card test for Adventurer was
	able to run the first two tests, due to the bug introduced into Adventurer,
	the third test kept encountering a segmentation fault.
	
	These are the results from my teammate2results.out
	
	Smithy
		Starting Test #1 - player only receives 3 cards after playing smithy 
		Game state = 6, Expected state = 7
		Test #1 FAILED! Player did not receive 3 cards.
		***This test failed as result of the bug introduced by teammate2.
		
		Starting Test #6 - ensure player doesn't receive additional actions 
		Current actions = 1, Expected actions = 0
		Test #6 FAILED! Player had additional actions.
	
	Adventurer
		Starting Test #1 - player receives first 2 treasure cards
         Current card = curse, Expected card = silver
         Current card = curse, Expected card = silver
		Test #1 FAILED! Player did not receive expected cards.
		***This test failed as result of the bug introduced by teammate2.

		Starting Test #2 - player receives treasures from own deck
         Current card = 0, Expected card = 4
         Current card = 0, Expected card = 4
		Test #2 FAILED! Player did not receive treasure cards from own deck.

	Council Room
		Starting Test #1 - player receives 4 cards after playing CouncilRoom 
		Game state = 9, Expected state = 8
		Test #1 FAILED! Player did not receive 4 cards.
		***This test failed as result of the bug introduced by teammate2.

		Starting Test #2 - council room card is discarded & replaced by correct card 
		Received card: estate, Expected card: copper 
		Test #2 FAILED! CouncilRoom was not replaced by correct card!
		

	Village
		Starting Test #1 - player receives 2 additional actions 
		Current actions = 1, Expected actions = 2
		Test #1 FAILED! Player did not receive 2 actions from Village.
		***This test failed as result of the bug introduced by teammate2.
*/ 
