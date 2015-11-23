/******************************
Susan Lee
CS 362_400_Fall15
Assignment5 – BugFixes.c
*******************************/


/*********************
NOTES
**********************/
The majority of bugs my teammates found were limited to the ones that 
were introduced intentionally to my code, or those impacted by the 
discardCard() method.  

In running my initial unit and random tests on my own code, I had already
discovered that there was a bug in the discardCard() method.  After fixing
the bugs found by my teammates, there were still some failures from other
bugs that I had to correct.  Using my analysis from the unit and random 
tests, I was able to correct those bugs.  Below is a summary of the bugs
I fixed.

In implementing my bug fixes, I found a number of game state members that 
I had not previously initialized in my random tests.  These were causing
some seg fault issues, which I have since corrected.  All tests are running
as expected for large inputs.

/*********************
SMITHY CARD
**********************/
- fixed i <= 3 in for loop to i<3. 
- fixed the discardCard() method to actually discard the played cards
     int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
     {
       //if card is not trashed, added to Played pile 
       if (trashFlag < 1)
       {
         //add card to played pile
         state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
         state->playedCardCount++;
         // SL BUG FIX 11.20.15: add card to discard pile - Code inspired by Erik Ratclier
         state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][handPos];
       }
       ...
     }

/*********************
ADVENTURER CARD
**********************/
- Fixed temp hand index variable z from z= z++ to z++.  This allows the temp hand
to increment and places all cards in the temp hand in the discard pile.
- Added call to discardCard() method at the end of the Adventurer card method to 
remove and discard the adventurer card from the player's hand.  In order to do this,
I had to refactor dominion.c/.h files as well as my cardtest2.c file to allow for the
initialization of the hand position for the adventurer card and the eventual passing
of it as a parameter in the various methods.
- Added code that checks for return value of shuffle() method.  This gives us an 
exit condition for the treasure finding loop.
- Some of the bug fixes required me to rethink my the base logic in my tests.  The
tests were modeled off of buggy code, so I had to make some modifications to account
for the corrected code.

/*********************
COUNCIL ROOM
**********************/
- Fixed condition for other players to draw, so that every other player gets a chance
to draw, and the current player doesn't get the extra draw.
- Also, Erik pointed out that I had a bug in my testing function that intended to set
the last index of player 2's hand to the council room card.  The hand size was 15, and
my logic added the card if the index was at 15.  I fixed this as well, and all tests 
passed with both bug fixes.
- I had to make some changes to my random tests to consider more random cases that were
being considered.  I also found that my test allows for the assignment of 0 cards in 
the player's hand (since it is assigned randomly).  I considered not allowing this case
to occur, but decided that I still wanted to observe the behavior for this type of 
boundary case.  I felt it gave me good information that I could use to ensure that this
case wouldn't be allowed in gameplay (it would be caught), and to help strengthen my 
own tests.

/*********************
VILLAGE CARD
**********************/
-Fixed the assignment for extra actions given to the player.  The player now get 2 extra
actions instead of resetting it to 2.

/*********************
TREASURE_MAP
**********************/
-Added a call to discardCard() method if the player's hand did not have 2 treasure cards, 
therefore requiring the card simply be removed from their hand.