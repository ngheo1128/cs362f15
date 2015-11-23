Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
BugsInTeammates.c

This file contains documentation of the bugs I found during testing of
teammates` code for Assignment 5.

Teammate 1 (Victor Hernandez):
Name:           
	adventurerCard() causes segFault when deck is empty. 
File:           
	dominion.c
Severity:       
	HIGH (High/Medium/Low)
Priority:       
	MEDIUM (High/Medium/Low)
Reported Date:  
	11/19/2015
Reason:         
	drawCard() does not check for empty deck.
Status:         
	OPEN
Description:    
	When drawCard() is called in adventurerCard() on an empty 
	deck, it returns -1 and does not increment handCount. 

	adventurerCard() decrements handcount, however, so handCount
	goes negative. 

Steps to Reproduce: 
	Initialize a struct gameState with a handCount[0] and 
	deckCount[0] of 0. Call adventurerCard() on player 0.

Expected Results:   
	adventurerCard() should return with no change in state.


Name:           
	villageCard() not discarding card properly. 
File:           
	dominion.c
Severity:       
	MEDIUM (High/Medium/Low)
Priority:       
	MEDIUM (High/Medium/Low)
Reported Date:  
	11/19/2015
Reason:         
	discardCard() is being called with the trash flag set.
Status:         
	OPEN
Description:    
	villageCard() should discard the played Village card into
	the playedCards array so that at the end of the turn, it
	can be recycled into the current player's deck. 

	Instead, the card is simply being removed from play.

Steps to Reproduce: 
	Compare deckCount, handCount, playedCardsCount 
	and discardCount before and after calling villageCard().

Expected Results:   
	VillageCard should be in playedCards array.


Name:           
	great_hallCard() draws 2X too many cards into hand. 
File:           
	dominion.c
Severity:       
	MEDIUM (High/Medium/Low)
Priority:       
	MEDIUM (High/Medium/Low)
Reported Date:  
	11/19/2015
Reason:         
	drawCard() invoked twice.
Status:         
	OPEN
Description:    
	great_hallCard() should draw 1 card and add 1 action.
	Instead, great_hallCard() draws 2 cards and adds 1 action.

Steps to Reproduce: 
	Compare handCount[0] before and after calling villageCard()
	on player 0.

Expected Results:   
	handCount[0] should be increased by 1.


Name:           
	isGameOver() returns false negative on certain empty cards. 
File:           
	dominion.c
Severity:       
	MEDIUM (High/Medium/Low)
Priority:       
	MEDIUM (High/Medium/Low)
Reported Date:  
	11/19/2015
Reason:         	
	Loop in isGameOver() does not iterate through all the card
	types. 
Description:    	
	The halting condition in the for loop is i == 25, so it 
	does not reach treasure_map.
 
	Therefore, if 2 card types are empty, and treasure_map is 
	empty, isGameOver returns false where it should return true.
Status:         
	OPEN

Steps to Reproduce: 
	Initialize a gameState in which values in supplyCoun**************

Expected Results:   
	handCount[0] should be increased by 1.


Teammate 2 (Billy Kerns):

Name:           
    adventureCard() causes segFault when deck is empty. 
File:  
    dominion.c
Severity:       
    HIGH (High/Medium/Low)
Priority:       
    MEDIUM (High/Medium/Low)
Reported Date:  
    11/19/2015
Reason:         
    drawCard() does not check for empty deck.
Status:         
    OPEN
Description:    
    When drawCard() is called in adventurerCard() on an empty 
	deck, it returns -1 and does not increment handCount. 

	adventurerCard() decrements handcount, however, so handCount
	goes negative. 

Steps to Reproduce: 
    Initialize a struct gameState with a handCount[0] and 
	deckCount[0] of 0. Call adventurerCard() on player 0.

Expected Results:   
    adventureCard() should return with no change in state.


Name:           
    adventureCard() loses 1 card from deck on every call. 
File:
    dominion.c
Severity:       
    MEDIUM (High/Medium/Low)
Priority:       
    MEDIUM (High/Medium/Low)
Reported Date:  
    11/19/2015
Reason:         
    adventureCard() is not discarding temp array completely.
Description:    
    The while loop that iterates through tempArray to move all cards
	to discard array, does not process every element of tempArray.

	Therefore, the first non-treasure card that is drawn from the
	deck after adventureCard() is invoked will be lost. 
Status:         
    OPEN

Steps to Reproduce: 
    Initialize a gameState in which the deck[0] has as its first
	4 elements: copper, copper, village, village. Initialize 
	discardCount[0] to 0. Set deckCount[0] to 4. 
	Call adventurerCard() on player 0.  

Expected Results:   
    discardCount[0] should equal 2.

    
Name:           
    smithyCard() not discarding card properly. 
File:           
    dominion.c
Severity:       
    MEDIUM (High/Medium/Low)
Priority:       
    MEDIUM (High/Medium/Low)
Reported Date:  
    11/19/2015
Reason:         
    discardCard() is being called with the trash flag set.
Status:         
    OPEN
Description:    
    smithyCard() should discard the played Smithy card into
	the playedCards array so that at the end of the turn, it
	can be recycled into the current player's deck. 

	Instead, the card is simply being removed from play.

Steps to Reproduce: 
    Compare deckCount, handCount, playedCardsCount 
	and discardCount before and after calling smithyCard().

Expected Results:   
    Smithy Card should be in playedCards array.

    
Name:           
    isGameOver() returns false negative on certain empty cards. 
File:           
    dominion.c
Severity:       
    MEDIUM (High/Medium/Low)
Priority:       
    MEDIUM (High/Medium/Low)
Reported Date:  
    11/19/2015
Reason:         
    Loop in isGameOver() does not iterate through all the card
	types. 
Description:    
    The halting condition in the for loop is i == 25, so it 
	does not reach treasure_map.
 
	Therefore, if 2 card types are empty, and treasure_map is 
	empty, isGameOver returns false where it should return true.
Status:        
    OPEN

Steps to Reproduce: 
    Initialize a gameState in which value of 
    supplyCount[treasure_map] and 2 other elements of supplyCount are equal to 0.
    Set all other elements to positive numbers. Call isGameOver() on this game state. 

Expected Results:   
    isGameOver() should return 1.

