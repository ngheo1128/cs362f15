/*
 * Title: cardtest1.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing remodel card
 * Testing for: - selected card should be placed in the trash
 *              - a card should be gained which costs up to two more than the card that was trashed
 *				- Note that the condition about the relative card costs is tested in cardeffect so it 
 *				  does not need to be tested here. 
 *             
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include "rngs.h"
 #include "interface.h"
 #include <time.h>
 
 void testRemodel() {
	 printf("\nTesting remodel card...\n");
	 srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	int player; //which player we are testing (could be 0, 1, 2, or 3)
	int remodel_position;
	int trash_position; 
	int gain_choice; 
	/*loop counters*/
	int i; 
	int j; 
	int errors = 0; 
	
	struct gameState G; 
	struct gameState save; 
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
	for (i = 0; i < 3000; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		
		remodel_position = rand() % 10; 
		player = rand() % 4; 
		
		trash_position = rand() % 10; 
		gain_choice = rand() % 27; 
		while (remodel_position == trash_position) {
			trash_position = rand() % 10; 
		}
		
		/*ensure there is at least 1 remodel card in the player's hand*/
		G.hand[player][remodel_position] = remodel;
		
		/*update player's turn to the player we have randomly seleted*/
		G.whoseTurn = player; 
		
		/*ensure there is at least one of the gain cards is in the supply*/
		G.supplyCount[gain_choice] = 10; 
		memcpy(&save, &G, sizeof(struct gameState));
		
		//function signature: playRemodel(struct gameState, int choice1, int choice2, int handPos);
		//int remodelCard(struct gameState *state, int handPos, int choice1, int choice2)
		//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
		//int z = remodelCard(&G, remodel_position, trash_position, gain_choice);
		int z = cardEffect(remodel, trash_position, gain_choice, 0, &G, remodel_position, 0);
		/*Check if remodel card has been removed from hand*/
		if (z != -1 && G.hand[player][remodel_position] == remodel) {
			printf("\nRemodel card was not removed!\n");
		}
		
		/*Check if card that was selected to gain is now in discard*/
		int test = 0; 
		for (j = 0; j < G.discardCount[player]; j++) {
			if (G.discard[player][j] == gain_choice) {
				test = 1; 
				break; 
			}
		}
		if (z != -1 && test == 0) {
			printf("\nCard to gain was not placed in discard.\n");
			errors++; 
		}
		
		/*Check if remodel card is in played pile*/ 
		test = 0; 
		for (j = 0; j < G.playedCardCount; j++) {
			if (z != -1 && G.playedCards[j] == remodel) {
				test = 1; 
				break; 
			}
		}
		if (z != -1 && test == 0) {
				printf("\nFound an error in loop 2.\n");
			errors++; 
		}
		
	}
	
	printf("\nNumbers of errors found is %d\n", errors); 
	printf("\nTesting remodel card complete!\n");
	 
 }
 
 int main () {
	 
	 testRemodel();
	 return 0; 
 }
 