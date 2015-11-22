Ben Henning
CS 362
Assignment 5
Bugfixes.c

Fixes for bugs reported by teammates:

/************************
1. Function isGameOver()
*************************/
BUG: 'game over' value is not returned in cases where 3 of the supply reserves are empty.
Teammate 1's test found this bug but mine did not, so it does not happen in all cases.

FIX: The for loop in the isGameOver function only iterates over the first 25 cards when
there are actually 27 different possible cards to check. This would cause the function to
return an incorrect value if sea_hag or treasure_map were empty. Changed the for-loop statement
from "for (i = 0; i < 25; i++)" to "for (i = 0; i <= treasure_map; i++)"
*Also modified a test case in unittest2.c to verify the fix worked

/*********************
2. Function scoreFor()
**********************/
BUG: Teammate reported that this function failed all tests. Upon examination of the code,
it looks like the loop that is supposed to score the cards in the player's deck is running
discardCount times instead of deckCount times.  Also, scoreFor is mistakenly calling the
function fullDeckCount for gardens and expecting the total number of cards in hand+deck+discard when
fullDeckCount only provides the total of a certain card.

FIX 1: Changed the third for-loop in scorefor from "for (i = 0; i < state->discardCount[player]; i++)"
to "for (i = 0; i < state->deckCount[player]; i++)"

FIX 2: Replaced calls to fullDeckCount within the scoreFor function with the following:
(state->handCount[player] + state->deckCount[player] + state->discardCount[player])

/**************
3. Smithy Card
***************/
BUG: Smithy draws 4 cards instead of 3

FIX: Changed for-loop in smithyCardEffect from "for (i = 0; i <= 3; i++)" to "for (i = 0; i < 3; i++)"
*A teammate also reported that smithy was not being discarded. This was probably an effect of an
extra card being drawn. Smithy contains a call to discard() and now passes all checks.

/*****************
4. Adventurer Card
******************/
BUG: Adventurer effect increases handcount far more than expected.

FIX: In the else block in the adventurerCardEffect function, changed the line
"state->handCount[currentPlayer]++" to "state->handCount[currentPlayer]--"

BUG: Cases in which there are less than 2 treasure cards in the deck + discard pile result in
a negative deck count.

FIX: Modified the while loop to make sure there is at least one card left in deck+discard. If there
is not, the loop ends.  Specifically, changed "while(drawntreasure<2" to
"while(drawntreasure<2 && (state->deckCount[currentPlayer] > 0 || state->discardCount[currentPlayer] > 0))"
*Modified randomtestadventurer to check for these conditions

Bugs that I introduced or found:

/*****************
1. Adventurer Card
******************/
BUG: Adventurer card is not discarded

FIX: Added call to discard function in adventurerCardEffect.  AdventurerCardEffect also takes
handpos as an argument now since it needs it for discard function.

/*****************
2. Steward Card
******************/
BUG: The two cards that were supposed to be trashed were discarded instead.

FIX: In the final else block in the stewardCardEffect function, changed the 4th argument from 0 to 1,
setting the trash flag.

/*****************
3. Sea_Hag Card
******************/
BUG: Sea_hag was affecting the current player instead of the other players.

FIX: Changed the if statement from "if (i == currentPlayer)" to "if (i != currentPlayer)"

BUG: Sea_hag decrements all other players' deck counts by 3

FIX: Sea_hag was decrementing deckCount at several locations in the code by using "--" instead of "-1".
Since the top card in the deck is replaced with a curse, deckCount does not need to be decremented at all.
Changed the code block within the if statement from:
    state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];
    state->deckCount[i]--;
    state->discardCount[i]++;
    state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
to:
    state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]-1];
    state->discardCount[i]++;
    state->deck[i][state->deckCount[i]-1] = curse;//Top card now a curse

BUG: Sea_hag is not discarded

FIX: Added call to discardCard at end of seaHagCardEffect. Function now takes handPos as an argument
since it is required for discardCard.


