Billy Kerns
Assignment 5
BugFixes.c

ID:
	1

Description:
	adventureCard() causes segFault when deck is empty

Discussion:
	I think the cause of this bug is the while loop running over and over again if it can't find two treasures.
	So to fix this I intoduced a new variable in the adventureCard while loop that counts how many times the deck
	is shuffled. At the top of the while loop a check is done to make sure the deck is only shuffled once preventing
	the segFault.

Fix:
	while(drawntreasure<2 && shuffled <= 1){
    	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    	shuffle(currentPlayer, state);
    	shuffled++;
  	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	2

Description:
	adventureCard() loses 1 card from deck on every call (My introduced bug)

Discussion:
	This bug is due to my introduced bug that made the while loop terminate early.  With the while loop terminating 
	early not all of the cards that were added to the temphand are added to the discard.

Fix:
	while(z-1>0){ back to while(z-1>=0){

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	3

Description:
	smithyCard() not discarding card properly (My introduced bug)

Discussion:
	This bug is due to my introduced bug that set the trashFlag when the smithyCard was played.  This causes the card to be
	trashed instead of recycled back to the discard pile. 

Fix:
	discardCard(handPos, currentPlayer, state, 1); changed back to this discardCard(handPos, currentPlayer, state, 0);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	4

Description:
	isGameOver() returns false negative on certain empty cards

Discussion:
	This bug is due to a for loop that only runs to 25 which does not count all the cards. It should go to 27 to make sure
	each card is counted.  

Fix:
	Changed (i = 0; i < 25; i++) to for (i = 0; i < 27; i++)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	5

Description:
	Deck not decremented after draw

Discussion:
	This bug only shows up when both deckCount and discardCount are 0.  Since the deck is 0 and there is no discard to
	shuffle back in the deck the card does nothing and the deck is not decremented which is correct.  So nothing is done
	to fix this because I am not sure it is a bug.

Fix:
	None

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	6

Description:
	Adventurer card is not discarded after it has been played

Discussion:
	This bug was due to there not being a call to discardCard in the adventureCard function.  To fix the bug a call to
	discardCard was add to the adventureCard right before it exits.  This required adding a new argument to adventureCard
	to keep track of cards position in the hand.  

Fix:
	The adventureCard declaration was changed from
	int adventureCard(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[], int z, int cardDrawn){
	to
	int adventureCard(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[], int z, int cardDrawn, int handPos){
	Within this function  discardCard(handPos, currentPlayer, state, 0); was added.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	7

Description:
	CouncilRoom card decreases number of buys instead of increasing it (My introduced bug)

Discussion:
	This was a bug I implemented to make the card do the opposited of what it should.

Fix:
	state->numBuys-- was changed back to state->numBuys++

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	8

Description:
	When the minion card is played with choice2 players draw one too many cards (My introduced bug)

Discussion:
	This bug that I introduced causing players to get extra cards when choice2 was selected and their handCount was less
	than 4.  Meaning this bug was a little bit more hidden than some of the others.  In addition to this a player could
	not even get to choice2 due to an additonal bug in the minion card hiding it even further.

Fix:
	(j = 0; j < 5; j++) was changed back to for (j = 0; j < 4; j++)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ID:
	9

Description:
	When the minion card is played the correct choice is not always selected (My introduced bug)

Discussion:
	This is the additonal bug mentioned in bug ID 8.  This bug causes the minion card to disregard the player''s choice.
	Since the if block has no else catch the minion card was essentially do nothing except discard the minion card.

Fix:
	(!choice1) was changed back to (choice1)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
