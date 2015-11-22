Bug 1: 
Smithy card is not being discarded from player’s hand.  
Found this by testing the player’s hand count and discard 
count after smithy was played.  The player’s hand count still 
had smithy card and the discard pile was empty.

Bug 2:
Village card is not being placed in the discard pile.  Found 
this by testing the player’s hand count and discard count.  
It is not staying in the player’s hand.  It is being trashed 
and should be placed in the player’s discard pile.

Bug 3:
Village card is not adding 2 to the current player’s actions.  
Found this by testing the player’s actions before and after 
the village card is played.