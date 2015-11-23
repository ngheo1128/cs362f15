********************************
     Bug Fixes for dominion
********************************

Bugs found by teammate:
-----------------------

Bug 1      : Smithy card trashed instead of going to the played pile
Code       : discardCard(handPos, currentPlayer, state, 1)
Fix	   : discardCard(handPos, currentPlayer, state, 0)
Code added : None
Test       : All tests passed unit test.


/**********************************************************************************************/


Bug 2 : Discard count not correct. Temp hand not discarding the cards.
Code  : state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z];
Fix   : state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z-1];

Code added in cardEffect_adventurer() function: 
	
	int i = 0;

	for (i = 0; i < state->handCount[currentPlayer]; i++){
		if (state->hand[currentPlayer][i] == adventurer){
			discardCard(i, currentPlayer, state, 0);
			//To find adventurer card and discard
			break;
		}
	}

Code added in discardCard() function:

	//Increment the number of discard
	state->discardCount[currentPlayer]++;

Test : Adventurer card discarded; number of discard incremented; player gain 2 treasure cards


------------------------------------------------------------------------------------------------


Bug found by myself:
--------------------

Bug 1 : Shuffle() function don't shuffle deck when deckCount = 0;
Fix   : (1) First if statement, (state->deckCount[player] > 3)
        (2) while (state->deckCount[player] < 3) {
		//Change form state->deckCount[player] to state->discardCount[player]
		card = floor(Random() * state->discardCount[player]);
		//Change form state->deckCount[player] to state->discardCount[player]
		newDeck[newDeckPos] = state->discard[player][card];
		newDeckPos++;
		for (i = card; i < state->deckCount[player] - 1; i++) {
			//Change form state->deck[player][i+1] to state->discard[player][i+1]
			state->deck[player][i] = state->discard[player][i + 1];
		}
		//Change form state->deckCount[player]-- to state->deckCount[player]++
		state->deckCount[player]++;
				}
Test   : Both tests passed unit test.


/**********************************************************************************************/
