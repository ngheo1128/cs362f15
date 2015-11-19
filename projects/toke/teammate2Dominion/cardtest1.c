//############################################################
// Filename: cardtest1.c
// Unit Test Objective: Tests the executeSmithyCard method
//                      in dominion.c. This validates the
//                      behavior for the smithy card.
//############################################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define NOISY_TEST 1

void TestThatPlayerHas3MoreCardsInTheirHand();
void TestThatPlayerGot3CardsFromTheirDeck();
void TestThatPlayerGot3CardsAddedToTheirHandOnly();
void TestAmountOfCoinsInSupplyDidNotChange();
void TestAmountOfVictoryCardsInSupplyDidNotChange();
void initializeStartGameDeck(struct gameState *state);

int main () {
	printf ("Card Testing: Smithy Card.\n");

	// Check that player 0 has 3 more cards in his hands now
	TestThatPlayerHas3MoreCardsInTheirHand();

	// Check that the cards drawn from the smithy action were drawn
	//  from the player's own deck
	TestThatPlayerGot3CardsFromTheirDeck();

	// Check that the cards were added the current players hand only
	TestThatPlayerGot3CardsAddedToTheirHandOnly();

	// Check that the coin supply did not change
	TestAmountOfCoinsInSupplyDidNotChange();

	TestAmountOfVictoryCardsInSupplyDidNotChange();

	return 0;
}

