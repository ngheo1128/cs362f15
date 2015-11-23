Bug Fixes
For each bug I put what code changes I made, in general I used the tests my teammates used to find and fix the bugs.
Smithy
Reported Bugs
Player received less then 3 cards
extra cards added to players hand
smithy card adds an incorrect card to players hand
I beleive these bugs can be traced back to the loop counter on draw card in the smithy function
for (i = 0; i <+ 2; ++i)
to
for (i = 0; i <= 2; i++) this was causing only two cards to be drawn which was responsible for these 3 bugs.

Adventurer
Reported Bugs
Does not take card from deck
Results incorrect handcount. Bug report says two should be added but I beleive only one card should be added as adventurer was discarded
These can be tracked back to the following if statement
if (cardDrawn == copper && cardDrawn == silver && cardDrawn == gold)
this can only be tripped if the card drawn is copper, silver and gold which cant occur. This causes the card to not be added to hand
and messes up deck count. to fix it we change it to
if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
This fixed the issues of no cards being added to hand and the treasure cards being added to hand however now 2 cards were being
added to hand rather then one so to fix this we added a discard card statement to discard the adventurer card.
discardCard(handPos, currentPlayer, state, 0);


Council Room
Reported Bugs
Player received more then 4 cards
extra cards added to players hand
These two bugs can both be traced to the fact that on each time through the for loop draw card is called twice rather then once. To 
fix this I changed
   for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	  drawCard(currentPlayer, state);
	}
to 
	 for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}
This was causing 8 cards to be drawn instead of 4 which was messing things up.


Village
Reported Bugs
Player did not receive 2 actions from this card
This is due to fault in the following statement
state->numActions =2;
this is setting actions to 2 rather then increasing them by two to deal with this we change it to
state->numActions =state->numActions+2;

There were two bugs reported about actions being affected improperly. I beleive this is more of an issue with the how the code was tested then the
actual functions. As reducing the number of actions of called playcard not the actual function such as smithyfunction although I could be mistaken.

