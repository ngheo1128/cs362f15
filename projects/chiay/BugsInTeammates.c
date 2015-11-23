**************************************
     Teammates's Dominion Testing
**************************************

DOMINION GAME FUNCTION
----------------------

Test 1  : Unit Tests for updateCoins() function
File    : unittest1.c
Results : All 4 tests passed unit test.


Test 2  : Unit Tests for scoreFor() function
File    : unittest2.c
Results : All 9 tests passed unit test.


Test 3  : Unit Tests for gainCard() function
File    : unittest3.c
Results : All 24 tests passed unit test.


Test 4  : Unit Tests for isGameOver() function
File    : unittest4.c
Results : All 3 tests passed unit test.



DOMINION CARD FUNCTION
----------------------

Test 1  : Unit Tests for Smithy Card Function
File    : cardtest1.c
Results : Both 2 tests passed unit test. Smithy card discarded, gained 3 cards.


Test 2  : Unit Tests for Adventurer Card Function
File    : cardtest2.c
Results : Both 2 tests failed unit test.

	  - Adventurer Card Effect Test 1:
	     -Adventurer card not discard, but gained 2 treasure cards
	  - Adventurer Card Effect Test 2:
	     -Adventurer Card not discard, and not gaining any treasure cards


Test 3  : Unit Tests for Council Room Card in cardEffect() function
File    : cardtest3.c
Results : Test failed unit test.

	  - Player gained 4 new cards and 1 number of buys, another player gained
	    one card
	  - Number of discard not increment


Test 4  : Unit Tests for Great Hall Card Function
File    : cardtest4.c
Results : Test passed unit test. Great Hall card discarded, gained one card and one
	  action.


Test 5  : Random Tests for Village Card in cardEffect() function
File    : randomtestcard.c
Results : All tests failed random test. 

	  - Village card discarded, gained one card and two actions
	  - Number of discard not increment


Test 6  : Random Tests for Adventurer Card Function
File    : randomtestadventurer.c
Results : All tests failed random test.

	  - Adventurer card not discard, but gain 2 treasure cards
	  - Number of discard incremented
