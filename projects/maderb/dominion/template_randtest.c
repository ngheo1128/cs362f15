#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#include"dominion.h"

int CardGen(int reference);
int checkResult(struct gameState currState);
int stringConverter(char* strConverted);

int main(int argc, char** argv){
	srand(time(NULL));

	struct gameState currState;
	int densityAdj;
	int i, j, k, executionNum, selector, adventurerNum;

	executionNum = 1000;

	for(k=0; k<executionNum ; k++){
		currState.numPlayers = (rand()%3) + 2; 				//2<=player number <=4
		currState.playedCardCount=0;		

		//stock decks for all players with randomized card number from 2 -> MAX_DECK.
		for(j=0;j<currState.numPlayers;j++){
			currState.discardCount[j] = 0;				//set discard count to 1;
			currState.discard[j][0]=gold;					//set one discarded card to treasure. If top card in discard not treasure card, discard shuffled into deck.
			currState.deckCount[j] = (rand()%(MAX_DECK-1))+2;	//2 <= decksize <= MAX_DECK
			densityAdj = (rand()%30) + 3;				//10% < treasure density < 100%
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.deckCount[j];i++){
				selector = rand() % densityAdj;
				currState.deck[j][i] = CardGen(selector);		
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
		}
		//stock hands with randomized card number from 1 - MAX_HAND.
		for(j=0;j<currState.numPlayers;j++){
			currState.handCount[j] = (rand()%(MAX_HAND-1))+2;	//1 <= handsize <= MAX_HAND
			densityAdj = (rand()%30) + 3;				//10% <= treasure density <= 100%
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.handCount[j];i++){
				selector = rand() % densityAdj;
				currState.hand[j][i] = CardGen(selector);
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
			adventurerNum = rand() % (currState.handCount[j]+1);	//introduce between 0 and handCount adventurer cards
			for(i=0;i<adventurerNum;i++){
				currState.hand[j][(rand() % currState.handCount[j])]=adventurer;	//randomly place 'adventurerNum' adventurer cards in hand. Allows overwrite.
			}
		}
		
		//decks/hands/discard all stocked. Deploy the Adventurers!
		
	}

	return 0;
}

int CardGen(int reference){
	switch(reference){
		case 0:
			return gold;
		case 1:
			return silver;
		case 2:
			return copper;
	}
	return village;
}

int checkResult(struct gameState currState){
	return 0;
}

int stringConverter(char* strConverted){
	int val=0;
	int i;

	for(i=0;isdigit(strConverted[i]);i++){
		val*=10;
		val += (strConverted[i]-'0');
	}

	return val;
} 
