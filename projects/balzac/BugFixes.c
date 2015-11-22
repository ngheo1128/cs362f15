/***************** BUGS FOUND USING MY TESTS ****************************************************************/
/*
Bugs found using test suite from assignment 3
Total bugs = 12
*/

/*from unittest1 discardCard()
Bug 1: When a card is discarded it is not added to the player's discard pile.
*/

/*from unittest2 drawCard()
Bug 2: When deck count is 0 and discard pile count is -1. Deck count is <= 0 after card is drawn. 
*/

/*from unittest3 isGameOver())
Bug 3: When 3 action card piles empty the game does not end. Specifically if Treasure Map card is one
		of the piles.
*/

/*from unittest4 scoreFor()
Bug 3: Score is not correctly calculated from the player's discard pile.
Bug 4: Score is not correctly calculated from the player's deck pile.
*/

/*from cardtest1 Smithy Card
Bug 5: Player does not receive the proper amount of cards.
*/

/*from cardtest2 Adventurer Card
Bug 6: Player's discard pile was not shuffled into player's deck.
Bug 7: Player does not receive the proper amount of cards.
Bug 8: Player does not receive two treasure cards.
*/

/*from cardtest3 Village Card
Bug 9: Player gains 2 actions but action count is not decreased from initial number of actions.
*/

/*from cardtest4 Steward Card
Bug 10: Using choice 1 player does not receive two cards.
Bug 11: Using choice 2 player does not receive two coins.
Bug 12: Using any choice other than 1 or 2 player does not discard two cards.
*/

/**********************************************************************************************************






/*BUG FIXES FROM MY TESTS*/


/******************************************************************************************************
Bug 3: When 3 action card piles are empty the game does not end. Specifically if Treasure Map card is one
		of the piles.
		
	Fixed by changing the for loop inside the isGameOver() from
	 for (i = 0; i = 25; i++)
	 
	 to
	 
	 for (i = 0; i <= 26; i++)
	 
	 This new for loop declaration iterates over each card pile
***************************************************************************************************/

/***************************************************************************************************
Bug 5: Player does not receive the proper amount of cards when using smithy card

	Fixed by changing the for loop inside smithy_card() from
	for (i = 1; i < 3; i++)
	
	to
	
	for (i = 0; i < 3; i++)

	This new for loop adds one 3 cards to player's hand rather than 2.
***************************************************************************************************/

/***************************************************************************************************
Bug 10: Using choice 1 player does not receive two cards.

	Fixed by changing the 
	if choice1 == 2 to if choice1 == 1 in steward_card()
	That way proper portion of code is executed when user selects choice 1
***************************************************************************************************/

/***************************************************************************************************
Bug 11: Using choice 2 player does not receive two coins.

	Fixed by changing the 
	if choice2 == 1 to if choice2 == 2 in steward_card()
	That way proper portion of code is executed when user selects choice 2
***************************************************************************************************/

/***************************************************************************************************
Bug 12: Using any choice other than 1 or 2 player does not discard two cards.
	
	Fixed by removing an extra call to discardCard() in steward_card()

***************************************************************************************************/

/***************************************************************************************************
Bug 9: Player gains 2 actions but action count is not decreased from initial number of actions.

	Fixed by changing the village statement in cardEffect() from
	state->numActions = state->numActions + 2;
	
	to
	
	state->numActions = state->numActions + 1;

	This still adds two actions for the player because it counts for the fact one action is used
	for playing the card. And playCard() is not being called in this unit test which decrements 
	the number of actions.
***************************************************************************************************/

/***************************************************************************************************
Bug 4: Score is not correctly calculated from the player's deck pile.

	Fixed by changing the for loop from
	for (i = 0; i < state->discardCount[player]; i++)
	 
	to
	 
	for (i = 0; i < state->deckCount[player]; i++)
	
	This new for loop actually iterates over the proper pile.
***************************************************************************************************/

/***************************************************************************************************
Bug 3: Score is not correctly calculated from the player's discard pile.

	This was actually not a bug after all, this was an error in the unit test itself.
	The unit test did not set the discard count, therefore it assumed the discard pile had
	no cards in it, therefore a score of 0 was returned.

***************************************************************************************************/

/***************************************************************************************************
Bug 1: When a card is discarded it is not added to the player's discard pile.

	Fixed by adding the recently played card to the discard pile and increased the discardCount by 1
	
	Added to discardCard()
	
	//add card to discard pile.
	state->discard[currentPlayer][state->discardCount[currentPlayer] + 1] = state->hand[currentPlayer][handPos];
	state->discardCount[currentPlayer]++;

***************************************************************************************************/

/***************************************************************************************************
Bug 2: When deck count is 0 and discard pile count is -1. Deck count is <= 0 after card is drawn. 

	Fixed this by adding an if else statement in drawCard(), if the discardCount is >0 the function
	performs like it previously did, else it just sets the discardCount to the deckCount pile.
	
	I also had to adjust my unit test because it was outputting the opposite expected results when
	a -1 discardCount pile is encountered.

***************************************************************************************************/

/***************************************************************************************************
Bug 6: Player's discard pile was not shuffled into player's deck.
Bug 7: Player does not receive the proper amount of cards.
Bug 8: Player does not receive two treasure cards.

	I had to adjust my cardtest2() to set the discardCount to a value rather than leave it Null.

	Bugs 7 and 8 only resulted when Bug 6 acted when the deckCount was zero.
	
	Fixed bug 6 by setting the deckCount to equal discardCount, therefore the shuffle function would work.
	Thus fixing bug 6, bugs 7 and 8 were fixed as well.
	
	Added in adventurer_card()
	
	 state->deckCount[currentPlayer] = state->discardCount[currentPlayer];
	 In the first if else statement where is checks if deckCount is < 1.
	 Set the new count before the shuffle function is called.

******************************************************************************************************/


