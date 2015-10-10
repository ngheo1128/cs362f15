#ifndef _CARDS_H
#define _CARDS_H
/* cards.h
 * New centralized implementation of Dominion cards.
 * Requires dominion.h to be included first.
 */

#ifndef NUM_CARDS
#define NUM_CARDS (treasure_map + 1)
#endif

 /* cardEffectHandler
 * What is says on the tin. A pointer to a function that handles a card's 
 * effect.
 */
typedef int (*cardEffectHandler)(int, int, int, struct gameState *, int, int *);

/* struct cardData
 * Contains relevant data for cards.
 */
struct cardData {
  int cost;
  cardEffectHandler effectHandler;
};

/* initializeCardData
 * Generates data for Dominion cards.
 */
void initializeCardData(struct cardData (*data)[NUM_CARDS]);

extern struct cardData cardsData[NUM_CARDS];
#endif