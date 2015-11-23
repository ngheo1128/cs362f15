Robert found these bugs and I fixed them:

	Teammate 1: Jibrahn Khoury
	Bugs found
	Bug 1: In function 'caseOutpost()'
	    The line 'state->outpostPlayed;' in the function doesn't increment the outpostPlayed counter. This would allow a player to play multiple outposts, or worse yet, never get to have their extra turn.

	Bug 2: In function 'caseSteward()'
	    The function never returns when called. Also, on choice == 1 the second 'drawcard' function is called with '0' as the current player, but the current player might not be '0' every time that the Steward card is played.

Kevin found these bugs and I fixed them:

	BUG #1 - dominion.c file caseVillage method
	      
	      Test Case Failed:
	        Validate number of player actions increases by 2
	        
	      Recommendation to Developer:
	        Review assignment of state->numActions in caseVillage method (line 663)
	          //+2 Actions
	          state->numActions = state->playedCardCount++ + 2;

	      Output:
	        cardtest1: cardtest1.c:51: main: Assertion `G.numActions == initActions + 2' failed.
	        /bin/sh: line 1: 16275 Aborted                 (core dumped) cardtest1 >> unittestresults.out

	    Note: cardtest1 commented out of Makefile to proceed to next tests
	    
	BUG #2 - dominion.c file caseAdventurer method
	(For this one, I found that I had an error checking if statement with no brackets.
		I needed to add a semicolon. Without the semicolon, it causes an uninitialized
		variable to be called.
		if(r= drawCard(currentPlayer, state) == -1)

	      Test Case Failed:
	        Validate the handcount is correct

	    Output:
	      cardtest4: cardtest4.c:48: main: Assertion `G.handCount[p] == initHandCount + 2' failed.
	      /bin/sh: line 1:  3172 Aborted                 (core dumped) cardtest4 >> unittestresults.out