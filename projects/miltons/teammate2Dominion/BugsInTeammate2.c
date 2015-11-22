/*

Teammate 2 name: Andrew Shen

issues:

compiler warnings:
    unused variables in cardEffect function of dominion.c:
    z, cardDrawn, drawntreasure, x


UNIT TESTS:

TEST NAME    FUNCTION NAME    RESULT    COVERAGE
unittest1    discardCard      PASS       1.88 %
unittest2    updateCoins      PASS      15.70 %
unittest3    drawCard         PASS       3.75 %
unittest4    gainCard         PASS      17.06 %


CARD TESTS:

TEST NAME    CARD NAME     RESULT                         COVERAGE
cardtest1    Smithy        PASS                            6.12 %
cardtest2    Adventurer    PASS                           20.24 %
cardtest3    Council Room  NOT REFACTORED / NOT TESTED     0.00 %
cardtest4    Mine Card     NOT REFACTORED / NOT TESTED     0.00 %


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


    The fault is located 

    while(drawntreasure<2){

      if (cardDrawn == copper || cardDrawn == silver)
        drawntreasure++;

Note: playdom won't run either from segfault error

*/