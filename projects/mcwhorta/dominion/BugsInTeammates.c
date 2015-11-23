Bugs in Teammate 1's Code (Rhett Guyer)
1. The card test for Adventurer card revealed that not enough treasure cards are added to the player’s hand, so the hand count is incorrect.
2. The card test for the Smithy card revealed the Smithy card was not being removed from the hand. The card count, however, was correct indicating that the wrong card is being removed. 
*Unit tests for getCost(), compare(), updateCards, and kingdomCards() did not reveal any bugs.
*Card tests for the Village and Great Hall cards did not reveal any bugs.


Bugs in Teammate 2's Code (Adrienne Pereira)
1. The card test for Adventurer card revealed that not enough treasure cards are added to the player’s hand, so the hand count is incorrect.
2. The card test for the Smithy card revealed that 3 cards are not added to the player’s hand. It is not clear from the test if the Smithy card was removed and only 1 or 2 cards were added or the Smithy card was not removed and 0 or 1 card was added. 
*Unit tests for getCost(), compare(), updateCards, and kingdomCards() did not reveal any bugs.
*Card tests for the Village and Great Hall cards did not reveal any bugs.