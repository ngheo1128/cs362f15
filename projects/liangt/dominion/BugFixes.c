/*

Per https://piazza.com/class/iespjuw0jz7jg?cid=151,
We don't have to use GDB to debug. I did not use it (although I know how to)

Most of these bugs were found either from my own refactor.c or my own unit and
random tests. Code Inspection was the primary method used.

None of my teammates sent me any bug reports.

Currently passes all tests except for a handful of tests for randomtestadventurer
	The condition which produces the failed tests is not accounted for in
	randomtestadventurer because the condition is extremely rare in actual play
	and not worth writing a separate test for. The actual function DOES take this
	condition into account, as shown below under buggyAdventurer.

discardCard():
	
	Uses state->discard instead of state->playedCards
		Before:
			state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
	    state->playedCardCount++;
	  After:
	  	state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos]; 
      state->discardCount[currentPlayer]++;

scoreFor():
	
	Correct score amounts for duchy and province cards
		Before:
			duchy) { score = score + 3; };
      province) { score = score + 6; };
    After:
    	duchy) { score = score + 5; };
      province) { score = score + 8; };

  Score from deck calculated properly
  	Before:
  		//score from deck
  		for (i = 0; i < state->discardCount[player]; i++)
  	After:
  		//score from deck
  		for (i = 0; i < state->deckCount[player]; i++)

buggySmithy():

	Draws 3 cards instead of 4
		Before:
			for (i = 0; i < 4; i++) {
		After:
			for (i = 0; i < 3; i++) {

	Does not trash smithy card
		Before:
			discardCard(handPos, currentPlayer, state, 1);
		After:
			discardCard(handPos, currentPlayer, state, 0);

buggyAdventurer():

	Draws 2 treasure cards instead of 3
		Before:
			while (drawntreasure < 3) {
		After:
			while (drawntreasure < 2) {

	Includes silver cards
		Before:
			if (cardDrawn == copper || cardDrawn == gold)
		After:
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)

	Discard adventurer card
		Before:
			[Nothing]
		After:
			discardCard(handPos, currentPlayer, state, 0); // discard adventurer card

	If deck and discard together do not have 2+ treasure cards, end while loop
	[This is an extremely rare condition in actual play]
		Before:
		  while (drawntreasure < 2) {
		    if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
		      shuffle(currentPlayer, state);
		    }
		    drawCard(currentPlayer, state);
		    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1]; //top card of hand is most recently drawn card.
		    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		      drawntreasure++;
		    else{
		      temphand[z]=cardDrawn;
		      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		      z++;
		    }
  		}
		After:
			int pool = state->deckCount[currentPlayer] + state->discardCount[currentPlayer];
		  int cardsDrawn = 0;
		  int allCardsDrawn = 0;
		  while (drawntreasure < 2 && !allCardsDrawn) {
		    if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
		      shuffle(currentPlayer, state);
		    }
		    drawCard(currentPlayer, state);
		    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1]; //top card of hand is most recently drawn card.
		    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		      drawntreasure++;
		    else{
		      temphand[z]=cardDrawn;
		      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		      z++;
		    }

		    // Prevents infinite loop if deck + discard doesn't contain 2+ treasure cards
		    cardsDrawn++;
		    if (cardsDrawn > pool)
		      allCardsDrawn = 1;

		  }

buggyVillage():
	
	Draws 1 card instead of 2
		Before:
			drawCard(currentPlayer, state);
  		drawCard(currentPlayer, state);
  	After:
  		drawCard(currentPlayer, state);

  Increases actions by 2 instead of 1
  	Before:
  		state->numActions = state->numActions + 1;
  	After:
  		state->numActions = state->numActions + 2;

buggyMine():

	Newly picked card is added to hand instead of deck
		Before:
			gainCard(choice2, state, 1, currentPlayer);
		After:
			gainCard(choice2, state, 2, currentPlayer);

	Chosen trashed card is actually trashed
		Before:
			//discard trashed card
		  for (i = 0; i < state->handCount[currentPlayer]; i++)
		  {
		    if (state->hand[currentPlayer][i] == j)
		      {
		        discardCard(i, currentPlayer, state, 0);      
		        break;
		      }
		  }
		After:
			//discard trashed card
		  for (i = 0; i < state->handCount[currentPlayer]; i++)
		  {
		    if (state->hand[currentPlayer][i] == j)
		      {
		        discardCard(i, currentPlayer, state, 1);      
		        break;
		      }
		  }

buggyCouncilRoom():

	Does not increase current coinage amount
		Before:
			updateCoins(currentPlayer, state, 3);
		After:
			[Deleted]

*/