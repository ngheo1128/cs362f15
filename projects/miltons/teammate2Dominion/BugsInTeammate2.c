/*

Teammate 2 name: Andrew Shen

issues:

UNIT TESTS:

unittest4.c (gainCard() function)
    test fails, returns non-zero value
    (note: this fails on my own code too, might be faulty test code)


CARD TESTS:

compiler warnings:

unittests, cardtests, and randomtests give compiler warnings for
    unused variables in cardEffect function of dominion.c:
    z, cardDrawn, drawntreasure, x

cardtest2: (Adventurer)
    /bin/sh: line 1: 19124 Segmentation fault (core dumped)
        cardtest2 >> unittestresults.out
        make: *** [unittestresults.out] Error 139


RANDOM TESTS:

randomtestcard:  PASS for all 2000 random tests

randomtestadventurer: FAIL
/bin/sh: line 1: 8676 Segmentation fault (core dumped)
    randomtestadventurer >> randomtestadventurer.out
    make: *** [randomtestadventurer.out] Error 139

*/