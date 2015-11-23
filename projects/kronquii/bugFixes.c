1. The function updateCoins is not declared in the dominin.h header. This causes a link-time warning. Fixed by addion updateCoins to the header file.
2. The adventurer card is not discarded. Fixed by adding a call to 'discardCard'.
4. The smithy card does not draw the right number of cards. Fixed by changing the loop conditions.
5. The council room does not add another buy. Another simple fix.
6. The arguments to the villagerEffect function are passed in the wrong order. Fixed by changing the order of the arguments.

None of my teammates reported any bugs to me.
