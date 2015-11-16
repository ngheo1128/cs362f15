/********************************** TESTING TEAMMATE 1 *********************************************************/

/* Here are the found bugs, below are the results from the tests.*/

/*
Bug 1: Smith card, player does not receive the proper amount of cards.
Bug 2: Adventurer card does not shuffle deck when deck count = 0.
Bug 3: Adventurer card does not give player proper amount of cards.
Bug 4: Adventurer card does not give player two treasure cards.
Bug 5: Village card action to play card was not decremented.
Bug 6: Discard card function does not add card to discard pile.
Bug 7: When deck count is 0 and discard pile is -1 deck count is less than 0 when draw card function is used.
Bug 8: Game is not over when 3 card stacks are empty.
Bug 9: Score is not correctly calculated for cards in player's discard pile.
Bug 10: Score is not correctly calculated for cards in player's deck pile.
Bug 11: Steward card does not discard 2 cards when user chooses this option.
Bug 12: Steward card does not give player proper amount of cards.
*/

/*****************************************CARD TESTS************************************************************/
/*

TESTING smithy_card():
Test player 1 with 5 card(s) with 1 card being a Smithy card.
Copper, Village, Silver, Smithy, Mine, 
PASS - Smithy card is in player's hand
Using Smithy card...
FAIL - Player 1 has not received the proper amount of cards.
Copper, Village, Silver, Estate, Mine, Copper, 
PASS - Smithy card was discarded from hand.

****************************************************************************************************

TESTING adventurer_card():
Test player 1 with 5 card(s) with 1 card being an Adventurer card.
Smithy, Village, Gardens, Adventurer, Mine, 
PASS - Adventurer card is in player's hand
Player's deck count is 0 and must be shuffled
Using Adventurer card...
FAIL - deckCount still 0, did not shuffle
FAIL - Player 1 has not received the proper amount of cards.
PASS - Adventurer card was discarded from hand.
FAIL - Two treasure cards were NOT added to hand.

***************************************************************************************************

TESTING Village card:
Test player 0 with 5 card(s) with 1 card being a Village card.
Copper, Village, Silver, Gold, Mine, 
PASS - Village card is in player's hand
Using Village card...
PASS - Player 0 has received 1 card.
FAIL - Player 0 gained 2 actions but action to play card was not decremented.
Copper, Copper, Silver, Gold, Mine, 
PASS - Village card has been discarded from player's hand

****************************************************************************************************

TESTING steward_card() with three different choices:
Test player 0 with 5 card(s) with 1 card being a Steward card.

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 0
PASS - 2 cards discarded.
Feast, Mine, 
PASS - Steward card has been discarded from player's hand

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 1
PASS - Player 0 has received 2 cards.
Feast, Village, Copper, Smithy, Mine, Copper, 
PASS - Steward card has been discarded from player's hand

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 2
PASS - Player 0 has received 2 coins.
Feast, Village, Mine, Smithy, 
PASS - Steward card has been discarded from player's hand
/*


/*****************************************UNIT TESTS*********************************************************/
/*

TESTING discardCard():
Copper, Silver, Village, Gold, Smithy, 
Discard village card trash flag set to 0
PASS - card added to played pile when trash flag set to 0.
FAIL - card NOT added to discard pile.
PASS - Last card replaced discarded card's position.
Copper, Silver, Smithy, Gold, 
PASS - card has been discarded from player's hand

Discard gold card trash flag set to 1
PASS - card NOT added to played pile when trash flag set to 1.
FAIL - card NOT added to discard pile.
PASS - Last card's position in hand discarded NOT replaced with another card.
Copper, Silver, Smithy, 
PASS - card has been discarded from player's hand

Copper, 
PASS - Player's hand is empty.
PASS - card has been discarded from player's hand

****************************************************************************************************

TESTING drawCard():
Draw card with cards left in deck.
PASS - card added to player's hand.
PASS - card removed from deck pile.
PASS - deck count is NOT less than 0.

Draw card with 0 cards left in deck and 5 cards in discard pile.
PASS - discard pile added to deck pile.
PASS - discard pile is empty.
PASS - card added to player's hand.
PASS - card removed from deck pile.
PASS - deck count is NOT less than 0.

Draw card with 0 cards left in deck but -1 discard pile.
PASS - discard pile added to deck pile.
PASS - discard pile is empty.
PASS - card added to player's hand.
PASS - card removed from deck pile.
FAIL - deck count is less than 0.

*****************************************************************************************************

TESTING isGameOver():
Determine if game is over when Province card stack is empty.
PASS - Game is NOT over when 1 Province remaining.
PASS - Game is over when 0 Province remaining.

Determine if game is over when 3 coin card stacks are empty; copper, silver, gold.
PASS - Game is NOT over when 1 card stack empty.
PASS - Game is NOT over when 2 card stacks are empty.
PASS - Game is over when 3 card stacks are empty.

Determine if game is over when 3 action card stacks are empty; Smithy, Village, Treasure Map
PASS - Game is NOT over when 1 card stack empty.
PASS - Game is NOT over when 2 card stacks are empty.
FAIL - Game is NOT over when 3 card stacks are empty.

******************************************************************************************************

TESTING scoreFor():

Player Hand
Curse, Silver, Village, Gold, Duchy, 
Score for Player's Hand is 2
PASS - Score correctly calculated for cards in Player's Hand

Discard Pile
Village, Smithy, Estate, Duchy, Curse, 
Score for Player's Discard pile is 0
FAIL - Score NOT correctly calculated for cards in Player's discard pile

Deck Pile
Curse, Curse, Village, Great Hall, Province, 
Score Player's Deck pile is 0
FAIL - Score NOT correctly calculated for cards in Player's deck pile
*/

