BUG FIXES
*********

isGameOver()
- Fixed function so that loop counts ALL cards to see if 3 supplies have been depleted.

scoreFor()
	- Originally the function used fullDeckCount to count cards for garden.  I would have fixed that function,
	but was unsure if doing so would break other functions.  Rewrote scoreFor() instead.  Scores now pass tests.
	Also deck iterations was incorrectly implemented.
	
discardCard()
	Discard Card was supposed to send cards to the discard pile, but it turns out that it did not perform
	as expected.  I modified the code so that cards are sent to the discard pile instead of the played pile
	This fixes smithy, and other cards as well.
	
playAdventurer()
	Refactored introduced bug fixed.  Parans missing { }
	
playCouncil_Room()
	fixed bug dealing with adding a buy.
	

