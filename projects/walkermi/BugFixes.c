Bug Fixes Report





Bug Report From Teammate One:
	- Teammate one did not submit a bug report to me because he did not create any unit tests, card tests, or
		random tests 



Bug Report From Teammate Two:
	-------------------------------------------------------------------------------
		-------------------------------------------------------------------------------
		Testing Method  : playCard()
		Seed            : 10
		  TEST FAIL    : Coin increment check failed

		    Tests Passed    : 4
		    Tests Failed    : 1
		-------------------------------------------------------------------------------

		-------------------------------------------------------------------------------
		-------------------------------------------------------------------------------
		Testing Method  : smithy()
		Seed            : 10
		  TEST FAIL    : Smithy card added correct number of cards failed
		    Tests Passed    : 0
		    Tests Failed    : 1
		-------------------------------------------------------------------------------

		-------------------------------------------------------------------------------
		-------------------------------------------------------------------------------
		Testing Method  : great_hall()
		Seed            : 10
		  TEST FAIL    : great_hall card add card to hand failed
		    Tests Passed    : 1
		    Tests Failed    : 1
		-------------------------------------------------------------------------------

		-------------------------------------------------------------------------------
		-------------------------------------------------------------------------------
		Testing Method  : adventurer()
		Seed            : 10
		  TEST FAIL    : Adventurer add correct number of cards to hand failed
		    Tests Passed    : 1
		    Tests Failed    : 1
		-------------------------------------------------------------------------------




		Random test bugs found (make randomtestadventurer.out)

		-------------------------------------------------------------------------------
		-------------------------------------------------------------------------------
		Testing Method  : adventurer()
		  TEST FAIL    : Adventurer add correct number of cards to hand failed : ev = 0 , actual = 2
	-------------------------------------------------------------------------------





Bug Fixes Based on Teammate Two's Report:

1.)
	1.a) Test That Failed
	-------------------------------------------------------------------------------
	Testing Method  : playCard()
	Seed            : 10
	  TEST FAIL    : Coin increment check failed

	    Tests Passed    : 4
	    Tests Failed    : 1
	-------------------------------------------------------------------------------

	1.b) Code Before Bug Fix

		int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
		{	
		  int card;
		  int coin_bonus = 0; 

		  if (state->phase != 0)
		    {
		      return -1;
		    }
			
		  if ( state->numActions < 1 )
		    {
		      return -1;
		    }
			
		  card = handCard(handPos, state);
			
		  if ( card < adventurer || card > treasure_map )
		    {
		      return -1;
		    }
			
		  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		    {
		      return -1;
		    }
			
		  state->numActions--;

		  updateCoins(state->whoseTurn, state, coin_bonus);
			
		  return 0;
		}


	1.c) Code After Bug Fix

		int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
		{	
		  int card;
		  int coin_bonus = 0; 

		  if (state->phase != 0)
		    {
		      return -1;
		    }
			
		  if ( state->numActions < 1 )
		    {
		      return -1;
		    }
			
		  card = handCard(handPos, state);
			
		  if ( card < adventurer || card > treasure_map )
		    {
		      return -1;
		    }
			
		  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		    {
		      return -1;
		    }
			
		  state->numActions--;

		  updateCoins(state->whoseTurn, state, coin_bonus + state->coins);	// LINE CHANGED
			
		  return 0;
		}


	1.d) Analysis
		- This bug was actually fairly subtle to catch and was due to the updateCoins() method resetting the
			current players coin count every time a card was played. To remediate the problem the states coins
			were added to the bonus value in when updateCoins is called in the function play card.


2.)
	2.a) Test That Failed
	-------------------------------------------------------------------------------
	Testing Method  : smithy()
	Seed            : 10
	  TEST FAIL    : Smithy card added correct number of cards failed
	    Tests Passed    : 0
	    Tests Failed    : 1
	-------------------------------------------------------------------------------

	2.b) Code Before Bug Fix
		
		int cardEffect_Smithy(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer, int i) {
		    for (i = 0; i <= 3; i++)
		    {
		        drawCard(currentPlayer, state);
		    }
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


	2.c) Code After Bug Fix
		
		int cardEffect_Smithy(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer, int i) {
		    for (i = 0; i < 3; i++)			// LINE CHANGED
		    {
		        drawCard(currentPlayer, state);
		    }
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


    2.d) Analysis
		- This bug was caused from the for loop drawing cards being changed from "<" to "<=" which made one more additinal
			card being drawn (four instead of three)


3.)
	3.a) Test That Failed
	-------------------------------------------------------------------------------
	Testing Method  : great_hall()
	Seed            : 10
	  TEST FAIL    : great_hall card add card to hand failed
	    Tests Passed    : 1
	    Tests Failed    : 1
	-------------------------------------------------------------------------------

	3.b) Code Before Bug Fix

		int cardEffect_GreatHall(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    drawCard(currentPlayer, state);
		    
		    state->numActions++;
		    
		    return 0;
		}


	3.c) Code After Bug Fix
	
		int cardEffect_GreatHall(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    drawCard(currentPlayer, state);
		    
		    state->numActions++;
		    discardCard(handPos, currentPlayer, state, 0);	// LINE ADDED
		    return 0;
		}


	3.d) Analysis
		- This bug was a little tricky to diagnose due to the wording on the unit test that failed. The unit test says 
			that the Great Hall card did not add a card to the players hand, however the code does in fact add a card
			to the players hand. I had to look at the source code of the unit test to realize the unit test was simply
			looking at hand count and not what cards were in the players hand. The bug was stopping the Great Hall card
			from being discarded so the player hand count was one greater than it should be which in turn caused the unit
			test to fail. The line that discarded to Great Hall card was added to the function and the bug was removed.


