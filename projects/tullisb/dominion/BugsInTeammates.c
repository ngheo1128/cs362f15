for phamdal:
===================================
Title: council_room_card Bug Report

Class: Serious Bug

Date: 11.18.15
Reported By: tullisb
Email: tullisb@oregonstate.edu

Is it reproducible: Yes

Description
===========
council_room_card fails when asserting if:
*playerHandcount is incremented by 3
*playerHandcount2 is incremented by 1
*coins remains unchanged 
*numBuys is incremented by 1


Expected Results
----------------
playerHandcount incremented by 3
playerHandcount2 incremented by 1
coins remain unchanged 
numBuys incremented by 1


Actual Results
--------------
playerHandcount incremented by 4 (bad)
playerHandcount2: decremented by 1 (bad)
coins remained unchanged  (good)
numBuys remained unchanged  (bad)


Suggested Fixes
-----------------
change line:	if ( i == currentPlayer ) 
to:				if ( i != currentPlayer )

change line:	return 1;
to:				return 0; 




for phamdal:
===================================
Title: smithy_card Bug Report

Class: Semi Serious Bug

Date: 11.18.15
Reported By: tullisb
Email: tullisb@oregonstate.edu

Is it reproducible: Yes

Description
===========
smithy_card fails when asserting whether played card is added to played pile or not


Expected Results
----------------
playerHandcount incrementd by 3
playerHandcount2 remains unchanged 
coins remains unchanged 
curse cards remain undistributed 
outpostPlayed remain unchanged
card is added to played pile


Actual Results
--------------
playerHandcount incrementd by 3 (good)
playerHandcount2 remains unchanged (good)
coins remains unchanged (good)
curse cards remain undistributed (good)
outpostPlayed remain unchanged (good)
card is not added to played pile (bad)

Suggested Fixes
-----------------
change line: 	discardCard(handPos, currentPlayer, state, 1);
to:				discardCard(handPos, currentPlayer, state, 0);



for wilcoant::
===================================
Title: play_council Bug Report

Class: Semi Serious Bug

Date: 11.18.15
Reported By: tullisb
Email: tullisb@oregonstate.edu

Is it reproducible: Yes

Description
===========
play_council fails when asserting whether number of buys remains unchanged or not


Expected Results
----------------
playerHandcount incremented by 3
playerHandcount2 incremented by 1
coins remain unchanged 
numBuys incremented by 1


Actual Results
--------------
playerHandcount incremented by 3 (good)
playerHandcount2 incremented by 1 (good)
coins remain unchanged (good)
numBuys is not incremented (bad)


Suggested Fixes
-----------------
promote line:	//state->numBuys++; 
to:				state->numBuys++;


