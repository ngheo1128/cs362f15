This is the documentation file for assignment 5.  Using GDB I fixed the bugs in my refactored cards code.

I fixed the bug in the smithy card, adventurer card, village card and the steward card.


In smithy_card() the bug that was found was that the player trashed the smithy card at the end of their turn, 
rather than discarding it.  The trash flag needed to be changed from one to zero in the discardCard function.

In adventurer_card() the bug that was found was that the player draws cards until four treasure cards are found
rather than two treasure cards.  The limit on the while loop in the code had to be changed from four to two.

In village_card() the bug that was found was that the function draws two cards rather than just one.  The second
line that contained the drawCard function call had to be deleted.

In steward_card() the bug that was found was that the function discards two cards and trashes one card, 
rather than discarding one card and trashing two cards.  The trash flags had to be changed from either a one to
a zero or a zero to a one in the discardCard function calls.  If is set to a one then that means the card is to 
be trashed, if it is set to a zero that means the card is to be discarded.