4.)
	4.a) Test That Failed
	-------------------------------------------------------------------------------
	Testing Method  : adventurer()
	Seed            : 10
	  TEST FAIL    : Adventurer add correct number of cards to hand failed
	    Tests Passed    : 1
	    Tests Failed    : 1
	-------------------------------------------------------------------------------

	4.b) Code Before Bug Fix

		int cardEffect_Adventurer(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int drawntreasure, int currentPlayer, int cardDrawn, int temphand[], int z) {
		    while(drawntreasure<2){
		        if (state->deckCount[currentPlayer] <1){
		            shuffle(currentPlayer, state);
		        }
		        drawCard(currentPlayer, state);
		        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		            drawntreasure++;
		        else{
		            temphand[z]=cardDrawn;
		            z++;
		        }
		    }
		    while(z-1>=0){
		        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
		        z=z-1;
		    }
		    return 0;
		}


	4.c) Code After Bug Fix

		int cardEffect_Adventurer(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int drawntreasure, int currentPlayer, int cardDrawn, int temphand[], int z) {
		    while(drawntreasure<2){
		        if (state->deckCount[currentPlayer] <1){
		            shuffle(currentPlayer, state);
		        }
		        drawCard(currentPlayer, state);
		        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		            drawntreasure++;
		        else{
		            temphand[z]=cardDrawn;
		            state->handCount[currentPlayer]--;		// LINE ADDED
		            z++;
		        }
		    }
		    while(z-1>=0){
		        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
		        z=z-1;
		    }
		    return 0;
		}


    4.d) Analysis
		- The bug was caused from the line that removed the top card from the temp hand from the players hand being removed
			which in turn made the non-treasure cards stay in the players hand instead of being discarded. 





Bug Fixes Based on Initial Refactoring:

1.) Salvager Card

	1.a) Code Before Bug Fix
		
		int cardEffect_Salvager(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    state->numBuys++;
		    
		    if (choice2)
		    {
		        state->coins = state->coins + getCost( handCard(choice1, state) );
		        discardCard(choice1, currentPlayer, state, 1);
		    }
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


	1.b) Code After Bug Fix

		int cardEffect_Salvager(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    state->numBuys++;
		    
		    if (choice1)	// LINE CHANGED
		    {
		        state->coins = state->coins + getCost( handCard(choice1, state) );
		        discardCard(choice1, currentPlayer, state, 1);
		    }
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


	1.c) Analysis
		- This bug was very subtle and was not caught be any unit tests (my own or my teammates). This bug changed the if
			statement in the code to be based on "choice2" instead of "choice1"

2.) Village Card

	2.a) Code Before Bug Fix
		
		int cardEffect_Village(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    drawCard(currentPlayer, state);
		    
		    state->numActions = state->numActions + 1;
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


	2.b) Code After Bug Fix
		
		int cardEffect_Village(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int currentPlayer) {
		    drawCard(currentPlayer, state);
		    
		    state->numActions = state->numActions + 2;		// LINE CHANGED
		    
		    discardCard(handPos, currentPlayer, state, 0);
		    return 0;
		}


    2.c) Analysis
		- This bug was fairly obvious as it simply changed the added actions for the current player from two to one.




Bug Fixes Based on My Unit & Card Tests:

1.) Adventurer Card

	1.a) Test That Failed
		Player: 2, Hand Count: 5
		Test 1: Adventurer Card is Discarded From Hand to Played Pile
		Expected: Adventurer Card Not In Hand
		ERROR: Adventurer Card Still In Hand
		Expected: Adventurer Card in Played Pile
		ERROR: Adventurer Card Not In Played Pile

	1.b) Code Before Bug Fix

		int cardEffect_Adventurer(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int drawntreasure, int currentPlayer, int cardDrawn, int temphand[], int z) {
		    while(drawntreasure<2){
		        if (state->deckCount[currentPlayer] <1){
		            shuffle(currentPlayer, state);
		        }
		        drawCard(currentPlayer, state);
		        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		            drawntreasure++;
		        else{
		            temphand[z]=cardDrawn;
		            state->handCount[currentPlayer]--;
		            z++;
		        }
		    }
		    while(z-1>=0){
		        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
		        z=z-1;
		    }
		    return 0;
		}


	1.c) Code After Bug Fix

		int cardEffect_Adventurer(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus, int drawntreasure, int currentPlayer, int cardDrawn, int temphand[], int z) {
		    while(drawntreasure<2){
		        if (state->deckCount[currentPlayer] <1){
		            shuffle(currentPlayer, state);
		        }
		        drawCard(currentPlayer, state);
		        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		            drawntreasure++;
		        else{
		            temphand[z]=cardDrawn;
		            state->handCount[currentPlayer]--;		
		            z++;
		        }
		    }
		    while(z-1>=0){
		        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
		        z=z-1;
		    }
		    discardCard(handPos, currentPlayer, state, 0);		// LINE ADDED
		    return 0;
		}


    1.d) Analysis
		- This bug was actually in the original version of dominion that was provided to us and not added through my initial
			refactoring. The adventurer card was never dicarded from the current players hand due to the discardCard() function 
			never being called.





