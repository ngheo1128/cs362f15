CS_362_Software Engineering
Assignment #5 Bug Fixes
thalijw


****************************************************************************************

						Fixing Bugs That My Teammates Found

****************************************************************************************

Description
-----------
	My teammates [ Jody Hansen, Brian Stamm ] Found bugs in my Smithy and Adventurer cards,
I used the GDB to debug my dominion.c code by running the debugger on my cardtest1.c and 
cardtest2.c (card unit tests) and The resuld and fixes are as follows:


-------------------------------------------
| Function Changed : Smithy card      	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

Reported Bugs
-------------
1- The PlayedCardCount did not change and remain 0 (card did not discarded)


GDB
---
I ran the debugger and set a watch command on the function discardCard() to see the
variable changes during the execution, the debugger showed that in dominio.c the line 1151
never executed (trashflag<1) and the value of state->playedCardCount always = 0

Code Changes
------------
This is a bug I introduced to the code, I fixed the bug by changing the trashflag back 
to be set to 0 instead of 1.

Code With Bug
-------------
discardCard(handPos, currentPlayer, state, 1);

Code Without Bug
----------------
discardCard(handPos, currentPlayer, state, 0);


-------------------------------------------
| Function Changed : Adventurer card  	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

Reported Bugs
-------------
1- The discardCount did not increase by one.

GDB
---
I ran the debugger and set a breakpoint on the function adventurer_refactor() to see the
variable changes during the execution, I followed the variables drawntreasure and Z, and
I found out that at the end of the execution, drawntreasure = 3 and Z = Always z.

But running the debugger showed my introduced bug in the variable drawntreasure, this 
variable should be = 2. 

Code Changes
------------
There is no changed needed to be made on the discardCount, since the code will preform correctly
if the drawCard() will draw a card that is not a copper, silver or gold, the varibale z will 
be more than zero and the discatCount will increase in this senario.

Code With Bug
-------------
while(drawntreasure<3)

Code Without Bug
----------------
while(drawntreasure<2)

-------------------------------------------
| Function Changed : council_room card 	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

Reported Bugs
-------------
1- The current player is the only one who gain cards.

GDB
---
I ran the debugger and set a breakpoint on the function council_room_refactor() to see 
the variable changes during the execution, I followed the variables state->handCount[currentPlayer],  
state->handCount[currentPlayer+1] and state->numBuys, I found out that state->numBuy increased by 1, 
state->handCount[currentPlayer] increased by 1, but state->handCount[currentPlayer+1] stayed the same
and its always at the line ( i == currentPlayer ) (the bug I introduced)

Code With Bug
-------------
( i == currentPlayer )

Code Without Bug
----------------
( i != currentPlayer )


****************************************************************************************

						Fixing Bugs That I Introduced

****************************************************************************************

-------------------------------------------
| Function Changed : Smithy card      	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

-------------------------------------------
| Function Changed : Adventurer card   	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

-------------------------------------------
| Function Changed : council_room card 	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

Description
-----------
I fixed those two bugs in the above teammate bug fix section.



-------------------------------------------
| Function Changed : Steward card   	  |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

GDB
---
I ran the debugger and set a breakpoint on the function steward_refactor() to see the
variable changes during the execution, I followed the variables state->handCount,  
state->discardCount and state->coins, I found out that when executing each choice that
the Handcount added two cards, the discardCount subtracted two, but the coins did not
add two, but it subtracted two.

Code With Bug
-------------
state->coins = state->coins - 2;

Code Without Bug
----------------
state->coins = state->coins + 2;


-------------------------------------------
| Function Changed : Remodel card 	      |
| Bugs Fixed       : One                  |
| Report Date      : 17-11-2015           |
-------------------------------------------

GDB
---
I didn't have a unit test to run the debugger on so I changed the bug I introduced on my 
Assignment#2 manually

Code With Bug
-------------
if ( (getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )

Code Without Bug
----------------
if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )




