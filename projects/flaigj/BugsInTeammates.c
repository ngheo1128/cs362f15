/*
Teammate1 bugs - Dustin Dihn - LOCATION: FLAIGJ/TEAMMATE1DOMINION
1) smithyCard: 3 cards were discarded instead of 1; 3 cards are missing from the hand(cardtest1Test5)

2) discardCard: cards do not get discarded, they appear to just get removed from the game
		- bug apparent in all cardtests when discarding
		- will likely mask other errors

3) sea_hag: sea_hag still remains in player hand as if discardCard was never called(cardtest4Test4)

4) sea_hag: sea_hag doesn't add curse cards to the top of the player deck. The count 
	is off or it's something else.(cardtest4Test5)(POSSIBLY RELATED TO JUST DISCARD COUNT BEING OFF)

5) adventurerCard or shuffle method: shuffling when deck is empty doesn't happen in 
	adventurer when the deck is 0 or 1.  This is evident because 2 treasures added fails.
	(randomtestadventurer: Treasure test fails)

6) scoreFor: (unittest4Test2) Score not correctly counted for cards in deck

7) scoreFor: (unittest4Test2) Score not correctly counted for cards in discard pile

Teammate2 bugs - Kelvin Watson - LOCATION: FLAIGJ/TEAMMATE2DOMINION
1) AdventurerEffect: (cardtest2Test4:Fails) 2 Treasures not added to hand.  Coppers do
	not add up and are likely the culprit.

2) sea_hag: sea_hag still remains in player hand as if discardCard was never called(cardtest4Test4)

3) sea_hag: sea_hag doesn't add curse cards to the top of the player deck. The count 
	is off or it's something else.(cardtest4Test5)(POSSIBLY RELATED TO JUST DISCARD COUNT BEING OFF)

4) discardCard: cards do not get discarded, they appear to just get removed from the game
		- bug apparent in all cardtests when discarding
		- will likely mask other errors

5) adventurerCard or shuffle method: shuffling when deck is empty doesn't happen in 
	adventurer when the deck is 0 or 1.  This is evident because 2 treasures added fails.
	(randomtestadventurer: Treasure test fails)

6) scoreFor: (unittest4Test2) Score not correctly counted for cards in deck

7) scoreFor: (unittest4Test3) Score not correctly counted for cards in discard

*/