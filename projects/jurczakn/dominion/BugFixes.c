Teammate found bugs:

Bug 1: Smith card, player does not receive the proper amount of cards.
fixed for loop on line 46 of refactor.c, 
	for (i = 1; i < 3; i++){
	changed to 
	for (i = 0; i < 3; i++){

Bug 2: Adventurer card does not shuffle deck when deck count = 0.
Added additional code to playAdventurer in refactor.c
	Added:
	if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			int i;

			for (i = 0; i < state->discardCount[currentPlayer]; i++){
				state->deck[currentPlayer][i] = state->discard[currentPlayer][i];
				state->discard[currentPlayer][i] = -1;
			}

			if (state->discardCount[currentPlayer]<0)
				state->deckCount[currentPlayer] = 0;

			else
				state->deckCount[currentPlayer] = state->discardCount[currentPlayer];

			state->discardCount[currentPlayer] = 0;

			shuffle(currentPlayer, state);
		}


Bug 3: Adventurer card does not give player proper amount of cards.
fixed while loop on line 18 of refactor.c,
	while (drawntreasure<2)
	changed to
	while (drawntreasure<3)

Bug 4: Adventurer card does not give player two treasure cards.
	*See Bug 3 fix

Bug 5: Village card action to play card was not decremented.
fixed algebra on line 97 of refactor.c
	state->numActions = state->numActions +2;
	changed to
	state->numActions = state->numActions + 1;

Bug 6: Discard card function does not add card to discard pile.
Added code to discardCard function on line 1247 in dominion.c
	state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos];
	state->discardCount[currentPlayer][handPos]++;

Bug 7: When deck count is 0 and discard pile is -1 deck count is less than 0 when draw card function is used.
Added if/else statement to draw card funciton in dominion.c
	Added:
	if (state->discardCount[player]<0)
		state->deckCount[player]=0;
	else
		state->deckCount[player]=state->discardCount[player]

Bug 8: Game is not over when 3 card stacks are empty.
fixed for loop on line 403 of dominion.c
	for (i=0;i<25;i++)
	changed to
	for (i=0;i<27;i++)

Bug 9: Score is not correctly calculated for cards in player's discard pile.
fixed for loop on line 445 of dominion.c
	for(i=0;i<state->discardCount[player];i++)
	changed to
	for(i=0;i<state->deckCount[player];i++)

Bug 10: Score is not correctly calculated for cards in player's deck pile.
	*See Bug 9 fix

Bug 11: Steward card does not discard 2 cards when user chooses this option.
	*See Bug 6 fix

Bug 12: Steward card does not give player proper amount of cards.
Added code on line 982 in dominion.c
	Added:
	drawCard(currentPlayer, state);

Introduced bugs:

Bug 1: Adventurer card does not take gold cards
fixed conditional on line 24 of refactor.c
	if (cardDrawn == copper || cardDrawn == silver)
	changed to
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)

Bug 2: Smity card only draws 2 cards
	*See Teammate found bugs - Bug 5 fix

Bug 3: playRemodel allows player to gain card worth 3 more than card trashed
fixed if statement on line 24 of refactor.c
	if((getCost(state->hand[currentPlayer][choice1])+3)>getCost(choice2)){
	changed to
	if((getCost(state->hand[currentPlayer][choice1])+2)>getCost(choice2)){

Bug 4: playVillage trashes village card after played
fixed discardCard call on line 96 of refactor.c
	discardCard(handPos, currentPlayer, state, 1)
	changed to
	discardCard(handPos, currentPlayer, state, 0)