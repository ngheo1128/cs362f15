smithyCard function, line 691: Introduced bug (found by teammate) gave
drawnCard to currentPlayer + 1, rather than current player. Bug fixed by removing
introduced bug.

teammate found bug in adventurerCard function, reporting that 0 treasure
cards in hand when function is called results in no treasure cards drawn. Could
not reproduce the bug.

villageCard function, line 707: Introduced bug (found by teammate) doubled number
of actions gained by player. Bug fixed by removing duplicate line of code.

feastCard function: Introduced bug (not found by teammates) drops one card during
resetting of hand per tempHand. Fixed by changing < to <= at line 772.

adventurerCard function, line 662: Introduced bug (found by teammate) replaced
incorrect card in hand with new card (should replace last card in array, not
second-last). Bug fixed by adjusting [state->handCound[currentPlayer]-2] to
[state->handCound[currentPlayer]-1]
