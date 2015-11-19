/******************************************************************
Anthony Wilcox
CS362, Fall 2015
Assignment 5

Bug Fixes:
--------------------------------------------------------------------
Bug play_council 01:
Bug found by talisb, line 729: 
  for (i = 0; i < 4; i++)
	{
      x++; //testing 
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
bug ->    //state->numBuys++;
			
      //Each other player draws a card
	  
changed to:
  for (i = 0; i < 4; i++)
	{
      x++; //testing 
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
fix->      state->numBuys++;
			
      //Each other player draws a card

Adds number of buys per for loop iteration.
-------------------------------------------------------------------
Bug play_smithy 01
Bug introduced by wilcoant
int play_smithy(int currentPlayer, struct gameState *state, int handPos)
{
    int i;
   //+3 Cards
bug ->    for (i = 0; i <= 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
for loop here will draw 4 cards.
int play_smithy(int currentPlayer, struct gameState *state, int handPos)
{
    int i;
   //+3 Cards
fix->    for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
---------------------------------------------------------------------
Bug play_adventurer 01:
bug placed by wilcoant: line 659 

bug-> if (cardDrawn == copper || (cardDrawn == silver && cardDrawn == gold))
	  drawntreasure++;
fix-> if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
  
*allows drawn treasure to increase when any treasure card is found.
----------------------------------------------------------------------
Bug play_remodel 01 
Bug introduced by wilcoant 
j = state->hand[currentPlayer][choice1];  //store card we will trash

bug->      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
	{
	  return -1;
	}

j = state->hand[currentPlayer][choice1];  //store card we will trash

fix-> if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
	{
	  return -1;
	}
	

*******************************************************************/