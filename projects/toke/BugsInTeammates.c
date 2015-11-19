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
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The smithy card is drawning 1 less card from the deck than it is
	supposed to.

// ----- Bug 2 -----
Title: Playing smithy card removes the incorrect number of cards from the deck.
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The smithy card is one less card from the deck than it was supposed to.
	This could be related to bug 1.

// ----- Bug 3 -----
Title: Playing smithy card adds an incorrect card to the hand.
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The card removed from the deck did not match the card added to the hand.
	This could be related to bug 1 and 2.

// ----- Bug 4 -----
Title: Playing Adventurer card does not take cards from the deck.
Where:
	adventurerfunction() in the dominion.c file.
Bug Description:
	My test shows that no cards were removed from the deck when there
	should have been cards removed.

// ----- Bug 5 -----
Title: Playing Adventurer card results in an incorrect hand count.
Where:
	adventurerfunction() in the dominion.c file.
Bug Description:
	Two cards should have been added to the hand, but my tests shows
	that no cards were added. This means that no treasures were added 
	to the hand.

// ----- Bug 6 -----
Title: Playing Village card results in an incorrect action count.
Where:
	villagefunction() in the dominion.c file.
Bug Description:
	The tests are showing one less action than expected.
