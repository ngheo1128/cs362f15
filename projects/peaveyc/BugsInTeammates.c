//Author: Sharon Kuo
//Test on function councilRoomCard
//Test run on 11/18/2015
//Test Name connorTest1.c
//Version: 1.0

Title: 			Council Room Card draws 3 cards not 4
Class: 			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on councilRoomCard it was discovered that instead of drawing four
				cards for the current player, only three were drawn.

Replication: 	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player should have the card Council Room. The player should then play the card. Bug occurs.

Expected Results:		Current player draws four cards.
Actual Results:			Current player draws three cards.


//Author: Sharon Kuo
//Test on function adventureCard
//Test run on 11/18/2015
//Test Name connorTest2.c
//Version: 1.0

Title:			Adventure Card draws three treasure not two
Class:			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on adventureCard it was discovered that instead of drawing two treasures
				three were drawn.

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have at least three treasures in the draw pile. Send the gamestate to the function
				adventureCard. Bug occurs.

Expected Results:		Current player draws two treasures.
Actual Results:			Current player draws three treasures.


//Author: Sharon Kuo
//Test on function adventureCard
//Test run on 11/18/2015
//Test Name connorTest2.c
//Version: 1.0

Title:			Adventure Card discard loss
Class:			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on adventureCard it was discovered that instead of discarding the proper
				amount of cards, there is one card not being discarded.

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have at least three treasures in the draw pile and one non treasure card interspersed 
				between the treasure cards. Send the gamestate to the function adventureCard. Bug occurs.

Expected Results:		All cards that are not treasure cards the are drawn, are discarded.
Actual Results:			All cards that are not treasure cards the are drawn, are discarded except one card.


//Author: Sharon Kuo
//Test on function smithyCard
//Test run on 11/18/2015
//Test Name cardtest1.c
//Version: 1.0

Title:			Incorrect discard in smithy card
Class:			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on cardEffect it was discovered that current players discard was 
				not increased by 1. 

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have a smithy card. Then the player must play the card. Bug occurs.

Expected Results:		Current player discard is increased by 1.
Actual Results:			Current player discard is increased by 0.


//Author: Tara Massey
//Test on function adventureRef
//Test run on 11/18/2015
//Test Name connorTest2.c
//Version: 1.0

Title:			Adventure Card Coin increase
Class:			Bug, Minor

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on adventureCard it was discovered that coin amount was being incremented twice.
				The author of the original program wrote "Use as you see fit" near the coin value, so this may
				be a perfectly legal function.

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have at least two treasures in the draw pile. Send the gamestate to the function adventureCard. Bug occurs.

Expected Results:		Coin amount in gamestate remains unchanged.
Actual Results:			Coin amount in gamestate is increased by two.


//Author: Tara Massey
//Test on function cardEffect case council_room
//Test run on 11/18/2015
//Test Name connorTest1.c
//Version: 1.0

Title:			Incorrect card draw in council room card
Class:			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on cardEffect it was discovered that current players hand was 
				being increased by 3 instead of 4. 

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have a council room card. Then the player must play the card. Bug occurs.

Expected Results:		Current player hand is increased by 4.
Actual Results:			Current player hand is increased by 3.


//Author: Tara Massey
//Test on function smithyRef
//Test run on 11/18/2015
//Test Name cardtest1.c
//Version: 1.0

Title:			Incorrect card draw in smithy card
Class:			Bug, Major

Reporter: 		Connor Peavey
Email: 			Connorpeavey@gmail.com

Environment:	Tests run on GNU/Linux on server flip3
Reproducible: 	True

Description:	While running unit test on cardEffect it was discovered that current players hand was 
				being increased by 3 instead of 2. 

Replication:	Create a gamestate. The necessary requirements for creating the bug is that the current 
				player have a smithy card. Then the player must play the card. Bug occurs.

Expected Results:		Current player hand is increased by 2.
Actual Results:			Current player hand is increased by 3.




