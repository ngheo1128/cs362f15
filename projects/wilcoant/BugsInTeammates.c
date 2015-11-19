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
Complete results can be examined in this directory file:
randomtestadventurer3.out 

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

for phamdal:
===================================
Title:  smithy_card 01

Class: Serious Bug

Date: 11.19.15
Reported By: wilcoant
Email: wilcoant@oregonstate.edu

Is it reproducible: Yes

Description
===========
TEST 1: Deck count after card played:
deck count = 13, expected = 10

TEST 2: Deck player hand count:
hand count = 0, expected = 3

TEST 3:  
Other player's hands: 
Player 1 hand count: 9 expected: 5

TEST 4: Card sum(correct cards added to hand):
Card sum = 0, expected = 43
another iteration:
TEST 1: Deck count after card played:
deck count = 5, expected = 5

TEST 2: Deck player hand count:
hand count = 7, expected = 8

TEST 3:  
Other player's hands: 
Player 2 hand count: 0 expected: 0

TEST 4: Card sum(correct cards added to hand):
Card sum = 22, expected = 70



Excerpt test results are from teammate2/randomtestcard.out, complete 
results can be examined there.  Player hand count is not  and deck 
count are not properly updating, the sum will also be incorrect
since the count is known to be incorrect.  


Expected Results
----------------
See above,  The hand count should be increased by 
three and the deck count should decrease by three. 
Further, other players hand counts should remain unchanged.


Actual Results
--------------
Other player hand counts are being altered and code insepction reveals
that this is unlikely to be the result of smithy_card and may be in 
a helper fn.  For the smith_card itslef, the deck count and hand count 
are sporadic in their increase and decrease.  Both should be done by 
three.  


Suggested Fixes
-----------------
change line 1171 in dominion.c: discardCard(handPos, currentPlayer, state, 1);
to:				discardCard(handPos, currentPlayer, state, 0);
	
for phamdal:
===================================
Title:  adventurer_card Bug Report 01

Class: Serious Bug

Date: 11.19.15
Reported By: wilcoant
Email: wilcoant@oregonstate.edu

Is it reproducible: Yes

Description
===========
TEST 3: Number of treasure coins after play:
treasure cards = 7, expected = 6
TEST 3: Number of treasure coins after play:
treasure cards = 0, expected = 2
TEST 3: Number of treasure coins after play:
treasure cards = 6, expected = 6


Drawn treasure cards are not updating properly. Exerpts above are from 
randomtestadventurer.out randomtestadventurer2.out in the teammate2
directory.  
Drawn treasure cards are updating sporadically, values are inconsistent
between actual and expected reslts.
Inconsistencies in Discard and Deck count exist but have existed across
multiple dominion.c implementations and I believe they point to drawCard.


Expected Results
----------------
See above,  the number of treasure cards in player hand should 
increment by 2 each time, there is inconsistency in this update.


Actual Results
--------------
player treasure card is incremented by too many, not enough, or not at 
all. 


Suggested Fixes
-----------------
change line 1139 in dominion.c: while (drawntreasure<2)
to:				while (drawntreasure <= 2))


****************************************************************************/