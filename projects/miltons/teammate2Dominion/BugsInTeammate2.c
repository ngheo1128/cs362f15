/*

Teammate 2 name: Andrew Shen

issues:

compiler warnings:
    unused variables in cardEffect function of dominion.c:
    z, cardDrawn, drawntreasure, x


UNIT TESTS:

unittest4.c (gainCard() function)
    test fails, returns non-zero value
    (note: this fails on my own code too, might be faulty test code)


CARD TESTS:

cardtest2: (Adventurer)
    /bin/sh: line 1: 19124 Segmentation fault (core dumped)
        cardtest2 >> unittestresults.out
        make: *** [unittestresults.out] Error 139


RANDOM TESTS:

randomtestcard:  FAIL for all 2000 random tests
                 (Smithy did not add expected number of cards to player's hand)

    The fault is located in function smithyEffect of dominion.c at line 687:
        for (i = 0; i < 4; i++)
    This line should be changed to read:
        for (i = 0; i < 3; i++)

    The loop should iterate only three times in order to create the desired
    game behavior by adding 3 cards to the player's hand (not 4).


randomtestadventurer: FAIL
/bin/sh: line 1: 8676 Segmentation fault (core dumped)
    randomtestadventurer >> randomtestadventurer.out
    make: *** [randomtestadventurer.out] Error 139


Note: playdom won't run either from segfault error

*/