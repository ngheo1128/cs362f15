Author: Allan Chan
ONID: chanal
Class: CS362
Filename: BugFixes.c
Description: Bug fixes for bugs reported by teammates on my dominion.c 
The bugs reported on my code can be found in the bottom half of this file
-------------------------------------------------------------------------

Fix 1: Both my teammates found a bug in adventurer
    int adventurerCard (int drawntreasure, struct gameState* state, int currentPlayer, int cardDrawn, int temphand[], int z) {
          while(drawntreasure<=2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }...

    The bug I originally introduced was drawnteasure<=2, I have corrected the bug by reverting it back to drawntreasure<2 for the while loop
    to allow the proper amount of treasure cards to be drawn, which should be 2 and not 3.

    Another bug within adventurer was that adventurer does not get discarded after play. I fixed this by adding the discardCard function
    at the end of the adventurer code.
        discardCard(handPos, currentPlayer, state, 0);

    My function prototype for adventurerCard has changed to include int handPos as a parameter for calling discardCard inside the function
        int adventurerCard (int drawntreasure, struct gameState* state, int currentPlayer, int cardDrawn, int temphand[], int z)...


Fix 2: Both my teammates found a bug in smithy
    int smithyCard(int currentPlayer, struct gameState* state, int handPos) {
      //+3 Cards
      int i;
      for (i = 0; i <= 3; i++)
    {
      drawCard(currentPlayer, state);
    }...

    The bug I originally introduced was for(i = 0, i <= 3, i++) inside the loop for drawcard. I have corrected the bug and
    made i<3 to allow the correct number of cards to be drawn to be 3 instead of 4. 

Fix 3: Teammates did not catch this bug due to their cardtests not testing council room
    int councilRoomCard (int currentPlayer, struct gameState* state, int handPos){
          //+4 Cards
          int i;
          for (i = 0; i <= 4; i++)
        {
          drawCard(currentPlayer, state);
        }...

    I fixed the bug where i<=4 should be i<4 so that the correct number of cards drawn should be 4 instead of 5. 

Fix 4: Teammates did not catch this bug due to their cardtests not testing salvager
    int salvagerCard(struct gameState* state, int choice1, int currentPlayer, int handPos) {
      //+1 buy
      state->numActions++;
    ...}

    I fixed the bug where state->numActions++ should be state->numBuys++ instead where salvager
    properly increments numBuys instead of numActions for the card effect. 


Fix 5: Fixed a bug in isGameOver
  int isGameOver(struct gameState *state) {

    ...
    for (i = 0; i < 26; i++)
      {
        if (state->supplyCount[i] == 0)
    { ...

  Since my teammate reported that the index of treasure_map(enum of 26) wasn't checked
  for the supplyCount, I changed the for loop from i<25 to i<26 to check for treasure_map












Below are the bugs reported to me by my teammates
---------------------------------------------------------------------------------------------
unittest1:
    gameOver() never checks the index of treasure_map to check if it is at 0.
    This means sometimes when a game is over, it might not register.

unittest2:
    discardCard() no bugs found based on written functionality within this test suite.

unittest3:
    scoreFor() contains a bug. The gardens card causes errors due to passing
    0 to numHandsCards for the card argument and therefore not actually
    counting all cards.s

unittest4:
    Since getWinners() uses scoreFor(), it would technically have the same issue listed above.
    My tests navigated around this to test the rest of the funnctionality and no
    bugs were found.

cardtest1:
    Testing the Adventure card showed 3 bugs. It will place up to 3
    treasure cards in hand since the while loop is <= instead of <. The funciton will also
    return hand count of -1 if no adventure cards are found. This last one might be an error
    or just undefined behavior. In addition, the card does not discard itself after being played

    "Caught introduced bug where adventurer may add more than max 2 treasures (3)"

cardtest2:
    Testing smithy card showed 1 major bug with the dsicardCard funciton. That funciton does not place
    discarded cards in the discard pile or increment the discardCount.

    "Caught introduced bug where drawCard() gets called 4 times."

cardtest3:
    tested the Village card. No bugs were found.

------------------------------------------------------------------------------------------

For card tests, I tested Smithy, Adventurer, Steward and Village. 
For unit tests, I tested getCost(), isGameOver(), gainCard() and updateCoins().


Interestingly, teammates Joshua and Allan both had the same bugs.


cardtest1.c
***************
Smithy Card Test:
    Expected card count: 8
    Actual card count: 9
Smithy Card Test is now over

Smithy: Smithy gave an extra card.
for (i = 0; i <= 3; i++)
looks like it should be i <= 3 makes the card return 4 cards instead of 3.

**Joshua: although my test didn't catch this, 
  discardCard(handPos, currentPlayer, state, 1);

the trash flag for discardCard is set to 1, it should be 0. 





cardtest2.c
***************
Adventurer Card Test:
    Expected card count: 8
    Actual card count: 10
Adventurer Card Test is now over


Adventurer: Adventurer had 2 extra cards. 

while(drawntreasure <= 2)

The condition for the while loop should be just < 2, not <= 2. By being <=2, while loop runs 1 extra, returning 1 more treasure card than expected. 

The other card was the adventurer card itself as the code given to us did not discard the adventurer card. 



Those were the two bugs I found via my unit tests. All other unit tests passed without bugs.
