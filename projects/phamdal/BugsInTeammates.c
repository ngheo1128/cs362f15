teammate 1 - tullisb dominion.c Bug Summaries: 

adventurer function
Bug Summary: 
1. does not draw correct number of cards, or correct cards
2. did not discard correct number of cards
3. adventurer was not placed in played pile
- when only 1 treasure card is in deck - 
4. draws incorrect number of cards
5. incorrect card drawn

suggested changes: 
1. change line 14 in dominion.c: while (drawntreasure<2 && state->numActions<2)
to:				while (drawntreasure <= 2))

smithy function
Bug Summary: 
1. card is not discarded
2. does not draw card
3. smithy is not placed in played pile

suggested changes: 
1. add line to dominion.c to end of smithy function: 
	discardCard(handPos, currentPlayer, state, 0);
2. change lines 38 - 41 in dominion.c from: 
	{
		if (state->hand[currentPlayer][state->handCount[currentPlayer]] > state->coins)
			drawCard(currentPlayer, state);
	}

	to: 
		drawCard(currentPlayer, state); 

sea_hag function
Bug Summary: 
1. Sea Hag was not played in played pile
2. Sea Hag not discarded, resulting handCount errors
3. Opponent deckCount errors, resulting in discarding wrong cards. 

suggested changes: 
1. change line 1215 in dominion.c from: 
	state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
	to: 
	state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i] - 1];
2. change line 1217 in dominion.c from: 
	state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
	to: 
	state->deck[i][state->deckCount[i] - 1] = curse; 
3. add line to dominon.c at the end of sea_hag case inbetween lines 1219 and 1220: 
	discardCard(handPos, currentPlayer, state, 0);

teammate 2 - wilcoant dominion.c Bug Summaries: 
adventurer function
Bug Summary: 
1. does not return correct value
2. incorrect number of cards drawn + discarded
3. incorrect cards discarded
4. adventurer was not placed in played pile
- when only 1 treasure card is in deck - 
5. draws incorrect number of cards

suggested changes: 
1. change line 784 in dominion.c from: 
	play_adventurer(state, drawntreasure, currentPlayer, temphand, cardDrawn);
	to: 
	return play_adventurer(state, drawntreasure, currentPlayer, temphand, cardDrawn);
2. change line 689 in dominion.c from: 
	if (cardDrawn == copper || (cardDrawn == silver && cardDrawn == gold))
	to: 
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
3. add line before 671 but after 670: 
	discardCard(handPos, currentPlayer, state, 0); 

smithy function
Bug Summary: 
1. does not return correct value

suggested changes: 
1. change line 780 in dominion.c from: 
	play_smithy(currentPlayer, state, handPos);
	to: 
	return play_smithy(currentPlayer, state, handPos);

council_room function
Bug Summary: 
1. does not return correct value
2. does not update numBuys appropriately 

suggested changes: 
1. change line 792 in dominion.c from: 
    play_council(state, currentPlayer, handPos); 
    to: 
    return play_council(state, currentPlayer, handPos);
2. change line 729 in dominion.c from: 
    //state->numBuys++;
    to: 
    state->numBuys++;

sea_hag function
Bug Summary: 
1. Sea Hag was not played in played pile
2. Sea Hag not discarded, resulting handCount errors
3. Opponent deckCount errors, resulting in discarding wrong cards. 

suggested changed: 
1. change line 1215 in dominion.c from: 
	state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
	to: 
	state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i] - 1];
2. change line 1217 in dominion.c from: 
	state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
	to: 
	state->deck[i][state->deckCount[i] - 1] = curse; 
3. add line to dominon.c at the end of sea_hag case inbetween lines 1219 and 1220: 
	discardCard(handPos, currentPlayer, state, 0);

Note: unittest tests on non-card functions did not find any bugs for both teammates, 
they transcript for those tests have been ommitted 

teammate 1 - tullisb 
Failed Transcript: 
TESTING smithy_card()
smithy_card discard/draw error
smithy_card does not draw from deck
smith_card does not place card in playedCard pile
smithy_card does not incremented playedCardCount
SMITHY_CARD: TESTS FOUND FAILURES

