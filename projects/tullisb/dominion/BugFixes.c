
**********
adventurerFunction();
bug:		while (drawntreasure<2 && state->numActions<2) {
fix:		while (drawntreasure<2) {
*The added criteria to enter the while loop is incorrect

bug line 4:	drawCard(currentPlayer, state);
fix:		shuffle(currentPlayer, state);

bug line 6:	shuffle(currentPlayer, state); 
fix:		drawCard(currentPlayer, state);	
*These two are listed together as it appears that the lines were swapped switching them back produces correct results according to expectations.

bug: 		temphand[currentPlayer] = cardDrawn;
fix:		temphand[z] = cardDrawn;
*The wrong index indeicator was being passed to the temphand array thus displaying incorrect results

buggy version:
void adventurerFunction(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) {
	while (drawntreasure<2 && state->numActions<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			drawCard(currentPlayer, state);
		}
		shuffle(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[currentPlayer] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}

correct version:
void adventurerFunction(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) {
	while (drawntreasure<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}


**********
smithyFunction()
bug:		for (i = 0; i <= 3; i++)
fix:		for (i = 0; i < 3; i++)
*The added criteria to increased iterations by one which is incorrect

bug:		if (state->hand[currentPlayer][state->handCount[currentPlayer]] > state->coins)					drawCard(currentPlayer, state);
fix:		drawCard(currentPlayer, state);
*There was an added conditional statement that should not be there.

bug line 9:	There was no call to discard
fix:		discardCard(handPos, currentPlayer, state, 0);

buggy version:
void smithyFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+3 Cards
	int i;
	for (i = 0; i <= 3; i++)
	{
		if (state->hand[currentPlayer][state->handCount[currentPlayer]] > state->coins)
			drawCard(currentPlayer, state);
	}
}

correct version:
void smithyFunction(int currentPlayer, struct gameState *state, int handPos) {
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}


**********
villageFunction()
bug:		if (state->deckCount < state->handCount)
fix:		'[nothing]'
*The added conditional statement does not belong in this function anywhere

bug:	state->numActions = state->numActions + state->numBuys;
fix:	state->numActions = state->numActions + 2;
*The integer added to numActions should be static and 2 not a dynamic number equal to state->numBuys

buggy version:
void villageFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	if (state->deckCount < state->handCount)
		drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + state->numBuys;
	
	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

correct version:
void villageFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + 2;

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
}


**********
great_hallFunction()
bug:	while (handPos = handPos - handPos, handPos < state->handCount) {
		drawCard(currentPlayer, state);
		handPos++;}
fix:	drawCard(currentPlayer, state);
*The added conditional while statement does not belong in this function anywhere and the incrementation of handPos is incorrect.  It should not be placed here.

bug:	discardCard(state->numBuys, currentPlayer, state, 0);
fix:	discardCard(handPos, currentPlayer, state, 0);
*the passing of incorrect parameters is incorrect.  fix contains the correct parameters to be passed

buggy version:
void great_hallFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	while (handPos = handPos - handPos, handPos < state->handCount) {
		drawCard(currentPlayer, state);
		handPos++;
	}

	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(state->numBuys, currentPlayer, state, 0);
}

correct version:
void great_hallFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	drawCard(currentPlayer, state);

	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}


**********
stewardFunction()
bug:	else if (choice2 == 2)
fix:	else if (choice1 == 2)
*the incorrect choice was being used for the boolean evaluation producing incorrect results

bug:	state->coins = state->numPlayers + 2;
fix:	state->coins = state->coins + 2;
*this is a big one.  the number of players was being changed as a result of this instead of the coin count

bug:	discardCard(choice1, currentPlayer, state, 1);
		discardCard(choice2, currentPlayer, state, 1);
fix:	discardCard(choice2, currentPlayer, state, 1);
		discardCard(choice3, currentPlayer, state, 1);
*the incorrect choices were being passed to the discardCard function producing incorrect results

buggy version:
void stewardFunction(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2, int choice3) {
	if (choice1 == 1)
	{
		//+2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	}
	else if (choice2 == 2)
	{
		//+2 coins
		state->coins = state->numPlayers + 2;
	}
	else
	{
		//trash 2 cards in hand
		discardCard(choice1, currentPlayer, state, 1);
		discardCard(choice2, currentPlayer, state, 1);
	}
}

correct version:
void adventurerFunction(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[], int z) {
	int cardDrawn;
	while (drawntreasure<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}