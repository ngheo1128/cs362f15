Name: 	Jeff Moss
Date:	11/17/15
Title: 	Documentation of the bugs that were fixed and the code changes.
File:	BugFixes.c
Class:	CS362 Fall 2015

The following bug fixes were implemented:

useSmithy()
Bug:handCount not incremented and decremented correctly.
Bug:deckCount increases by 4 instead of 3
Fix: Changed logic in useSmithy so that cards being drawn were < 3 rather than <= 3 

discardCard()
Bug: discardCount not incremented correctly. 
Fix: added code to increment discardCount at the end of the function.

useAdventurer()
Bug: Adventurer card not discarded
Fix: Updated signature and added discard function to adventurer.

Bug: discardCount not incrementing correctly
Fix: After further testing, there was a small logic error found in the card test. cardtest2 was updated by ensuring that the non-treasure cards were added last. Further, cardtest2 
had a off by one error by counting the adventurer card in the logic. Further testing with
the random tester confirmed that the adventurer card was added to the deck but not removed.Additional functionality was added to adventurer to discard the adventurer card. This 
fixed a number of ongoing bugs.

Bug: change in deck did not equal change in hand and change in discard
Fix: When useAdventurer was changed to include the discard function, the deck change
was no longer 2 but 1. The randomtestadventurer random test was updated to reflect this change.
 
useVillage()
Bug: Currentplayer changes after use village
Fix: Removed post decrement from discardCard function

Bug: pre-handcount +1 does not equal post hand-count
Fix: Error in the logic for the randomcardtest. Because an additional card is drawn and 
the village card is discarded, there should be no change in hand count.

useGreat_hall()
Bug: Number of actions not incrementing correctly.
Fix: Changed decrementor to incrementor in useGreat_hall() function

isGameOver()
Bug: The isGameOver function fails on the last three cards
Fix: isGameOver only checks from 0 to 24. The function should check from 0 to 27. This 
fix was implemented in the function. 
