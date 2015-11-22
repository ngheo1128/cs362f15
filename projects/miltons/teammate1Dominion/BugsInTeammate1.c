/*

Teammate 1 name: Ashok Nayar

issues:

UNIT TESTS:




CARD TESTS:

compiler warnings: cardtest1 and cardtest2 give compiler warnings for
    unused variables in cardEffect function of dominion.c:
    z, cardDrawn, drawntreasure, temphand, x

TEST NAME    CARD NAME     RESULT
cardtest1    Smithy        PASS (did not crash)
cardtest2:   Adventurer    FAIL
    /bin/sh: line 1: 31639 Segmentation fault (core dumped)
        cardtest2 >> unittestresults.out
        make: *** [unittestresults.out] Error 139
cardtest3


RANDOM TESTS:

randomtestcard:  PASS for all 2000 random tests

randomtestadventurer: FAIL
    /bin/sh: line 1: 11054 Segmentation fault (core dumped)
        randomtestadventurer >> randomtestadventurer.out
        make: *** [randomtestadventurer.out] Error 139


*/