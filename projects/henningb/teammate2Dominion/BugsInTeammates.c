Ben Henning
CS 362
Assignment 5
BugsInTeammates.c

Bugs found in teammate 2's (Drew Machowicz) code:


Smithy card:
1. Player's hand has 1 more card than it should, and player's deck is missing one more card
than it should, indicating 4 cards are being drawn instead of 3.
2. Smithy card disappears from hand but doesn't show up in playedCards, indicating it is
being trashed instead of discarded.

Adventurer card:
1. Adventurer remains in hand and is not being discarded
2. Two cards are always added to the player's hand but they are not always treasure cards.
Random testing shows that most frequently 0 of the 2 cards are treasure cards and that occasionally
1 of the 2 cards is a treasure card.  It seems the function is just adding the top two card from
the deck to the player's hand regardless of whether or not they are treasure cards.

Sea_Hag card:
1. Sea_hag is not discarded
2. CardEffect sea_hag case decrements non-calling players' deck counts by 3
3. Top card of non-calling players' decks is not a curse card




