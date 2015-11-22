/* Kathryn McDonald
 * Filename: BugsInTeammates.c
 * Description: Bug report for teammate1Dominion weckwerth's dominion.c file and picotte's dominion.c file
 */

/* Weckwerth */
cardtest1 results:
Pass: Reworked smithy function
Fail: Hand count (4)
Pass: Number of actions
Pass: Coins
Pass: Number of buys

cardtest2 results:
Pass: Reworked adventurer function
Fail: Hand count (5)

cardtest3 results:

cardtest4 results:

unittest1 results:

unittest2 results:

unittest3 results:

unittest4 results:

randomtestadventurer results:
Fail: handCount (numPlayers: 3, tested player: 0)
An unknown error sometimes causes a segmentation fault in the random tester.

randomtestcard results:
Fail: numActions (numPlayers: 2-3, tested player: 0)

/* Picotte */
cardtest1 results:
Fail: Hand count (8)
Pass: Number of actions
Pass: Coins
Pass: Number of buys

cardtest2 results:
All tests passed!
Pass: Hand count
Pass: Drawn card is Treasure card
Pass: Drawn card is Treasure card

cardtest3 results:
Pass: +1 card
Fail: +2 actions

cardtest4 results:
All tests passed!
Pass: Hand count

unittest1 results:
All tests passed!
Testing players 0-1 with 1-5 cards and 0-10 bonus

unittest2 results:
All tests passed!
Pass: Player 0 deckCount unchanged
Pass: Player 1 deckCount unchanged
Pass: whoseTurn unchanged
Pass: Phase unchanged
Pass: Coins unchanged
Pass: numBuys unchanged
Pass: Player 0 handCount unchanged
Pass: Player 1 handCount unchanged

unittest3 results:
All tests passed!
Pass: Testing regular outcome
Pass: Not enough buys
Pass: Not enough cards
Pass: Not enough coins

unittest4 results:
All tests passed!
Pass: Success test in discard pile
Pass: Success test in deck
Pass: Success test in hand
Pass: Test not enough cards
Pass: Test card not in game

randomtestadventurer results:
An unknown error sometimes causes a segmentation fault in the random tester.

randomtestcard results:
Testing 2-3 players, with players 0 and 1 under test
Fail: numActions
