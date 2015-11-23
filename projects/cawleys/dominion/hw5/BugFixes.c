
1) Smithy() Put discard back
	Uncommented the discardcard() at dominion.c:1349
2) Adventurer() changed to draw 2 treasure cards
	Changed from while(drawntreasure<4) to while(drawntreasure<2) at dominion.c:1311
3) Adventurer() was not being discarded. 
	Added section of code to find the hand position of the adventuer card at dominion.c:1303-1309
	Added discardcard() at dominion.c:1332
4) Great_hall() corrected the add action part of the code
	changed state->numActions -- to state->numActions ++ at dominion.c:1372
5) Village() corrected to add 2 action
	changed from state->numActions = state->numActions + 4 to state->numActions = state->numActions + 2 at dominion.c:1359