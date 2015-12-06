Title: BugsInTeamates.cabs
Description: Explains bugs found in teammates code
Course: CS 362 Software Engineering II
Date: 11/22/15

Teammate 1: Solomon Huynh

Unit Test Results: 
1. UpdateCoins() had no bugs. 
2. getCost() had no bugs.
3. buyCard() had no bugs.
4. isGameOver() contains a bug. In the test results, we can see that the game continues even when 
   more than three of the card supply counts are at zero. Looking at the frequency that these errors occur, 
   we can see that the higher numbered cards occur much more often than the others. This leads us to examine 
   the loop that checks these cards: 
   
   for (i = 0; i < 25; i++){
      if (state->supplyCount[i] == 0){
        j++;
      }
   }
   
   We can see that the stopping condition occurs before the higher numbered cards are counted (i < 25). So the higher
   numbered cards are not being counted and the stopping condition needs to be updated. 

Card Test Results: 
1. smithyCard() contains a bug. The test results show that the hand count after the card is played is always
   incorrect. We can see why if we examine the loop which adds cards to the player's hand: 
   
   for (i = 0; i < 2; i++)
   {
	  drawCard(currentPlayer, state);
   }
   
   The loop is set to halt when i < 2 so only two cards are added to the player's hand instead of the required 3. 

2. remodelCard() had no bugs. 
3. councilRoom() contains a bug. The test results show errors in the number of cards in the player's hand at the end
   of the turn. Since the test set the player's hand to contain only the council room card (1 card), the hand should 
   have 4 cards at the end of the turn. It does not. Examining the source code, we see that the loop to add cards starts at 
   1 instead of the correct 0. So only 3 cards are added to the player's hand. 
4. AdventurerCard() has a bug. The Adventurer card is never discarded. Examining which treasure cards are picked up, we see that
   that the silver is never being picked up. Then looking at the loop in the source code, we see that the conditional does not check
   if the card is silver so it is never picked up. 

Random Test Results:
1. randomtestcard (smithy card): This test shows that the player's hand count is always incorrect. This is because the smithy card function
   picks up only two cards instead of the required three. 
2. randomtestadventurer (adventurer card): This test shows that the adventurer card is never discarded, and that silver cards are not counted. 

Teammate 2: Larissa Hahn

Unit Test Results: 
1. UpdateCoins() had no bugs. 
2. getCost() had no bugs.
3. buyCard() had no bugs.
4. isGameOver() contains a bug as noted above. 

Card Test Results: 
1. smithyCard() contains a bug. The test results show that the hand count after the card is played is always
   incorrect. We can see why if we examine the loop which adds cards to the player's hand: 
   
   for (i = 1; i <= 4; i++)
   {
	  drawCard(currentPlayer, state);
   }
   
   The loop is set to after 4 iterations so 4 cards are added to the player's hand instead of the required 3. 

2. remodelCard() had no bugs. 
3. councilRoom() contains two bugs. The first is in how the number of buys is incremented: 
   //+2 Buy
   state->numBuys + 2;
   It should be "+= 2", not "+ 2".
   
   The second is in how the players draw cards: 
   //Each other player draws a card
  for (i = 0; i <= state->numPlayers; i++)
  {
    if ( i == currentPlayer )
    {
      drawCard(i, state);
    }
  }
  The test results show that both the player's hand count and the opponents' hand counts are wrong. This is because the player is drawing
  a card but the opponents are not (i == currentPlayer should be i != currentPlayer). 
4. AdventurerCard() has a bug. The Adventurer card is never discarded. This is shown in the test results. 

Random Test Results:
1. randomtestcard (smithy card): This test shows that the player's hand count is always incorrect. This is because the smithy card function
   picks up four cards instead of the required three. 
2. randomtestadventurer (adventurer card): This test shows that the adventurer card is never discarded.