/* Kathryn McDonald
 * Filename: BugFixes.c
 * Description: Bug fixes for my dominion.c file
 */

The bugs that both of my teammates found are the bugs that I introduced:
Namely, that my smithy function adds an extra card to the player's hand,
and that my adventurer function only allows the player to draw one treasure card.

Bugs I introduced that my teammates did not report are as follows:
The great hall function does not add +1 action like it should.
The embargo function discards the card rather than trashes it.

I fixed my buggy smithy function by changing the for loop condition to < instead of <=.
I fixed my buggy adventurer function by initializing drawnTreasure at 0 instead of 1.
I fixed my buggy great hall function by adding code to add +1 action.
I fixed my embargo function by changing discardCard to 1, which trashes the card.