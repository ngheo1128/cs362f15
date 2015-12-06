/*
Solomon Huynh
CS362 Assignment 5
BugsInTeammates.c

Instructions on running makefile tests for both Larissa Hahn and Dustin Chase:
1) For unit and card tests, enter "make unittestresults.out"
2) For randomtestadventurer.c, enter "make randomtestadventurer.out"
3) for randomtestcard.c (smithy card), enter "make randomtestcard.out"


Larissa Hahn Bugs:
1) Found in: unittestresults.out - cardtest4.c
villageCard function - The number of actions only increased by 1 when it should of increased by 2.
Fix: Change "state->numActions = state->numActions++;" to "state->numActions = state->numActions + 2;"

2) Found in: unittestresults.out - cardtest3.c
councilRoomCard function - The number of buys did not increase and is 0 when it should of increased by 2.
Fix: Change "state->numBuys + 2;" to "state->numBuys += 2;"


Dustin Chase Bugs:
1) Found in: unittestresults.out - cardtest1.c, randomtestcard.out - randomtestcard.c
playSmithy function - The number of cards drawn is shown as 2 when it should of been 3
Fix: Change the for loop "for (i = 0; i < 2; i++)" to "for (i = 0; i < 3; i++)"

2) Found in: unittestresults.out - cardtest2.c
playAdventurer function - The drawntreasure variable normally increments when a treasure card is
drawn. The issue is it only increments when it sees copper and silver but not gold. Gold is considered
a treasure card as well and should be incremented when it is drawn.
Fix: Change the if condition "if (cardDrawn == copper || cardDrawn == silver)" to
"if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)"


*/