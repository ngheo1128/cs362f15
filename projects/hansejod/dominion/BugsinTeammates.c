Jody Hansen
CS 362 Assignment 5
Bug Report

All results can be viewed in the file unittestresults.out in the folders teammate1_stammbr_dominion and
teammate2_thalijw_dominion.

****************************************************************************************************************
BUG REPORTS FOR THALIJW:
****************************************************************************************************************

Bug Report #1
Title: The varibale playedCardCount has unexpected value after calling the Smithy card function.

Class: Serious bug

Date: 11-15-2015
Reported By: Jody Hansen
Email: hansejod@oregonstate.edu

Product: Dominion Game          Version: Refactored Smithy card
Platform: OSU Flip              Version: flip1

Is it reproducible: Yes

Description
===========
Function is expected to add three cards from the deck to the hand of the current player (passed as an argument).
The function is also suppose to discard one card from the hand to a variable that holds the played pile. The test
records the handCount, deckCount, and playedCardCount before calling the Smithy card. Those results are compared
with the results of those counts after the function is called. A bug was found in that the playedCardCount did
not increase by one. The playedCardCount remained at 0, suggesting that the card was discarded somewhere else or
not recorded in the proper variable.

Steps to Produce/Reproduce
--------------------------
1) Set seed to 1000.
2) Set numPlayer to 2.
3) Set an array of ten with the cards of adventurer, council_room, feast, gardens, mine, remodel, smithy,
village, baron, and great_hall
4) Create a gameState structure
5) Initialize a game
6) Call the Smithy function with the game structure, player (0), and handPos (4) as parameters.

Expected Results
----------------
Expected the function to discard a card from the hand to the played pile. playedCardCount integer should have
increased by one.

Actual Results
--------------
playedCardCount remained at 0.


Bug Report #2
Title: The varibale discardCount has unexpected value after calling the Adventurer card function.

Class: Serious bug

Date: 11-15-2015
Reported By: Jody Hansen
Email: hansejod@oregonstate.edu

Product: Dominion Game          Version: Refactored Adventurer card
Platform: OSU Flip              Version: flip1

Is it reproducible: Yes

Description
===========
Function is expected to add three treasure cards from the deck to the hand of the player (player is passed
as argument). The function is also suppose to discard one card from the hand of the currentPlayer to a variable
that holds the discarded cards, discardCount. The test records the handCount[0], discardCount[0], and
the temphand array before and after calling the Adventurer card function. The results are compared
with each other and evaluated for correct behavior. A bug was found in that the discardCount did not
increase by one. The discardCount remained at 0.

Steps to Produce/Reproduce
--------------------------
1) Set seed to 1000.
2) Set numPlayer to 2.
3) Set an array of ten with the cards of adventurer, council_room, feast, gardens, mine, remodel, smithy,
village, baron, and great_hall
4) Create a gameState structure
5) Initialize two copies of a temphand array
6) Initialize a game
7) Set deckCount to 0.
8) Call the Adventurer function with the game structure, player (0), cardDrawn, temphand array,
drawntreasure (0), and z (0) as parameters.

Expected Results
----------------
Expected the function to discard a card from the hand to the discarded card pile. discardCount integer should
have increased by one.

Actual Results
--------------
discardCount remained at 0.


Other bugs found:
Adventurer: temphand was passed as an argument in the function call. However, the value was not changed.
Council room: handCount of player1 was not increased by 3.
Seahag: The last card in the deck for other players does not equal 0.
Seahag: The deck is decreased by more than 1.

*Note! Errors in seahag function are most likely due to introduce errors prior to refactoring.

****************************************************************************************************************
BUG REPORTS FOR STAMMBR:
****************************************************************************************************************

Bug Report #1
Title: The varibale handCount has unexpected value after calling the Smithy card function.

Class: Serious bug

Date: 11-15-2015
Reported By: Jody Hansen
Email: hansejod@oregonstate.edu

Product: Dominion Game          Version: Refactored Smithy card
Platform: OSU Flip              Version: flip1

Is it reproducible: Yes

Description
===========
Function is expected to add three cards from the deck to the hand of the current player (passed as an argument).
The function is also suppose to discard one card from the hand to a variable that holds the played pile. The
total handCount should equal two after the cards are added and the played card is discarded. The test
records the handCount, deckCount, and playedCardCount before calling the Smithy card. Those results are compared
with the results of those counts after the function is called. A bug was found in that the handCount variable
did not increase by two, but instead increased by three.

Steps to Produce/Reproduce
--------------------------
1) Set seed to 1000.
2) Set numPlayer to 2.
3) Set an array of ten with the cards of adventurer, council_room, feast, gardens, mine, remodel, smithy,
village, baron, and great_hall
4) Create a gameState structure
5) Initialize a game
6) Call the Smithy function with the game structure, player (0), and handPos (4) as parameters.

Expected Results
----------------
The function was expected to add two to the total to the variable handCount.

Actual Results
--------------
handCount increased by three.

Other information
-----------------
As might be expected, the deckCount is expected to decrease by three but is instead decreased by four. This would
account for an increase in the handCount.


Bug Report #2
Title: The varibale handCount has unexpected value after calling the Council Room card function.

Class: Serious bug

Date: 11-15-2015
Reported By: Jody Hansen
Email: hansejod@oregonstate.edu

Product: Dominion Game          Version: Refactored Council Room card
Platform: OSU Flip              Version: flip1

Is it reproducible: Yes

Description
===========
At a high level, the function is expected to add three cards from the deck to player one and one card from the
deck to all other players. At a technical level, the variables handCount[0] should increase by three while
handCount[1] (in a two player game) should increase by one. The bug found was that handCount[1], second player,
did not increase by one.

Steps to Produce/Reproduce
--------------------------
1) Set seed to 1000.
2) Set numPlayer to 2.
3) Set an array of ten with the cards of adventurer, council_room, feast, gardens, mine, remodel, smithy,
village, baron, and great_hall
4) Create a gameState structure
5) Initialize a game
8) Call the Council Room function with the game structure, player (0), handPos (4) as parameters.

Expected Results
----------------
Expected the function to add one to the variable handCount[1] in a two player game.

Actual Results
--------------
handCount[1] remained at zero throughout the tests. A card was not added to the second player.

Other bugs found:
Adventurer: temphand was passed as an argument in the function call. However, the value was not changed.
Seahag: The last card in the deck for other players does not equal 0.
Seahag: The deck is decreased by more than 1.

*Note! Errors in seahag function are most likely due to introduced errors prior to refactoring.

