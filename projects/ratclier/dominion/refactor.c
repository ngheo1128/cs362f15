Changes to Dominion card code
----------------------------------------------------------

10/9/2015:

In dominion.c:

- Moved code for Smithy, Adventurer, Treasure Map, Feast, and Mine cards
  out of switch statement in cardEffect() and into their own functions.
  These functions are called from cardEffect()'s switch statement. 

- drawntreasure, cardDrawn, z, x, and temphand[] have been moved from
  cardEffect() to the functions for the cards mentioned in the previous
  bullet. They are not used elsewhere in cardEffect().


In dominion.h:

- Added function declarations for smithyCard(), adventurerCard(), treasureMapCard(),
  feastCard(), and mineCard().


10/10/2015:

In dominion.c:

- In smithyCard(), changed the trashFlag in the call to discardCard() from
  0 to 1 (sets the card as trashed). (BUG)

- In adventureCard(), changed the cardDrawn assignment to not place drawn
  card at the end of the hand. (BUG)

- In treasureMapCard(), changed the code that trashes both treasure cards
  to no longer trash them (trashFlag changed from 1 to -1). (BUG)

- In feastCard(), after gainCard(), removed the line that would set x = 0
  to signal the end of card buying. (BUG)


10/25/2015:

In dominion.c:

- In feastCard(), removed the infinite loop that resulted from the code
  change from 10/10/2015. Noting the bug would require MANUAL testing, not
  automated testing. Instead, I set the gainCard() call just above x=0 to
  put the gained card in the player's hand instead of the discard pile.
  (So there's still a BUG)


11/19/2015:

In randomtestcard.c:

- Fixed a bug where discarded treasure map cards was not detected
  correctly.
- Changed if/if statements to if/else/if statements for checking top gold
  cards (forgot the else).

In cardtest1.c, cardtest3.c, and cardtest4.c (unit tests):

- Correctly set the current player (was not done at all before) by setting
  state->whoseTurn to currentPlayer in the card test function.

In cardtest3.c:

- Added code to force ONLY one treasure map card or ONLY two treasure map
  cards. Code to do this was lifted from randomtestcard.c.

In unittest2.c:

- Changed if statement after running gainCard() to read the supply count
  of the requested card instead of the return value of gainCard(). I am
  not sure why I checked gainCard()'s return value in the first place, it
  does not reveal anything about card supplies. 

In dominion.c:

- Changed discardCard() to add card to discard pile and increment
  discardCount for the current user. Previously the function only added to
  the (seemingly useless) playedCards[] array. When a card is discarded,
  it's supposed to go to the discard pile at a minimum.


11/20/2015:

In unittest1.c:

- Changed all tests for played card piles and counts to discard piles and
  counts. Played cards have little/no bearing on discarded card handling
  in Dominion so it does not make sense to test against them.  Discarded
  card test results make a lot more sense now.

