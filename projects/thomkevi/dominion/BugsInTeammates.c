Report for Teammate #1 - wardro - Robert Ward

    It appears that some if not all bugs had been corrected in the latest dominion.c file
    checked into github.  dominion.c from assignment 2 was retrieved:

      git checkout 04db92cd4e81e08d74c6af1fac75d8d99bee4f05 projects/wardro/dominion/dominion.c

    BUG #1 - dominion.c file playVillage method
      
      Test Case Failed:
        Validate number of player actions increases by 2
        
      Recommendation to Developer:
        Review assignment of state->numActions in playVillage method (line 1328)
              // add two actions
              state->numActions = 2;

      cardtest1 output: 
        cardtest1: cardtest1.c:51: main: Assertion `G.numActions == initActions + 2' failed.
        /bin/sh: line 1: 21830 Aborted                 (core dumped) cardtest1 >> unittestresults.out

    Note: cardtest1 commented out of Makefile to proceed to next tests
      
    BUG #2 - dominion.c file playSmithy method

      Test Case Failed:
        Validate the played card count is correct, increased by 1
        
      Recommendation to Developer:
        Review assignment of discard value (line 1277).  Should be 1 to discard.
            int discard = 2; // 1 is for trashing, we are moving to played cards pile though

      cardtest3 output: 
        cardtest3: cardtest3.c:45: main: Assertion `G.playedCardCount == initPlayedCount + 1' failed.
        /bin/sh: line 1: 29390 Aborted                 (core dumped) cardtest3 >> unittestresults.out

    Note: cardtest3 commented out of Makefile to proceed to next tests

    BUG #3 - dominion.c file playAdventurer method

      Test Case Failed:
        Validate the handcount is correct.  Should have increased by 2.

      cardtest4 output:
        cardtest4: cardtest4.c:46: main: Assertion `G.handCount[p] == initHandCount + 2' failed.
        /bin/sh: line 1: 15327 Aborted                 (core dumped) cardtest4 >> unittestresults.out

      randomtestadventurer output:
        randomtestadventurer: randomtestadventurer.c:64: ExecuteRandomTest: Assertion `G.handCount[p] == initHandCount + 2' failed.
        /bin/sh: line 1: 26711 Aborted                 (core dumped) randomtestadventurer >> randomtestadventurer.out

    BUG #4 - dominion.c file playCouncil_room method

      Test Case Failed:
        Validate the handcount for the other players is correct, should have increased by 1
        
      Recommendation to Developer:
        Review for loop construct to make sure all players are looped over (line 1360)
          // other players draw one card
          for (i=1; i < state->numPlayers; i++)

      randomtestcard output:
        randomtestcard: randomtestcard.c:84: ExecuteRandomTest: Assertion `G.handCount[player] == initHandCount[player] + 1' failed.
        /bin/sh: line 1: 30099 Aborted                 (core dumped) randomtestcard >> randomtestcard.out


Report for Teammate #2 - khouryji - Jibrahn Khoury

    BUG #1 - dominion.c file caseVillage method
      
      Test Case Failed:
        Validate number of player actions increases by 2
        
      Recommendation to Developer:
        Review assignment of state->numActions in caseVillage method (line 663)
          //+2 Actions
          state->numActions = state->playedCardCount++ + 2;

      Output:
        cardtest1: cardtest1.c:51: main: Assertion `G.numActions == initActions + 2' failed.
        /bin/sh: line 1: 16275 Aborted                 (core dumped) cardtest1 >> unittestresults.out

    Note: cardtest1 commented out of Makefile to proceed to next tests
    
    BUG #2 - dominion.c file caseAdventurer method

      Test Case Failed:
        Validate the handcount is correct

    Output:
      cardtest4: cardtest4.c:48: main: Assertion `G.handCount[p] == initHandCount + 2' failed.
      /bin/sh: line 1:  3172 Aborted                 (core dumped) cardtest4 >> unittestresults.out

      randomtestadventurer: randomtestadventurer.c:66: ExecuteRandomTest: Assertion `G.handCount[p] == initHandCount + 2' failed.
      /bin/sh: line 1: 14002 Aborted                 (core dumped) randomtestadventurer >> randomtestadventurer.out

      
    NOTE - dominion.c file cardeffect council_room case

      Looks like there might be a problem with the randomtester as an assert was hit for the council_room
      but Jibrahn did not touch that code.
    
      Output:
        randomtestcard: randomtestcard.c:88: ExecuteRandomTest: Assertion `G.handCount[player] == initHandCount[player] + 1' failed.
        /bin/sh: line 1: 15785 Aborted                 (core dumped) randomtestcard >> randomtestcard.out