/****************************************** RANDOM TESTS ****************************************************/

/*

p = player
HC = handcount
DeC = deck count
DiC = discard count

adventurer_card() PRE: p 1 HC 4 DeC -1 DiC 5
adventurer_card() POST: p 1 HC -495 DeC 0 DiC 504
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 1 DiC 5
adventurer_card() POST: p 1 HC 5 DeC 0 DiC 5
FAIL - Two treasure cards were NOT added to hand.

adventurer_card() PRE: p 0 HC 4 DeC 0 DiC 5
adventurer_card() POST: p 0 HC 4 DeC 0 DiC 5
FAIL - deckCount still 0, did not shuffle
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 0 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 1 DiC 5
adventurer_card() POST: p 1 HC 5 DeC 0 DiC 5
FAIL - Two treasure cards were NOT added to hand.

adventurer_card() PRE: p 1 HC 4 DeC 3 DiC 5
adventurer_card() POST: p 1 HC 5 DeC 0 DiC 7
FAIL - Two treasure cards were NOT added to hand.

adventurer_card() PRE: p 1 HC 4 DeC -1 DiC 5
adventurer_card() POST: p 1 HC -495 DeC 0 DiC 504
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 1 DiC 5
adventurer_card() POST: p 1 HC 5 DeC 0 DiC 5
FAIL - Two treasure cards were NOT added to hand.

adventurer_card() PRE: p 1 HC 4 DeC -1 DiC 5
adventurer_card() POST: p 1 HC -495 DeC 0 DiC 504
FAIL - Player 1 has not received the proper amount of cards.

967 out of 300000 Tests failed

******************************************************************************************************

steward_card() PRE: p 1 HC 70 DeC 466 DiC 463
steward_card() POST: p 1 HC 70 DeC 466 DiC 463
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 254 DeC 314 DiC 210
steward_card() POST: p 1 HC 254 DeC 314 DiC 210
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 357 DeC 188 DiC 489
steward_card() POST: p 1 HC 357 DeC 188 DiC 489
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 224 DeC 499 DiC 45
steward_card() POST: p 1 HC 224 DeC 499 DiC 45
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 111 DeC 205 DiC 280
steward_card() POST: p 1 HC 111 DeC 205 DiC 280
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 368 DeC 59 DiC 467
steward_card() POST: p 1 HC 368 DeC 59 DiC 467
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 423 DeC 499 DiC 316
steward_card() POST: p 1 HC 423 DeC 499 DiC 316
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 170 DeC 209 DiC 71
steward_card() POST: p 1 HC 170 DeC 209 DiC 71
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 395 DeC 94 DiC 405
steward_card() POST: p 1 HC 395 DeC 94 DiC 405
FAIL - 2 cards NOT discarded.

4965 out of 15000 Tests failed

*/


















