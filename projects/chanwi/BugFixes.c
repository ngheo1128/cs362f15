/*Bug Fixes
**Wilson Chan
**CS362 Assignment 5

I fixed the following bugs found by my teammates and also the bugs I intentionally introduced for Assignment 2.

-- adventurerCard() Bugs
Bug1. Three treasure cards are drawn instead of two treasure cards.
Fix1. Bug was introduced in Assignment 2 by changing the operator. I reverted the statement 'while(drawntreasure<=2)' back to 'while(drawntreasure<2)'.

Bug2. The shuffle method is always activated regardless of how many cards are left in the deck.
Fix2. Bug was introduced in Assignment 2 by changing the operator. I reverted the statement '(state->deckCount[currentPlayer] =0)' back to '(state->deckCount[currentPlayer] <1)'.

Bug3. Card is not discarded after it has been played.
Fix3. The card was missing the discardCard() method. I added this statement at the end of the adventurer card function: 'discardCard(handPos, currentPlayer, state, 0);'	


-- smithyCard() bugs
Bug1. Card will not be discarded unless 3 cards are drawn. Card will not be discarded when player can not draw 3 cards if total cards in deck and discard pile is less than three.
Fix1. Bug was introduced in Assignment 2. I removed the condition 'if(i == 3){...}' from the function.

Bug2. Card is discarded into trash instead of discard pile.
Fix2. Bug was introduced in Assignment 2. I reverted the statement 'discardCard(handPos, currentPlayer, state, 1)' back to 'discardCard(handPos, currentPlayer, state, 0)'. The correct value is 0 which is the discard pile.


-- councilRoomCard() bugs
Bug1. When there are more than two players, only one other player will draw a card instead of all other players.
Fix1. I introduced the bug in Assignment 2, by rewriting the card drawing portion for only the next player. To fix the bug, I reverted the following statement:

	int nextPlayer = currentPlayer + 1;
	if (nextPlayer > state->numPlayers - 1){
		nextPlayer = 0;
	}
	drawCard(nextPlayer, state);
	
back to 

	for (i = 0; i < state->numPlayers; i++){
		if ( i != currentPlayer ){
			drawCard(i, state);
	    }
	}

Bug2. Card will not be discarded unless 4 cards are drawn. Card will not be discarded when player can not draw 4 cards if total cards in deck and discard pile is less than three.
Fix2. Bug was introduced in Assignment 2. I removed the condition 'if(i == 4){...}' from the function.


-- treasureMapCard()
Bug1. Gold cards are added to discard pile instead of the deck.
Fix1. Bug was introduced in Assignment 2. I reverted the statement 'gainCard(gold, state, 0, currentPlayer)' back to 'gainCard(gold, state, 1, currentPlayer)'. The correct value for deck is 1.

Bug2. When check hand for other treasure map cards, it skips the first card in the hand.
Fix2. Bug was introduced in Assignment 2. I reverted the statement 'for (i = 1; i < state->handCount[currentPlayer]; i++)' back to 'for (i = 0; i < state->handCount[currentPlayer]; i++)'. The counter i should start at 0.


-- isGameOver()
Bug1. When counting empty stacks, some cards were not considered such as the treasure map card.
Fix1. The bug is caused by bad for loop which considered cards from 0 to 24. I increment the loop by 2 to include up to the last card. I made the following code change: 'for (i = 0; i < 25; i++)' changed to for '(i = 0; i < 27; i++)'


-- discardCard()
Bug1. The discardCard() moved cards from the hand to the played pile, but the card never actually goes to the discard pile.
Fix1. I revised the code to discard a played card from hand to the discard pile. I made the following code changes: 

      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
	  
Changed to

      state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos];
      state->discardCount[currentPlayer]++;

	  
-- scoreFor()
Bug1. Victory cards in deck are calculated incorrectly.
Fix1. Bug is caused by a bad for loop. The loops counts up to the discardCount of the player instead the deckCount of the player. I made changed the statement 'for (i = 0; i < state->discardCount[player]; i++)' to 'for (i = 0; i < state->deckCount[player]; i++)'.

*/