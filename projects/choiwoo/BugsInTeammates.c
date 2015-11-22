
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


