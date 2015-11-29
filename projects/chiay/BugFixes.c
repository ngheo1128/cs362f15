********************************
     Bug Fixes for dominion
********************************

** All bugs introduced in assignment 2 are reverted before bug fixes. **

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
Code added : None
Test       : Both tests passed unit test.


/**********************************************************************************************/


Bug 2      : Calculation error in scoreFor() function for discardCount and deckCount
Code       : Third for - loop. for (i = 0; i < state->discardCount[player]; i++)
Fix        : Third for - loop. for (i = 0; i < state->deckCount[player]; i++)
Code added : None
Test       : All 9 tests passed unit test.


/**********************************************************************************************/


Bug 3      : cardEffect_council_rool() function won't discard council room card (introduced in assignment 2)
Code       :

       for (i = 0; i < state->numPlayers; i++)
       {
          if (i != currentPlayer)
	  {
	     drawCard(i, state);
	  }
	  else
	  {
	     return;
	  }
       }

Fix        :

       for (i = 0; i < state->numPlayers; i++)
       {
          if (i != currentPlayer)
	  {
	     drawCard(i, state);
          }
       }

Code added : None
Test       : Test passed unit test.


/**********************************************************************************************/
