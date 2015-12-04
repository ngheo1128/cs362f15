//Name: Rhett Guyer
//Class: CS 362
// Date: 11/22/15
//Assignment: Assignment 5 Bug Fixes

//Objective: Explain the Bug Fixes that were made to my Dominion.c file. Below is a response to how I fixed each bug reported. My responses are inserted as comments while the uncommented text is from my teammates.


List of Bugs Found – Rhett Guyer (From Mc Whorter, Allyce)

1. The card test for Adventurer card revealed that not enough treasure cards are added to the player’s 

hand, so the hand count is incorrect.

	/*
	The issue with this section of code was not so much that the function does not return the correct number of treasure cards but rather the fact that it does not include a way to handle an issue where the deck count hits 0 and needs to be reshuffled. In order to fix this I added in some code to make sure that the deck would be reshuffled if the deck count does go down to zero.	
	*/

2. The card test for the Smithy card revealed the Smithy card was not being removed from the hand. The 

card count, however, was correct indicating that the wrong card is being removed. 

	/*
	In the Smithy card there was a chance that some hands would accidentally remove the wrong card when in fact the Smithy card was the card that needed to be removed. In order to fix this I removed the code that was causing these hands to have the "handPos" variable reduced by 1.	
	*/

*Unit tests for getCost(), compare(), updateCards, and kingdomCards() did not reveal any bugs.

	/*
	I did not find any bugs in these cards either.	
	*/

*Card tests for the Village and Great Hall cards did not reveal any bugs.

	/*
	I am not sure if these cards were actually tested by Allyce or if she had written tests for other cards but these functions did in fact have bugs. The great hall card had a bug that caused the function to draw two cards rather than one for some hands. Also, the village card was altered to set the number of coins to 4 no matter how many that variable held.	
	*/



Bug Report – Rhett Guyer (From Pereira, Adrienne)

1) My test of the adventurer card function found that when the player’s deck count is 3 or less 2 

treasure cards are not added. 

	/*
	The issue with this section of code was that it does not include a way to handle an issue where the deck count hits 0 and needs to be reshuffled. In order to fix this I added in some code to make sure that the deck would be reshuffled if the deck count does go down to zero.	
	*/

2) Also, for the adventurer card function when the player’s deck count is 1 or 0, it is not reduced 

properly.

	/*
	See above as I think this error relates to the above.	
	*/

3) My test for the smithy function found that sometimes the handcount and deck count of the 

player is off. Here are the results of my test:

Testing Smithy...

Test 0 with player 3 and handPos 1

Hand Count test passed 

Deck Count test passed 

Test 1 with player 0 and handPos 0

Hand Count test passed 

Deck Count test passed 

Test 2 with player 1 and handPos 3

Hand Count test passed 

Deck Count test passed 

Test 3 with player 0 and handPos 1

Hand Count test failed. The player's hand increased by 1 not 2 

Deck Count test failed. The player's deck decreased by 2 not 3 

Test 4 with player 2 and handPos 7

Hand Count test passed 

Deck Count test passed 

Test 5 with player 2 and handPos 2

Hand Count test passed 

Deck Count test passed 

Test 6 with player 2 and handPos 3

Hand Count test passed 

Deck Count test passed 

Test 7 with player 3 and handPos 4

Hand Count test passed 

Deck Count test passed 

Test 8 with player 3 and handPos 3

Hand Count test passed 

Deck Count test passed 

Test 9 with player 2 and handPos 1

Hand Count test failed. The player's hand increased by 0 not 2 

Deck Count test failed. The player's deck decreased by 1 not 3

	/*
	In the Smithy card there was a chance that some hands would accidentally remove the wrong card when in fact the Smithy card was the card that needed to be removed. In order to fix this I removed the code that was causing these hands to have the "handPos" variable reduced by 1.	
	*/
	
	
/*
OTHER BUGS NOT FOUND:

Some other bugs that were not found by my teammates were the two in the Great Hall card and the Village card. Both of these were fixed by removing some code in the function. For the Great Hall card I removed the section that was doing multiple draws of new cards and for the village card I removed the code that was changing the coin count.

Another bug that I introduced was the removal of the discard function in the Outpoast Card. All I did to add this back was call the discardCard function witht the hand position that is passed into the outpoastCard function.

Finally, one bug that I addressed but was not actually on that I intorduced was the addition of the discardCard function in the Adventurer Card. I used GDB to debug this function so that I could see if the array of cards in the hand changed at any point and what happened to the Adventurer card after it was used. From what I could tell, the function did not properly remove the card which is incorrect for the program. I added in the discardCard function to remove the card in the hand and it seems to have worked but I am not sure if this function was not called for a reason and having it there would actually introduce a new bug when a function is called after the adventurer card.
*/