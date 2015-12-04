/*
*******************************************************************************
Team member: Tara Massey
Date tested: 2015/11/19
Tested: Smithy card, Adventurer card, Village card, Council Room card,
  getCost(), isGameOver(), fullDeckCount(), and scoreFor().
*******************************************************************************

Title: Smithy card effect draws too many cards

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the smithy card function to compare values of the
player's hand count, deck count, discarded card count, and played card count
from before and after playing the smithy card. The hand count and deck counts
are not as expected. 

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(smithy, 0, 0, 0, &game, 1, 0)
4. Compare hand count and deck count with expected values
5. Examine actual values of hand count and deck count for player 0

Expected Results
----------------
game.handCount[0] = 5
game.deckCount[0] = 2

Actual Results
--------------
game.handCount[0] = 6
game.deckCount[0] = 1


===============================================================================

Title: Adventurer card effect does not discard played card

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the adventurer card function to compare values of
the player's hand count, deck count, discarded card count, and played card
count from before and after playing the adventurer card. The hand count and
played card counts are not as expected (1 more hand count and 1 less played
card than expected).

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(adventurer, 0, 0, 0, &game, 1, 0)
4. Compare hand count and played card count with expected values
5. Examine actual values of hand count and played card count for player 0

Expected Results
----------------
game.handCount[0] = 4
game.playedCardCount = 1

Actual Results
--------------
game.handCount[0] = 5
game.playedCardCount = 0


===============================================================================

Title: scoreFor() does not correctly count score for garden cards

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the scoreFor() function to calculate the score for
players based on some generated sets of decks. Compared expected score with
actual score for the following scenarios: empty deck, hand, and discard pile;
15 kingdom and 3 garden cards; 15 treasure and 3 garden cards; 9 estate, 3
duchy, 3 province, and 3 curse cards.

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player with 15 kingdom cards
    and 3 garden cards (or 15 treasure cards and 3 garden cards)
3. Call the scoreFor() function
4. Compare actual score with expected score
5. Examine actual score

Expected Results
----------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 3
15 treasure cards and 3 garden cards (total of 18 cards): score = 3

Actual Results
--------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 0
15 treasure cards and 3 garden cards (total of 18 cards): score = 0


*******************************************************************************
Team member: Connor Peavey
Date tested: 2015/11/19
Tested: Smithy card, Adventurer card, Village card, Council Room card,
  getCost(), isGameOver(), fullDeckCount(), and scoreFor().
*******************************************************************************

Title: scoreFor() does not correctly count score for garden cards

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the scoreFor() function to calculate the score for
players based on some generated sets of decks. Compared expected score with
actual score for the following scenarios: empty deck, hand, and discard pile;
15 kingdom and 3 garden cards; 15 treasure and 3 garden cards; 9 estate, 3
duchy, 3 province, and 3 curse cards.

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player with 15 kingdom cards
    and 3 garden cards (or 15 treasure cards and 3 garden cards)
3. Call the scoreFor() function
4. Compare actual score with expected score
5. Examine actual score


Expected Results
----------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 3
15 treasure cards and 3 garden cards (total of 18 cards): score = 3

Actual Results
--------------
15 kingdom cards and 3 garden cards (total of 18 cards): score = 0
15 treasure cards and 3 garden cards (total of 18 cards): score = 0

===============================================================================

Title: Smithy card is not played/discarded correctly

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu


Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the smithy card function to compare values of the
player's hand count, deck count, discarded card count, and played card count
from before and after playing the smithy card. The played card count is not as
expected.

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(smithy, 0, 0, 0, &game, 1, 0)
4. Compare played card count with expected value
5. Examine actual played card count

Expected Results
----------------
game.playedCardCount = 1

Actual Results
--------------
game.playedCardCount = 0


===============================================================================

Title: Adventurer card effect does not discard played card

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the adventurer card function to compare values of
the player's hand count, deck count, discarded card count, and played card
count from before and after playing the adventurer card. The hand count and
played card counts are not as expected (1 more hand count and 1 less played
card than expected).

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(adventurer, 0, 0, 0, &game, 1, 0)
4. Compare hand count and played card count with expected values
5. Examine actual values of hand count and played card count for player 0

Expected Results
----------------
game.handCount[0] = 4
game.playedCardCount = 1

Actual Results
--------------
game.handCount[0] = 5
game.playedCardCount = 0


===============================================================================

Title: Village card effect draws an extra card

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the village card function to compare values of the
player's hand count, deck count, discarded card count, and played card count
from before and after playing the village card. The hand count and deck counts
are not as expected (1 more hand count and 1 less deck count than expected).
This bug may be confused with the effect of the discarding played card bug (see
next bug).

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(village, 0, 0, 0, &game, 1, 0)
4. Compare hand count and deck count with expected values
5. Examine actual values of hand count and deck count for player 0

Expected Results
----------------
game.handCount[0] = 3
game.deckCount[0] = 4

Actual Results
--------------
game.handCount[0] = 4
game.deckCount[0] = 3


===============================================================================

Title: Village card effect does not discard played card correctly

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the village card function to compare values of the
player's hand count, deck count, discarded card count, and played card count
from before and after playing the village card. The played card count is not as
expected (1 less played card than expected). This bug may be confused with the
effect of the extra card drawn bug (see previous bug).

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(village, 0, 0, 0, &game, 1, 0)
4. Compare played card count with expected value
5. Examine actual value of played card count

Expected Results
----------------
game.playedCardCount = 1

Actual Results
--------------
game.playedCardCount = 0

===============================================================================

Title: Council room card effect does not discard played card correctly

Class: Bug, major

Date: 2015/11/19
Reported By: Sharon Kuo
Email: kuos@oregonstate.edu

Product: Dominion                 Version: Assignment 2
Platform: Linux                   Version: FLIP and Ubuntu 12.04 x64

Is it reproducible: Yes

Description
===========
Used a unit test written for the council room card function to compare values
of the player's hand count, deck count, discarded card count, and played card
count from before and after playing the council room card. The played card
count is not as expected (1 less played card than expected), but the hand count
is as expected, indicating that this is an issue with how the card is
discarded (trash flag set).

Steps to Produce/Reproduce
--------------------------
1. Make dominion files
2. Initialize 2-player game and set cards for each player
3. Call the cardEffect() function with the following for player 0:
    cardEffect(council_room, 0, 0, 0, &game, 1, 0)
4. Compare played card count with expected value
5. Examine actual value of played card count

Expected Results
----------------
game.playedCardCount = 1

Actual Results
--------------
game.playedCardCount = 0

*/