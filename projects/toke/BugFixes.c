/////////////// Bug Fix Documentation //////////////////

// Fix 1:
Bug Originator: Carol Toro
Bug Title: Player did not receive the 3 cards
Fix: The root cause of this bug was that the smithy code
     was drawing more cards than it was supposed to.

	Before Code:
		for (i = 0; i < 5; i++)
		{
			drawCard(currentPlayer, state);
		}
	
	After Code:
		for (i = 0; i < 3; i++)
		{
			drawCard(currentPlayer, state);
		}

	Notice, we are only drawing three cards now.

// Fix 2:
Bug Originator: Carol Toro
Bug Title: Smithy was not replaced by correct card
Fix: This bug is fixed by Fix 1. Look above to see 
     the code changes.

// Fix 3:
Bug Originator: Carol Toro
Bug Title: Council room adds one additional buy than it should.
Fix: The code was adding an additional buy. In order to fix,
     we will remove the extra buy.

    Before Code:
		state->numBuys++;
		state->numBuys++;

    After Code: 
		state->numBuys++;

// Fix 4
Bug Originator: Carol Toro
Bug Title: Great Hall is drawing 1 more card than it should.
Fix: The code was drawing 1 additional card than it should.
     Removed the additional add.

    Before Code:
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);

    After Code: 
  		drawCard(currentPlayer, state);

 // Fix 5
Bug Originator: Carol Toro
Bug Title: Village card is causing player to recieve more than 2 actions
Fix: The code is incrementing the number of actions by 4. Change the 
     increment to 2.

    Before Code:
		state->numActions = state->numActions + 4;

    After Code: 
  		state->numActions = state->numActions + 2;
