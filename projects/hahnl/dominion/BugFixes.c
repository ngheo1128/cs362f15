/****************************************************************************
Author: Larissa Hahn
BugsFixes.c

Group members are Solomon Huynh and Dustin Chase.
*****************************************************************************

----------------------------------------------------------------
Changes to dominion.c based on the bugs found by group members:
----------------------------------------------------------------

---------------------------------------------------
Bugs found by Dustin Chase:
---------------------------------------------------
1. isGameOver() contains a bug.
We can see that the stopping condition occurs before
the higher numbered cards are counted (i < 25).
So the higher numbered cards are not being counted
 the stopping condition needs to be updated.
--------------------------------
ACTION TO CORRECT THIS BUG: The stopping condition is
now corrected to be i < 27 so it is now properly
checking the 27 cards that are available in the game.

---------------------------------------------------
2. smithyCard() contains a bug. The test results show that
the hand count after the card is played is always incorrect.
--------------------------------
ACTION TO CORRECT THIS BUG: The stopping condition is
now corrected to be i < 3 so three cards are added to
the player's hand. Also it begins at i = 0 instead of i = 1.

---------------------------------------------------
3. adventurerCard() contains a bug. The Adventurer card
is never discarded.
--------------------------------
ACTION TO CORRECT THIS BUG: Fix the bugs I introduced. See below.

---------------------------------------------------
4. councilRoom() contains two bugs. Buys is incremented
by +2. i == currentPlayer.
--------------------------------
ACTION TO CORRECT THIS BUG: Buys is now incremented to += 2,
and when drawing a card, it's now the opponent's hand count
that is fixed: i != currentPlayer.


---------------------------------------------------
Bugs found by Solomon Huynh:
---------------------------------------------------
1. villageCard() - The number of actions only
increased by 1 when it should of increased by 2.
--------------------------------
ACTION TO CORRECT THIS BUG: Changed "state->numActions = state->numActions++;"
to "state->numActions = state->numActions + 2;"

---------------------------------------------------
2. councilRoomCard() - The number of buys did not increase
and is 0 when it should of increased by 2.
--------------------------------
ACTION TO CORRECT THIS BUG: Changed "state->numBuys + 2;"
to "state->numBuys += 2;" however as noted below, I changed
the comment as well as introduced a bug so it should actually
be the final fix in this report.


----------------------------------------------------------------
Now the changes to dominion.c based on bugs that I introduced:
----------------------------------------------------------------

1. Adventurer Card - void adventurerCard ()
The first if statement to check if the deck is empty checks if the
state is less than 0 instead of the original less than 1.
drawntreasure gets decremented instead of incremented.
state->handCount[currentPlayer] gets incremented instead of decremented.
--------------------------------
ACTIONS TO CORRECT THESE BUGS: If statement is now less than 1, drawntreasure
is now incremented, handCount is now decremented.

---------------------------------------------------
2. Great Hall Card - void greatHallCard ()
Comment and action now reflect -1 instead of +1. Wondering if changing
the comment will throw someone off when debugging.
--------------------------------
ACTIONS TO CORRECT THESE BUGS: Number of actions is now incremented.

---------------------------------------------------
3. Council Room Card - void councilRoomCard ()
+2 instead of increment for buys.
Second for loop now states <= instead of <
--------------------------------
ACTIONS TO CORRECT THESE BUGS: Seeing that I introduced this bug, I'm
now changing it to be an increment instead of += 2 as well and also I'm
fixing the for loop.
****************************************************************************/
