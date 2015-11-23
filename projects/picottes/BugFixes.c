Bug Fixes:

Smith Card: It the for loop was iterating an extra time because i was set to go to <=3. I
changed it <3 so that only 3 cards would be added to the players hand.

Village Card: The function was removing two actions from the player instead of granting an
additional two actions. I changed this: state->numActions = state->numActions - 2; to this:
state->numActions = state->numActions + 2;

Adventurer Card: The function was first off reshuffling the deck and disrupting the treasure
count by reshuffling if the player had one card left in the hand. The big bug was the infinite
loop that sometimes came up caused by this loop:
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
        z=z+1;
    }
I changed the last line to z=z-1 to stop incrementing z and break the potential infinite loop.

I then debugged and followed with clean tests and all came back as passing.