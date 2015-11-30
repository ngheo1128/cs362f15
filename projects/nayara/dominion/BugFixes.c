/* Ashok Nayar
* cs362, Fall 2015
* Assignment 5: Bug Fix documentation
*/

** Fixes for adventurer card 
The bug introduced was that copper cards were ignored by the function. The following change was made to this line of code:
(cardDrawn == silver || cardDrawn == gold)

to 

(cardDrawn == silver || cardDrawn == gold cardDrawn == copper)

** Fixes for village card
The bug introduced multiplied the action count by 2 instead of adding 2. This line of code was changed from:

    state->numActions = state->numActions * 2;

to 
    state->numActions = state->numActions + 2

** Fixes for council card
The bug introduced gave an extra card to the current player for every other player in the game, rather than dealing out an extra card to each other player. The following line of code was changed from

        if ( i == player )
        {
            drawCard(i, state);
        }

to 

        if ( i != player )
        {
            drawCard(i, state);
        }

** Fixes for feast
The bug introduced to this function did not add any coins to the coin count. The line of code was changed from

    updateCoins(player , state, 0);

to 
    updateCoins(player , state, 5);

