/***************************************************************************
Anthony Wilcox
cs362, Fall 2015
Assignment 5
file: BugsInTeammates.c
documentation: (used format for bug report from teammate tullisb that he gave me for my bugs
because i like the look of it)


for tullisb:
===================================
Title:  adventurerFunction Bug Report 01

Class: Serious Bug

Date: 11.19.15
Reported By: wilcoant
Email: wilcoant@oregonstate.edu

Is it reproducible: Yes

Description
===========
TEST 3: Number of treasure coins after play:
treasure cards = 4, expected = 6
TEST 3: Number of treasure coins after play:
treasure cards = 0, expected = 2

Drawn treasure cards are not updating properly. All test runs in 
randomtestadventurer.out show expected incrementation of 
treasure cards to be off by two.  


Expected Results
----------------
See above,  the number of treasure cards in player hand should 
increment by 2.


Actual Results
--------------
player treasure card is incremented by 0


Suggested Fixes
-----------------
change line 14 in dominion.c: while (drawntreasure<2 && state->numActions<2)
to:				while (drawntreasure <= 2))
	
for tullisb:
===================================
Title:  adventurerFunction Bug Report 02

Class: Serious Bug

Date: 11.19.15
Reported By: wilcoant
Email: wilcoant@oregonstate.edu

Is it reproducible: Yes

Description
===========
Made suggested fix to bug 01 and ran again: sample results from 
randomtestadventurer.out are below:
TEST 3: Number of treasure coins after play:
treasure cards = 0, expected = 2
TEST 3: Number of treasure coins after play:
treasure cards = 7, expected = 6


Drawn treasure cards are not updating properly.  Fixed entry to 
while loop as stated in bug 01 but now treasure cards are updating 
improperly in more sporadic ways.
Futher:
TEST 1: Deck count after card played:
deck count = 2, expected = 4

TEST 2: Discard count after card played:
discard count = 0, expected = 2

TEST 4: Value of cards in hand:
value of cards = 9, expected = 6

Deck count, discard count, and the value of the treasure cards are not 
properly updating.  Other values may be linked directly to the drawCard
function as we know there is an issue there.  

Expected Results
----------------
See above,  the number of treasure cards in player hand should 
increment by 2. Deck count should reflect the correct number of
drawn cards missing and the discard count should update properly
for the drawn card.  


Actual Results
--------------
player treasure card is incremented by differing amounts.  Discard 
count and deck count are not updating properly either. 



Suggested Fixes
-----------------
change line 16 in dominion.c: 
if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			drawCard(currentPlayer, state);
		}
		shuffle(currentPlayer, state);
To: 
if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);


****************************************************************************/