/*********************************** TESTING TEAMMATE 2 *********************************************************/

/* Here are the found bugs, below are the results from the tests.*/

/*
Bug 1: Smithy card does not give the player the proper amount of cards.
Bug 2: Adventurer card does not shuffle the deck when deck count is 0.
Bug 3: Adventurer card does not give the player the proper amount of cards.
Bug 4: Adventurer card does not give player two treasure cards.
Bug 5: Village card does not give the player a card.
Bug 6: Village card does not decrement an action for using the card.
Bug 7: Steward card does not give player two cards.
Bug 8: Discard card function does not add card to discard pile.
Bug 9: Draw card does not add card to player's hand when deck count is 0.
Bug 10: Draw card does not remove a card from deck when deck count is 0 (deck not shuffled).
Bug 11: After draw card is called deck count is 0 when initially deck count is 0.
Bug 12: When deck count is 0 and discard pile is -1 deck count is less than 0 when draw card function is used.
Bug 13: Game is not over when 3 card stacks are empty.
Bug 14: Score is not correctly calculated for cards in player's discard pile.
Bug 15: Score is not correctly calculated for cards in player's deck pile.
Bug 16: Steward card does not discard 2 cards when user chooses this option.
*/


/*****************************************CARD TESTS************************************************************/

/*
TESTING smithy_card():
Test player 1 with 5 card(s) with 1 card being a Smithy card.
Copper, Village, Silver, Smithy, Mine, 
PASS - Smithy card is in player's hand
Using Smithy card...
FAIL - Player 1 has not received the proper amount of cards.
Copper, Village, Silver, Smithy, Mine, 
PASS - Smithy card was discarded from hand.

*******************************************************************************************************

TESTING adventurer_card():
Test player 1 with 5 card(s) with 1 card being an Adventurer card.
Smithy, Village, Gardens, Adventurer, Mine, 
PASS - Adventurer card is in player's hand
Player's deck count is 0 and must be shuffled
Using Adventurer card...
FAIL - deckCount still 0, did not shuffle
FAIL - Player 1 has not received the proper amount of cards.
Smithy, Village, Gardens, Adventurer, Mine, PASS - Adventurer card was discarded from hand.
FAIL - Two treasure cards were NOT added to hand.

********************************************************************************************************

TESTING Village card:
Test player 0 with 5 card(s) with 1 card being a Village card.
Copper, Village, Silver, Gold, Mine, 
PASS - Village card is in player's hand
Using Village card...
FAIL - Player 0 has not received a card.
FAIL - Player 0 gained 2 actions but action to play card was not decremented.
Copper, Mine, Silver, Gold, 
PASS - Village card has been discarded from player's hand

*******************************************************************************************************

TESTING steward_card() with three different choices:
Test player 0 with 5 card(s) with 1 card being a Steward card.

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 0
PASS - 2 cards discarded.
Feast, Mine, 
PASS - Steward card has been discarded from player's hand

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 1
FAIL - Player 0 has not received 2 cards.
Feast, Village, Mine, Smithy, 
PASS - Steward card has been discarded from player's hand

Feast, Village, Steward, Smithy, Mine, 
PASS - Steward card is in player's hand
Using steward card choice1 is 2
PASS - Player 0 has received 2 coins.
Feast, Village, Mine, Smithy, 
PASS - Steward card has been discarded from player's hand
*/

/*****************************************UNIT TESTS*********************************************************/

