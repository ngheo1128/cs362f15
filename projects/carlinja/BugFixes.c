Bug 1
	
	 scoreFor
	Bug:
		Incorrectly calculates score
			Calculates lower score when discardCount < deckCount
			Calculates higher score when discardCount > deckCount
	
	Fix:
		for (i = 0; i < state->deckCount[player]; i++)

Bug 2
	
 scoreFor
	Bug:
		Gardens cards give a score of 0
	
	Fix:
		Changes made to program:
			if (state->hand[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };
			if (state->discard[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };
			if (state->deck[player][i] == gardens) { score = score + ( (state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10 ); };
Bug 3
	
	isGameOver
	Bug:
		isGameOver returns 1 when 3 card piles are empty
	
	Fix:
		Changes made to program:
			for (i = 0; i < 27; i++)

Bug 4
	Test: cardtest1.c and randomtestadventurer
	Location: adventurer card
	Bug:
		Deck did not lose 2 cards with full deck of coin cards
		Hand did not gain 2 cards with full deck of coin cards
	Conditions to produce bug:
		Deck is made up of all coin cards
		deckCount >= 2

	Fix: Seg faults. Need to break if drawcard returns -1

	Changes made to program:
			if(drawCard(currentPlayer, state) == -1){
			break;
		}

Bug 5
	Test: cardtest2.c
	Location: smithy card
	Bug:
		Deck did not lose 3 cards
		Hand did not gain 2 cards
	Fix: I terminated my loop early on purpose, reverted that change here
		for (i = 0; i >= 3; i++)
Bug 6
	Test: cardtest4.c and randomtestcard.c
	Location: treasure map
	Bug:
		Treasure maps were not trashed in player's hand at positions 0 and 9
	Conditions to produce bug:
		Treasure cards are set to hand indexes 0 and 9
		handPos = 0
		index = 9
		handCount = 10
	Fix:
	Changes to program
			if(handPos > index){
			discardCard(handPos, currentPlayer, state, 1);
			discardCard(index, currentPlayer, state, 1);
			}else{
			discardCard(index, currentPlayer, state, 1);
			discardCard(handPos, currentPlayer, state, 1);     
			}

ADITY's found bugs

	Bug 1
Test: cardtest2.c
Location: Adventurer Card
Description: 
			Calling this function increases drawntreasure by 2 rather than one if a treasure is drawn. 
			Also, the loop for discarding temphand starts at z rather than z-1.
Conditions to reproduce:
			At least 1 treasure drawn

Fix:

	Fixed earlier through Brian's testing
Bug 2
Test: cardtest1.c
Location: Smithy Card
Description:
			Since the loop is set to i > 3, it never executes, and cards are never drawn.
Conditions to reproduce:
			Smithy card played

Fix:
	
	Fixed earlier through Brian's testing

Bug 3
Test: cardtest3.c
Location: Village Card
Description: 
			Displayed no observable bugs on testing. However, inspection of the source code revealed
			that the function returns 1 instead of 0, leading to effects further in the program
Conditions to reproduce
			Village card played
			playCard() requires a value from cardEffect()

Fix:
	changed return value to 0;

	change in program:
		return 0;
Bug 4
Test: cardtest4.c
Location: Great Hall
Description: 
			Calling this function increases the number of actions by 2 instead of 1
Conditions to reproduce:
			Great Hall card played

Fix:

	state->numActions + 1;