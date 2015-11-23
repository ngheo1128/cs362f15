 Teammate 1: Anne
    Bug No.'s Sent: 7 and 8
 Teammate 2: Jana
    Bug No.'s Sent: 6 and 7
    
    
 ALL BUGS FOUND IN TEAMMATE CODE
 
                            Gain Card
Bug No. :    1 
Teammate: 1, 2
Function: gainCard
Description: A positive valued illegal card should return an error message. Test 2b  card returns 0 for illegal positive card
 values. Logic in function checks if supply count for the card is < 1, but garbage stored in that
location in memory is probably resulting in a false  positive.
preconditiions: function called with card 1000
postconditions: function should return -1
Expected: -1
Actual: 0

                                scoreFor
Bug No. :     2
Teammate: 1, 2
Function: scoreFor
Description: hand score is incorrectly calculated, I cannot figure out why (might be because variable ispf type int, and should be unsigned int)
preconditiions: hand set to curse, estate, duchy, province, great_hall,gardens
    handCounts set to 6
    deckCount set to 0
    discardCount set to 0
postconditions: score should be returned
Expected: 11
Actual: 9

Bug No. :    3 
Teammate: 1, 2
Function: scoreFor
Description: deck score is incorrectly calculated, function is iterateing over discardCount, not deck count
preconditiions: hand set to curse, estate, duchy, province, great_hall,gardens
    handCounts set to 6
    deckCount set to 0
    discardCount set to 0
postconditions: score should be returned
Expected: 11
Actual: 0

                                End Turn
Bug No. :     4
Teammate: 1, 2
Function: endTurn
Description :played cards to do not make it back to the discard pile when endTurn is called, endTurn also does not check for the cleanup phase
preconditiions:add smithy card to played pile, call end turn
postconditions: discardCount should reflect addition of smithy card if deck is not empty
Expected: 0
Actual: -1


                                Smithy Card
Bug No. :     5
Teammate: 1
Function: cardSmithy
Description: Smithy card is only drawing 2 / 3 cards
preconditiions: Hand  count is set to 5, card in position 0 is set to smithy
postconditions: Hand should be 7
Expected: 7
Actual: 6

Bug No. :     6
Teammate: 2
Function: cardSmithy
Description: Smithy card is trashed instead of added to played cards pile
preconditiions: Hand  count is set to 5, card in position 0 is set to smithy
postconditions: Hand count is 7, three cards are drawn, smithy is only card in played pile
Expected: 13 (smithy)
Actual: 387389207

                                Adventurer Card
Bug No. :     7
Teammate: 1, 2
Function: cardAdventurer
Description: adventurer card only adds 1 treasure card  
preconditiions:  card is called, and deck is checked for 2 additional treasures
postconditions: 2 extra treasures hould be found in deck
Expected: 6
Actual: 5

Bug No. :     8
Teammate: 1, 2
Function: cardAdventurer
Description: when deck is set to empty, discard is not shuffled and added to deck
preconditiions:  deck emptied, discard full of unique cards (to check shuffle), call adventurer 
postconditions: deck should consist of previous shuffled discard cards
Expected: 6
Actual: 5

                        Treasure Map
  
Bug No. :     9
Teammate: 1, 2
Function: cardEffect called with treasure_map
Description: 4 gold cards are not added to top of deck, at the top of the deck there is one extra card
suggests potential bug in gainCard function
preconditiions:  hand at 0, and at 4 are set to treasure cards. No golds in deck
postconditions: Top of deck should contain 4 gold cards.
Player 3 Deck
9  Expected: 6 (Gold) Actual: 4
8  Expected: 6 (Gold) Actual: 6
7  Expected: 6 (Gold) Actual: 6
6  Expected: 6 (Gold) Actual: 6
5                     Actual: 6
4                     Actual: 4
3                     Actual: 4
2                     Actual: 4
1                     Actual: 4

 Bug No. :     10
Teammate: 1, 2
Function: cardEffect called with treasure_map
Description: 2 treasure cards should be in player's discard pile but they are not 
they are not in played pile either
preconditiions: hand at 1, and at 3 are set to treasure cards.
postconditions: Top two cards of discard pile are Treasure Map cards.

Player 0's played cards:

Top of discard pile...
Card at Position 2: 1
Card at Position 1: 4
Card at Position 0: 4

Number of Treasure Maps, Expected: 2   Actual: 0




                                                                                 