/*

TESTING discardCard():
Copper, Silver, Village, Gold, Smithy, 
Discard village card trash flag set to 0
PASS - card added to played pile when trash flag set to 0.
FAIL - card NOT added to discard pile.
PASS - Last card replaced discarded card's position.
Copper, Silver, Smithy, Gold, 
PASS - card has been discarded from player's hand

Discard gold card trash flag set to 1
PASS - card NOT added to played pile when trash flag set to 1.
FAIL - card NOT added to discard pile.
PASS - Last card's position in hand discarded NOT replaced with another card.
Copper, Silver, Smithy, 
PASS - card has been discarded from player's hand

Copper, 
PASS - Player's hand is empty.
PASS - card has been discarded from player's hand

**********************************************************************************************************

TESTING drawCard():
Draw card with cards left in deck.
FAIL - card NOT added to player's hand.
FAIL - card NOT removed from deck pile.
FAIL - deck count is less than 0.

Draw card with 0 cards left in deck and 5 cards in discard pile.
PASS - discard pile added to deck pile.
PASS - discard pile is empty.
PASS - card added to player's hand.
PASS - card removed from deck pile.
PASS - deck count is NOT less than 0.

Draw card with 0 cards left in deck but -1 discard pile.
PASS - discard pile added to deck pile.
PASS - discard pile is empty.
PASS - card added to player's hand.
PASS - card removed from deck pile.
FAIL - deck count is less than 0.

**********************************************************************************************************

TESTING isGameOver():
Determine if game is over when Province card stack is empty.
PASS - Game is NOT over when 1 Province remaining.
PASS - Game is over when 0 Province remaining.

Determine if game is over when 3 coin card stacks are empty; copper, silver, gold.
PASS - Game is NOT over when 1 card stack empty.
PASS - Game is NOT over when 2 card stacks are empty.
PASS - Game is over when 3 card stacks are empty.

Determine if game is over when 3 action card stacks are empty; Smithy, Village, Treasure Map
PASS - Game is NOT over when 1 card stack empty.
PASS - Game is NOT over when 2 card stacks are empty.
FAIL - Game is NOT over when 3 card stacks are empty.

************************************************************************************************************

TESTING scoreFor():

Player Hand
Curse, Silver, Village, Gold, Duchy, 
Score for Player's Hand is 2
PASS - Score correctly calculated for cards in Player's Hand

Discard Pile
Village, Smithy, Estate, Duchy, Curse, 
Score for Player's Discard pile is 0
FAIL - Score NOT correctly calculated for cards in Player's discard pile

Deck Pile

Score Player's Deck pile is 0
FAIL - Score NOT correctly calculated for cards in Player's deck pile

/******************************************RANDOM TESTS ***********************************************/

/*
steward_card() PRE: p 1 HC 111 DeC 205 DiC 280
steward_card() POST: p 1 HC 111 DeC 205 DiC 280
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 368 DeC 59 DiC 467
steward_card() POST: p 1 HC 368 DeC 59 DiC 467
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 423 DeC 499 DiC 316
steward_card() POST: p 1 HC 423 DeC 499 DiC 316
FAIL - 2 cards NOT discarded.

steward_card() PRE: p 1 HC 170 DeC 209 DiC 71
steward_card() POST: p 1 HC 170 DeC 209 DiC 71
FAIL - Player 1 has not received 2 cards.

steward_card() PRE: p 1 HC 395 DeC 94 DiC 405
steward_card() POST: p 1 HC 395 DeC 94 DiC 405
FAIL - 2 cards NOT discarded.

4965 out of 15000 Tests failed

***********************************************************************************************************

I had to change a line of code in cards.c because of segment fault error. They do the same thing
except one calls teammates 2, defined lastDrawn function.

The line used to be: cardDrawn = lastDrawn(currentPlayer, state);
But I changed it to: cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];


p = player
HC = handcount
DeC = deck count
DiC = discard count

adventurer_card() PRE: p 1 HC 4 DeC 273 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 273 DiC 5
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 238 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 238 DiC 5
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 274 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 274 DiC 5
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 230 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 230 DiC 5
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 349 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 349 DiC 5
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 343 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 343 DiC 5
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 143 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 143 DiC 5
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC -1 DiC 5
adventurer_card() POST: p 1 HC 4 DeC -1 DiC 5
FAIL - deckCount still -1, did not shuffle
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 114 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 114 DiC 5
FAIL - Two treasure cards were NOT added to hand.
FAIL - Player 1 has not received the proper amount of cards.

adventurer_card() PRE: p 1 HC 4 DeC 342 DiC 5
adventurer_card() POST: p 1 HC 4 DeC 342 DiC 5
FAIL - Player 1 has not received the proper amount of cards.

77304 out of 300000 Tests failed
*/