/**************************************************************************************
Team Member: Connor Peavey
Date Run: 11/13/2015
Tested: isGameOver, gainCard, updateCoins, discardCard, Adventurer, Smithy, Village,
Steward
***************************************************************************************
Title: Smithy card is not properly discarded   

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored smithy function. Compared the value of
playedCardCount to the expected value of one for a discard.
After the card was played the comparison show the was incorrectly handled.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(smithy, 0, 0, 0, &testState, 0, 0)
3. Compare playedCardCount g ame state after the call to expected amount
4. Examine playedCardCount of the game state after the call

Expected Results
----------------
testState.playedCardCount = 1


Actual Results
--------------
testState.playedCardCount = 0


-----------------------------------------------------------------------------------------
Title: Adventurer card is not properly discarded   

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored adventurer function. Ensure proper results by
creating a deck where the first card drawn is non-treasure, and the next two are treasure
cards. After the card was played the card discard was incorrectly handled. The 
playedCardCount of the current player was not increased for the adventurer card.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(adventurer, 0, 0, 0, &testState, 0, 0)
3. Set up the  deck, ensuring first card drawn is non-treasure, and the next two are
treasure cards
4. Compare playedCardCount of game state after the call to the expected amount
5. Examine playedCardCount of the game state after the call. Should be 1 to indicate a
discard, as found in the discardCard function.


Expected Results
----------------
testState.playedCardCount = 1


Actual Results
--------------
testState.playedCardCount = 0

-------------------------------------------------------------------------------------------
Title: Village Card provides player with an extra card  

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored village function. Compare the handCount of the
current player from before the cardEffect function is called for Village to the handCount
of the current player after the function is called. The result is greater than expected
by one. One can see this extra card was taken from their own deck by comparing the post-call
game state's deckSize to pre-call game state's decksize - 1.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate. You will be starting with a handCount of 5, per rules.
2. Call the cardEffect function as: cardEffect(village, 0, 0, 0, &testState, 0, 0)
3. Compare handCount of the currrent player before the function call to after
4. Compare the deckSize of the current player after the call to the deckSize before the
call - one
5. Examine the handCount of the currrent player after the call
6. Examine the deckSize of the current player after the call


Expected Results
----------------
testState.handCount[p] = 5
testState.deckSize[p] = 4

Actual Results
--------------
testState.handCount[p] = 6
testState.deckSize[p] = 3

------------------------------------------------------------------------------------------
Title: Village Card not properly discarded after use 

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored village function. Compared the value of
playedCardCount to the expected value of one.
After the card was played the comparison show the discard was incorrectly handled.
The playedCardCount was not increased.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(village, 0, 0, 0, &testState, 0, 0)
3. Compare playedCardCount of game state after the call to the expected amount
4. Examine playedCardCount of the game state after the call


Expected Results
----------------
testState.playedCardCount = 1


Actual Results
--------------
testState.playedCardCount = 0

-----------------------------------------------------------------------------------------
Title: Village Card does not increase number of actions by two

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored village function. Compare the total number of
actions to two. Comparing the difference between the previous game states numActions to
the numActions of the game state after call should, but does not, equal two.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(village, 0, 0, 0, &testState, 0, 0)
3. Subtract the pre-call numActions from the post-function call numActions
4. Examine the difference and compare to two. Should equal two, but does not.


Expected Results
----------------
testState.numActions - originalState.numActions = 2


Actual Results
--------------
testState.numActions - originalState.numActions = 1

-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
Title: Steward Card, trash option chosen, cards are not trashed

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored steward function. Choose to the option to trash
cards. Then review if the playedCardCount has increased in the post-call game state. If 
properly trashed, the playedCardCount should not increase for the discarded cards. The
playedCardCount is increasing.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(steward, 3, duchy, estate, &testState, 0, 0)
3. Compare post call playedCardCount to two, the card amount trashed in the call
4. Examine the playedCardCount, as it should not have increased by those two cards, but did.


Expected Results
----------------
testState.playedCardCount < 2


Actual Results
--------------
testState.playedCardCount > 2

-----------------------------------------------------------------------------------------

*******************************************************************************************
Team Member: Sharon Kuo
Date Run: 11/13/2015
Tested: isGameOver, gainCard, updateCoins, discardCard, Adventurer, Smithy, Village,
Steward
*******************************************************************************************
Title: Smithy card is not properly discarded   

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored smithy function. Compared the value of
playedCardCount to the expected value of one for a discard.
After the card was played the comparison show the was incorrectly handled.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(smithy, 0, 0, 0, &testState, 0, 0)
3. Compare playedCardCount game state after the call to expected amount
4. Examine playedCardCount of the game state after the call. Should have a playedCardCount of 1, but does not.

Expected Results
----------------
testState.playedCardCount = 1


Actual Results
--------------
testState.playedCardCount = 0

---------------------------------------------------------------------------------

Title: Extra card drawn when Adventurer Card is played

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored adventurer function. Set players hand to contain
no treasure cards. Set deck to contain treasure cards. Call function. Incorrect number of
treasure cards kept at end of function.
Repeatable when randomized or set deck is created, so long as total number drawn is tracked.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Set test state's player's hand to contain 5 non-treasure cards
3. Set deck to contain five treasure cards
4. Call function cardEffect(adventurer, 0, 0, 0, &testState, 0, 0)
5. Set a counter variable to 0
6. Loop through player's hand after the function has been called, increment the counter
variable everytime hand[current player][loop position] is equal to copper, silver, or gold.
7. Compare variable to 2
8. Compare post-call handSize to original state's handsize + 2.


Expected Results
----------------
afterCount - beforeCount = 2
count = 2

Actual Results
--------------
afterCount - beforeCount = 3
count = 2

------------------------------------------------------------------------------------

Title: Adventurer card is not properly discarded, bug in original version as well   

Class: Bug, major

Date:  11/13/2015         
Reported By: Tara Massey
Email: masseyta@oregonstate.edu


Product: dominion.c             Version: Assignment2
Platform: Unix
Environment: Linux on flip server

Is it reproducible: Yes

Description
===========
Ran a unit test against the refactored adventurer function. Ensure proper results by
creating a deck where the first card drawn is non-treasure, and the next two are treasure
cards. Then Compared the values of playedCardCount to the expected 
value of one. 
After the card was played the comparison show the discard was incorrectly handled.
The playedCardCount of the current player was not increased for the adventurer card.

Steps to Produce/Reproduce
--------------------------
1. Make all dominion files and create a gamestate
2. Call the cardEffect function as: cardEffect(adventurer, 0, 0, 0, &testState, 0, 0)
3. Set up the  deck, ensuring first card drawn is non-treasure, and the next two are
treasure cards
4. Compare playedCardCount of game state after the call to the expected amount
5. Examine playedCardCount of the game state after the call


Expected Results
----------------
testState.playedCardCount == 1


Actual Results
--------------
testState.playedCardCount == 0
