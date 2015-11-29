/*
------------------------------
BugFixes.c
Assignment 5
jenkinch
------------------------------

barlanj Found Bugs + Fixes:

    isGameOver():
        PRE: Playing province count > 0 with [salvager] [sea_hag] and [village] depleted 
        POST: expected game over, returned game running

        This is due to bug in for loop inside isGameOver - loop does not encompass all CARDs
        
        FIXED: In isGameOver(), the for loop that was "for (i = 0; i < 25; i++)" is now "for (i = 0; i < 27; i++)".
               This correctly encompasses all the cards.

    Smithy:
        PRE:
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
            gamestate for player 1 was not changed appropriately (handCount)
            This is due to second inrementation of i in for loop inside activateSmithy -
            this makes it draw only 2 cards.
            
        FIXED: Removed the additional "i++" from within the for loop.
___________________________________________________________________________________
hattont Found Bugs + Fixes:

    Adventurer:
        Test case setup: 
            Active player is player[0]
            Test Hand: 4 cards- estate,province,gold,duchy
            deckcount 	= 4
            discardCount 	= 0
            handCount 	= 0
        Results:
             Fail to collect enough treasure. This is due to a errant loop count
             in the first if-statement.
             
        FIXED: In the first if-statement "<2" was changed to "<1" to correctly check for an empty deck.

    Smithy:
        Test case setup:
            handCount 	= 3
            playedCardCount = 1
            deckCount 	= 1
            numActions 	= 0
        Results: 
            When Smithy card is played the hand count is incorrectly incremented.
            This bug could be a result of switched currentPlayer and handPos.
             
        FIXED: The currentPlayer and handPos arguments were switched back to their proper positions in the
               call to discardCard().
____________________________________________________________________________________
Remaining Self-Introduced Bugs + Fixes:
        
    Adventurer:
        Bugs: In the second if-else block, the "z++" was moved from the bottom of the else to the bottom of the if.
              
        FIXED: The "z++" was removed from the bottom of the if and added back to the bottom of the else. 
        
    Village:
        Bugs: In the "+2 Actions" code, on the right side of the equal sign 
              "state->numActions" has been changed to "state->supplyCount".
        
        FIXED: In the context mentioned above, "state->supplyCount" was changed back to "state->numActions".
        
    Steward:
        Bugs: The currentPlayer and choice arguments have been switched in the two 
              calls to discardCard() in the else statement.
        
        FIXED: The currentPlayer and choice arguments in the context mentioned above were switched back.
        
    Minion:
        Bugs: The "draw 4 j for-loop" now uses j <= 4 instead of the j < 4.

        FIXED: The "j <= 4" in the context mentioned above was switched back to "j < 4".
*/