void TestThatPlayerHas3MoreCardsInTheirHand()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;

	// Check that player 1 has 3 more cards in his hands now
	printf("Testing...Player 1 has 2 more cards in his hand after smithy is played. (3 new cards minus 1 discarded smithy card)\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	int preHandCount = G.handCount[player1];
	int handpos = 0;
	G.hand[player1][handpos] = smithy;
	smithyfunction(&G, player1, handpos);
	int postHandCount = G.handCount[player1];
	if (postHandCount != preHandCount + 2)
	{
		printf("Test Failed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}
	else
	{
		printf("Test Passed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}
}

void TestThatPlayerGot3CardsFromTheirDeck()
{
	printf("Testing...Player 1 got three cards from his deck.\n");
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };
	struct gameState G;
	int handpos = 0;
	int player1 = 0;
	int player2 = 1;

	// Check that the cards drawn from the smithy action were drawn
	//  from the player 1's own deck
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);
	int preDeckCount = G.deckCount[player1];
	int preHandCount = G.handCount[player1];
	int firstCardToBeRemovedFromDeck = G.deck[player1][preDeckCount - 1];
	int secondCardToBeRemovedFromDeck = G.deck[player1][preDeckCount - 2];
	int thirdCardToBeRemovedFromDeck = G.deck[player1][preDeckCount - 3];
	// printf("first card removed from deck: %d\n", firstCardToBeRemovedFromDeck);
	// printf("second card removed from deck: %d\n", secondCardToBeRemovedFromDeck);
	// printf("third card removed from deck: %d\n", thirdCardToBeRemovedFromDeck);
	int prePlayer2DeckCount = G.deckCount[player2];

	smithyfunction(&G, player1, handpos);

	int postHandCount = G.handCount[player1];
	int firstCardToBeAddedToHand = G.hand[player1][postHandCount - 2];
	int secondCardToBeAddedToHand = G.hand[player1][postHandCount - 1];
	int thirdCardToBeAddedToHand = G.hand[player1][0]; // Card is added to the beginning because the smithy card is discarded

	// printf("postHandCount: %d\n", postHandCount);
	// int i;
	// for (i = 0; i < postHandCount; ++i)
	// {
	// 	printf("post hand: %d\n", G.hand[player1][i]);
	// }
	// printf("firstCardToBeAddedToHand: %d\n", firstCardToBeAddedToHand);
	// printf("secondCardToBeAddedToHand: %d\n", secondCardToBeAddedToHand);
	// printf("thirdCardToBeAddedToHand: %d\n", thirdCardToBeAddedToHand);
	int postPlayer2DeckCount = G.deckCount[player2];

	// Check player 1's deck counts
	int postDeckCount = G.deckCount[player1];
	if (postDeckCount != preDeckCount - 3)
	{
		printf("Test Failed: Expected deckCount was %d. Actual deckCount was %d.\n", preDeckCount - 3, postDeckCount);
	}
	else
	{
		printf("Test Passed: Expected deckCount was %d. Actual deckCount was %d.\n", preDeckCount - 3, postDeckCount);
	}

	// Check the types of card added to player 1's hand
	if ((firstCardToBeRemovedFromDeck != firstCardToBeAddedToHand)
	        || (secondCardToBeRemovedFromDeck != secondCardToBeAddedToHand)
	        || (thirdCardToBeRemovedFromDeck != thirdCardToBeAddedToHand))
	{
		printf("Test Failed: Cards removed from deck did not match card added to hand.\n");
	}
	else
	{
		printf("Test Passed: Cards removed from deck did matched card added to hand.\n");
	}

	// Check that no cards were taken from player 2's deck
	if (prePlayer2DeckCount != postPlayer2DeckCount)
	{
		printf("Test Failed: Cards were removed from player 2's deck.\n");
	}
	else
	{
		printf("Test Passed: Cards were not removed from player 2's deck.\n");
	}
}

void TestThatPlayerGot3CardsAddedToTheirHandOnly()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	int player2 = 1;

	// We are executing the smithy card for player 1. We already validated that they
	// got the 3 extra cards in their in a previous test. This test is to test that
	// player 2's hand was not affected.
	printf("Testing...Player 2 did not have their hand affected if player 1 played the smithy card.\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	int prePlayer2HandCount = G.handCount[player2];
	int handpos = 0;
	// executeSmithyCard(player1, &G, handpos);
	smithyfunction(&G, player1, handpos);

	int postPlayer2HandCount = G.handCount[player2];
	if (postPlayer2HandCount != prePlayer2HandCount)
	{
		printf("Test Failed: Player 2's hand was affected by player 1's smithy card.\n");
	}
	else
	{
		printf("Test Passed: Player 2's hand was not affected by player 1's smithy card.\n");
	}
}

void TestAmountOfCoinsInSupplyDidNotChange()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int handpos = 0;
	int player1 = 0;

	printf("Testing...The amount of coins in the coin supply did not change.\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	int preCopper = G.supplyCount[copper];
	int preSilver = G.supplyCount[silver];
	int preGold = G.supplyCount[gold];
	// executeSmithyCard(player1, &G, handpos);
	smithyfunction(&G, player1, handpos);

	int postCopper = G.supplyCount[copper];
	int postSilver = G.supplyCount[silver];
	int postGold = G.supplyCount[gold];
	if ((postCopper != preCopper)
	        || (postSilver != preSilver)
	        || (postGold != preGold))
	{
		printf("Test Failed: The amount of coins in the supply changed.\n");
	}
	else
	{
		printf("Test Passed: The amount of coins in the supply is unchanged.\n");
	}
}

void TestAmountOfVictoryCardsInSupplyDidNotChange()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int handpos = 0;
	int player1 = 0;

	printf("Testing...The amount of victory cards supply did not change.\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	int preEstate = G.supplyCount[estate];
	int preDuchy = G.supplyCount[duchy];
	int preProvince = G.supplyCount[province];
	// executeSmithyCard(player1, &G, handpos);
	smithyfunction(&G, player1, handpos);

	int postEstate = G.supplyCount[estate];
	int postDuchy = G.supplyCount[duchy];
	int postProvince = G.supplyCount[province];
	if ((postEstate != preEstate)
	        || (postDuchy != preDuchy)
	        || (postProvince != preProvince))
	{
		printf("Test Failed: The amount of victory cards in the supply changed.\n");
	}
	else
	{
		printf("Test Passed: The amount of victory cards in the supply is unchanged.\n");
	}
}

void initializeStartGameDeck(struct gameState *state)
{
	int i, j;
	for (i = 0; i < 2; ++i)
	{
		state->deckCount[i] = 0;
		for (j = 0; j < 3; j++)
		{
			state->deck[i][j] = estate;
			state->deckCount[i]++;
		}
		for (j = 3; j < 10; j++)
		{
			state->deck[i][j] = copper;
			state->deckCount[i]++;
		}
	}

}
