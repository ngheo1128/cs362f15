/*
 * Solved improper discard issue: Added discardCount increment and card addition to discard pile within discardCard() function. Solved discard problem in all card functions.
 *
 *Adjusted getWinners() to register 1st player in when assessing for winners (1st player can now win games)
 *
 *adventurerEffect() changed <= to < in draw loop so that only 2 cards are drawn, as opposed to 3.
 *
 *salvagerEffect() added discardCard(choice1) in order to discard targeted card when salvager is played.
 *
 *smithyEffect() changed handpos+1 to handpos within smithyEffect so that proper card is discarded when played.
 *
 *scoreFor() changed i<discardCount to i<deckCount within third for loop in order to properly iterate through cards in deck. This corrected Discard and Deck scoring and changed deckCount() 
 *function to return deckCount+discardCount+handCount rather than iterating through all cards in each.
 *
 */
