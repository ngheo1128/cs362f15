 So, if you cannot find out any bug, you will loose only 10 points). 
Please note that you may need to change your tests in order to match the 
refactored code. Based on how your teammates refactored the code, what 
are the method names, what are the parameter passed, you have to change 
your tests. This will also indicate how maintainable your tests are. 

CS 362 - ASSIGNMENT 4               KELVIN WATSON 
BugsInTeammates.c                   ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
----------------------------------------------------------------------------------------------------------------------------



BUG REPORT FOR TEAMMATE 1 (Jason Flaig; onid: flaigj)
-----------------------------------------------------
Two bugs were detected using tests in cardtest1.c and cardtest2.c

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ID	DESCRIPTION					EXPECTED OUTPUT			ACTUAL OUTPUT			SEVERITY  PRIORITY	HOW TO REPRODUCE			
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1	Number of cards in hand 	pre-call handCount=5	pre-call handCount=5	High	  Medium	Call smithyCard()
	is one more than expected 	post-call handCount=7	post-call handCount=8						using valid game
	after call to smithyCard().																		state, player and
	Also, number of cards in 																		hand position.
	deck one less than expected.
	These buggy outputs are due 
	to drawCard() method being 
	called one too many times.	
	Bug detected using unit tests 
	in cardtest1.c.
----------------------------------------------------------------------------------------------------------------------------
2	Number of gold treasure 	gold treasure count=2	gold treasure count=0	High	  Urgent	Call the 
	cards consistently 																				cardEffect() method
	computes to 0. Gold 																			using the adventurer
	treasure cards are not 																			enumerated type as 
	counted towards the 																			an argument, which 
	hand's treasure count. 																			in turn calls the 
	Bug detected using unit 																		adventurerCard() 
	tests in cardtest2.c.																			method. Count the 
																									number of gold 
																									treasure cards in
																									the hand.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



BUG REPORT FOR TEAMMATE 2 (Dustin Dinh; onid: dinhd)
----------------------------------------------------
Two bugs were detected using tests in cardtest1.c and cardtest2.c

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ID	DESCRIPTION					EXPECTED OUTPUT			ACTUAL OUTPUT			SEVERITY  PRIORITY	HOW TO REPRODUCE			
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1	Number of cards in hand 	pre-call handCount=5	pre-call handCount=5	High	  Urgent	Call smithyCard()
	is two less than expected 	post-call handCount=7	post-call handCount=5						using valid game
	after call to smithyCard().																		state, player and
	Note that cardtest1.c 																			hand position.
	forces the user to draw 
	from a deck containing only 
	gold treasure cards as a 
	second check to verify that 
	the drawn cards were indeed	
	placed in the hand. As a 
	result of the bug, the number 
	of gold cards drawn is
	incorrect as well. This is a 
	side effect of the card being
	immediately discarded after 
	being drawn. These buggy 
	outputs are due to the 
	discardCard() method being 
	enclosed inside the for loop
	where cards are being drawn.
	Bug detected using unit tests 
	in cardtest1.c.
----------------------------------------------------------------------------------------------------------------------------
2	The player's discard card	discardCount=5			discardCount=6		High		Urgent		Call adventurerCard()
	count is consistently one 																		using valid game
	more than the expected 													If left unfixed,  		state, player, and hand
	discard card count. This is												subsequent attempts  	position. Check discard
	due	to a bug causing an extra											to use discard pile    	count against a oracle	
	card (actually uninitialized 											may result in invalid   after card draws and 
	junk data) from the temphand 											(junk data) being 		discard of temphand.
	being added to the discard												accessed.
	pile due to accessing data 							
	outside of the temphand
	array bounds (data at invalid 
	array index -1 is being 
	accessed). Bug detected using
	unit tests in cardtest2.c.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++