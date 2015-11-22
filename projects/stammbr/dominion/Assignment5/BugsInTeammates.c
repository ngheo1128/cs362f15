/*****************************************
 * Name:  Brian Stamm
 * Assignment:  5
 * Date:  11.22.15
 * Notes:  Bug number is the number of the bug, while the letter stands
 * for whose bug it refers to.
 * **************************************/

/****************************************
Teammate:  Wisam
Title:  Smithy - discard error
Bug Number:  1w
Class:  Serious Bug
Date:  11.22.15
Reported By:  Brian Stamm
Email:  stammbr@oregonstate.edu

Product:  dominion.c

Is it reproducible:  Yes.

Description:  When running the smithy_refactor() method, it does not discard the 
player's hand properly.  Instead of getting rid of the smithy card, it is kept in 
the player's hand.

Steps to Produce/Reproduce -
1.  Set initial variables.
	a)  Create struct gameState
	b)  Create an array of kingdom cards (adventurer, gardens, embargo, village, 
		minion, mine, cutpurse, sea_hag, tribute, smithy)
	c)  Seed rand, create a random int.
	d)  Create int players (at least 2, no more than 4)
	d)  Initialize game with initializeGame, (initializeGame(players, arrayKingdom,
		randomNum, gameState))
2.  Create int curPlayer, set to 1.
3.  Create int handPos, set to 0.
4.  Pass curPlayer, &gameState, and handPos to smithy_refactor.

Expected Results:  The game's playCardCount should be increased by one, and curPlayer's
discard count should also be increased.  Also, it should add 3 new cards, discard the 
current card.

Acutal Results:  It does not discard the played card, which does not increase the 
playedCardCount and curPlayer's discardCount.

Workarounds:	N/A  
****************************************/

/****************************************
Teammate:  Wisam
Title:  Adventurer - TOO MUCH TREASURE!
Bug Number:  2w
Class:  Serious Bug
Date:  11.22.15
Reported By:  Brian Stamm
Email:  stammbr@oregonstate.edu

Product:  dominion.c

Is it reproducible:  Yes.

Description:  When running the adventurer_refactor method, it adds an extra treasure
card to the player's hand.

Steps to Produce/Reproduce -
1.  Set initial variables.
	a)  Create struct gameState
	c)  Seed rand, create a random int.
	d)  Create int players (at least 2, no more than 4)
	d)  Initialize game with initializeGame, (initializeGame(players, arrayKingdom,
		randomNum, gameState))
2.  Create int curPlayer, set to 1.
3.  Create int z, set to 0, and do the same with an int cD.
4.  Create an array to hold player's deck (tempHand[MAX_HAND]).
5.  Create int treasure, set to zero - this counts how many treasure cards had been 
	found.
6.  Set curPlayer's deck with random cards, with at least 3 treasure cards.
7.  Pass treasure, &gameState, tempHand, z, cD, and curPlayer to method, in that order. 

Expected Results:  The curPlayer's hand will now have 2 added treasure cards.

Acutal Results:  The curPlayer's hand actually has 3 treasure cards :(

Workarounds:	N/A  
****************************************/

/****************************************
Teammate:  Wisam
Title:  Council Card does not add proper card amounts
Bug Number:  3w
Class:  Serious Bug
Date:  11.22.15
Reported By:  Brian Stamm
Email:  stammbr@oregonstate.edu

Product:  dominion.c

Is it reproducible:  Yes.

Description:  When running the council_room_refactor method, it adds an extra card to
the current player's hand, while not adding a card to the other player's hands.

Steps to Produce/Reproduce -
1.  Set initial variables.
	a)  Create struct gameState
	b)  Create an array of kingdom cards (adventurer, gardens, embargo, village, 
		minion, mine, cutpurse, sea_hag, tribute, smithy)
	c)  Seed rand, create a random int.
	d)  Create int players (at least 2, no more than 4)
	e)  Initialize game with initializeGame, (initializeGame(players, arrayKingdom,
		randomNum, gameState))
2.  Create int curPlayer, set to 1.
3.  Create int handPos, set to 0.
4.  Create an array to hold players' hand count (int groupHand[players]).
	a)  In a for loop, fill the array with current players' handCount amount.
5.  Pass curPlayer, &gameState, and handPos to council_room_refactor, in that order. 

Expected Results:  The curPlayer's hand have 4 new cards, discard current card, and
have an added buy.  Also, the other players should have one added card in their hand..

Acutal Results:  The curPlayer's gets 5 new cards, and the other players do not get
a card.

Workarounds:	N/A  
****************************************/

/****************************************
Teammate:  Jody
Title:  Council Card does not add a buy
Bug Number:  4j
Class:  Serious Bug
Date:  11.22.15
Reported By:  Brian Stamm
Email:  stammbr@oregonstate.edu

Product:  dominion.c

Is it reproducible:  Yes.

Description:  When running the callCouncilRoom method, does not add a buy
to the current player's numBuys.

Steps to Produce/Reproduce -
1.  Set initial variables.
	a)  Create struct gameState
	b)  Create an array of kingdom cards (adventurer, gardens, embargo, village, 
		minion, mine, cutpurse, sea_hag, tribute, smithy)
	c)  Seed rand, create a random int.
	d)  Create int players (at least 2, no more than 4)
	e)  Initialize game with initializeGame, (initializeGame(players, arrayKingdom,
		randomNum, gameState))
2.  Create int curPlayer, set to 1.
3.  Create int handPos, set to 0.
4.  Pass curPlayer, &gameState, and handPos to callCouncilRoom, in that order. 

Expected Results:  The curPlayer will have 2 buys.

Acutal Results:  The curPlayer only has 1 buy, or a single buy.

Workarounds:	N/A  
****************************************/

/****************************************
Teammate:  Jody
Title:  Adventurer - TOO MUCH TREASURE! (Redux)
Bug Number:  5j
Class:  Serious Bug
Date:  11.22.15
Reported By:  Brian Stamm
Email:  stammbr@oregonstate.edu

Product:  dominion.c

Is it reproducible:  Yes.

Description:  When running the callAdventurer method, it adds an extra treasure
card to the player's hand.

Steps to Produce/Reproduce -
1.  Set initial variables.
	a)  Create struct gameState
	c)  Seed rand, create a random int.
	d)  Create int players (at least 2, no more than 4)
	d)  Initialize game with initializeGame, (initializeGame(players, arrayKingdom,
		randomNum, gameState))
2.  Create int curPlayer, set to 1.
3.  Set curPlayer's deck with random cards, with at least 3 treasure cards.
7.  Pass curPlayer and &gameState to callAdventurer method, in that order. 

Expected Results:  The curPlayer's hand will now have 2 added treasure cards.

Acutal Results:  The curPlayer's hand actually has 3 treasure cards :(

Workarounds:	N/A  
****************************************/