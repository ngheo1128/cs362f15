Jody Hansen
Assignment #5
BugFixes

Objective:
Fix all the bugs that are found in your code.. First fix the bugs that your teammate found then
fix the bugs that you introduced. Use GDB to debug your code and fix it. Provide a documentation
file to discuss which bugs you fix and mention your code changes.

Prelimnary thoughts:
Even though I had run my code through my test cases, my first thought was to run playdom to see
what kind of behavior was displayed while the program was running. Immediately it produced a
segmentation fault, which provided good practice to tracing a seg fault using gdb. Here are the
following commands I used to trace the first seg fault.

$ gdb playdom
Reading symbols from /nfs/stak/students/h/hansejod/CS362/dominion/playdom...done.
$ (gdb) run
Starting program: /nfs/stak/students/h/hansejod/CS362/dominion/playdom
Starting game.

Program received signal SIGSEGV, Segmentation fault.
____strtol_l_internal (nptr=0x0, endptr=0x0, base=10,
                       group=<value optimized out>, loc=0x3514b8e5a0) at ../stdlib/strtol_l.c:298
298	  while (ISSPACE (*s))
$ (gdb) backtrace
#0  ____strtol_l_internal (nptr=0x0, endptr=0x0, base=10,
group=<value optimized out>, loc=0x3514b8e5a0) at ../stdlib/strtol_l.c:298
#1  0x0000003514833c60 in atoi (nptr=<value optimized out>) at atoi.c:28
#2  0x0000000000400fa7 in main (argc=1, argv=0x7fffffffe3d8) at playdom.c:13

One look at line 13 in playdom.c made me realized that I had forgotten to add how many players
I wanted to use in the command-line argument. As silly as this was, this could actually be
useful in the future when someone doesn't give an error message when required arguments are left
off.

However, this exercise did bring up a good point. How do you pass command-line arguments in gdb?
Answer: gdb --args <executable file> arg1 arg2 arg3...

********************************************************************************

The bugs that were reported were:

1.  callCoucilRoom - it doesn't increase the buys like it should.
2.  callAdventurer - you get too much treasure. - Reported by both teammates.
3.  callSmithy - All tests pass. No bug introduced.

BUG FIXES:
1. Council Room function:
This bug was a bit easier to debug since I already knew that I was looking for the specific
variable numBuys. When I ran cardtest3 and stepped into Council Room, I found that numBuys did
not increase like it should. I needed to change state->numBuys to state->numBuys++.

gdb printout:
Breakpoint 1, main () at cardtest3.c:40
40	    printf("Number of buys: %d\n", resulta);
(gdb) next
Number of buys: 1
42	    printf("Calling CouncilRoom function!\n");
(gdb) next
Calling CouncilRoom function!
43	    callCouncilRoom(0, 4, &game);
(gdb) step
callCouncilRoom (currentPlayer_=0, handPos_=4, state=0x7fffffff7bd0)
at dominion.c:1269
1269	    for (i = 0; i < 4; i++)
(gdb) next
1271	        drawCard(currentPlayer_, state);
(gdb) print state->numBuys
$1 = 1
(gdb) next
1269	    for (i = 0; i < 4; i++)
(gdb) next
1271	        drawCard(currentPlayer_, state);
(gdb) print state->numBuys
$2 = 1
(gdb) next
1269	    for (i = 0; i < 4; i++)
(gdb) next
1271	        drawCard(currentPlayer_, state);
(gdb) print state->numBuys
$3 = 1
(gdb) next
1269	    for (i = 0; i < 4; i++)
(gdb) print state->numBuys
$4 = 1
(gdb) next
1271	        drawCard(currentPlayer_, state);
(gdb) print state->numBuys
$5 = 1
(gdb) next
1269	    for (i = 0; i < 4; i++)
(gdb) next
1278	    for (i = 0; i < state->numPlayers; i++)

