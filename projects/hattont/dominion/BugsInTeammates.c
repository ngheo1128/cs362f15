/*
CS362-F15
Ty Hatton
Assignment 5
BugInTeammates.c

---------------------
jenkinch - teammate1

BUG 1
 activateAdventurer() using cardtest1.c

Test case setup: 
	Active player is player[0]
	Test Hand: 4 cards- estate,province,gold,duchy
	deckcount 	= 4
	discardCount 	= 0
	handCount 	= 0
Results:
     Fail to collect enough treasure. This is due to a errant loop count
     in the first if-statement.
---------------------

BUG 2
 activateSmithy() using cardtest4.c

Test case setup: 
     Card order in hand: province,duchy, gold
Results:
     When Smithy card is played the last cards are in wrong order.  
     This is possibly due to the incorrect number of for loops being executed. 
	 
-------------
-------------
barlanj - teammate2

BUG 1 
     cardEffect_adventurer() using cardtest1

Test case setup: 
     Active player is player[0]
     Test Hand: 4 cards- estate,province,gold,duchy
	deckcount 	= 4
	discardCount 	= 0
	handCount 	= 0
Results:
     Fail to collect enough treasure. This is possibly due to a errant loop count.

*/
