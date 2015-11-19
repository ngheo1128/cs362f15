/////////////////////////////////////////////////////////////////////
// Teammate 1 Bugs - Teammate Name: Carol Toro
/////////////////////////////////////////////////////////////////////

// ----- Bug 1 -----
Title: Playing smithy card results in incorrect handcount.
Where:
	smithyCard() in the dominion.c file.
Bug Description:
	The expected hand count after the smithy card code is executed is 8,
	but the actual handcount is 7. This means that the smithy card code is
	drawing 1 less card than is supposed to.

// ----- Bug 2 -----
Title: Playing smithy card removes the incorrect cards from the deck.
Where:
	smithyCard() in the dominion.c file.
Bug Description:
	The card removed from the deck did not match the card added to the hand

/////////////////////////////////////////////////////////////////////
// Teammate 2 Bugs - Teammate Name: Sean Harrington
/////////////////////////////////////////////////////////////////////

// ----- Bug 1 -----
Title: Playing smithy card results in incorrect handcount.
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The smithy card is drawning 2 less cards from the deck than it is
	supposed to.

// ----- Bug 2 -----
Title: Playing smithy card removes the incorrect number of cards from the deck.
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The smithy card is one less card from the deck than it was supposed to.

// ----- Bug 3 -----
Title: Playing smithy card adds an incorrect card to the hand.
Where:
	smithyfunction() in the dominion.c file.
Bug Description:
	The card removed from the deck did not match the card added to the hand.

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
