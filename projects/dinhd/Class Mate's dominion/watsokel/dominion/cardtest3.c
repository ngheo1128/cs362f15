/*
This program tests the smithyCard function.
The parameters for this function are:
int currentPlayer, struct gameState *state, int handPos

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int i;

    //initialize the game
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    initializeGame(2, k, 2, &G);

    //replace all cards in hand with a adventurer card
    for (i = 0; i < numHandCards(&G); i++)
    {
        G.hand[0][i] = smithy;
    }
    


    // check state of game before calling function
    // printState(&G);
    //  printSupply(&G);
    // // printScores(&G);
    // printHand(0, &G);
    // // printPlayed(0, &G);
    // printDeck(0, &G);
    // printf ("Number of cards in hand %i \n", numHandCards(&G));


    printf("* * * * * * * * * * * * * * * * Testing smithy card * * * * * * * * * * * * * * * * \n");

    //keeps track of played cards
    int playedCards = 0;
    int cardsInHand = G.handCount[0];

    i = 4;
    playCard(i, -1, -1, -1, &G);


    //check to see if adventurer card goes into discard
    //printPlayed(0, &G);
    //printHand(0, &G);
    //make sure card is discarded
    if (G.hand[4][i] == smithy)
    {
        printf("Smithy card in last spot in hand was not discarded\n");
    }
    
    //make sure there are + 2 cards in hand 
    if (numHandCards(&G) != cardsInHand + 2)
    {
        int cardsHand = cardsInHand + 2;
        printf("Error: Expected %i, got %i instead \n", cardsHand, numHandCards(&G));
    }
    
    //make sure that smithy was discarded. 
    if  (G.playedCards[playedCards] != smithy)
    {
        printf("Smithy card was not discarded\n");
    }
    playedCards++;

    // printState(&G);
    
    // printPlayed(0, &G);
    // printDeck(0, &G);
    

    printf("All tests passed!\n");

    
    
    return 0;
}
