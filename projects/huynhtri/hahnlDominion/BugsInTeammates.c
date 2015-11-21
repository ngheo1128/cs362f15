/*
Solomon Huynh
CS362 Assignment 5
BugsInTeammates.c - Larissa

Larissa Hahn Bugs:
1) Found in: unittestresults.out - cardtest4.c
villageCard function - The number of actions only increased by 1 when it should of increased by 2.
Fix: Change "state->numActions = state->numActions++;" to "state->numActions = state->numActions + 2;"

2) Found in: unittestresults.out - cardtest3.c
councilRoomCard function - The number of buys did not increase and is 0 when it should of increased by 2.
Fix: Change "state->numBuys + 2;" to "state->numBuys += 2;"



*/