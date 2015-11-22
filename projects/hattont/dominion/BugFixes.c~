/*******************
Ty Hatton
CS362-F15
Assignment 5
BugFixes.c
*******************/


/******
NOTES
******/

The bugs my teammates found were mostly of my creation. The outlier was
the isGameOver() bug.

Below is a summary of the bugs I corrected and re-ran in unit tests.

/*********************/

/*isGameOver()*/

int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  /*for (i = 0; i < 25; i++) <- Wrong number of cards*/
	for (i = 0; i < 27; i++) /*<- Correction*/
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}

/********************************************************/

/*villageCard()*/

int villageCard(struct gameState *state, int currentPlayer, int handPos) {
  //+1 card
  drawCard(currentPlayer, state);
      
  //+2 Actions
  /*state->numActions = state->numActions + 3; <- Wrong number of cards*/
  state->numActions = state->numActions + 2;/*<- Correction*/
      
  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

/********************************************************/

/*greatHallCard()*/

int greatHallCard(struct gameState *state, int currentPlayer, int handPos){
	
		//+1 Card
  	drawCard(currentPlayer, state);

  	//+1 Actions
  	/*state->numActions+2; <-Wrong increase in numActions*/
	state->numActions+1; /*<- Correction*/

  	//discard card from hand
  	discardCard(handPos, currentPlayer, state, 0);
  	return 0;
	
	
}

/********************************************************/
	
/*council_roomCard()*/

int council_roomCard(struct gameState *state, int currentPlayer, int handPos) {
  	int i;

	//+4 Cards
      for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
      state->numBuys++;
			
      //Each other player draws a card
      /*for (i = 1; i < state->numPlayers; i++)<- Starts with wrong player*/
		for (i = 0; i < state->numPlayers; i++) /*<- Correction*/
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}
			
      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);
			
      return 0;
}

/********************************************************/
	
/*cutpurseCard()*/
int cutpurseCard(struct gameState *state, int currentPlayer, int handPos){
  int i;
  int j;
  int k;
  int x;
	updateCoins(currentPlayer, state, 2);
      	/*for (i = 0; i < state->numPlayers; i++) {<- Starts with wrong player*/
	for (i = 0; i < state->numPlayers; i++){ /*<-Corrected*/
	  			if (i != currentPlayer) {
	      		for (j = 0; j < state->handCount[i]; j++) {
		  				if (state->hand[i][j] == copper) {
		      			discardCard(j, i, state, 0);
		      			break;
		   				 }
		 					 if (j == state->handCount[i]) {
		      				for (k = 0; k < state->handCount[i]; k++){
			  						if (DEBUG)
			    					printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
								}	
		      			break;
		    			}		
						}					
	    		}				
				}			
	
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);			

  return 0;
}




