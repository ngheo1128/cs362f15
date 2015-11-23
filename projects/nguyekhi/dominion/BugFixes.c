/*

Smithy card: 
fix 1 <= 3 to 1 < 3

adventurer card: 
fix: state->deckCount[currentPlayer] == 0 to state->deckCount[currentPlayer] == 0
fix: cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]; to cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
fix: state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z]; to state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];

council_room card:
fix: for (i = 0; i < state->numPlayers; i++) to for (i = 0; i < 4; i++)
fix: for (i = 0; i < 4; i++) to for (i = 0; i < state->numPlayers; i++)

great_hall card:
fix: state->numBuys++; to state->numActions++;

steward card:
fix: discardCard(choice2, currentPlayer, state, 0) to discardCard(choice2, currentPlayer, state, 1)

*/