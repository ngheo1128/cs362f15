/******BUGFIXES.c******

Reported by teammates:

Bugs in scoreFor(), isGameOver() and Treasure Map card were
not introduced by me. However, they function correctly
upon testing for me. Also, I believe they are functioning
correctly based on code inspection

Adventurer: 
Fixed a bug where hand and discard pile
were not being altered after function call. This was
due to temphand and cardDrawn being passed by value
rather than by reference.

------------------------------------

Refactored bugs:

Smithy:
Fixed a bug where the trash flag is set for discardCard(). 
Reset trash flag to zero.

Ambassador:
Fixed a bug where the revealed card goes to the hand rather than
to discard pile. Reset gainCard()'s toFlag to 0.

Embargo:
Fixed the return value bug by making cardEffect() return the result
of embargoFunction().


*/

//end of BugFixes.c