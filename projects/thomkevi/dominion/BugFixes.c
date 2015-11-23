This documents the bugs that were found by other testers as well as that were also introduced,
and fixed.

Robert Ward found
    Bug 1: In function 'playAdventurer'
        In the conditional statement 'if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)' a '&&' 
        is used that should probably be an '||'. It is requiring that the card drawn be both 'gold' and 'copper' or 'silver' 
        at the same time, which is not possible. This statement never executes the true condition.

      playAdventurer:  One comparator "||" for cardDrawn was switched to "&&"

        This has been corrected by replacing the && with ||

        
Robert Ward found    
    Bug 2: In the function 'playRemodel'
        The second choice is never gained. The bug is in the statement 
        'gainCard(choice1, state, 0, currentPlayer)'. Instead of gaining choice2, 
        choice1 is selected.

          playRemodel:  gainCard function parameter 1 changed from choice2 to choice1
          
          This has been corrected by replacing choice1 with choice2 in the gainCard call


playCouncilRoom:  The if statement checking if i equals the current player has been removed.
                  All players will draw an extra card including the current player.

  This was previously corrected.  No change in latest checkin.  

  
playSmithy:  The comparator "<" in the for statement has been switched to ">"

  This was previously corrected.  No change in latest checkin.  