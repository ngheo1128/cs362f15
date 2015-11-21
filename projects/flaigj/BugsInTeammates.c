/*
Teammate1 bugs - Dustin Dihn - LOCATION: FLAIGJ/TEAMMATE1DOMINION
1) smithyCard: 3 cards were discarded instead of 1; 3 cards are missing from the hand(cardtest1Test5)

2) discardCard: cards do not get discarded, they appear to just get removed from the game
		- No discardCount after a discarded card(cardtest1Test4)
		- Card removed from the game instead of discarded(cardtest1Test6)

3) sea_hag: sea_hag still remains in player hand as if discardCard was never called(cardtest4Test4)

4) sea_hag: sea_hag doesn't add curse cards to the top of the player deck. The count 
	is off or it's something else.(cardtest4Test5)(POSSIBLY RELATED TO JUST DISCARD COUNT BEING OFF)

5) scoreFor: (unittest4Test2) Score not correctly counted for cards in deck
Test 2: Test score for player 2's deck.
Deck: copper, province, province, copper, copper
score after deck: 0
Failed: Expected = 12 Actual = 0


Teammate2 bugs - Kelvin Watson - LOCATION: FLAIGJ/TEAMMATE2DOMINION
1) AdventurerEffect: (cardtest2Test4) 2 Treasures not added to hand.  Coppers do
	not add up and are likely the culprit.

2) sea_hag: sea_hag still remains in player hand as if discardCard was never called(cardtest4Test4)

3) sea_hag: sea_hag doesn't add curse cards to the top of the player deck. The count 
	is off or it's something else.(cardtest4Test5)(POSSIBLY RELATED TO JUST DISCARD COUNT BEING OFF)

4) discardCard: cards do not get discarded, they appear to just get removed from the game
		- No discardCount after a discarded card(cardtest1Test4)
		- Card removed from the game instead of discarded(cardtest1Test6)

5) scoreFor: (unittest4Test2) Score not correctly counted for cards in deck
Test 2: Test score for player 2's deck.
Deck: copper, province, province, copper, copper
score after deck: 0
Failed: Expected = 12 Actual = 0

*/