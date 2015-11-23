//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      October 25, 2015
// Project:   Assignment 3 - Unit Tests
// Filename:  unittest3.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the updateCoins() function
//
// updateCoins():
// Tallies the coin value of the current player's treasuer cards along
// with optional bonus and writes it to state->coins, a var that is not
// player-speciric.
//
// player    - current player
// state     - holds the game state
// bonus     - amount to add to coins
//
// Always returns 0.
//
int testUpdateCoins(int player, struct gameState *state, int bonus)
{
    int coinCount = 0;            // tracks total coins
    int i;                        // loop iterator
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run updateCoins()
    //
    updateCoins(player, state, bonus);

    // Report the current player's coins
    //
    printf("Player %d coins:\n", player);
    for (i = 0; i < state->handCount[player]; i++)
    {
        if (state->hand[player][i] == copper)
        {
            coinCount += 1;
            printf("\tOne copper (1)\n");
        }
        else if (state->hand[player][i] == silver)
        {
            coinCount += 2;
            printf("\tOne silver (2)\n");
        }
        else if (state->hand[player][i] == gold)
        {
            coinCount += 3;
            printf("\tOne gold (3)\n");
        }       
    }   
    if(coinCount == 0) printf("\tNone...\n");
    printf("Plus optional bonus: %d\n", bonus);
    coinCount += bonus;

    // Note that state->coins is not tied to any player. It is a temporary
    // placeholder for coin information. Original values in origState are
    // not used in determining new state->coins values.
    //
    if(state->coins == coinCount)
    {
        printf("updateCoins: PASS game state holds correct number of coins (%d)\n", state->coins);
    }
    else
    {
        printf("updateCoins: FAIL game state holds incorrect number of coins (%d)\n", state->coins);
    }

    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");
    
    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;      // default number of players
    int randomSeed = 100;    // random seed for the game
    int player;              // current player
    int bonus;               // optional bonus coins
    struct gameState *state; // holds the new state of the game
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Player 0, bonus 5
    //
    printf(">>> TESTING: updateCoins(), player 0's coins, 5 bonus...\n");
    player = 0;
    bonus = 5;
    testUpdateCoins(player, state, bonus);

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Player 1, bonus 3
    //
    printf(">>> TESTING: updateCoins(), player 1's coins, 3 bonus...\n");
    player = 1;
    bonus = 8;
    testUpdateCoins(player, state, bonus);

    return 0;
}



