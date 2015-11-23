/*
BugFixes.c
	
	Smithy Card:
	
	In my refactored Smithy Card effect function, Ashok and Scott's tests revealed
	that handCount was being incremented incorrectly. I was quickly able to fix
	the line of code that created the error by making a single change to the for
	loop in the refactored function from:
		for (i = 0; i < 4; i++)
	to
		for (i = 0; i < 3; i++).
	
	
	Adventurer Card:
	
	Scott and Ashok's tests both revealed the fatal bug in my Adventurer Card
	implementation, which was that the function was not checking for gold cards.
	This bug occurred on line 664 where the if statement was missing a statement
	to check for cardDrawn == gold.
	The fix was simply changing line 664 from:
		if (cardDrawn == copper || cardDrawn == silver)
	to
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	
	
	Village Card:
	
	Ashok's test revealed that my implementation of the Village Card was improperly
	incrementing numActions. The fix was changing line 707 from:
		state->numActions = state->numActions + 1;
	to
		state->numActions = state->numActions + 2;
		
*/