2. Adventurer function:
After running cardtest2 that tests the Adventurer function, what we can see is that we are looping
through the while loop a total of three times, which results in drawntreasure equaling 3 at the
end of the function (shown with the command print cardtreasures++). We can either fix this by
changing while(drawntreasure<=2) to while(drawntreasure<=1) or while(drawntreasure<2).

gdb printout:
Breakpoint 1, main () at cardtest2.c:58
58	        printf("discardCount %d \n", result2);
(gdb) next
discardCount 0
60	        printf("Calling Adventurer function!\n");
(gdb) next
Calling Adventurer function!
61	        callAdventurer(0, &game1);
(gdb) step
callAdventurer (currentPlayer_=0, state=0x7fffffff7bd0) at dominion.c:1238
1238	    int z=0;
(gdb) next
1239	    int drawntreasure=0;
(gdb) next
1243	    while(drawntreasure<=2){
    (gdb) print drawntreasure
    $1 = 0
    (gdb) next
    1244	        if (state->deckCount[currentPlayer_] <1){//if the deck is empty we need to shuffle discard and add to deck
        (gdb) next
        1245	        shuffle(currentPlayer_, state);
        (gdb) next
        1247	        drawCard(currentPlayer_, state);
        (gdb) next
        1248	        cardDrawn_ = state->hand[currentPlayer_][state->handCount[currentPlayer_]-1];//top card of hand is most recently drawn card.
        (gdb) next
        1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
            (gdb) next
            1250	            drawntreasure++;
        (gdb) print drawntreasure
        $2 = 0
        (gdb) next
        1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
            (gdb) next
            1243	    while(drawntreasure<=2){
                (gdb) print drawntreasure
                $3 = 1
                (gdb) next
                1244	        if (state->deckCount[currentPlayer_] <1){//if the deck is empty we need to shuffle discard and add to deck
                    (gdb) next
                    1245	        shuffle(currentPlayer_, state);
                    (gdb) next
                    1247	        drawCard(currentPlayer_, state);
                    (gdb) next
                    1248	        cardDrawn_ = state->hand[currentPlayer_][state->handCount[currentPlayer_]-1];//top card of hand is most recently drawn card.
                    (gdb) next
                    1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
                        (gdb) next
                        1250	            drawntreasure++;
                    (gdb) next
                    1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
                        (gdb) next
                        1243	    while(drawntreasure<=2){
                            (gdb) print drawntreasure
                            $4 = 2
                            (gdb) next
                            1244	        if (state->deckCount[currentPlayer_] <1){//if the deck is empty we need to shuffle discard and add to deck
                                (gdb) next
                                1245	        shuffle(currentPlayer_, state);
                                (gdb) next
                                1247	        drawCard(currentPlayer_, state);
                                (gdb) next
                                1248	        cardDrawn_ = state->hand[currentPlayer_][state->handCount[currentPlayer_]-1];//top card of hand is most recently drawn card.
                                (gdb) next
                                1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
                                    (gdb) next
                                    1250	            drawntreasure++;
                                (gdb) next
                                1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
                                    (gdb) next
                                    1243	    while(drawntreasure<=2){ //Fix bug here <= to <
                                        (gdb) print drawntreasure
                                        $5 = 3
                                        (gdb) next
                                        1257	    while(z-1>=0){
                                            (gdb) next
                                            1261	    return 0;
                                            (gdb) next
                                            1262	}

3. Smithy function:
I can see that my pre-fix change did not alter the amount of times that the loop was executed.
Although there was a change, the behavior of the code did not change.
                                        
gdb printout:
(gdb) next
Calling Smithy function!
56	        callSmithy(0, 2, &game);
(gdb) step
callSmithy (currentPlayer_=0, handPos_=2, state_=0x7fffffff7bc0)
at dominion.c:1225
1225	    for (i = 0; i < 3; ++i)
(gdb) next
1227	        drawCard(currentPlayer_, state_);
(gdb) next
1225	    for (i = 0; i < 3; ++i)
(gdb) next
1227	        drawCard(currentPlayer_, state_);
(gdb) next
1225	    for (i = 0; i < 3; ++i)
(gdb) next
1227	        drawCard(currentPlayer_, state_);
(gdb) next
1225	    for (i = 0; i < 3; ++i)
(gdb) next
1231	    discardCard(handPos_, currentPlayer_, state_, 0); //To do fix 0 to 1
(gdb) next
1232	    return 0;
                                        

                                        
********************************************************************************
                                        
Unreported bugs that I introduced:
1.  Adventurer - State no longer references the correct variable in the strucutre in
state->handCount[currentPlayer_] to state->deckCount[currentPlayer_].
2.  Ambassador - One of the return statements returns 0 instead of 1, return -1 -> return 0.
3.  Ambassador - The break statement was removed.
                                        
BUG FIXES:
1. Adventurer function:
Below is an excerpt from Adventurer card. There appears to be a bug in drawCard in which it
does not add the card to the current player's hand. Since player 1's hand is always initialized
with a 4 in the top position, the code does not enter into the else statement. Thus, my second bug
was never found. It also explains why when I tested temphand[] (as an argument), it never
changed. It also explains why the discardCount never increased. To circumvent this issue,
I harded coded cardDrawn_ so that it's value equaled 10. I was then able to step through the
else statement in the code (please review the second gdb printout). It became very clear that
it would not remove the top card of the most recently drawn, so I switched it back to
state->handCount[currentPlayer_].
                                        
gdb printout
1247	        drawCard(currentPlayer_, state);
(gdb) next
1248	        cardDrawn_ = state->hand[currentPlayer_][state->handCount[currentPlayer_]-1];//top card of hand is most recently drawn card.
(gdb) print cardDrawn_
$4 = 4
(gdb) next
1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
(gdb) next
1250	            drawntreasure++;

gdb printout
1249	        if (cardDrawn_ == copper || cardDrawn_ == silver || cardDrawn_ == gold)
(gdb) next
1252	            temphand[z]=cardDrawn_;
(gdb) next
1253	            state->deckCount[currentPlayer_]--; //this should just remove the top card (the most recently drawn one).
                                        
2. Ambassador function:
This bug is potentially a very tricky bug since it's not immediately apparent that return 1 (in gdb
printout) is not the correct value. However, if you go to the playCard() function in which
cardEffect is called, you will observe the following code.

gdb printout
1315	    if (j < choice2_)
(gdb) next
1317	        return 1;
  
Excerpt from playCard()
//play card
  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    {
      return -1;
    }
	
  //reduce number of actions
  state->numActions--;

Through logic, we know that we do not want to reduce the number of actions with this card,
therefore when the ambassador function is called, it should always return -1. Thus, the conditional
will be meet and the code does not proceed further.
    
3. Ambassador function:
For the last bug, after going through the for loop in which the program is to discard ONE card,
it becomes apparent that several cards are being discarded. The solution to this is to add
a break statement after the first card is discarded. The program will exit the for loop. 
                                        
gdb printout
1327	    for (i = 0; i < state->numPlayers; i++)
(gdb) next
1336	    discardCard(handPos_, currentPlayer_, state, 0);
(gdb) next
1339	    for (j = 0; j < choice2_; j++)
(gdb) next
1341	        for (i = 0; i < state->handCount[currentPlayer_]; i++)
(gdb) next
1343	            if (state->hand[currentPlayer_][i] == state->hand[currentPlayer_][choice1_])
(gdb) next
1345	                discardCard(i, currentPlayer_, state, 1);
(gdb) next
1341	        for (i = 0; i < state->handCount[currentPlayer_]; i++)
(gdb) next
1343	            if (state->hand[currentPlayer_][i] == state->hand[currentPlayer_][choice1_])
(gdb) next
1345	                discardCard(i, currentPlayer_, state, 1);
(gdb) next
1341	        for (i = 0; i < state->handCount[currentPlayer_]; i++)
(gdb) next
1339	    for (j = 0; j < choice2_; j++)
(gdb) next
1351	    return 0;
                                        
                                        
                                        
                                        
                                        
