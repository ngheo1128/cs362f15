Bug fix 1:
Found by teammate: Yes
Introduced in assignment 2: Yes

Bug in smithyEffect() that resulted in two cards being drawn
instead of 3. Changed the loop iterator within smithyEffect()
so that 3 calls to drawCard are made.


Bug fix 2:
Found by teammate: Yes
Introduced in assignment 2: Yes

Bug in adventurerEffect() that resulted in the card not
being discarded due to the hand position being incorrectly
update within the function.  Re-added the line to update
hand position.


Bug fix 3:
Found by teammate: No 
Introduced in assignment 2: Yes

Bug in mineEffect() that resulted in a mine card being
removed from the deck and not the player's hand.  Fixed
mineEffect() so it correctly searches the player's hand
for the card and not the deck.


Bug fix 4:
Found by teammate: No
Introduced in assignment 2: Yes

Bug in villageEffect() that resulted in the two chosen
cards from option 3 not being trashed.  Re-added the trash
flag to the discardCard() calls within the function.