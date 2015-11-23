Victor Hernandez
CS_362_F15
Assignment 5 - Part 1 - BugsInTeammates.c

//////////////////////////////////////////////////////////////////////////////////////////

Teammate 1 - Daniel Bonnin

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
drawCard()

Bug Description - 
Deck not decremented after draw

Severity - 
Minor

Steps to Reproduce - 
Initialize a gamestate where a players deckCount and discardCount are both set to 0, then call drawCard() on this state.

Expected Behavior - 
The postDeckCount should be equal to the preDiscardCount - 1 after the function has been called, although in this instance this combination of deckCount and discardCount should be impossible.

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
smithyCard()

Bug Description - 
Incorrect number of cards drawn

Severity - 
Minor

Steps to Reproduce - 
Initialize a gamestate where hand[player][4] = smithy, then call the smithyCard() function

Expected Behavior - 
The player's handCount should be 7 after the Smithy card is played

Actual Behavior - 
The player's handCount is 5 after the Smithy card is played

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
adventurerCard()

Bug Description - 
Adventurer card is not discarded after it has been played

Severity - 
Major

Steps to Reproduce - 
Initialize a gamestate where hand[player][4] = adventurer, then call the adventurerCard() function

Expected Behavior - 
The player's hand should no longer contain the Adventurer card after it has been played

Actual Behavior - 
The player's hand contains the Adventurer card after it has been played

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
villageCard()

Bug Description - 
Incorrect number of actions added

Severity - 
Minor

Steps to Reproduce - 
Initialize a gamestate where hand[player][4] = village, then call the villageCard() function

Expected Behavior - 
The player's numActions should be 3 after the Village card is played

Actual Behavior - 
The player's numActions is 2 after the Village card is played

//////////////////////////////////////////////////////////////////////////////////////////

Teammate 2 - Billy Kerns

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
drawCard()

Bug Description - 
Deck not decremented after draw

Severity - 
Minor

Steps to Reproduce - 
Initialize a gamestate where a players deckCount and discardCount are both set to 0, then call drawCard() on this state.

Expected Behavior - 
The postDeckCount should be equal to the preDiscardCount - 1 after the function has been called, although in this instance this combination of deckCount and discardCount should be impossible.

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
smithyCard()

Bug Description - 
Smithy not in played pile

Severity - 
Minor

Steps to Reproduce - 
Initialize a gamestate where hand[player][4] = smithy, then call the smithyCard() function

Expected Behavior - 
The playedCards[] should contain 'smithy', indicating that the Smithy card is in the played pile

Actual Behavior - 
The playedCards[] does not contain 'smithy' after the card has been played

File -
dominion.c

Date Seen - 
11/19/2015

Function Name - 
adventureCard()

Bug Description - 
Adventurer card is not discarded after it has been played

Severity - 
Major

Steps to Reproduce - 
Initialize a gamestate where hand[player][4] = adventurer, then call the adventureCard() function

Expected Behavior - 
The player's hand should no longer contain the Adventurer card after it has been played

Actual Behavior - 
The player's hand contains the Adventurer card after it has been played
