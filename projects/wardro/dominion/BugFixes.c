Robert Ward
11-22-2015
Assignment 5
Fixing Bugs

My teammates found all of the bugs that I introduced. In addition to fixing the bugs introduced I also fixed one that I had found earlier. 

Bug Fixes:
In function "playVillage": 
    Instead of increasing the number of actions the player had to take, the actions were just set to two. The line 'state->numActions = 2' was changed to 'state->numActions = state->numActions + 2'. 
    
In function "playSmithy":
    The last argument for the discardCard function was set to 2 instead of 0. A value of 1 would have trashed the card, and 0 discards the card. Any other value than 0 also causes the card to be trashed. I fixed this by defining the discard value to be 0 instead of 2.
    
In function "playAdventurer":
    I set the cardDrawn to the wrong value. cardDrawn should have been the card in the end of the players hand but I set it to the card after the end of the players hand, which could have been anything. My code "cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] ];" and the correct code "cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] -1 ];". 
    There was a second error that I had found. When drawing for treasure, if there weren't two treasures in the discard pile or deck the function would draw all of the available cards and then start discarding cards from the players hand. To fix this I added a check to see if the player actually drew a card, if not the function would break out of the loop. The fixed code: 'if ( drawCard(currentPlayer, state) == -1) break;'. 
    
In function "playCouncil_room":
    The last bug was in the loop for letting other players draw a card. I started the loop at player 1 instead of player 0. With this error, if a player other than player 0 played the council room card then player 0 wouldn't get to draw a card. To fix this I started the loop at 0: 'for (i=0; i < state->numPlayers; i++)'.
    
At this point I believe that all of the bugs have been found and fixed in the refactored cards.
