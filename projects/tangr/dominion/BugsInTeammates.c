Teammate2Hammarlp

Unittest2 
Discarding is buggy. 
When a card is discarded, 
	the hand count decreases by one - correct
	discard pile gains 1 card - fail

Adjusted "randomtestcard" (no change necessary. Parameters aligned)
	possible error in deck counting when playing smithy
	
Adjusted "adventurerCard" function from playAdventurer 
	less parameters are necessary?
	This is a bug unto itself.
	The "adventurer card" can be played indefinitely!
	
	Score changed consistently when played! Error!
	Possible Error in the handsize.
	
	
	
Teammate1Sibailajr

Unittest2
Discarding is buggy. 
When a card is discarded, 
	the hand count decreases by one - correct
	discard pile gains 1 card - fail
	
Adjusted "randomtestcard" (changed function playSmithy (...)-> smithyFunct (...)
	addressed parameters accordingly
	
	play Smithy
	Discovered bug: Score was changing.
	
Adjustment to adventurerFunct for randomtestadventurer
	difficult to understand what is going on.
	He uses a lot more variables than anticipated.
	I do not understand what tempHand[] is and this threw everything off.