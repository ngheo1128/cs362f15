/* Utilities for random testing. */
#include "dominion.h"
#include <string.h>

/* all-cards oracle 

reqs:
- check 
*/

/* copyCards
preconditions:
- stateCopy points to an allocate gameState struct
*/
void copyCards(const struct gameState *realState, 
               struct gameState *stateCopy) {
    // copy hand, deck, discard
    memcpy(realState, stateCopy, sizeof(struct gameState));
}

void sortCards(struct gameState *state) {
    // sort hand, deck, discard
}

/*
preconditions:
- before and after have their cards sorted

return: 0 if after matches before given the changes
*/
int checkCards(const struct gameState *before, 
                const struct gameState *after,
                int numAdded, enum CARD *cardsAdded,
                int numRemoved, enum CARD *cardsRemoved) {

}