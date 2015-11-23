ANNE LINDENBURG'S BUGS
Smithy
   Bug 6: Hand size for Smithy is off by one.
    The hand size is less than what is expected.

        Fix: Changed loop to start iteration at 0, instead of 1
        date: 11/ 21/ 2015


Treasure Map
    Bug 7: Hand size for Treasuer Map is off by 1.
    Checked the hand size and found it is stating there is 
    one more than what is expected.

        Fix: Only one treasure card was being trashed, called discard a with the trash flag set for
        the treasure map in handPos so that both treasure map cards were trashed
        date: 11/ 21/ 2015


JANA GALLINA'S BUGS
Bug #1
    Function: play_adventurer
    Description: deckcount doesn’t decrease by the proper amount (drawntreasure doesn’t 
    increment through looping)

        Fix: changed variable drawnTreasure to increment instead of being set equal to 2
        date: 11/21/2015

 Bug #2
    Function: play_smithy
    Description:  currentPlayer does not draw 3 cards. Deck count decrease failed.

        Fix: Changed loop to start iteration at 0, instead of 1
        date: 11/ 21/ 2015


MY BUGS
PLAY ADVENTURER
    orignal behavior: if a treasure card is drawn, the drawntreasure variable would +1
    modified behavior: if a treasure card is drawn, the drawntreasure variable is set to 2 
    (*cards are discarded cards until one treasure is found*)
    
        Fix: Anne and Jana found this bug, it was fixed as detailed above
    
PLAY CUTPURSE
    normal behavior: each other player discards a copper card, or reveals a hand without any copper
    modified behavior: each other player discards a SILVER card, or reveals a hand without any silver
    
        Fix: changed compariston value from silver to copper (from 5 to 4)


PLAY TREASURE MAP
    orginal behavior: if two treasure map cards are found, both are trashed
    modified behavior: if two treasure map cards are found, only the second one is trashed
    
        Fix: Anne found this bug and it was fixed as detailed above


PLAY SMITHY
    original behaviour:  +3 cards
    modified behavior: +2 cards (loop counter starts at 1)
    
        Fix: Jana found this bug, it was fixed as detailed above
