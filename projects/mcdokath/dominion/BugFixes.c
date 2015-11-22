/* Kathryn McDonald
 * Filename: BugFixes.c
 * Description: Bug fixes for my dominion.c file
 */

The bugs that both of my teammates found are the bugs that I introduced:
Namely, that my smithy function adds an extra card to the player's hand,
and that my adventurer function only allows the player to draw one treasure card.

I fixed my buggy smithy function by changing the for loop condition to < instead of <=.

I fixed my buggy adventurer function by initializing drawnTreasure at 0 instead of 1.