/*
This file contains bug fixes as of 11-22-2015.


isGameOver: (found by jenkinch)
------------------------------------------------------------------------
fixed  for (i = 0; i < 25; i++) to 
       for (i = 0; i < 27; i++)

       This will now check all card piles


smithy: (found by jenkinch)
------------------------------------------------------------------------
fixed  discardCard(0, currentPlayer, state, handPos) to
       discardCard(handPos, currentPlayer, state, 0);

       This fixed the hand position and trash flag parameters


adventurer: (found by hattont)
------------------------------------------------------------------------
fixed  initialized z to 0 and
       addded z++ in else statement inside the first while loop

       This fixes the the discard game state of the player which
       previously contained grabage as z was uninitialized
       and z never having been incremented - causing erronious loop
       count


council room:
------------------------------------------------------------------------ 
fixed  for (i = 0; i <= 4; i++) to
       for (i = 0; i < 4; i++)

	   Thid fixes the handCount and deckCount of the player gamestate

*/
