/*
Bugs Teammate2 found: Kelvin Watson

Bug 1. 2 errors
Error: Extra card in hand after smithyCard() called
Error: Number of cards less in deck 1 less than expected after smithyCard() called
Fixed: YES
Explanation of fix: Given the behavior and since this is a bug I introduced I fixed the bug
by removing the = symbol in the for loop inside smithyCard() in dominion.c; fixed line for 
(i = 0; i < 3; i++) which was originally for (i = 0; i <= 3; i++)

Bug 2.
Error: Number of gold cards in adventurerCard() consistently computes to 0
Fixed: YES
Explanation of fix: Another bug I introduced by omitting gold cards from adventurerCard()
in the following conditional statement. if (cardDrawn == copper || cardDrawn == silver) is
the original buggy version. (cardDrawn == copper || cardDrawn == silver || cardDrawn == 
gold) is the new fixed code.

Bug 3.
Error: card at top of discard pile is not expected card in sea_hag for player
Fixed: YES but I left it commented it out because it causes a segfault
Explanation: Discard card not called in sea_hag so added line 
discardCard(handPos, currentPlayer, state, 0); but this player's test segfaults so I left
line 1222 commented out

Bug 4.
Error: card at top of oponent's deck not a curse card
Fixed: YES
Explanation: In sea_hag changed state->deck[i][state->deckCount[i]--] = curse; to line
state->deck[i][state->deckCount[i]-1] = curse; so the deckCount is not incorrectly
decremented putting the curse card in the second to last position

Bug 5.
Error: number of curse cards in game supply not decremented
Fixed: YES
Explanation: After the top card on the deck is initialized as a curse there is no logic
to decrement the curse count supply so I added state->supplyCount[curse]--; to fix it

Bug 6.
Error: DeckCount is decrementing 3 cards when it should not decrement anything
Fixed: YES
Explanation: Changed line state->discard[i][state->discardCount[i]++] = 
state->deck[i][state->deckCount[i]--]; to state->discard[i][state->discardCount[i]++] = 
state->deck[i][state->deckCount[i]-1]; so the deckCount isn't decremented 

Bug 7.
Error: After a call to discardCard(), the discard count remains the same 
Fixed: YES
Explanation: Changed line state->playedCardCount++; to state->discardCount[currentPlayer]++; 
Discard count was never incremented

Bug 8.
Error:
Fixed: YES
Explanation: Changed line to state->playedCards[state->playedCardCount] = 
state->hand[currentPlayer][handPos]; to state->discard[currentPlayer][state->discardCount
[currentPlayer]] = state->hand[currentPlayer][handPos]; because the current card played
wasn't reaching the discard pile


Bugs Teammate1 found: Dustin Dinh
Adventurer Card:
1) Description: Adventurer card did not go into discard pile after being played. 
Card remains in hand.
Fixed: YES
Explanation: Needed to call discardCard in adventurerCard

2) Description: Wrong type and number of coins drawn into hand.
Fixed: ALREADY FIXED in bug2

Smithy Card:
1) 	Description: Received 1 extra card. In test, hand size was 8 instead of 7.
Fixed: ALREADY FIXED in bug1

2)	Description: Card drawn hand does not match the first 3 cards on top of deck.
Fixed: ALREADY FIXED in bug1

Mine Card
1) 	Description: Cannot swap a higher costing coin for a lower or equivalent
costing coin.
Fixed: YES
Explanation: changed line from if ((getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2))
((getCost(state->hand[currentPlayer][choice1]) + 3) < getCost(choice2))

2)	Description: Mine card remains in hand when played.
Fixed: YES
Explanation: Already fixed discardCard

3)	Description: Swapped coin is missing from played area.
Fixed: YES
Explanation: Related to error 1 in mine

4) 	Description: Mine card missing from played. 
Fixed: YES
Explanation: Related to error 1 in mine

Minion Card
1)	Description: Bonus coins not received when choice 1 made.
Fixed: Not necessary
Explanation: Asked Teammate because this one odd and he said it should not have been included

2)	Description: Player 2 does not discard their cards when minion is played.
Fixed: YES
Explanation: Changed discardCard(handPos, i, state, 1); to discardCard(handPos, 
i, state, 0); as to avoid trashing the cards

isGameOver()
1)	Description: Depletion of Sea Hag plus 2 other piles does not end the game.
Fixed: YES
Explanation: Changed for loop bound i < 25 to i < 27 to account for all cards to end 
game properly

2)	Description: Depletion of Treasure Map plus 2 other piles does not end the game.
Fixed: YES
Explanation: Same as isGameOver error number 1

scoreFor()
1)	Description: Deck points are not scored correctly. 
Fixed: YES
Explanation: Changed the 3rd for loop to iterate through the deckCount instead of the 
discardCount twice

2) Description: Discard points are not scored correctly.
Fixed: YES
Explanation: Same as other scoreFor errror


Errors I introduced
tributeCard: 
Removed line 428 which was - shuffle(nextPlayer,state);//Shuffle the deck
in original refactor: changed back
Fixed: YES

council_roomCard: 
Changed line 463 in original refactor: changed back
from - for (i = 0; i < 4; i++)
to - for (i = 0; i <= 4; i++)
Fixed: YES

Removed lines 468 and 469 in original refactor: changed back
//+1 Buy
state->numBuys++;
Fixed: YES
*/