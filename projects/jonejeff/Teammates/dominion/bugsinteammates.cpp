    My random tests for the smithy card had a pass ratio of 1992 pass and 8 failed.
The failures were from my test not taking into account the shuffling of the deck not sure
how it was missed. As for my teammates bug I found it using GDB trying to find the shuffling
problem. The bug I found in his was that he had inverted the trash flag so that the smithy card
was trashed instead of going to the played pile.

    My random test for the adventurer card segfaulted for a long time due to the temphand getting
out of bounds. After fixing that I found that it failed evey time due to the discard count not
not being correct. Then using gdb and I went though and found that temp hand was not discarding
the cards.
