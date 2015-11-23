/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing UpdateCoins()
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define assert_msg(x) for ( ; !(x) ; assert(x) )
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int maxHandCount = 499;
	// arrays of all coppers, silvers, and golds
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("\nTESTING updateCoins():\n");
	for (p = 0; p < numPlayer; p++)
	{
		for (handCount = 1; handCount <= maxHandCount; handCount++)
		{
			for (bonus = 0; bonus <= maxBonus; bonus++)
			{
#if (NOISY_TEST == 1)
				printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on hand

				memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
				updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
				printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif
				assert_msg(G.coins == handCount * 1 + bonus) // check if the number of coins is correct.
				{
					printf("ASSERTION 'G.coins == handCount * 1 + bonus' FAILED: "
						"File: %s, Line: %d, Iteration: p = %d, handCount %d, bonus %d\n",
						__FILE__, __LINE__ - 2, p, handCount, bonus); //Failure Message
				}

				memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
				updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
				printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
				assert_msg(G.coins == handCount * 2 + bonus) // check if the number of coins is correct.
				{
					printf("ASSERTION 'G.coins == handCount * 2 + bonus' FAILED: "
						"File: %s, Line: %d, Iteration: p = %d, handCount %d, bonus %d\n", 
						__FILE__, __LINE__ - 2, p, handCount, bonus); //Failure Message
				}

				memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
				updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
				printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
				assert_msg(G.coins == handCount * 3 + bonus) // check if the number of coins is correct.
				{ 
					printf("ASSERTION 'G.coins == handCount * 3 + bonus' FAILED: "
						"File: %s, Line: %d, Iteration: p = %d, handCount %d, bonus %d\n",
						__FILE__, __LINE__ - 2, p, handCount, bonus); //Failure Message
				}
			}
		}
	}

	printf("All tests passed!\n");

	return 0;
}