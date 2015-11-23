// CS 362 Assignment 5
// Fall 2015
// Keenan Bishop
//
// Bugs in teammates code
//
/*

Teammate 1: Sarah Cawley (cawleys)

Adventurer: My tests indicated that an incorrect of cards were drawn/discarded.  My random test indicated that 90% of the tests failed.  Looking closer at the results, this means that the function most likely did not take correct action according to the number of treasures.  My unit tests indicated that 1 less than normal card was drawn.  Inspecting the source code confirmed that the adventurer card did not draw enough treasure cards.


village: My unit test segfaulted due to my teammates implementation.  
My random test completed but failed 100% of the tests.  
These random tests checked the number of actions added and the +1 card added to the deck, so something went wrong there.  
Stepping through with gdb indicated that the number of actions added and the card added was incorrect.





Teammate 2: Tony Huynh (huynhton)

adventurer: Very similar to Sarah's bug. From both random and unit tests, it is clear that the adventurer card drew an incorrect number of cards.  My tests were not specific enough to pinpoint this exactly, since the adventurer card has an increased complexity (variable length loop)).  My random test only indicated that there was a problem with the amount of cards.


village:  This segfaulted my unit test, as with Sarah's.  It also failed 99% of the unit tests.  After editing my test a bit, I found that 2 card was drawn instead of 1.
Additionally, only 1 action was gained instead of the expected 2.

*/
