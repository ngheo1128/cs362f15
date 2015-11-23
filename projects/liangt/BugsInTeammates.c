/*

Bugs in nguyekhiDominion:

shuffle(): PASSED
isGameOver(): PASSED
discardCard(): FAILED
	Test: discarded card in discarded pile [failed]
		unittest3: unittest3.c:47: main: Assertion `G.discard[1][0] == gardens' failed.
scoreFor(): FAILED
	Test: Starting deck + hand has score of 3 from estate cards [failed]
		unittest4: unittest4.c:26: main: Assertion `scoreFor(0, &G) == 3' failed.
	Test: If discardCount == deckCount and all cards are duchy [failed]
		unittest4: unittest4.c:56: main: Assertion `scoreFor(0, &G) == 3*5*5' failed.
	Test: If discardCount == deckCount and all cards are province [failed]
		unittest4: unittest4.c:67: main: Assertion `scoreFor(0, &G) == 3*5*8' failed.

CEsmithy(): FAILED
	Test: Net increase of 2 cards in player's hand [failed]
		cardtest1: cardtest1.c:36: main: Assertion `G.handCount[0] == 5+3-1' failed.
	Test: Smithy card in discard pile [failed]
		cardtest1: cardtest1.c:43: main: Assertion `G.discard[0][0] == smithy' failed.

CEadventurer(): FAILED
	Test: all coppers in deck [failed]
		cardtest2: cardtest2.c:44: main: Assertion `G.hand[0][G.handCount[0]-1] == copper && G.hand[0][G.handCount[0]-2] == copper' failed.
	Test: all silvers in deck [failed]
		cardtest2: cardtest2.c:60: main: Assertion `G.hand[0][G.handCount[0]-1] == silver && G.hand[0][G.handCount[0]-2] == silver' failed.
	Test: all golds in deck [failed]
		cardtest2: cardtest2.c:76: main: Assertion `G.hand[0][G.handCount[0]-1] == gold && G.hand[0][G.handCount[0]-2] == gold' failed.
	Test: only two treasure cards are drawn

	Random testing CEadventurer():
	Test Runs: 10000
	Total Sub-tests: 40000
	Sub-tests passed: 3386
		handCount tests passed: 1182
		hand tests passed: 272
		discard tests passed: 769
		nonhandCount tests passed: 1163
	Sub-tests failed: 36614
	Coppers drawn: 1157
	Silvers drawn: 1147
	Golds drawn: 1170

Random testing village via cardEffect():
Test Runs: 10000
Total Sub-tests: 40000
Sub-tests passed: 20563
	handCount tests passed: 10000
	actions tests passed: 10000
	discard tests passed: 563
	nonhandCount tests passed: 0
Sub-tests failed: 19437

------------------------------------------------------------------------

Bugs in taylijameDominion:

shuffle(): PASSED
isGameOver(): PASSED
discardCard(): FAILED
	Test: discarded card in discarded pile [failed]
		unittest3: unittest3.c:47: main: Assertion `G.discard[1][0] == gardens' failed.
scoreFor(): FAILED
	Test: Starting deck + hand has score of 3 from estate cards [failed]
		unittest4: unittest4.c:26: main: Assertion `scoreFor(0, &G) == 3' failed.
	Test: If discardCount == deckCount and all cards are duchy [failed]
		unittest4: unittest4.c:56: main: Assertion `scoreFor(0, &G) == 3*5*5' failed.
	Test: If discardCount == deckCount and all cards are province [failed]
		unittest4: unittest4.c:67: main: Assertion `scoreFor(0, &G) == 3*5*8' failed.

smithy_ref(): FAILED
	Test: Net increase of 2 cards in player's hand [failed]
		cardtest1: cardtest1.c:36: main: Assertion `G.handCount[0] == 5+3-1' failed.
	Test: Smithy card in discard pile [failed]
		cardtest1: cardtest1.c:43: main: Assertion `G.discard[0][0] == smithy' failed.

Random testing adventurer_ref():
Test Runs: 10000
Total Sub-tests: 40000
Sub-tests passed: 10567
	handCount tests passed: 1
	hand tests passed: 10000
	discard tests passed: 565
	nonhandCount tests passed: 1
Sub-tests failed: 29433
Coppers drawn: 6357
Silvers drawn: 6723
Golds drawn: 6920

Random testing buggyVillage():
Test Runs: 10000
Total Sub-tests: 40000
Sub-tests passed: 20557
	handCount tests passed: 10000
	actions tests passed: 10000
	discard tests passed: 557
	nonhandCount tests passed: 0
Sub-tests failed: 19443

*/