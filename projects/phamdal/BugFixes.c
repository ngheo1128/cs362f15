Bug Fixes made from found bugs:

Changes made to Adventurer code: 
Bug: Adventurer function drew incorrect number of cards
original line :	while(drawntreasure <= 2)
changed line:	while(drawntreasure <2)

Bug: Adventurer card was not being placed in "played pile", handCount differences + was not being discarded
added line: discardCard(handPos, currentPlayer, state, 0); 

Changes made to Smithy code: 
Bug: Smithy card was not being placed in "played pile"
original line: 	discardCard(handPos, currentPlayer, state, 1);
changed line: 	discardCard(handPos, currentPlayer, state, 0);

Changes made to Council Room code: 
Bug: Player 1 receive too many cards, other players did not receive any cards
original line:	if ( i == currentPlayer )
changed line:	if ( i != currentPlayer )

Bug: Return value incorrect
original line:	return 1; 
changed line: return 0; 

Changes made to Sea Hag code: 
Bug: Player 1 deckCounts off

remove line:  state->deckCount[i]--;
change lines: 
original line: state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];
changed line: state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i] - 1];			    

orignal line:  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
changed line: state->deck[i][state->deckCount[i] - 1] = curse;//Top card now a curse

Bug: Sea Hag card was not being placed in "played pile"
added line: discardCard(handPos, currentPlayer, state, 0

Bug Fixes made to reverse changes: 

Changes made to Great Hall code:  
original line:	state->numActions--;
changed line:	state->numActions++;

original line: 	discardCard(handPos, currentPlayer, state, 1);
changed line: 	discardCard(handPos, currentPlayer, state, 0);

Changes made to Cut Purse code: 
Original line:	if (state->hand[j][i] == copper)
changed line:	if (state->hand[i][j] == copper)
