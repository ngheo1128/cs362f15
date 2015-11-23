Drew Machowciz
ONID: machowid, github dmachowi

Total bugs found: 2
+++++++++++++++++++++++Partner 1+++++++++++++++++++++++
cardtest1 and cardtest3 were not used against partners code as they didn't match the
cards he introduced bugs to.

cardtest2 results (adventurer card):
I actually found more bugs in my test code than I did in my partner's code. I was able
to find a bug he introduced where he incremented the handCount instead of decrementing 
the handCount. In the end I changed my code so the test actually tested correctly. The
number of treasures before and after are what they should be, however it seems that the
adventurer card is NOT being discarded as it should be. There should be a net gain of 1
for the hand, but there is two. Also, I ran a loop to check there is no adventurer card in
the hand and it is still there.

cardtest4 results (smithy card):
After running my test I saw that the handcount was wrong, so I looked at the dominion.c
file of the partner and saw the loop condition says i<=3 but actually it should be i < 3.
I also removed one part of my test that I realized I didn't need to check when playing 
the smithy card. This allowed all tests to pass after fixing the bug. 

randomTestCard (smithy card):
I again found bugs in my test code, but after fixing them the smithy card tests all passed
as I had already fixed the bug in the dominion.c file.

randomTestAdventurer (adventurer card):
I was getting a segfault when I ran this for the first time, so I checked the same problem
I had before when I was writing it. That was I added an if statement in the adventurer card
function in dominion.c where it breaks if z becomes larger than MAX_HAND which is 500. I had
the problem where the loop was running until segfault because and the temphand array was much
larger than it should be. With this conditional statement I capped it at MAX_HAND and then the
test ran with no problems, however I noticed there were some problems with my test. As I had
already found the bugs with the cardtest I decided not to spend the time fixing it for now.
**Update
After finishing this assignment I read on piazza that we cannot change our partner's dominon code,
only our own tests that we wrote. My cardtest1 found the bugs with or having changed my partner's code.
However the randomTestAdventurer will segfault without the small code change. This does not really
matter as it is buggy anyways.

+++++++++++++++++++++++Partner 2+++++++++++++++++++++++

cardtest2 results (adventurer card):
I ran the newer fixed code against the second partner's code. That is, everything passes
except it seems that the adventurer card is still in the hand at the end of the turn. It
seemed that there no bugs in the code, so I checked the refactor.c file and saw that the bugs
had already been fixed.

cardtest4 results (smithy card):
As with the previous test, I ran the newer fixed version against the second partner's code
and got the same results. The test passed and the bug listed in the refactor.c file has
already been fixed.

cardtest3 results (council room card):
This card had no bugs added to it by my partnet, but my own test was buggy, so some of the
tests in my test passed and some failed. This is not a bug in the dominion code. 

randomTestCard (smithy card):
All tests passed as the bug has already been fixed.

randomTestAdventurer (adventurer card):
As with partner 1, I added a break to the dominon.c code to prevent the segfault from happening.
Also, the results of this test are the same as the test for partner 1.

**Update
After speaking with my teammmate he gave me a copy of his buggy dominion.c code to run my tests
against. The tests for the smithy card passed just like before as there were no bugs. The
randomTestAdventurer test ran without adding any additional code, which seemed odd to me as
previous runs would segfault. I then checked again the results from cardtest2 which also 
tests the adventurer card. I saw it was failing some tests so I took a look at the code. 
It was saying the number of treasure cards is incorrect and the Adventurer card was not 
discarded. One thing I noticed quicky was that there were brackets missing in the first 
while loop of the playAdventurer function. Then I studied the loop more carefully
to find the problem about the treasure cards being incorrect. I then noticed that the
while loop had switched the logic running the loop. It should be while(treasureCards < 2)
but it was changed to while(treasureCards > 2) which means the loop would never run.
However, because of the missing brackets, it was running one time. I fixed those two bugs
and then reran the tests. After running the test again the treasure card number was correct,
but I still had the same problem as with teammate1 where the adventurer card is still in the
hand.