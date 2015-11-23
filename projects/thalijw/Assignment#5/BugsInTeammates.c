CS_362_Software Engineering
Assignment #5
thalijw


Report Outline
--------------
	I created two folders DominionteammateJody and DominionteammateBrian, I added their dominion.c and
added my Unittests, cardtests and ramdomtests to it, in each file I added new rule to the MakeFile
to run all the test and produce results in teammate1results.out and teammate2results.out respectively
by runing the command makefile teammate2results.out

*****************************************************************************************************
										Jody Hansen Dominion Bugs
*****************************************************************************************************

Description
-----------
	I tested Jody's dominion.c file with my unittest, cardtest and randomtests. I changed the
MakeFile to have new rule teammate1results.out to output the test reult to it, and i found the 
following bugs.

-----------------------------------------
| Function Tested: Adventurer card      |
| Test Result    : Failed               |
| Number of Bugs : One                  |
| Report Date    : 17-11-2015           |
-----------------------------------------

Expected Test Results
---------------------
	The test initializes the HandCount = 5 cards and the Total Coins = 5 coins, The expected 
outcome is adding two cards (HandCount = 7) and add two coins to total coins (Coins = 7) and
discardedCount = discardedCount + Non-tresure Cards drawn

Acutal Test Results
--------------------
The Adventurer Card did NOT add two card to the player's hand, FAILED
Expected of Player hand Count = 7!
Outcome of Player hand Count = 8!
Total Hand coins before playing the cards (5 Copper = 5 Coins)
Total Hand coins after playing the cards = 8 Coins

The test showed that we added one more card than needed.

Bugs
----
	The bug was Jody changed the conditional loop for drawing the cards from "drawntreasure<2" to 
"drawntreasure<=2" which made the loop exeute one more time than it needed.

-----------------------------------------
| Function Tested: Smithy card          |
| Test Result    : Failed               |
| Number of Bugs : One                  |
| Report Date    : 17-11-2015           |
-----------------------------------------

Description
-----------
	I ran my unit test on Jody's code for the fucntions updateCoins(), scoreFor(), gainCard() and 
fullDeckCount(), all the unit test passed indicating that there is no bugs in these function in
Jody's code.

I ran the card unit test for the Smithy function and the result was all the tests PASSED!

Then I ran the random test unit on the Smithy function and here the test Faild!


Expected Test Results
---------------------
	The unit test Set's tha handCount = 5, after playing the card 3 cards will be added to the 
Players hand and one card will be discarded, So total handCount after playing the card should = 7

Acutal Test Results
-------------------
Running the card test PASSED and gave HandCount = 7!

But running the random test gave the following results:

PreGame and Post number of coins Didn't match, Test FAILED!
PreGame and Post Hand count Didn't match, Test FAILED!
PreGame and Post Deck count Didn't match, Test FAILED!
PreGame and Post Discard count Didn't match, Test FAILED!

Bugs
----
	Jody has changed method of incrementing the i variable used in the conditional loop from 'i++' 
to '++i' !, I believe her intention was to make the loop run one less time than it should be, BUT 
this is not the case of the user for prefix and postfix, in the for loop the result will be identical 
so executing for (i=0; i<3, i++) will loop 3 times and for (i=0; i<3, ++i) will also loop three times.

So the result is even with this change the smithy code does what it should be doing, and that is
the reason why my unit test passed but the random test failed.


*****************************************************************************************************
										Brian Stamm Dominion Bugs
*****************************************************************************************************

Description
-----------
	I tested Brian's dominion.c file with my unittest, cardtest and randomtests. I changed the
MakeFile to have new rule teammate1results.out to output the test reult to it, and i found the 
following bugs.

-----------------------------------------
| Function Tested: Adventurer card      |
| Test Result    : Failed               |
| Number of Bugs : One                  |
| Report Date    : 17-11-2015           |
-----------------------------------------

Expected Test Results
---------------------
	The test initializes the HandCount = 5 cards and the Total Coins = 5 coins, The expected 
outcome is adding two cards (HandCount = 7) and add two coins to total coins (Coins = 7) and
discardedCount = discardedCount + Non-tresure Cards drawn

Acutal Test Results
-------------------
	Playing the card added the correct number of cards and the correct number of cois to the 
player hand but it DID NOT add the correct number of discarded cards to the discard pile

Number of matched games = 0
Number of Not matched games = 1000
Number of matched Handcounts = 1000
Number of matched Deckcounts = 990
Number of matched Discardcounts = 0
Number of matched Coins = 1000

Which shows that we do have matching number of handCounts and number of Coins, but we didn't match
in all the cases with the number of Discardcounts! and that meant that we are not discarding the
correct number of cards after playing the Adventurer. the code responsible for that is the while
loop while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
    z=z-1;
  	}

Bugs
----	
	The bug Brian introcuded was he changed the condition for the loop to be 'z>=0' instead of 'z-1>=0'
which made the number of cards added to the discard pile more than it should be.


-----------------------------------------
| Function Tested: Smithy card          |
| Test Result    : Failed               |
| Number of Bugs : One                  |
| Report Date    : 17-11-2015           |
-----------------------------------------

Expected Test Results
---------------------
	The unit test Sets tha handCount = 5, after playing the card 3 cards will be added to the 
Players hand and one card will be discarded, So total handCount after playing the card should = 7

Acutal Test Results
-------------------
Smithy did NOt add the correct number of cards to the hand, FAILED
Player hand Count before smithy was: 5 Expected to be 7
Player hand Count After smithy is: 8

Asserton failure on (NewHandCount == oldHandCount + 2)

Wich indicate that we are adding one more card that we should in the for loop!, After testing
Brian code.

Bugs
----
	Brian changed the conditional in the for loop to drawcard calls from "i<3" to "i<=3"
which made the loop execute one more time and add one more card than we needed.




