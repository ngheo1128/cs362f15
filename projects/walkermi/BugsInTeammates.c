Teammate Code Bug Report



Teammate 1: James Riccelli

Unit Tests:
	updateCoins()
		- No bugs found

	fullDeckCount()
		- No bugs found

	discardCard()
		- No bugs found

	gainCard()
		- No bugs found

Card Tests:
	Adventurer Card
		- Test 1: Adventurer Card is Discarded From Hand to Played Pile
			Expected: Adventurer Card Not In Hand
			ERROR: Adventurer Card Still In Hand
			Expected: Adventurer Card in Played Pile
			ERROR: Adventurer Card Not In Played Pile
				- Analysis: Adventurer card not discarded or added to played pile when played
		- Test 2: Cards are Drawn From Deck and Non-Treasure Cards Are Discarded in Discard Pile
			Expected Deck Count: 3, Actual Deck Count: 2
			cardtest1: cardtest1.c:163: main: Assertion `preState.deckCount[player] - (cardCounter + 2) == state.deckCount[player]' failed.
			Abort (core dumped)
				- Analysis: Adventurer Card draws three treasure cards instead of two

	Smithy Card
		- Test 2: Three Cards are Drawn From Deck
			Expected Deck Count: 7, Actual Deck Count: 6
			ERROR: More Than Three Cards Drawn
				- Analysis: Four cards drawn from deck instead of three
		- Test 3: Three Cards are Added to Hand
			Expected Hand Count: 8, Actual Hand Count: 9
			ERROR: More Than Three Cards Added to Hand
				- Analysis: Four card added to hand instead of three

	Great Hall Card
		- No bugs found

	Village Card
		- Test 4: Current Player's Actions Are Increased By Two
			Expected Num Actions: 3, Actual Num Actions: 4
			ERROR: Two Actions NOT Added To Current Player
				- Analysis: Current player's actions are increased by three instead of two



Teammate 2: Jason Gourley

Unit Tests:
	updateCoins()
		- No bugs found

	fullDeckCount()
		- No bugs found

	discardCard()
		- No bugs found

	gainCard()
		- No bugs found

Card Tests:
	Adventurer Card
		- Test 1: Adventurer Card is Discarded From Hand to Played Pile
			Expected: Adventurer Card Not In Hand
			ERROR: Adventurer Card Still In Hand
			Expected: Adventurer Card in Played Pile
			ERROR: Adventurer Card Not In Played Pile
				- Analysis: Adventurer card not discarded or added to played pile when played
		- Test 4: Hand Count Increases By One (Plus Two Treasure & Minus One Adventurer
			Expected Hand Count: 6, Actual Hand Count: 7
			ERROR: Hand Count Not Incremented By One
				- Analysis: Adventurer card not discarded from hand so hand count did not increment 
					by only one card (+2 treasure and -1 adventurer card)
	
	Smithy Card
		- Test 2: Three Cards are Drawn From Deck
			Expected Deck Count: 7, Actual Deck Count: 6
			ERROR: More Than Three Cards Drawn
				- Analysis: Four cards drawn from deck instead of three
		- Test 3: Three Cards are Added to Hand
			Expected Hand Count: 8, Actual Hand Count: 9
			ERROR: More Than Three Cards Added to Hand
				- Analysis: Four cards added to hand instead of three
	
	Great Hall Card
		- No bugs found

	Village Card
		- No bugs found