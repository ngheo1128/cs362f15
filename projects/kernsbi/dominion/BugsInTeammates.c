Billy Kerns

Daniel Bonnin Bugs:

Noverse Bug Reporting Template
==============================

	Title: 
		Smithy Card Failure

	Class:
		Card bug

	Date:   
		11/13/2015 

	Reported By:  
		Billy Kerns 

	Email:      
		kernsbi@oregonstate.edu

	Product:  
		Dominion Game    

	Platform:   
		linux  

	Is it reproducible:
		Yes

	Description: 
		The Smithy card only adds two cards to the player''s hand instead of three.

	Steps to Produce/Reproduce:
		Play the Smithy card.

	Expected Results:
		handCount should go up by three assuming no shuffle has taken place.

	Actual Results:
		handCount only goes up by two and deckCount only goes down by two.

	Workarounds:
		None

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Title: 
		Village Card Failure 1

	Class:
		Card bug

	Date:   
		11/13/2015 

	Reported By:  
		Billy Kerns 

	Email:      
		kernsbi@oregonstate.edu

	Product:  
		Dominion Game    

	Platform:   
		linux  

	Is it reproducible:
		Yes

	Description: 
		Played the Village card noting the amount of numActions in the gameState.  After playing the Village card the amount
		of numActions was greater than the original amount + 2

	Steps to Produce/Reproduce:
		Play Village card

	Expected Results:
		The gameState''s numActions to be incremented by two.

	Actual Results:
		The gameState''s numActions is incremented by more than two.

	Workarounds:
		None

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Victor Hernandez Bugs: 
Noverse Bug Reporting Template
==============================

	Title: 
		Smithy Card Failure

	Class:
		Card bug

	Date:   
		11/16/2015 

	Reported By:  
		Billy Kerns 

	Email:      
		kernsbi@oregonstate.edu

	Product:  
		Dominion Game    

	Platform:   
		linux  

	Is it reproducible:
		Yes

	Description: 
		Played the Smithy card noting the amount of played cards in the gameState.  After playing the Smithy card the 
		amount of played cards was not increased to account for the played card.

	Steps to Produce/Reproduce:
		Play Smithy card keeping track of played card count

	Expected Results:
		The gameState''s played card count to be incremented by one.

	Actual Results:
		The gameState''s played card count is not incremented at all.

	Workarounds:
		None

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Title: 
		Great Hall Card Failure 

	Class:
		Card bug

	Date:   
		11/16/2015 

	Reported By:  
		Billy Kerns 

	Email:      
		kernsbi@oregonstate.edu

	Product:  
		Dominion Game    

	Platform:   
		linux  

	Is it reproducible:
		Yes

	Description: 
		Played the Great Hall card noting the amount of cards in the player''s hand.  After playing the Great Hall card 
		the amount of cards in the player''s hand has one more than it should.

	Steps to Produce/Reproduce:
		Play Great Hall card keeping track of player''s hand count

	Expected Results:
		The player''s hand count to be the same as it was before the card was played.

	Actual Results:
		The player''s hand count has one more than the hand count before the card is played.

	Workarounds:
		None
