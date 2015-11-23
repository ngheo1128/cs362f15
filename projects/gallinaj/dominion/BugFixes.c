Jana Gallina
CS362 Fall 2015
Assignment 5
BugFixes

Bug 1:
Function: adventurer
Description: The cards that the player actually has for their treasure cards is
off by one. Tested hand size and what was actually in expected from treasure deck.
This was off by one with mixed treasure deck and empty treasure.
Fix: I changed the code in the while loop to read drawntreasure < 2,
rather than drawntreasure <= 2.

Bug 2:
Function: smithy
Description: The hand size for Smithy is off by one. The size will be a
number say 1 and the expected is one more so 2. The discard played
card ends up being one more than expected.
Fix: In the call to the discardCard function, I changed the value being passed as
trashFlag from 1 to 0, signalling that the card is not trashed.

Bug 3:
Function: village
Description: The discard played count is off by 1 and actions is showing a
greater value. What is expected from would be 0 but it is showing there is a value
The actions for this card would expect a value of 1 but is actually 0.
Fix: In the call to the discardCard function, I changed the value being passed
as trashFlag from 9 to 0, signalling htat the card is not trashed.

Bug 4:
Function: Feast
Description: In the final for loop to reset the hand, the value of i is incorrect.
Fix: In the final for loop to reset the hand, I changed the value of i
to be i <= state->handCount.

Bug 5:
Function: scoreFor()
Description: In scoreFor, deckScore is incorrectly calculated.
Fix: The function is iterating over discardCount instead of over deckCount.
I changed the code to iterate over the correct value.


