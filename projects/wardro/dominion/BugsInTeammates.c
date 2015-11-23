Robert Ward
11-21-2015
Assignment 5

Teammate 1: Jibrahn Khoury
Bugs found
Bug 1: In function 'caseOutpost()'
    The line 'state->outpostPlayed;' in the function doesn't increment the outpostPlayed counter. This would allow a player to play multiple outposts, or worse yet, never get to have their extra turn.

Bug 2: In function 'caseSteward()'
    The function never returns when called. Also, on choice == 1 the second 'drawcard' function is called with '0' as the current player, but the current player might not be '0' every time that the Steward card is played.



Teammate 2: Kevin Thompson
Bugs found
Bug 1: In function 'playAdventurer'
    In the conditional statement 'if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)' a '&&' is used that should probably be an '||'. It is requiring that the card drawn be both 'gold' and 'copper' or 'silver' at the same time, which is not possible. This statement never executes the true condition. 
    
Bug 2: In the function 'playRemodel'
    The second choice is never gained. The bug is in the statement 'gainCard(choice1, state, 0, currentPlayer)'. Instead of gaining choice2, choice1 is selected.




