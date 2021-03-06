/////////////////////////////////////////////////////////////////////
// Teammate 1 Bugs - Teammate Name: Carol Toro
/////////////////////////////////////////////////////////////////////

// ----- Bug 1 -----
Title: Playing smithy card results in an incorrect action count.  
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
The expected action count after the smithy card code is executed is 1,
but the actual action count is 2. This means the smithy card is adding 
actions when it isnt supposed to.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the smithy card.

Expected Results
----------------
Action count is 1.

Actual Results
--------------
Action count is 2.

Workarounds
-----------
None.

/////////////////////////////////////////////////////////////////////
// Teammate 2 Bugs - Teammate Name: Sean Harrington
/////////////////////////////////////////////////////////////////////

// ----- Bug 1 -----
Title: Playing smithy card results in incorrect handcount.
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
The smithy card is drawning 1 less card from the deck than it is
supposed to.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the smithy card.

Expected Results
----------------
Hand count is increased by 2.

Actual Results
--------------
Hand count is increased by 1.

Workarounds
-----------
None.

// ----- Bug 2 -----
Title: Playing smithy card removes the incorrect number of cards from the deck. 
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
The smithy card is one less card from the deck than it was supposed to.
This could be related to bug 1.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the smithy card.

Expected Results
----------------
Deck count is reduced by 3.

Actual Results
--------------
Deck count is reduced by 2.

Workarounds
-----------
None.

// ----- Bug 3 -----
Title: Playing smithy card adds an incorrect card to the hand.
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
The card removed from the deck did not match the card added to the hand.
This could be related to bug 1 and 2.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the smithy card.

Expected Results
----------------
The first card from the deck should be placed at the end of the hand. 
The second card from the deck should be placed right after that. 
The third card should replace where the smithy card was in the hand.

Actual Results
--------------
The cards were not added in that order. The last card was not the 
third card from the deck.

Workarounds
-----------
None.

// ----- Bug 4 -----
Title: Playing Adventurer card does not take cards from the deck.
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
My test shows that no cards were removed from the deck when there
should have been cards removed.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the adventurer card.

Expected Results
----------------
Deck count should be reduced by at least 2 cards.

Actual Results
--------------
Deck count was not reduced..

Workarounds
-----------
None.

// ----- Bug 5 -----
Title: Playing Adventurer card results in an incorrect hand count.
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
Two cards should have been added to the hand, but my tests show
that no cards were added. This means that no treasures were added 
to the hand.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the adventurer card.

Expected Results
----------------
2 cards should be added to the hand.

Actual Results
--------------
No cards were added to the hand.

Workarounds
-----------
None.

// ----- Bug 6 -----
Title: Playing Village card results in an incorrect action count.
Class: Incorrect behavior
Date: 11/19/15                          Reported By: Kevin To
Email: toke@oregonstate.edu     
Product: dominion.c                        
Platform: C  
Is it reproducible: Yes 

Description
===========
The tests are showing one less action than expected.

Steps to Produce/Reproduce
--------------------------
1. Set up game state.
2. Run the code for the village card.

Expected Results
----------------
2 actions are added for player.


Actual Results
--------------
1 action was added for player.

Workarounds
-----------
None.