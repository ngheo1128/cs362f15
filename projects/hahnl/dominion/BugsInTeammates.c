/****************************************************************************
Author: Larissa Hahn
BugsinTeammates.c

Group members are Solomon Huynh and Dustin Chase.
*****************************************************************************

****************************************
BUG REPORT for Solomon Huynh:
****************************************

-- FAIL: Too FEW cards drawn.
---- Target: 3 cards. Actual: 2 cards.
^^^^^^^ Test Number 999 out of 1000 ^^^^^^^
-- FAIL: Too FEW cards drawn.
---- Target: 3 cards. Actual: 2 cards.
^^^^^^^ Test Number 1000 out of 1000 ^^^^^^^
****************************************
  ---- TEST FAILURE STATUS REPORT ----
  ----        Smithy Card         ----
****************************************
Total Test Failures:      1000/1000
Discard Card Errors:      31
Draw Card Errors:         1000
Played Card Errors:       0
****************************************
For Smithy Card:
2 bugs found with Discarding and Drawing.
Draw Card test always draws 3 instead of 2 cards.
Smithy Card sometimes does not get discarded.
cardTest1.c - Bug found with incorrect handCount after playing SmithyCard


-- FAIL: Adventurer card not discarded.
-- FAIL: Too FEW cards drawn.
---- Target: 2 cards. Actual: -1 cards.
-- FAIL: Too FEW treasure cards.
---- Target: 2 cards. Actual: 0 cards.
^^^^^^^ Test Number 1 out of 2 ^^^^^^^
-- FAIL: Adventurer card not discarded.
-- FAIL: Too FEW cards drawn.
---- Target: 2 cards. Actual: -1 cards.
-- FAIL: Too FEW treasure cards.
---- Target: 2 cards. Actual: 0 cards.
^^^^^^^ Test Number 2 out of 2 ^^^^^^^
****************************************
  ---- TEST FAILURE STATUS REPORT ----
  ----       Adventurer Card      ----
****************************************
Total Test Failures:      2/2
Discard Card Errors:      2
Draw Card Errors:         2
Treasure Card Errors:     2
****************************************
For Adventurer Card:
3 Bugs Found: Discard, Draw, and Treasure Count
These three bugs are: Adventurer Card not discarded. Too few cards drawn, it says -1.
Also it says 0 Treasure Cards instead of the Two treasure cards needed.
cardTest2.c - Bug found with incorrect handCount after playing adventurerCard

Other cards:
cardTest3.c - Bugs found with incorrect handCount and discardCount after playing village card
cardTest4.c - Bugs found with incorrect handCount and discardCount after playing Great Hall card



****************************************
BUG REPORT for Dustin Chase:
****************************************

-- FAIL: Too FEW cards drawn.
---- Target: 3 cards. Actual: 2 cards.
^^^^^^^ Test Number 264 out of 1000 ^^^^^^^
-- FAIL: Too FEW cards drawn.
---- Target: 3 cards. Actual: 2 cards.
^^^^^^^ Test Number 265 out of 1000 ^^^^^^^
-- FAIL: Smithy card not discarded.
-- FAIL: Too FEW cards drawn.
---- Target: 3 cards. Actual: 2 cards.
^^^^^^^ Test Number 266 out of 1000 ^^^^^^^
****************************************
  ---- TEST FAILURE STATUS REPORT ----
  ----        Smithy Card         ----
****************************************
Total Test Failures:      1000/1000
Discard Card Errors:      34
Draw Card Errors:         1000
Played Card Errors:       0
****************************************
For Smithy Card:
2 bugs found with Discarding and Drawing.
Draw Card test always draws 3 instead of 2 cards.
Smithy Card sometimes does not get discarded.
cardTest1.c - Bug found with incorrect handCount after playing SmithyCard


-- FAIL: Adventurer card not discarded.
-- FAIL: Too FEW cards drawn.
---- Target: 2 cards. Actual: -1 cards.
-- FAIL: Too FEW treasure cards.
---- Target: 2 cards. Actual: 0 cards.
^^^^^^^ Test Number 1 out of 2 ^^^^^^^
-- FAIL: Adventurer card not discarded.
-- FAIL: Too FEW cards drawn.
---- Target: 2 cards. Actual: -1 cards.
-- FAIL: Too FEW treasure cards.
---- Target: 2 cards. Actual: 0 cards.
^^^^^^^ Test Number 2 out of 2 ^^^^^^^
****************************************
  ---- TEST FAILURE STATUS REPORT ----
  ----       Adventurer Card      ----
****************************************
Total Test Failures:      2/2
Discard Card Errors:      2
Draw Card Errors:         2
Treasure Card Errors:     2
****************************************
For Adventurer Card:
3 Bugs Found: Discard, Draw, and Treasure Count
These three bugs are: Adventurer Card not discarded. Too few cards drawn, it says -1.
Also it says 0 Treasure Cards instead of the Two treasure cards needed.
cardTest2.c - Bug found with incorrect handCount after playing adventurerCard

Other cards:
cardTest3.c - Bugs found with incorrect handCount and discardCount after playing village card
cardTest4.c - Bugs found with incorrect handCount and discardCount after playing Great Hall card

****************************************************************************/
