Woo Choi
CS362 F15
BugFixes.c

Bugs found by teammates:
I've gone over your dominion code, Woo,  and saw that things were consistent with your refactor/dominion code so I didn't have issues with your code.
The bugs that I've found from my tests were pretty much the ones that you introduced, as seen in your refactor.c file. My test results for bugs were:
*In smithy, I was able to detect that the player gained an incorrect amount of cards
*In adventurer, I was able to detect the incorrect amount of treasure cards drawn and that adventurer was not discarded from the player's hand
*In council room, I was able to detect the incorrect number of cards drawn by the player that played council room

Smithy: 
	My teammate found my bug that I introduced. 
	    for (i = 1; i < 3; i++)
		should be
		for (i = 0; i < 3; i++)
		It is now fixed.
		
Adventurer:
	1. while(drawntreasure<2) does not run.
	Reason being:   int drawntreasure=10; should be int drawntreasure=0;
	since drwantreasure was set as 10, it did not even attempt to go through the whileloop.
	
	2. There is no discard for adventurer
	discardCard(handPos, currentPlayer, state, 0);
	is now written in
	

Council Room:
	for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i == currentPlayer )
	  
	inside the for loop, 
	it should be i != currentPlayer
	Fixed.
	

Bugs that I introduced that teammates did not catch:
(As of 11/19/15 14:44)

Great_Hall:

	instead of state->numActions++, it became state->numAction = 2;
	so action number will be 2 after using this card no matter what
	
	Fixed back to state->numActions++;
	
Village:

	instead of +2 actions, # of actions just becomes 2
	    from
			state->numActions = state->numActions + 2;
		to
			state->numActions = 2;
	
	Fixed back to
		state->numActions = state->numActions + 2;
			
			