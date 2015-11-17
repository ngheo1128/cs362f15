Introduction
============
For the following tests, I used my unit tests and card tests developed over the past few weeks.
The tests were largely developed as random tests with the exception being the test for the
adventurer card.  This week I adapted the tests to the new dominion.c file and functions and
ran the tests.

Teammate 1
==========
Project Folder: dmachowi
-
	UNIT TEST 1 - initializeGame()
		No adaptations to the test were neccesary, no bugs were found in this function.  This is
		not too surprising since I found no bugs in my copy of the code either, nor were we asked to
		introduce new bugs to this function.

		
	UNIT TEST 2 - shuffle()
		No adaptations to the test were neccesary, no bugs were found in this function.  This is
		not too surprising since I found no bugs in my copy of the code either, nor were we asked to
		introduce new bugs to this function.		
	
	
	UNIT TEST 3 - isGameOver()
		No adaptations to the test were neccesary.  It appears that the same bug that existed in my
		copy of the code is present in this copy as well -- that is, a 'game over' value is not
		accurately returned when one should for instances were three of the supply reserves have
		been depleted.
		
		To be accurately returned, the line
			for (i = 0; i < 25; i++)	
		should be changed to no include a hard coded value for i.  An appropriate change would be:
			for (i = 0; i <= treasure_map; i++)
		
		
	UNIT TEST 4 - scoreFor()
		No adaptations to the test were neccesary.  It appears that the same bug that existed in my
		copy of the code is present in this copy as well.
		
		RESULTS:
		The unit test immediately reported an error in nearly every case.  It would appear that garden
		score calculation was poorly implimented.  While garden is supposed to give a point for every 10
		cards a player owns in the deck, hand, or discard, by using the function fullDeckCount() in it's
		equation, it ends up having problems.

		fullDeckCount looks to be something of a poor evolution of a function with poor or outdated
		documentation.  The header file states that fullDeckCount returns deck+hand+discard... in which
		case scoreFor should work.  However, fullDeckCount clearly only counts the number of a particular
		card.  It's possible that the functionality of fullDeckCount had changed from its original meaning.
		That is to say, fullDeckCount(player, 0, gs) only counts the number of curse cards in the deck, hand,
		and discard pile.
	
	
	CARD TEST 1 - SMITHY
		I did have to make some minor adaptations to my test to match this function.
			Original prototype:	int playSmithy(int handPos, int currentPlayer, struct gameState *state);
			New prototype:		void playSmithy(struct gameState *state, int handPos);
		
		While mostly the same, I had my tests assign currentPlayer to the gamestate member variable
			gs->whoseTurn
		
		I also had to remove reading in of the return value since no return value was given.  Of
		course, this turned out to be not much of a problem since I didn't use the return value
		anyway.
		
		RESULTS:
		The results of the adapted test revealed an issue with the smithy card function.  I came
		across the following issues:
		* It appears the smithy card is not properly discarded at the end of the function.
		* It appears that an extra card is drawn because handCount is +1 and discardCount is -1
		
		The first problem was actually a problem I had found in my own tests.  It's actually a
		problem with a the function discardCard() which doesn't actually properly do as its supposed
		to.
		
		The second problem however, is a problem with the following line:
			for (i = 0; i <= 3; i++)
		This line iterates the next command 4 times, not the intended 3 times.  To fix:
			for (i = 0; i < 3; i++)
	

	CARD TEST 2 - ADVENTURER
	I made some minor adaptations to this test as well.
		Original prototype: int playAdventurer(int currentPlayer, struct gameState *state);
		New prototype:		void playAdventurer(struct gameState *state);
	
	To make the adaptations, I removed references to a return variable in my test and assigned
	member variable gs->whoseTurn with currentPlayer
	
		Trial 1
		Test for identification of treasure cards (copper and silver)
		* Mismatched discardCount. Expected: 10, Actual: 11
		
		Trial 2
		Test for identification of treasure cards (copper and silver)
		* Mismatched discardCount. Expected: 10, Actual: 11
		
		Trial 3
		Test for Skipping of all other Treasure Cards
		* Mismatched deckCount. Expected: 0, Actual: 24
		* Mismatched discardCount. Expected: 12, Actual: 11
		
		Trial 4
		Treasure cards must be drawn from Discard
		* Mismatched deckCount + discardCount. Expected: 13, Actual: 14
		
		Trial 5
		NOT ENOUGH TREASURES
		* Mismatched deckCount + discardCount. Expected: 15, Actual: 14
		* Mismatched handCount. Expected: 5, Actual: 7
	
	Further, running the random tests for this function revealed that an extra card was found either
	in the deck or discard... and two treasure cards were not always present in the hand.
	
	The culprit appears to be this line:
		if (state->deckCount[currentPlayer] <=1){//if the deck is empty we need to shuffle discard and add to deck
	which shuffles the discard into the deck while there is still a card left to draw.  It should read:
		if (state->deckCount[currentPlayer] <= 0){//if the deck is empty we need to shuffle discard and add to deck
	
	
	Another issue that appears is as follows.
		if ((cardDrawn = copper) | (cardDrawn = silver) | (cardDrawn = gold)){
	which should read as:
		if ((cardDrawn == copper) || (cardDrawn == silver) || (cardDrawn == gold)){
	
	The buggy line caused the cardDrawn to always register as a treasure card since it converts the
	card.  This would explain the failure in trial three.
	
	The last issue is where the discard is larger than what we had expected.  The reason for this is
	that the variable z has been improperly initialized.  Changing the following line will fix it:
		int z = 1;
	to
		int z = 0;
		
	Finally, fixing these issues reveals an original bug where playAdventurer did not work if there
	were less than two treasures present in either the deck or discard pile combined.  A fix for this
	would be to add a condition in the while loop that stopped the search when the deck and discard pile
	were empty.
	
	
		
Teammate 2
==========
Project Folder: henningb
-
	UNIT TEST 1 - initializeGame()
		No adaptations to the test were neccesary, no bugs were found in this function.  This is
		not too surprising since I found no bugs in my copy of the code either, nor were we asked to
		introduce new bugs to this function.

		
	UNIT TEST 2 - shuffle()
		No adaptations to the test were neccesary, no bugs were found in this function.  This is
		not too surprising since I found no bugs in my copy of the code either, nor were we asked to
		introduce new bugs to this function.		
	
	
	UNIT TEST 3 - isGameOver()
		No adaptations to the test were neccesary.  It appears that the same bug that existed in my
		copy of the code is present in this copy as well -- that is, a 'game over' value is not
		accurately returned when one should for instances were three of the supply reserves have
		been depleted.
		
		To be accurately returned, the line
			for (i = 0; i < 25; i++)	
		should be changed to no include a hard coded value for i.  An appropriate change would be:
			for (i = 0; i <= treasure_map; i++)
		
		
	UNIT TEST 4 - scoreFor()
		No adaptations to the test were neccesary.  It appears that the same bug that existed in my
		copy of the code is present in this copy as well.
		
		The unit test immediately reported an error in nearly every case.  It would appear that garden
		score calculation was poorly implimented.  While garden is supposed to give a point for every 10
		cards a player owns in the deck, hand, or discard, by using the function fullDeckCount() in it's
		equation, it ends up having problems.

		fullDeckCount looks to be something of a poor evolution of a function with poor or outdated
		documentation.  The header file states that fullDeckCount returns deck+hand+discard... in which
		case scoreFor should work.  However, fullDeckCount clearly only counts the number of a particular
		card.  It's possible that the functionality of fullDeckCount had changed from its original meaning.
		That is to say, fullDeckCount(player, 0, gs) only counts the number of curse cards in the deck, hand,
		and discard pile.
		
		
	CARD TEST 1 - SMITHY
	
	
	CARD TEST 2 - ADVENTURER

Conclusions
===========
