/*
Brian Tiegs
CS 362 - Assignment

Bug Report for Dominion.c

*******************************************************************************

Teammate 1 - James Carlin

Bug 1
	Test: unittest1.c
	Location: scoreFor
	Bug:
		Incorrectly calculates score
			Calculates lower score when discardCount < deckCount
			Calculates higher score when discardCount > deckCount
	Conditions to produce bug:
		Hand, deck and discard pile contain estate or curse cards
		discardCount does not equal deckCount

Bug 2
	Test: unittest1.c
	Location: scoreFor
	Bug:
		Gardens cards give a score of 0
	Conditions to produce bug:
		Hand, deck and discard pile contain garden cards
		handCount, discardCount and/or deckCount are greater than 0

Bug 3
	Test: unittest2.c
	Location: isGameOver
	Bug:
		isGameOver returns 1 when 3 card piles are empty
	Conditions to produce bug:
		3 card piles are empty
		At least 1 card pile is the Sea Hag card or Treasure Map card

Bug 4
	Test: cardtest1.c and randomtestadventurer
	Location: adventurer card
	Bug:
		Deck did not lose 2 cards with full deck of coin cards
		Hand did not gain 2 cards with full deck of coin cards
	Conditions to produce:
		Deck is made up of all coin cards
		deckCount >= 2

Bug 5
	Test: cardtest2.c
	Location: smithy card
	Bug:
		Deck did not lose 3 cards
		Hand did not gain 2 cards
	Conditions to produce bug:
		No special condtitions needed

Bug 6:
	Test: cardtest4.c and randomtestcard.c
	Location: treasure map
	Bug:
		Treasure maps were not trashed in player's hand at positions 0 and 9
	Conditions to produce bug:
		Treasure cards are set to hand indexes 0 and 9
		handPos = 0
		index = 9
		handCount = 10

*******************************************************************************

Teammate 2 - Aditya Gune

Bug 1
	Test: unittest1.c
	Location: scoreFor
	Bug:
		Incorrectly calculates score
			Calculates lower score when discardCount < deckCount
			Calculates higher score when discardCount > deckCount
	Conditions to produce bug:
		Hand, deck and discard pile contain estate or curse cards
		discardCount does not equal deckCount

Bug 2
	Test: unittest1.c
	Location: scoreFor
	Bug:
		Gardens cards give a score of 0
	Conditions to produce bug:
		Hand, deck and discard pile contain garden cards
		handCount, discardCount and/or deckCount are greater than 0

Bug 3
	Test: unittest2.c
	Location: isGameOver
	Bug:
		isGameOver returns 1 when 3 card piles are empty
	Conditions to produce bug:
		3 card piles are empty
		At least 1 card pile is the Sea Hag card or Treasure Map card

Bug 4:
	Test: cardtest4.c and randomtestcard.c
	Location: treasure map
	Bug:
		Treasure maps were not trashed in player's hand at positions 0 and 9
	Conditions to produce bug:
		Treasure cards are set to hand indexes 0 and 9
		handPos = 0
		index = 9
		handCount = 10

Bug 5:
	Test: randomtestadventurer.c
	Location: adventurer card
	Bug:
		Treasure cards were not added to player's hand
		Discarded cards from deck were not moved to discard pile
	Conditions to produce bugs:
		Discard pile contains 0 treasure cards
		Deck contains 0 treasure cards
*/
