In function adventurerF() added discardCard and added an argument that shows the index of the adventurer being played.
This will allow the card to be discarded.
Also in function adventurerF() the gamestate numActions variable is decremented, and cardsPlayedCount is incremented.

In function villageF() fixed the draw 2 +1 action to draw 1 +2 actions.
In function villageF() fixed the discardCard flag, so the card is discarded and not trashed.

In function smithyF() fixed the discardCard flag, so the card is discarded and not trashed.

In function council_roomF() fixed the discardCard flag, so the card is discarded and not trashed.

In function feast() fixed infinite loop when attempthing to purchase an invalid card.

In randomCardTest fixed an error in logic where discardCard was not taken into account.