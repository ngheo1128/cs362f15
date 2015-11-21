Dustin Dinh
CS 362 Assignment 5

***********************************  isGameOver  ***********************************
1) 	Changed line 407 Now counts sea hag and treasure map depletion correctly. 
    for (i = 0; i < 25; i++)

    To:

    for (i = 0; i < 27; i++)

***********************************  scoreFor  ***********************************

1)  Changed line 460 Now correctly iterates over the correct number of discarded cards to count score.
  
    for (i = 0; i < state->discardCount[player]; i++)

    To:

    for (i = 0; i < state->deckCount[player]; i++)

***********************************  discardCard  *********************************** 

1)   Changed line 1239-1240 Now discards into discard pile rather than played. 

    state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
    state->playedCardCount++;

    To:

    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos]; 
    state->discardCount[currentPlayer] += 1;

***********************************  adventurerCard ***********************************
1)  Added to line 717 Now properly discards the played card

    discardCard(handPos, currentPlayer, state, 0);

2) Changed line 712  Now does not discard an extra card

  while(z>=0)
  
  To:

  while(z > 0)

***********************************  smithyCard ***********************************
1) Changed line 727 Now only discards 1 card instead of 3

  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  
      
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
  }

  To:

  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

***********************************  mineCard ***********************************

1)  Changed line 738 Inputs were swapped, so illegal swaps were done.

     int choice2, int choice1)

    To:

     int choice1, int choice2)

2) Changed line 751 Now checks to make sure card being swapped are treasure cards instead of just valid cards

  if (choice2 > treasure_map || choice2 < curse)
  
  To:

  if (choice2 > gold || choice2 < copper)

3)  Changed line 758 Now does not swap coins that cost 3 more than original

    if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
    
    To:

    if ( (getCost(state->hand[currentPlayer][choice1]) + 3) < getCost(choice2) )

***********************************  minionCard ***********************************

1)  Changed line 822 Other players were having therr cards trashed rather than discarded

    discardCard(handPos, i, state, 1);

    To:

    discardCard(handPos, i, state, 0);