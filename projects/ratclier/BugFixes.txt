dominion.c:

- Changed trash flag from 1 to 0 in arguments to smithyCard(). When set to 1,
  the discarded card was trashed instead of being added to the played pile.

- Changed trash flag from -1 to 1 in arguments to discardCard() in
  treasureMapCard() function. The two Treasure Map cards are supposed to be
  trashed when played, but instead they were going to the played pile.

- Changed the toFlag in the arguments to gainCard() in feastCard() to send new
  cards to discard (0). Was previously set to add cards to player's hand (2),
  which is incorrect.

- Changed cardDrawn assignment in adventurerCard() to add cards to the end of
  the hand. Was previously set to add cards past the end of the hand.

- Changed discardCard() to add card to discard pile, not just the played card
  pile (what does the played card pile even do?). Cards were not registering
  as being discarded before, but now they are (assuming the card code calls
  discardCard() in some way, that is).
