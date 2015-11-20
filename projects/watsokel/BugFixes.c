CS 362 - ASSIGNMENT 5               KELVIN WATSON 
BugFixes.c                          ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
----------------------------------------------------------------------------------------------------------------------------

BUG FIXES
---------

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ID  BUG DESCRIPTION                                 BUG FIX                                                 DATE FIXED          
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1   In adventurerEffect(), drawntreasure was not    The incorrect if condition:                             17 Nov 2015
    incremented when a copper was drawn.                if (cardDrawn == silver || cardDrawn == gold)       20:01hr
                                                    has been corrected to:
                                                        if (cardDrawn == copper || cardDrawn == silver 
                                                        || cardDrawn == gold)
                                                    The drawntreasure variable will now be incremented 
                                                    when a copper card is drawn. The bug-fixed refactored
                                                    code now passes all of the original unit tests in 
                                                    cardtest2.c.
----------------------------------------------------------------------------------------------------------------------------
2   There is a bug in the discardCard() method      See bug fix for bug ID 4. 
    whereby the sea_hag case does not actually 
    discard the sea_hag card after it is played. 
    Because this bug can be resolved by fixing
    the bug associated with the discardCard() 
    method, please see bug fix for bug ID 4. 
----------------------------------------------------------------------------------------------------------------------------
3   After a call to the sea_hag case of             The erroneous statements have been corrected as         17 Nov 2015 
    cardEffect(), the card at the top of the        follows:                                                20:21 hr    
    opponent's discard pile after discarding top        state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];              
    of deck is not a curse card. Instead, the top   has been corrected to:
    element of the discard pile is garbage data.        state->discard[i][state->discardCount[i]++]=state->deck[i][state->deckCount[i]-1]; 
                                                    The deckCount is no longer decremented, as this step 
                                                    should only access the top of the deck, and the 
                                                    discardCount is incremented via post-fix notation. Note
                                                    that the deckCount should not be decremented at all in 
                                                    the sea_hag case since a card is being discarded from 
                                                    the deck, but a curse is being added to the deck.
                                                    Next, the following 2 statements were deleted:
                                                        state->deckCount[i]--;
                                                        state->discardCount[i]++;
                                                    The first of these statements was deleted because, as 
                                                    mentioned above, the deckCount should not be altered 
                                                    as a card from the deck is being discarded and another 
                                                    (a curse) is being added to it. The second of these
                                                    statements was deleted since the discardCount was 
                                                    already incremented in the first corrected statement 
                                                    using post-fix notation. 
----------------------------------------------------------------------------------------------------------------------------
3   In the sea_hag case of the cardEffect()         This is the erroenous statement:                        17 Nov 2015 
    method, the curse card is placed in the             state->deck[i][state->deckCount[i]--]=curse;        20:40 hr
    incorrect location in the deck. In the buggy    In the bug fix, the above line is replaced with
    version of sea_hag, the opponent's deck was         state->deck[i][state->deckCount[i]-1]=curse;        
    actually decremented incorrectly twice prior    In addition, the line:
    to this line, so the curse is actually              --state->supplyCount[curse];
    inserted into the wrong location in the deck    was added to decrement the supply count for the
    (beneath the top of the deck).                  curse cards.The fixed code now passes all of the
                                                    original unit tests in cardtest3.c.
        
----------------------------------------------------------------------------------------------------------------------------
4   After a call to discardCard(), the discard      When trashFlag<1, the original discardCard() method     17 Nov 2015
    count is not incremented as expected. Instead,  places the discard to be discarded into the             21:17 hr
    it remained the same. Checking the top of the   playedCards pile instead of the discard pile.
    discard pile resulted in a garbage value, even  To correct this, the following incorrect statements
    though the discarded card was a gold card.          state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
    These two bugs are detected in my own               state->playedCardCount++;
    unittest2.c tests, and my teammates' tests      were replaced with the following statement:
                                                        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][handPos];
                                                    which assigns the card from the hand to be 
                                                    discarded to the top of the discard pile, then
                                                    increments the discard count.
----------------------------------------------------------------------------------------------------------------------------
5   In adventurerEffect2(), the  adventurer         This is the buggy statement:                            17 Nov 2015
    card was refactored to shuffle when                 if (state->deckCount[currentPlayer]<2)              21:22 hr
    the deckCount was less than 2, which is         which has been correct to:
    a bug, as the deck should be shuffled                   if (state->deckCount[currentPlayer]<1)
    when the deck is empty (deckCount==0).          After the fix, the code for the adventurerEFfect() 
                                                    and adventurerEffect2() method now passes all of
                                                    the original unit tests in unittest2.c.
----------------------------------------------------------------------------------------------------------------------------
6   The total score is computed incorrectly in      The for loop header is incorrect for the third score    17 Nov 2015     
    the scoreFor() method. More specifically,       computation loop. Specifically, the header:             21:31 hr
    the score computed from the discard pile            for (i = 0; i < state->discardCount[player]; i++)
    is added twice in error, while no score         appears twice in the scoreFor() method, incorrectly
    is computed for the deck.                       computing the score from the discard pile twice, while
                                                    not computing the score for the deck at all. To fix
                                                    this bug, the second duplicate for loop header was 
                                                    replaced with
                                                        for (i = 0; i < state->deckCount[player]; i++)
----------------------------------------------------------------------------------------------------------------------------
7   The total score is computed incorrectly in      The for loop header is incorrect for the third score    17 Nov 2015     
    the scoreFor() method. No score was computed    computation loop. This header:                          21:31 hr
    from the cards in the deck.                         for (i = 0; i < state->discardCount[player]; i++)
                                                    is duplicated in error in the scoreFor() method, thus
                                                    erroneously computing the score from the discard pile 
                                                    twice, while not computing the score for the deck at all. 
                                                    As explained above in bug ID 6, to fix this, 
                                                    the second duplicate for loop header was replaced with
                                                        for (i = 0; i < state->deckCount[player]; i++)
----------------------------------------------------------------------------------------------------------------------------
8   In the sea_hag case in cardEffect(), the        The line:                                               20 Nov 2015
    discardCard() method was not called to              discardCard(handPos,currentPlayer,state,0);         08:38 hr
    discard the sea_hag card after it was           was added to the sea_hag case in cardEffect() to
    played, resulting in the sea_hag card not       discard the sea_hag card after it is played.
    being discarded, and remaining in the hand.
----------------------------------------------------------------------------------------------------------------------------
9   In smithyEffect(), the smithy card was not      The buggy line:                                         20 Nov 2015
    actually discarded after it was played,             discardCard(handPos,currentPlayer,state,1);         08:41 hr
    resulting in the smithy card remaining in       was corrected to:
    the player's hand even after a call to              discardCard(handPos,currentPlayer,state,0);
    discardCard().                                  which now contains the correct discard flag.