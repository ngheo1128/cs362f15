Victor Hernandez
CS_362_F15
Assignment 5 - Part 2 - BugFixes.c

Below are the bugs found by teammates which also include the bugs that I introduced
//////////////////////////////////////////////////////////////////////////////////////////
scoreFor() - 

Bug 1:
scoreFor() does not always return the correct score for a player

Fix: on line 444 of dominion.c changed   for (i = 0; i < state->discardCount[player]; i++) to   for (i = 0; i < state->deckCount[player]; i++)

//////////////////////////////////////////////////////////////////////////////////////////
discardCard() -

Bug 2:
discardCard() function does not increment the gameState discard count

Fix: on line 1190 of dominion.c changed state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; to state->discard[currentPlayer][state->discardCount[currentPlayer] + 1] = state->hand[currentPlayer][handPos]; and on line 1191 of dominion.c changed state->playedCardCount++; to state->discardCount[currentPlayer]++;

//////////////////////////////////////////////////////////////////////////////////////////
adventurerCard() - 

Bug 3:
adventurerCard() causes segFault when deck is empty.

Fix: on line 1291 of dominion.c changed (state->deckCount[currentPlayer] <=1) to
(state->deckCount[currentPlayer] <1)

//////////////////////////////////////////////////////////////////////////////////////////
smithyCard() - 

Bug 4:
smithyCard() is not added to the played card count

Fix: on line 1320 of dominion.c changed discardCard(handPos, currentPlayer, state, 1); to discardCard(handPos, currentPlayer, state, 0);

//////////////////////////////////////////////////////////////////////////////////////////
villageCard() -

Bug 5:
villageCard() does not add the correct amount of actions to the gameState

Fix: on line 1329 of dominion.c changed state->numActions = state->numActions + 3; to state->numActions = state->numActions + 2;

Bug 6:
villageCard() is not discarding card properly

Fix: on line 1332 of dominion.c changed discardCard(handPos, currentPlayer, state, 1); to discardCard(handPos, currentPlayer, state, 0);

//////////////////////////////////////////////////////////////////////////////////////////
great_HallCard() - 

Bug 7:
great_HallCard() adds an extra card to the players hand

Fix: removed line 1339 - drawCard(currentPlayer, state); from dominion.c

//////////////////////////////////////////////////////////////////////////////////////////
isGameOver() - 

Bug 8:
isGameOver() returns false negative on certain empty cards

Fix: on line 402 of dominion.c changed for (i = 0; i < 25; i++) to for (i = 0; i <= 26; i++)