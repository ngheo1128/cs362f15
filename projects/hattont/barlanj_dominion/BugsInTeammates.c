/*

In using my cardtest and unittest, I found a few bugs inside my
teammates dominion.c method implementations. Below are two for
each teammate. I also didn't have to edit any of my code that
I previously wrote a few weeks ago. This shows that my test cases
are somewhat extensive in relation to the method they are testing.

I replaced all of the cardtest and unittest in both teammates folder
with my own (my own local copy that is)


----------------------------------------------------------
hattont - teammate1
----------------------------------------------------------

---------------
BUG 1 - council room / testFile: cardtest3.c
--------------
Test Case: playing council_room from position 0 with only 2 players.
           Active player is player[0]


Pre-Setup:
     numPlayer = 2
     whoseTurn = 0
     handPos = 0
     hadncount = 5, discardCount = 5, deckCount = 5

     Player1:
     testHand1[5] = {council_room, copper, copper, copper, copper};
     discardPile1[5] = {silver, silver, silver, silver, silver};
     deckPile1[5] = {gold, gold, gold, gold, gold};

     Player2:
     testHand2[5] = {council_room, copper, copper, copper, copper}
     discardPile2[5] = {silver, silver, silver, silver, silver};
     deckPile2[5] = {gold, gold, gold, gold, gold};


POST:
     Segmentation Fault upon playing the council_room card from position 0
     of player 1. This is due to the for loop inside council_roomCard that
     starts at player 2 all the time.


-------------
BUG 2 - isGameOver() / test file: unittest1
-------------
PRE: Playing province count > 0 with [silver] [baron] and [treasure map] depleted 
POST: expected game over, returned game running

This is due to bug in for loop inside isGameOver - loop does not encompass all CARDs


----------------------------------------------------------
jenkinch - teammate1
----------------------------------------------------------

---------------
BUG 1 - isGameOver() / test file: unittest1
--------------
PRE: Playing province count > 0 with [salvager] [sea_hag] and [village] depleted 
POST: expected game over, returned game running

This is due to bug in for loop inside isGameOver - loop does not encompass all CARDs

---------------
BUG 2 - Smithy Card / test file: cardtest1
--------------

PRE:
	...
    numPlayer = MAX_PLAYERS
    active_player = 0
    handPos = 0

    handCount = 5
    discardCount = 10
    deckCount = 10

    testHand[5] = {smithy, copper, copper, silver, gold}
    discardPile[5] = {copper, copper, copper, copper, copper}
    deckPile[5] = {adventurer, adventurer, adventurer, adventurer, adventurer}

POST
	....
    gamestate for player 1 was not changed appropriately (handCount)

    This is due to second inrementation of i in for loop inside activateSmithy -
    this makes it draw only 2 cards.


*/