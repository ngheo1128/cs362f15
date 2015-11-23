
/*****************************************************************************
Title: BugFixes.c
Assignment: 5

Purpose: Record bugs reported to me in dominion code and record the code corrections
implemented to fix bugs. Fix bugs not found by teammates that were originally
mentioned in refactor.c
******************************************************************************

------------------------   Bug #1 ----------------------------
REPORTED:
Title:             Adventure Card Coin increase
Class:             Bug, Minor

Reporter:          Connor Peavey
Email:             Connorpeavey@gmail.com

Description:   	   While running unit test on adventureCard it was discovered that coin amount was being incremented twice.
                   The author of the original program wrote "Use as you see fit" near the coin value, so this may
                   be a perfectly legal function.

Expected Results:  Coin amount in gamestate remains unchanged.
Actual Results:    Coin amount in gamestate is increased by two.

CODE CAUSING ERROR:
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
            drawntreasure++;
            state->coins = state->coins++;
        }else{

FIX IMPLEMENTED:
Removed the line that increased the coins for the current state.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
            drawntreasure++;
        }else{



---------------------- BUG # 2 --------------------------------
REPORTED:
Title: 				Adventurer card effect does not discard played card
Class: 				Bug, major

Reporter: 			Sharon Kuo
Email: 				kuos@oregonstate.edu

Description:		Used a unit test written for the adventurer card function to compare values of
					the player's hand count, deck count, discarded card count, and played card
					count from before and after playing the adventurer card. The hand count and
					played card counts are not as expected (1 more hand count and 1 less played
					card than expected).

Expected Results: 	game.handCount[0] = 4		game.playedCardCount = 1
Actual Results:		game.handCount[0] = 5		game.playedCardCount = 0

CODE CAUSING ERROR:
      while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
        z=z-1;
      }
      
    return 0;

FIX IMPLEMENTED:
Discarded the played card via discardCard function. This increased playedCardCount as long as the discard
flag is set.

      while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
      }

      discardCard(handPos, currentPlayer, state, 0);
      
    return 0;


---------------------- BUG #3  --------------------------------
REPORTED:
Title:              Incorrect card draw in smithy card
Class:              Bug, Major

Reporter:           Connor Peavey
Email:              Connorpeavey@gmail.com

Description:   	    While running unit test on cardEffect it was discovered that current players hand was 
                    being increased by 3 instead of 2. 


Expected Results:   Current player hand is increased by 2.
Actual Results:     Current player hand is increased by 3.

Title: 		    Smithy card effect draws too many cards
Class: 		    Bug, major

Reporter: 	   Sharon Kuo
Email: 		   kuos@oregonstate.edu

Description:	   Used a unit test written for the smithy card function to compare values of the
      		  player's hand count, deck count, discarded card count, and played card count
		  from before and after playing the smithy card. The hand count and deck counts
		  are not as expected. 

Expected Results:	game.handCount[0] = 5       game.deckCount[0] = 2
Actual Results:		game.handCount[0] = 6


CODE CAUSING ERROR:
    for (i = 0; i <= 3; i++)
	{
	  drawCard(currentPlayer, state);
	}

FIX IMPLEMENTED:
Remove equal sign from loop to correct number of cards drawn.
    for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}



---------------------- BUG #4 --------------------------------
REPORTED: 		Not reported by teammates
Class: 			Bug, minor

Description: 	When baron card is played the current player gains a duchy instead
		of an estate.

Expected Results:	testState->supplyCount[duchy] == state->supplyCount[duchy] -1
Actual Results:		testState->supplyCount[duchy] == state->supplyCount[duchy]

CODE CAUSING ERROR:
    if (supplyCount(duchy, state) > 0){
        gainCard(duchy, state, 0, currentPlayer);//Gain an estate
        state->supplyCount[duchy]--;//Decrement Estates
        if (supplyCount(duchy, state) == 0)
                

FIX IMPLEMENTED:
Changed estate to duchy in gainCard function, supplyCount, and game testing for isGameOver.
    if (supplyCount(estate, state) > 0){
         gainCard(estate, state, 0, currentPlayer);//Gain an estate
         state->supplyCount[estate]--;//Decrement Estates
         if (supplyCount(estate, state) == 0){
             isGameOver(state);
         }



---------------------- BUG #5 --------------------------------
REPORTED: 		Not reported by teammates
Class: 			Bug, minor

Description:	Call the steward card function. Select to have two cards trashed. The
		cards not indicating a trashed status. The cards are indicating a
		discarded status.

Expected Results:	testState->discardCount < 2
Actual Results:		testState->discardCount > 2

CODE CAUSING ERROR:
        //trash 2 cards in hand
        discardCard(choice2, currentPlayer, state, 0);
        discardCard(choice3, currentPlayer, state, 0);

FIX IMPLEMENTED:
Changed trash flag status to 1, to indicate the cards should be trashed.
        //trash 2 cards in hand
        discardCard(choice2, currentPlayer, state, 1);
        discardCard(choice3, currentPlayer, state, 1);


-

----------------------- BUG #6 ----------------------------
REORTED:
Title:            Infinite loop in Feast card
Class:            Bug, Major

Reporter:         Connor Peavey
Email:            Connorpeavey@gmail.com

Environment:      Tests run on GNU/Linux on server flip3
Reproducible:     True

Description:      While running unit test on cardEffect it was discovered that the feast case in cardEffect
                  causes the program to enter an infinite loop.

Replication:      Create a gamestate. The necessary requirements for creating the bug is that the current 
                  player have a feast card. Then the player must play the card, and select a gold card. Bug occurs.

Expected Results:  Gain a gold card.
Actual Results:    Program enters infinite loop.
	
STATUS:
Investigated Bug. Replicated Steps and tested with following test:

	struct gameState g;				// gamestate, original
	struct gameState testState;		// gamestate under test
	int k[10] = {feast, gardens, curse, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int p = 0;

		// Create a gamestate
		initializeGame(numPlayers, k, 1000, &g);
		memcpy(&testState, &g, sizeof(struct gameState));

		// Have a feast card, play the card, select curse
		cardEffect(feast, gold, 0, 0, &testState, 0, 0);
		printf("My hand: ");
		int hand = testState.handCount[p];
		printf("Hand: %d", hand);

RESULTS:			Infinite loop replicated.

CODE CAUSING ERROR:
  while( x == 1) {//Buy one card
	if (supplyCount(choice1, state) <= 0){
	  if (DEBUG)
	    printf("None of that card left, sorry!\n");

	  if (DEBUG){
	    printf("Cards Left: %d\n", supplyCount(choice1, state));
	  }
	}
	else if (state->coins < getCost(choice1)){
	  printf("That card is too expensive!\n");

	  if (DEBUG){
	    printf("Coins: %d < %d\n", state->coins, getCost(choice1));
	  }
	}
In this section of code x is never changed to 0 on the unit tests until a correct choice1 is acheived. While
this is managable in the AI run game, it is not while manually putting in a choice1 for a unit test.

FIX IMPLEMENTED:
Allowed for a return value to exit the infinite loop so function can be called with an appropriate choice1 value.
  while( x == 1) {//Buy one card
	if (supplyCount(choice1, state) <= 0){
	  if (DEBUG)
	    printf("None of that card left, sorry!\n");

	  if (DEBUG){
	    printf("Cards Left: %d\n", supplyCount(choice1, state));
	  }
    return -1;
	}
	else if (state->coins < getCost(choice1)){
	  printf("That card is too expensive!\n");

	  if (DEBUG){
	    printf("Coins: %d < %d\n", state->coins, getCost(choice1));
	  }
	}
    return -1;
  }else{


---------------------------- BUG #7 ---------------------------------

REPORTED:
Title: 			scoreFor() does not correctly count score for garden cards
Class: 			Bug, major

Reporter: 		Sharon Kuo
Email: 			kuos@oregonstate.edu

Description:	Used a unit test written for the scoreFor() function to calculate the score for
		players based on some generated sets of decks. Compared expected score with
		actual score for the following scenarios: empty deck, hand, and discard pile;
		15 kingdom and 3 garden cards; 15 treasure and 3 garden cards; 9 estate, 3
		duchy, 3 province, and 3 curse cards.

Expected Results:	15 kingdom cards and 3 garden cards (total of 18 cards): score = 3
					15 treasure cards and 3 garden cards (total of 18 cards): score = 3

Actual Results:		15 kingdom cards and 3 garden cards (total of 18 cards): score = 0
					15 treasure cards and 3 garden cards (total of 18 cards): score = 0

STATUS:
Tested the scoreFor function as well as the fullDeckCount function called within the sccoreFor()
function per replication specification. Additioanlly made sure the deckCount was set high eough to
allow for all 18 cards to be counted. Tested with the following code:

		// copy into a test state so I don't destroy the world
		initializeGame(numPlayers, k, 1000, &g);
		g.deckCount[p] = 13;
		memcpy(&testState, &g, sizeof(struct gameState));
		testState.hand[p][0] = gold;
		testState.hand[p][1] = gold;
		testState.hand[p][2] = gold;
		testState.hand[p][3] = gold;
		testState.hand[p][4] = gold;
		testState.deck[p][0] = gold;
		testState.deck[p][1] = gold;
		testState.deck[p][2] = copper;
		testState.deck[p][3] = gold;
		testState.deck[p][4] = silver;
		testState.deck[p][5] = copper;
		testState.deck[p][6] = gold;
		testState.deck[p][7] = gold;
		testState.deck[p][8] = gold;
		testState.deck[p][9] = gold;
		testState.deck[p][10] = gardens;
		testState.deck[p][11] = gardens;
		testState.deck[p][12] = gardens;
		deckSize = testState.deckCount[p];
		int score = 0;
		printf("Deck: %d\n", deckSize);
		int count = fullDeckCount(p, 0, &testState);
		if(count != 18)
			printf("Error in fullDeckCount");
		printf("\nCount: %d\n", count);
		score = scoreFor(p, &testState);
		if(score != 3){
			printf("Error in scoreFor");
		}
		printf("Score %d\n", score);

	return 0;

RESULTS: 	Same as reported.

CODE CAUSING ERROR:
 if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
 
 AND

  for (i = 0; i < state->deckCount[player]; i++)
    {
     if (state->deck[player][i] == card) 
     	 count++;
    }
The garden card is supposed to add 1 point for every 10 cards the player has, rounded down. So,
if the deckCount is set to allow for all cards in this test deck with 3 garden cards and 18 cards
total, the above code does not accurately count all cards, as it is matching to card zero.

FIX IMPLEMENTATION:
Removed the if statement matching to card zero, instead allowing for full card count.
 for (i = 0; i < state->deckCount[player]; i++)
    count++;

  for (i = 0; i < state->handCount[player]; i++)
    count++;

  for (i = 0; i < state->discardCount[player]; i++)
   	count++;

  return count;

  CHECKED RESULTS WITH TEST: 	Score = 3, correct
