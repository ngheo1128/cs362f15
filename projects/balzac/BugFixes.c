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


/*END OF BUG FIXES FROM MY TESTS...waiting for team-mate bug reports*/