TESTING adventurer_card()
Testing with deck of 8 cards
Cards: Curse, Feast, Silver, Outpost, Gold, Estate, Adventurer, and Silver
adventurer_card did not draw correct number of cards
adventurer_card did not draw correct cards
adventurer_card did not discard correct number of cards
adventurer_card was not placed in played pile
Testing case where only 1 treasure card in deck
adventurer_card has drawn incorrect number of cards
adventurer_card has drawn incorrect card

Testing with empty deck but populated discard pile
PASSED
ADVENTURER_CARD: TESTING HAS FOUND ERRORS

TESTING council_room_card()
Game of 3 players
ALL TESTS PASSED

TESTING sea hag switch case in cardeffect()
Game of 3 players
sea_hag was not placed in played pile
Incorrect number of cards in Player 1 hand
Player 2/3 decks altered in unexpected way
Player 2/3 did not obtain the curse card at top of deck
Wrong top of deck cards were discarded
SEA_HAG TESTING HAS FOUND ERRORS

Random Adventurer Card Tests------------------------

HandCount Failures: 998/1000     HandCount Passes: 2/1000
DeckCount Failures: 0/1000       DeckCount Passes: 1000/1000
PlayedCardCount Failures: 1000/1000      PlayedCardCount Passes: 0/1000
Resulting Cards Failures: 978/978        Resulting Cards Passes: 0/978

(occasional seg faults)

Random Sea Hag Card Tests------------------------

Played Pile Failures: 1000/1000  Played Pile Passes: 0/1000
Top Deck Failures: 998/1000      Top Deck Passes: 2/1000
Deck Count Failures: 0/1000      Deck Count Count Passes: 1000/1000
HandCount Failures: 1000/1000    HandCount Passes: 0/1000
Opp. Deck Count Failures: 1000/1000      Opp. Deck Count Passes: 0/1000
Top Card Failures: 985/1000      Top CardPasses: 15/1000

------------------------------------------------------------------------------------------

teammate 2 - wilcoant
TESTING smithy_card()
smithy_card failture to run
SMITHY_CARD: TESTS FOUND FAILURES

TESTING adventurer_card()
Testing with deck of 8 cards
Cards: Curse, Feast, Silver, Outpost, Gold, Estate, Adventurer, and Silver
adventurer_card failed to run
adventurer_card did not draw correct number of cards
adventurer_card did not discard correct number of cards
adventurer_card did not discard correct cards
adventurer_card was not placed in played pile
Testing case where only 1 treasure card in deck
adventurer_card has drawn incorrect number of cards

Testing with empty deck but populated discard pile
adventurer_card doesn't shuffle discard pile back into deck as stated
ADVENTURER_CARD: TESTING HAS FOUND ERRORS


TESTING council_room_card()
Game of 3 players
coucil_room_card has not returned successfully
council_room_card does not add correct number of buys
COUNCIL_ROOM_CARD: TESTING HAS FOUND ERRORS


TESTING sea hag switch case in cardeffect()
 Game of 3 players
sea_hag was not placed in played pile
Incorrect number of cards in Player 1 hand
Player 2/3 decks altered in unexpected way
Player 2/3 did not obtain the curse card at top of deck
Wrong top of deck cards were discarded
SEA_HAG TESTING HAS FOUND ERRORS


Random Adventurer Card Tests------------------------

HandCount Failures: 996/1000     HandCount Passes: 4/1000
DeckCount Failures: 9/1000       DeckCount Passes: 991/1000
PlayedCardCount Failures: 1000/1000      PlayedCardCount Passes: 0/1000
Resulting Cards Failures: 983/983        Resulting Cards Passes: 0/983

Random Sea Hag Card Tests------------------------

Played Pile Failures: 1000/1000  Played Pile Passes: 0/1000
Top Deck Failures: 1000/1000     Top Deck Passes: 0/1000
Deck Count Failures: 0/1000      Deck Count Count Passes: 1000/1000
HandCount Failures: 1000/1000    HandCount Passes: 0/1000
Opp. Deck Count Failures: 1000/1000      Opp. Deck Count Passes: 0/1000
Top Card Failures: 980/1000      Top CardPasses: 20/1000