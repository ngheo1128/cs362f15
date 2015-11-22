// Tony Huynh	CS 362	Fall 2015	BugsInTeammates.c

/* Documentation:
	Before I talk about my test results, here are the things I am testing for:
	functions: gainCard, discardCard, scoreFor, getCost
	cards: smithy, adventurer, village, councilRoom.
	
	Sarah Cawley:
	In her code, I have found three bugs using my tests.  Two of the bugs are expected- they are the required smithy and adventurer bug.  Finding these expected bug is good because it lets me know that my tests work.  The other bug I was able to find was in the village card. Her bug was that the village card did NOT provide two extra turns, but it continued to provide one extra card.
	No bugs were found in the functions I was testing for.
	
	Keenan Bishop:
	In Keenan's code, I saw a similar result.  As usual, bugs were found in smithy and adventurer. I found a bug in the village card. In his case, he caused an error to both gaining a card and gaining two actions.  I feel this helps justify my tests' validity by picking up these errors in the code.
	And just like Sarah, I could not find any bugs with the functions I was testing.  
	
	Looking through Sarah's code, it looks like she refactored:
		cards- adventurer, smithy, village, and great hall
		
	For Keenan's code, it appears that he refactored:
		cards- adventurer, smithy, village, and great hall
*/