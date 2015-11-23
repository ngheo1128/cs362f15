Anne Lindenberg
Assignment 5
CS362

Bugs found from Teammates:


Function: cardSmithy

Description: currentPlayer does not draw 3 cards. Deck count decrease failed.

Fixed bug in the deck count for correct amount of cards drawn so in the for loop i = 1 and should be i = 0.


Function: cardAdventurer

Description:  discardcount is incorrect

Fixed bug in the while loop for discardCount z-1> 0 should be z-1>=0

Smithy Card
Bug No. :     5
Teammate: 1
Function: cardSmithy
Description: Smithy card is only drawing 2 / 3 cards
preconditiions: Hand  count is set to 5, card in position 0 is set to smithy
postconditions: Hand should be 7
Expected: 7
Actual: 6

Fixed bug in the deck count for correct amount of cards drawn so in the for loop i = 1 and should be i = 0.


Bug No. :     8
Teammate: 1
Function: cardAdventurer
Description: when deck is set to empty, discard is not shuffled and added to deck
preconditiions:  deck emptied, discard full of unique cards (to check shuffle), call adventurer
postconditions: deck should consist of previous shuffled discard cards
Expected: 6
Actual: 5

Fixed bug in the while loop for discardCount z-1> 0 should be z-1>=0


Bugs found in code:

Function Council_room the played card in the discardCard isn't the correct trashflag is 1 should be 0

Function Remodel gainCard function is called the choice used was changed to choice1 should be choice2