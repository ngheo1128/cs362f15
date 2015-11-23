
gameOver()
    gameOver() never checks the index of treasure_map (25) to check if it is at 0.
    This means sometimes when a game is over, it might not register.
    Before:
    for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
        {
          j++;
        }
    }
    After:
    for (i = 0; i < 26; i++)
    {
      if (state->supplyCount[i] == 0)
        {
          j++;
        }
    }

ScoreFor()
    scoreFor() contains a bug. The gardens card should return the # of cards in the players deck /10.
    Instead it only counts the number of curses and / 10. It passes 0 (only one card to search for)
    to fullDeckCount() wgere it needs to check if it is between 0-25.

    Before:
    if (state->deck[player][i] == gardens) {
        score = score + ( fullDeckCount(player, 0, state) / 10 );
    }

    After:
    I rewrote how the function handles fullDeckCount. It is very inneficient but I am unsure of how
    a real world end user might be using fullDeckCount and do not want to break their theorectical code.
      if (state->hand[player][i] == gardens) {
        for(x = 0; x < 26; ++x) {
            tempScore += fullDeckCount(player, x, state);
        }
        score = score + ( tempScore / 10 );
      }

Adventurer Card:
    Fixed error where 4 treasure cards were placed in hand
    Before: while(drawntreasure <= 2); After while(drawntreasure < 2)

Smithy Card:
    Fixed an error where it added 4 cards instead of 3.
    Before:for (i = 0; i <= 3; i++); After for (i = 0; i < 3; i++)

    Testing smithy card showed 1 major bug with the dsicardCard function. That funciton does not place
    discarded cards in the discard pile or increment the discardCount.

discardCard()
    Does not actually place the discarded card into the discard pile neither does it increment the pile count.
    Added the following lines to the function:
    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos];
    state->discardCount[currentPlayer]++
