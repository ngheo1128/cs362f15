/* -----------------------------------------------------------------------
*
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int checkDiscardCard(int handPos, int player, struct gameState* state,int handCount, int discardedCard){
  int errFlag=0; //used in place of assertion failure: test passed=0; assertion failure=1
  int r = discardCard(handPos,player,state,0);
  assert(r==0);
  //check handCount
  if(state->handCount[player] != (handCount-1)){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif
  }
  //assert(state->handCount[player] == (handCount-1));
  //check discard pile for the card discarded
  if(state->discardCount[player] != 1){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif
  }

  if(state->discard[player][(state->discardCount[player])-1] != discardedCard){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, discardedCard=%d, expected=%d\n", state->discard[player][(state->discardCount[player])-1], discardedCard);
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS, discardedCard=%d, expected=%d\n",state->discard[player][(state->discardCount[player])-1] , discardedCard);
#endif
  }
  //assert(state->discard[player][(state->discardCount[player])-1] == discardedCard);
  
  return errFlag;
}


int main() {
  int i,p,r;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine
    , remodel, smithy, outpost, salvager, sea_hag};
  struct gameState G;
  int estates[MAX_HAND];
  int golds[MAX_HAND];
  int errFlag=0;
  int supplyPos, toFlag, gain;
  
  for (i = 0; i < MAX_HAND; i++){
    estates[i] = estate;
  }
  
  for (i = 0; i < MAX_HAND; i++){
    golds[i] = gold;
  }
  
  printf ("TESTING gainCard():\n");
	
	for (p = 0; p < numPlayers; p++){
		for(supplyPos = curse; supplyPos <= treasure_map; supplyPos++){
      for(toFlag = 0; toFlag <= 2; toFlag++){
        printf("Testing player %d, supply card %d with gain card flag of %d:\n", p, supplyPos, toFlag);
        memset(&G, 23, sizeof(struct gameState));   // clear game state
        r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
        gain = gainCard(supplyPos,&G,toFlag,p);
        if(supplyPos != curse && supplyPos != estate && supplyPos != duchy &&  supplyPos != province 
          && supplyPos != copper && supplyPos !=silver && supplyPos != gold && supplyPos != adventurer 
          && supplyPos != council_room && supplyPos != feast && supplyPos != gardens && supplyPos != mine 
          && supplyPos != remodel && supplyPos != smithy && supplyPos != outpost && supplyPos != salvager
          && supplyPos != sea_hag){
            if(gain != -1){
              printf("  gainCard(): FAIL, gain=%d, expected=%d\n", gain, -1);
              errFlag++;
            }else{
              printf("  gainCard(): PASS, gain=%d, expected=%d\n", gain, -1);
            }
        } else{
          if(gain != 0){
            printf("  gainCard(): FAIL, gain=%d, expected=%d\n", gain, 0);
            errFlag++;
          }else{
            printf("  gainCard(): PASS, gain=%d, expected=%d\n", gain, 0);
          }
        }
      }
    }
  }
  
  if(errFlag != 0){
    printf("Some tests failed.\n");
  } else {
    printf("All tests passed!\n");
  }

  return 0;
}