/*
Solomon Huynh
CS362 Assignment 5
BugFixes.c

Bug Fixes:
1) adventureCard()
Card: Adventure
Bug: Doing a count of the treasured picked, after thecard was used, silver was not ever picked up.
After looking at the code, the function only picks up copper and gold cards.
Fix: Included silver card to be a treasure card so it will draw silver cards as well.
Changes: "if (cardDrawn == copper || cardDrawn == gold)" to
"if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)"

2) adventureCard()
Card: Adventure
Bug: The adventurerCard function does not discard the card used so after the card is played, it 
remains to be in the player's hand along with the two treasure cards drawn. The hand count and 
played cards does not update after playing adventurer card and is affected due to the bug.
Fix: Added the discard card function right before the return statement and included the hand
position as an argument.
Additions: "discardCard(handPos, currentPlayer, state, 0);"
Changes: "void adventurerCard(struct gameState *state){" to
"void adventurerCard(struct gameState *state, int handPos){"

3) smithyCard()
Card: Smithy
Bug: The number of cards drawn is 2 instead of 3. This was confirmed after the smithy card was 
used and checked the number of cards in hand, which is only 2.
Fix: Changed the for loop to loop 3 times instead of 2.
Changes: "for (i = 0; i < 2; i++)" to "for (i = 0; i < 3; i++)"

4) villageCard()
Card: Village
Bug: The number of actions increased should be two but it increased to three instead. The rest 
of the tests of drawing one card and discarding a card passed.
Fix: Changed the number of actions to be two instead of three.
Changes: "state->numActions = state->numActions + 3;" to "state->numActions = state->numActions + 2;"

5) councilRoomCard()
Card: Council Room
Bug: The number of cards drawn were 3 instead of 4. The number of buys and other players drawing 1 
card are correct.
Fix: The variable "i" starts at 0 instead of 1 to correctly draw 4 cards
Changes: "for (i = 1; i < 4; i++)" to "for (i = 0; i < 4; i++)"

6) isGameOver() (unit test)
Bug: Recap that rules for game over are either to have no province cards in the supply or three card 
supplies being depleted. When testing the function, it was noticed that it was checking if 25 cards 
are have no supplies left rather than the 27 cards that are available in the game. This is an 
obvious bug because the last two cards being depleted would not be checked at all.
Fix: Changes the loop to go from 0 to 27 instead of 0 to 25. This would check through all 27 cards.
Changes: "for (i = 0; i < 25; i++){" to "for (i = 0; i < 27; i++){"


*/