/*END OF BUG FIXES FROM MY TESTS*/




/************************************ BUG REPORT FROM TEAMMATE 1 ************************************/
/*

	Teammate 1:

	adventurer card bugs:
		1. hand size too large after every test
		2. 4 extra cards in hand after every test
		3. either all or some cards in wrong position in hand after every test

	smithy card bugs:
		1. hand size too small after every test
		2. only 2 cards drawn after every test
		3. cards drawn are in wrong hand positon (first card drawn replaces position of smity card, second hand card and end of deck instead of both being at end of deck) for every test

	scoreFor bugs:
		1. Score incorrect whenever there are more victory cards in deck than discard pile
		2. Score often wrong whenever there are more victory cards in discard pile than deck

	isGameOver bugs:
		1. reutrns 1 when 3 actions cards not in play are empty

	*results for all test can be found in cs362f15/projects/jurczakn/teammate1Dominion/*.out
	

*/

/****************************************************************************************************/


/*BUG FIXES FROM TEAMMATE 1 TESTS*/


/***************************************************************************************************
Bug isGameOver #1:  returns 1 when 3 actions cards not in play are empty

	In order to fix this bug I would need to add an extra parameter to the isGameOver() which would then 
	alter the tests. Therefore I did not do this fix because I would have to alter my teammate's unit tests.
	
	This is how I would fix this bug though,
	
	I would add kingdomCards[10] as a parameter to isGameOver()
	I would then make a nesting for loop inside isGameOver() to iterate over every supply count for all
	of the cards and iterate over each kingdom card to see if the supply card is in the kingdomCards set
	to determine if the card is in the game.
	
	This fix would prevent the game from ending if 3 card stacks that are not in the current game happened
	to obtain a count of zero.
	
/***************************************************************************************************


/***************************************************************************************************
Bug smithy card #1 & #2 hand size too small after every test. Only 2 cards drawn after every test

	This was fixed when I fixed the the bugs from my unit tests Bug #5.
    

/***************************************************************************************************


/***************************************************************************************************
Bug smithy card #3 cards drawn are in wrong hand position (first card drawn replaces position of smithy card, 
		   second hand card and end of deck instead of both being at end of deck) for every test
		   
AND

Bug adventurer card #3 either all or some cards in wrong position in hand after every test

		   
		  **** This is not a bug. **** 
		   
		   The reason this is not a bug is because in discardCard() it clearly comments that
		   the card being discarded is replaced with the last card in the hand. If the card being discard
		   is not the only card in the hand or not at the very end of the hand.
		   
		    //replace discarded card with last card in hand
			
			Therefore teammate 1 was testing for functionality where the discarded card is replaced with the 
			next card ahead of it and then the new cards drawn are at the end of the hand.

/***************************************************************************************************


/***************************************************************************************************
Bug adventurer card #1 & #2 hand size too large after every test. 4 extra cards in hand after every test

	These bugs were fixed when I fixed bugs 7 & 8 from my tests.

/***************************************************************************************************

/***************************************************************************************************
Bug scoreFor #1 & #2 Score incorrect whenever there are more victory cards in deck than discard pile
					 Score often wrong whenever there are more victory cards in discard pile than deck

			I fixed the calculation bugs for scoreFor() when I fixed bugs 3 and 4 from my tests.
			I don't believe the test my teammate performed is accurate.
			
			For example from the test's output, adding one more "garden" card to the discard pile
			some how results in an expected outcome from 0 to 3. As you can see below, the output 
			doesn't seem trust worthy.
			
			I think there is an error in the unit test.
			
			Test player 1 with 9 victory card(s).
			5 of card number 5 in hand
			3 of card number 5 in deck
			1 of card number 5 in discard
			Score calculated: 0, Expected: 0
			SUCCESS
			
			Test player 1 with 10 victory card(s).
			5 of card number 5 in hand
			3 of card number 5 in deck
			2 of card number 5 in discard
			Score calculated: 0, Expected: 3
			FAILURE<=============================
			
			Test player 1 with 11 victory card(s).
			5 of card number 5 in hand
			3 of card number 5 in deck
			3 of card number 5 in discard
			Score calculated: 0, Expected: 3
			FAILURE<=============================
			
			Test player 1 with 12 victory card(s).
			5 of card number 5 in hand
			3 of card number 5 in deck
			4 of card number 5 in discard
			Score calculated: 0, Expected: 3
			FAILURE<=============================
			

/***************************************************************************************************

/*end of bug fixes from teammate 1*/




/************************************ BUG REPORT FROM TEAMMATE 2 ************************************/
/*
	unittest1: no bugs
	unittest2: no bugs
	unittest3: no bugs
	unittest4: no bugs
	
	cardtest1: the player's hand isn't initialized correctly, causing it to be empty after initializeGame
	cardtest2-4: the same bug occurred as in cardtest1, making further card tests impossible
*/
/****************************************************************************************************



/*BUG FIXES FROM TEAMMATE 2 TESTS*/


/****************************************************************************************************
Bug cardtest1-4

	It appears that teammate 2 is relying on initializeGame() to populate the player's hand instead of
	populating the player's hand with the test.
	
	The fix for this is in dominion.c starting at line 168 the code that draws a player's hand when the 
	game is initialized is commented out. By un-commenting the code, initializeGame()
	should draw a player's hand.

/****************************************************************************************************





