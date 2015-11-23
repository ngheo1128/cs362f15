Robert,

You had this:
for(i=1;i<state->numPlayers;i++)
should be this:
for(i=0;i<state->numPlayers;i++)

And for village, you had this:
	state->numAction= 2;
should be this:
	state->numAction=state->numActions + 2;		

Also these tests failed: (These were found after my initial report to team member, so he was not informed of these following bugs)
*****************************************************
*CARDTEST2 Suite
  (tests ADVENTURER with 3 semi-random states)
*****************************************************
Test handCount+=1: FAILED
handCount Before: 10
handCount After: 12
*****************************************************
*CARDTEST4 Suite
  (tests VILLAGE with 3 semi-random states)
*****************************************************
Error: playedCards changed.
playedCard#1 Before: 16
playedCard#1 After: 3

Error: playedCardCount changed.
playedCardCount Before: 1
playedCardCount After: 2




Kevin,

For Adventurer, you had this:
	if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)
should be this:
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)

For Remodel, you had this:
	gainCard(choice1, state, 0, currentPlayer);
should be this:
	gainCard(choice2, state, 0, currentPlayer);

Below are additional tests that were not included in the bug report I sent to my teammate, so he does not know about these:
*****************************************************
*CARDTEST4 Suite
  (tests VILLAGE with 3 semi-random states)
*****************************************************
Test numActions+=2: FAILED
numActions Before: 13
numActions After: 2

Error: playedCards changed.
playedCard#7 Before: 4
playedCard#7 After: 7

Error: playedCardCount changed.
playedCardCount Before: 7
playedCardCount After: 8
*****************************************************
*CARDTEST2 Suite
  (tests ADVENTURER with 3 semi-random states)
*****************************************************
Test handCount+=1: FAILED
handCount Before: 9
handCount After: 11

Test handCount+=1: FAILED
handCount Before: 10
handCount After: 12

Test handCount+=1: FAILED
handCount Before: 2
handCount After: 4
