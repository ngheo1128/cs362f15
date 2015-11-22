/*
------------------------------
BugsInTeammates.c
Assignment 5
jenkinch
------------------------------

Fortunately, my tests proved robust enough not to require any modification to
effectively run on my teammates' code.

Below are the bug reports for each of my teammates. I've limited them to two bugs
each to match the assignment requirements.

Exhaustive test case results and failures can be found in:
    teammate1Dominion/barlanj_unittestresults.out
    teammate1Dominion/barlanj_randomtestadventurer.out
    teammate1Dominion/barlanj_randomtestcard.out
    teammate2Dominion/hattont_unittestresults.out
    teammate2Dominion/hattont_randomtestadventurer.out
    teammate2Dominion/hattont_randomtestcard.out

teammate1 = barlanj
    
    BUG 1 ~ Unit Test - isGameOver():
    
        barlanj_unittestresults.out Extract:
            isGameOver(): FAIL when gardens, copper, and treasure_map piles are empty
            isGameOver(): FAIL when sea_hag, silver, and gold piles are empty
            
        How to Reproduce:
            1) Initialize game using the following values:
                seed = 1000;
                numPlayer = 2;
                k[10] = {adventurer, council_room, feast, gardens, mine
                        , remodel, smithy, village, sea_hag, treasure_map};
                
            2) Call isGameOver() and test if it returns properly given either of these two scenarios:
                i)  G.supplyCount[gardens] = 0;
                    G.supplyCount[copper] = 0;
                    G.supplyCount[treasure_map] = 0;
                    
                ii) G.supplyCount[sea_hag] = 0;
                    G.supplyCount[silver] = 0;
                    G.supplyCount[gold] = 0;
        
        Description:
            When treasure_map or sea_hag cards was one of the three piles that run out of cards
            isGameOver() did not return correctly. This is because they are enumerated as 25
            and 26 in dominion.h, respectively, and the loop that counts empty piles in
            isGameOver() only goes up to i < 25, and thus never accounts for them.
       
    BUG 2 ~ Card Test - Smithy:
    
        barlanj_unittestresults.out Extract:
            cardEffect(smithy): FAIL player 0, discardCount correct after discard 
        
        How to Reproduce:
            1) Initialize game using the following values:
                seed = 1000;
                numPlayer = 2;
                k[10] = {sea_hag, council_room, feast, gardens, mine
                        , remodel, smithy, village, baron, great_hall};
            
                player0Hand = {sea_hag, copper, copper, copper, smithy};
                player0Discard = {copper, council_room, feast, gardens, mine
                                 , remodel, smithy, village, copper, province};
                player0Deck = {copper, copper, gold, curse, curse
                              , remodel, smithy, village, duchy, great_hall};
                player0HandCount = 5;
                player0DiscardCount = 10;
                player0DeckCount = 10;
                G.whoseTurn = 0;
                
            2) Activate the smithy card effect and test if player0DiscardCount increases by one.
        
        Description:
            The card failed to correctly update discardCount for the current player after
            being activated. This is due to the fact that the handPos and trashFlag arguments
            in the call to discardCard have been erroneously switched causing improper discards.
    
teammate2 = hattont
    
    BUG 1 ~ Card Test - Village:
    
        hattont_unittestresults.out Extract:
            cardEffect(village): FAIL player 0, numActions correct after draw
            
        How to Reproduce:
            1) Initialize game using the following values:
                seed = 1000;
                numPlayer = 2;
                k[10] = {sea_hag, council_room, feast, gardens, mine
                        , remodel, smithy, village, baron, great_hall};
                        
                player0Hand = {sea_hag, copper, copper, copper, village};
                player0Discard = {copper, council_room, feast, gardens, mine
                                 , remodel, smithy, village, copper, province};
                player0Deck = {copper, copper, gold, curse, curse
                              , remodel, smithy, village, duchy, great_hall};
                player0HandCount = 5;
                player0DiscardCount = 10;
                player0DeckCount = 10;
                G.whoseTurn = 0;
                
            2) Activate the village card effect and test if current player's numActions is incremented by two.
        
        Description:
            The card failed to update numActions correctly. This is due to erroneously incrementing
            numActions by 3 instead of 2 in the card's code.
       
    BUG 2 ~ Card Test - Great Hall:
    
        hattont_unittestresults.out Extract:
            cardEffect(great_hall): FAIL player 0, numActions correct after draw 
        
        How to Reproduce:
            1) Initialize game using the following values:
                seed = 1000;
                numPlayer = 2;
                k[10] = {sea_hag, council_room, feast, gardens, mine
                        , remodel, smithy, village, baron, great_hall};
                        
                player0Hand = {sea_hag, copper, copper, copper, great_hall};
                player0Discard = {copper, council_room, feast, gardens, mine
                                 , remodel, smithy, village, copper, province};
                player0Deck = {copper, copper, gold, curse, curse
                              , remodel, smithy, village, duchy, great_hall};
                player0HandCount = 5;
                player0DiscardCount = 10;
                player0DeckCount = 10;
                G.whoseTurn = 0;
                
            2) Activate the great hall card effect and test if current player's numActions is incremented by one.
        
        Description:
            The card failed to update numActions correctly. This is due to erroneously incrementing
            numActions by 2 instead of 1 in the card's code.
*/