/*Kenny Lu
November 21, 2015
CS362
Assignment 5

Documentation of the bugs in my teammate's code

Teammate 1 (greenaca)
------------------------------------------------------------------------------------------------
Unit Test 1: Testing updateCoins() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 2: Testing gainCard() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 3: Testing shuffle() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 4: Testing isGameOver() Function

Result: Passed
------------------------------------------------------------------------------------------------
Card Test 1: Test smithy card

Result: Passed
------------------------------------------------------------------------------------------------
Card Test 2: Testing adventurer card

Result: Failed (during testing that player has right amount of cards in hand)
------------------------------------------------------------------------------------------------
Card Test 3: Testing village card

Result:  Failed (make sure an extra card is in hand after playing village card
(old hand and new hand should be equal))
------------------------------------------------------------------------------------------------
Card Test 4:  Testing steward card

Result: Passed
------------------------------------------------------------------------------------------------
Random Test: Testing adventurer card

Result: Failed
------------------------------------------------------------------------------------------------
Random Test: Testing village card

Result: Failed
------------------------------------------------------------------------------------------------
Bugs found:  

Bug 1:  The first bug that my tests caught was in the adventurer card.  My card test 2 (unit test)
file flagged a failed test indicating that the player doesn't have the right amount of cards in their
hand after the card is played.  Upon further code inspection of dominion.c, we find that the while loop
yields an incorrect number of treasures to be drawn.  The drawn treasure count must be equal to 4 or
more before the while loop exits.  This yields a count of 4 treasure cards being drawn instead of the 
usual 2 that the regular dominion game has.

Bug 2: The second bug that my tests found was in the village card.  This test failure was a result of my
card test 3 (unit test) failing and returning an error that the failure occurred during the testing that made sure 
an extra card was in the hand after the village card was played.  As a result of the card rules, the hand count
before the card was played should be equal to the hand after the card is played (because a the card is played and
another card is drawn yielding a net card gain of 0).  Upon further inspection of the dominion.c code, we find that
this buggy card indeed calls the drawCard() function twice yielding 2 cards being drawn instead of the typical 1
that is in the normal card rules.




Teammate 2 (gieses)
------------------------------------------------------------------------------------------------
Unit Test 1: Testing updateCoins() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 2: Testing gainCard() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 3: Testing shuffle() Function

Result: Passed
------------------------------------------------------------------------------------------------
Unit Test 4: Testing isGameOver() Function

Result: Passed
------------------------------------------------------------------------------------------------
Card Test 1: Test smithy card

Result: Failed
------------------------------------------------------------------------------------------------
Card Test 2: Testing adventurer card

Result: Failed (during test that player has right amount of cards in hand)
------------------------------------------------------------------------------------------------
Card Test 3: Testing village card

Result: Passed
------------------------------------------------------------------------------------------------
Card Test 4:  Testing steward card

Result: Passed
------------------------------------------------------------------------------------------------
Random Test: Testing adventurer card

Result: Not Available
------------------------------------------------------------------------------------------------
Random Test: Testing village card

Result: Not Available
------------------------------------------------------------------------------------------------
Bugs found:  

Note:  When I ran all of my unit tests, they all ran successfully after some test refactoring but
I noticed that whatever I tried, I couldn't run my random tests.  I tried to see if the dominion game
would run by itself by running playdom but I would get the same segmentation fault as my random tests 
were giving.  Because my random tests depend heavily on a healthy gamestate, I believe this corruption
in the initial dominion code lead to these errors.  Because my unit test were dependent on only functions
(given through the dominion.h header file), these tests were able to run with no problem.

Bug 1:  The first bug was found through my card test 1 unit test and was found in the smithy card.  My unit test was
testing if the right amount of cards were drawn (2 cards) but I found that only 1 card was drawn.  This was caused by the
for loop initalizer starting at 1 instead of 0 which yielded only 1 card being drawn instead of 2.

Bug 2:  The second bug that I found was through card test 2 where the adventurer card was tested.  My unit test indicated
that the test failed when the unit test checked whether the player had the right amount of cards in his hand after
the card was played.  Upon inspection of the dominion.c code, we find that indeed, the while loop draws 3 treasures
instead of 2.  The while loop exits when the drawntreasure reaches three when this varible (drawntreasure was initialized
at 0).  As a result, 3 treasure cards are drawn which the unit test caught when it flagged that the wrong number of
cards were in the deck after this card was played.
*/






