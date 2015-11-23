/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 17, 2015
 * File Name:              unittest2.c
 * Overview:
 *   Unit tests for adventurer card
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

	//intialization steps below borrowed from unittest2
    //seed for initialize game
    int seed = 12345;
    int i = 0;
    int advFlag = 0;
    //here you can choose number of players, between 2 and 4
    int numPlayers = 2;
    //here you can choose player number, starting at 0, up to # of players -1
    int player = 0;
    //players start with 5 cards
    int handNum = 5;
    //this one should pass
    //array to hold current cards
	int currHand[handNum];
    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

while (player < numPlayers){
    printf("+++++++++++++++++ testing player %d +++++++++++++++++++\n", player);
    struct gameState newGame;
    initializeGame(numPlayers, k, seed, &newGame);

	advFlag = 0;
	i = 0;
	handNum = 5;
	currHand[0] = adventurer;  //worth 1
    currHand[1] = gold;  //worth 3
    currHand[2] = silver;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = estate; 

    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    newGame.handCount[player] = handNum;
    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing playAdventurer Fuction for player %d...\n", player);
    printf("Intializing Game...\n");

    printf("Check adventurer card is in hand of player %d...\n", player);
    for(i = 0; i < newGame.handCount[player]; i++) {
    	if (currHand[i] == adventurer) {
    		printf("Adventurer is in hand...\n");
    		advFlag = 1;
    		break;
    	} else {
    		continue;
    	}
    }


    int drawntreasureBefore = 0;
    int drawntreasureAfter = 0;
    int handNumBefore = handNum;
    int deckCountBefore = newGame.deckCount[player];
    int discardCountBefore = newGame.discardCount[player];

    if (!advFlag) {
    	printf("No Adventurer Card In Hand!\n");
    } else {
    	//check number of treasuare cards before
    	for (i = 0; i < newGame.handCount[player]; i++){
            //printf("This is hand at %d: %d\n", i, newGame.hand[player][i] );
    		if ((newGame.hand[player][i] == copper) || (newGame.hand[player][i] == silver) || (newGame.hand[player][i] == gold)){
    			drawntreasureBefore++;
                //printf("one treasure %d\n", drawntreasureBefore );
    		}
    	}
        //changed to match partners code
        //int playAdventurer(int currentPlayer, struct gameState *state)
        playAdventurer(player, &newGame);
    	//playAdventurer(&newGame);

        //added hand
    	// if ((deckCountBefore + discardCountBefore + handNumBefore) == (newGame.handCount[player] + newGame.deckCount[player] + newGame.discardCount[player])){
    	// 	printf("Passed! Discard + Deck counts are the same before and after (no new or disappeared cards)\n");
    	// } else {
    	// 	if (deckCountBefore + discardCountBefore +handNumBefore > (newGame.handCount[player] + newGame.deckCount[player] + newGame.discardCount[player])) {
    	// 		printf("Failed! There are cards missing!\n");
        //            printf("There are %d cards in the discard and should be %d\n",newGame.discardCount[player], discardCountBefore );
         //            printf("There are %d cards in deck should be %d\n\n", newGame.deckCount[player], deckCountBefore);
    	// 	} else {
    	// 		printf("Failed! There are too many cards!\n");
    	// 	}
    	// }
        //    printf("\n\n\n\n\n");


        //not necessary
    	//check hand has one more card
    	if ((handNum+1) == newGame.handCount[player]) {
    		printf("Passed! Number of cards in the hand is correct\n");
    	} else {
    		printf("Failed! Number of cards in hand is wrong!\n");
            printf("There are %d cards and there should be %d cards\n", newGame.handCount[player], handNum+1);
    	}

        printf("\n\n");
    	//check hand has two more treasure cards
    	for (i = 0; i < newGame.handCount[player]; i++){
    		if ((newGame.hand[player][i] == copper) || (newGame.hand[player][i] == silver) || (newGame.hand[player][i] == gold)){
    			drawntreasureAfter++;
                //printf("one treasure %d\n", drawntreasureAfter );

    		}
    	}

        for(i = 0; i < newGame.handCount[player]; i++) {
        if (currHand[i] == adventurer) {
            printf("Adventurer is in hand... Not Discarded!\n");
            advFlag = 1;
            break;
        } else {
            continue;
        }
    }

    	if ((drawntreasureBefore+2) == drawntreasureAfter){
    		printf("Passed! Number of treasure cards is correct!\n");
    	} else {
    		printf("Failed! Number of treasure cards is incorrect!\n");
            printf("There are %d treasures and should be %d\n", drawntreasureAfter, drawntreasureBefore+2 );
    	}
    }
    player++;

    }
	return 0;
}
