Name: 	Jeff Moss
Date:	11/17/15
Title: 	Documentation of the bugs that were found through the execution of unit tests, 
	card tests, and random tests on the adventurer and village cards.
File:	BugsInTeammates.c
Class:	CS362 Fall 2015
------------------------------------------------------------------------------------------

For both teammates, the following were unit tested in dominion.c:
shuffle(), fullDeckCount(), isGameOver(), gainCard()

For both teammates, the following card tests were performed in dominion.c:
Smithy, Adventurer, Village, Great_hall

For both teammates, the following random tests were performed in dominion.c:
Adventurer, Great_hall
------------------------------------------------------------------------------------------

Teammate: Wilson Chan
BUGS FOUND

Smithy Card:
-Once the smithy card is used, it should be discarded 
and the discardCount incremented by one. Currently, it doesn't appear to be 
incremented (discardCount was still 0).

Adventurer Card:
-handcount not incrementing correctly. After drawing two cards, the handCount should be 2.
Instead, -781 was returned.
-The discard count was not incremented correctly. In this test case, discardCount was
expected to be 6, but 781 was returned.
-playedCardCount does not get incremented correctly (expected 1, got 0). 
-deckCount may not be counting correctly. That is, the change in the players hand and discard
count should equal the change in deckCount. 
-Upon use of the adventurer card, the player's hand should match the test scenario.
In this scenario, the player's hand was different than the test scenario. Card 0 should
have been 5 but 0 was returned. Card 1 should have been 5 but 4199419 was returned.

Village card:
- Once the village card is used, it should be discarded and the discardCount incremented
by one. It doesn't appear to be incremented (discardCount was still 0).

Great_hall card:
-Once the great_hall card is used, it should be discarded and the discardCount incremented.
It doesn't appear to be incremented (discardCount was still 0).
-When it's player 1's turn, for some reason player 0's deckCount gets changed.
-handCount doesn't appear to increment correctly. (expected 1, got 0).

------------------------------------------------------------------------------------------

Teammate: Rachael McConnell
BUGS FOUND

Smithy card:
-Once the smithy card is used, it should be discarded 
and the discardCount incremented by one. Currently, it doesn't appear to be 
incremented (discardCount was still 0).
-handCount not incrementing correctly, after drawing two cards and discarding the smithy,
the count should be 2. 1 was returned.

Adventurer card:
-handcount not incrementing correctly. After drawing two cards, the handCount should be 2.
Instead, 0 was returned.
-playedCardCount does not get incremented correctly (expected 1, got 0). 
-Upon use of the adventurer card, the player's hand should match the test scenario.
In this scenario, the player's hand was different than the test scenario. Card 0 should
have been 5 but 11 was returned. Card 1 should have been 5 but 4 was returned.
-The discard count was not incremented correctly. In this test case, discardCount was
expected to be 6, but 10 was returned.

Village card:
- Once the village card is used, it should be discarded and the discardCount incremented
by one. It doesn't appear to be incremented (discardCount was still 0).

Great_hall card:
-Once the great_hall card is used, it should be discarded and the discardCount incremented.
It doesn't appear to be incremented (discardCount was still 0).
-When it's player 1's turn, for some reason player 0's deckCount gets changed.
-handCount doesn't appear to increment correctly. (expected 1, got 0).
