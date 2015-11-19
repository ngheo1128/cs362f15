Billy Kerns
BugsInTeammates.c

Teammate 1-Daniel Bonnin

ID:
	1

Description:
	Calling the scoreFor function does not always return the correct score for a player.

Expected Output:
	Correct score 

Actual Output:
	Incorrect score

Severity:
	High-Does not break game but could lead to the wrong player winning or losing

Priority:
	Medium-Game is still playable but with incorrect results

How to Reproduce:
	Call scorefor function making sure the player''s discard count is different than the player''s hand count

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	2

Description:
	Calling the discardCard function does not increment the gameState''s discard count

Expected Output:
	discardCount: 296        

Actual Output:
	Iteration #0    Test 5 failed.
	Actual discardCount: 295	

Severity:
	Low-Does not seem to have much of an effect on playing the game

Priority:
	Low-Needs to be fixed as it may effect the game in unforeseen ways that haven''t been found yet

How to Reproduce:
	Call the discardCard function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	3

Description:
	The smithy card does not add three card to the player''s hand

Expected Output:
	handCount = 332

Actual Output:
	Iteration # 0 Test 1 failed. 
	Actual: deckCount = 331

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the smithy card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	4

Description:
	The smithy card does not remove three card from player''s deck

Expected Output:
	deckCount = 301

Actual Output:
	Iteration # 0 Test 2 failed.
	Actual: deckCount = 302

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the smithy card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	5

Description:
	The adventurer card does not add two treasure cards to the player''s hand when two treasure are available

Expected Output:
	treasure in hand = 51

Actual Output:
	Iteration #: 0  Test 6 failed
	treasure in hand = 49

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the adventurer card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	6

Description:
	The village card does not add the correct amount of actions to the gameState

Expected Output:
	numActions = 3

Actual Output:
	Iteration #:0   Test 2 failed
	numActionst = 4

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the village card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	7

Description:
	The discardCount is not incremented when the village card is played

Expected Output:
	discardCount = 373

Actual Output:
	Iteration #: 0  Test 3 failed
	discardCount = 372

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the village card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	8

Description:
	The great hall card does not always add a card to the player''s hand

Expected Output:
	cardCount = 477

Actual Output:
	Iteration #:0   Test 1 failed
	cardCount = 476

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the great hall card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	9

Description:
	The great hall card does not increment the discarded card count

Expected Output:
	discardCount = 373

Actual Output:
	Iteration #: 0  Test 4 failed
	Actual: discardCount = 372

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the great hall card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	10

Description:
	The great hall card does will sometimes effect other players

Expected Output:
	Player 0(not the player who played the card) handCount = 340

Actual Output:
	Iteration #: 0  Test 5 failed
	Player 0 handCount = 341

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Create a gameState with multiple players and play the great hall card a few times and the error will show up

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	11

Description:
	The great hall card does will sometimes effect other players

Expected Output:
	Player 0(not the player who played the card) handCount = 340

Actual Output:
	Iteration #: 0  Test 5 failed
	Player 0 handCount = 341

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Create a gameState with multiple players and play the great hall card a few times and the error will show up

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

The random tests on the adventurer card brought up the same bugs as the unit tests so I will not be repeating
them here.

The random tests on the village card brought up the same bug as the unit tests so I will not be repeating them
here.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Teammate 2-Victor Hernandez

ID:
	1

Description:
	Calling the scoreFor function does not always return the correct score for a player.

Expected Output:
	Correct score 

Actual Output:
	Incorrect score

Severity:
	High-Does not break game but could lead to the wrong player winning or losing

Priority:
	Medium-Game is still playable but with incorrect results

How to Reproduce:
	Call scorefor function making sure the player''s discard count is different than the player''s hand count

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	2

Description:
	Calling the discardCard function does not increment the gameState''s discard count

Expected Output:
	discardCount: 296        

Actual Output:
	Iteration #0    Test 5 failed.
	Actual discardCount: 295	

Severity:
	Low-Does not seem to have much of an effect on playing the game

Priority:
	Low-Needs to be fixed as it may effect the game in unforeseen ways that haven''t been found yet

How to Reproduce:
	Call the discardCard function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	3

Description:
	The smithy card is no added to the played card count

Expected Output:
	playedCardCount = 297

Actual Output:
	Iteration # 0 Test 9 failed. Card was not added to played card count
	playedCardCount = 296

Severity:
	Low-Does not seem to have much of an effect on playing the game

Priority:
	Low-Needs to be fixed as it may effect the game in unforeseen ways that haven''t been found yet

How to Reproduce:
	Call the discardCard function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	4

Description:
	The village card does not add the correct amount of actions to the gameState

Expected Output:
	numActions = 3

Actual Output:
	Iteration #:0   Test 2 failed
	numActionst = 4

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the village card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	5

Description:
	The discardCount is not incremented when the village card is played

Expected Output:
	discardCount = 311

Actual Output:
	Iteration #: 0  Test 3 failed
	discardCount = 310

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the village card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	6

Description:
	The great hall card adds an extra card to the players hand

Expected Output:
	cardCount = 46

Actual Output:
	Iteration #:0   Test 1 failed
	Actual: cardCount = 47

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the great hall card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ID:
	7(random adventurer testing)

Description:
	The player''s hand count is not decremented to account for the adventurer card being played

Expected Output:
	Post handCount = 164 

Actual Output:
	Iteration #: 0  Test 10 failed
	Post handCount = 165

Severity:
	High-Could change outcome of the game

Priority:
	High-Not game breaking but still a large problem

How to Reproduce:
	Play the great hall card

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
The random tests on the village card brought up the same bug as the unit tests so I will not be repeating them
here.
