/*
Solomon Huynh
CS362 Assignment 5
BugsInTeammates.c - Dustin

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