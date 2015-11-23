#pragma once

int playAdventurer (struct gameState *state, int currentPlayer, int cardDrawn, int drawntreasure, int temphand[], int z);

/*BUGGED
 * This version of smithy only has the player draw 2 cards instead of 3.  
 * The for loop initializes i as 1 when it should be initialized as 0.
 */

int playSmithy (struct gameState *state, int currentPlayer, int handPos);

/* BUGGED
 * This version of remodel allows the player to trash a card and gain a card
 * costing THREE more than the card trashed.  It should only by allowed to 
 * add a card costing two more.  In the third line, inside the if statement,
 * the cost of the coin should be added by 2, not 3.
 */

int playRemodel (struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos);


/*BUGGED
 * This version of village trashed the village card after it is used.  On the
 * second to last line, the discardCard funtion has the trashFlag set.  It 
 * should be called with a 0 as the last argument instead of a 1.
 */

int playVillage (struct gameState *state, int currentPlayer, int handPos);

//NOT BUGGED

int playMine (struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos);