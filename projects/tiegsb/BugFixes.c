/*
Brian Tiegs
CS 362 - Assignment 5

Bug Fixes for Dominion.c

*******************************************************************************

Bug 1

Identified by James Carlin and Aditya Gune
Location: adventurerEffect()

Bug:
	Calling the function removes 3 cards from the player's hand even if the player has no cards.
	Calling the function fails to add 2 cards to the player's hand.

Fix:
	The bug causes the handCount to be decremented too many times. In the function, handCount is mentioned in 2 locations. First when determining cardDrawn and second when discarding a non-treasure card from the hand. The bug occurs when determining cardDrawn. Instead of taking the top card from the player's hand, handCount is decremented. The bug was fixed by changing the following code:
	Before fix:
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]--];
	After fix:
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

*******************************************************************************

Bug 2

Identified by James Carlin and Aditya Gune
Location: smithyEffect()

Bug:
	The function fails to add cards to hand. Supposed to add 3.
	Calling the function never results in the player drawing cards.
	The player's hand count and discard count stays the same.

Fix:
	The bug results in the drawCard function to never be called. The drawCard function is only called in the for loop. Looking at the for loop, it is clear the conditional statement was not implemented correctly. The loop will never run since the conditional statement is 'i > 3'. The bug was fixed by changing the following code:
	Before fix:
		for (i = 0; i > 3; i++)
	After fix:
		for (i = 0; i < 3; i++)

*******************************************************************************

Bug 3

Identified by Aditya Gune
Location: council_roomEffect()

Bug:
	Calling the function results in Player 0's hand increasing by 4 cards. Player 1's hand never increases.

Fix:
	The bug results in the player to draw too many cards and the other players not drawing any cards. There are 2 drawCard calls in the function. The first one calls drawCard for the currentPlayer while the second calls drawCard for the other players. The bug occurs in the second drawCard call. Instead of calling drawCard for the other player, it is called for the current player. The bug was fixed by changing the following code:
	Before fix:
		drawCard(currentPlayer, state);
	After fix:
		drawCard(i, state);

*******************************************************************************

Bug 4

Identified by Aditya Gune
Location: baronEffect()

Bug:
	The number of coins does not increase. It's always at 4.

Fix:
	The bug results in the coins to always be 4. There is only one declarative statement for coins. The problem here is the statement sets coins equal to 4 instead of increasing them. The bug was fixed by changing the following code:
	Before fix:
		state->coins = 4;
	After fix:
		state->coins += 4;

*******************************************************************************

Bug 5

Identified by my unit tests
Location: scoreFor()

Bug:
	Scores calculated incorrectly when discardCount and deckCount values are different.

Fix:
	The bug results in an incorrect score when discardCount and deckCount are different. In the function, deckCount is not used and discardCount is used twice. When calculating the score from the deck, discardCount is used in the conditional instead of deckCount. The bug was fixed by changing the following code:
	Before fix:
		for (i = 0; i < state->discardCount[player]; i++)
	After fix:
		for (i = 0; i < state->deckCount[player]; i++)

*******************************************************************************

Bug 6

Identified by my unit tests
Location: scoreFor()

Bug:
	Gardens card is not being calculated correctly by scoreFor(), always returns a score of 0.

Fix:
	The bug causes the garden card to not be calculated correctly. There are 3 statements where the garden card is being calculated. The problem is the call to fullDeckCount. Instead of calculating the total number of cards in the deck, it calculates the total number of cards with the value of '0' in the deck. The bug was fixed by changing the following code:
	Before fix:
		if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
	After fix:
		if (state->hand[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };
		if (state->discard[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };
		if (state->deck[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };

*******************************************************************************

Bug 7

Identified by my unit tests
Location: isGameOver()

Bug:
	Does not end game if 1 of the 3 empty card piles are either Sea Hag or Treasure Map.

Fix:
	The bug does not check all cards to see if the supplyCount is empty. Specifically it is not checking Sea Hag and Treasure Map. These are the last 2 cards in the array therefore the problem likely occurs by not looping through all of the cards. In the function there is 1 for loop that loops 25 times. The bug occurs because there are 27 cards. The bug was fixed by changing the following code:
	Before fix:
		for (i = 0; i < 25; i++)
	After fix:
		for (i = 0; i < 27; i++)

*******************************************************************************

Bug 8

Identified by my unit tests
Location: adventurerEffect()

Bug:
	If no treasure cards are in the deck or discard pile, a segmentation fault occurs.

Fix:
	The bug causes a segmentation fault when there are no treasure cards in the hand, deck and discard pile. Examining the adventurer function there is no check for this therefore the code will fail to draw a card and continue to discard a card from the player's hand even when there is nothing left. The problem can be fixed by checking if drawCard failed and breaking the loop if it does fail. The bug was fixed by changing the following code:
	Before fix:
		drawCard(currentPlayer, state);
	After fix:
		if(drawCard(currentPlayer, state) == -1){
			break;
		}

*******************************************************************************

Bug 9

Identified by my unit tests
Location: treasure map card in cardEffect()

Bug:
	If 2 treasure cards are in hand, they are not always trashed from the player's hand.

Fix:
	The bug can cause the treasure map cards to not be discarded correctly. There are two calls to discardCard in the function. The problem occurs because if the first card is located before the second, discarding the first card will cause the indexes to shift and the second treasure map card will no longer be at its previous index. The bug can be fixed by checking which card's index is last in hand position and discarding it first. The bug was fixed by changing the following code:
	Before fix:
		discardCard(handPos, currentPlayer, state, 1);
		discardCard(index, currentPlayer, state, 1);		
	After fix:
		if(handPos > index){
			discardCard(handPos, currentPlayer, state, 1);
			discardCard(index, currentPlayer, state, 1);
		}else{
			discardCard(index, currentPlayer, state, 1);
			discardCard(handPos, currentPlayer, state, 1);     
		}

*******************************************************************************
*/
