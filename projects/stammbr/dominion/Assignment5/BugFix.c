/****************************************************
 * Author:  Brian Stamm
 * Title:  BugFix.c
 * Assignment:  5
 * Date:  11.22.15
 * Notes:  This is in reference to my dominion.c file.
 * Also, at the bottom, I detail what I changed in my cardTests
 * so they worked better.
 * **************************************************/
/*
I was informed about 3 bugs from my teammates.  Both teammates found an error in
my smithyMethod.  In this function, the player got an extra card because of how the
for loop was expressed.  In line 1166, it was:

for (i = 0; i <= 3; i++)

Rather than being "<=", it should have been just "<".

******************

One of my teammates found an error in my adventurerMethod, which produces an error
on the amount of discards.  It is in line 1156, which has:

 while(z>=0)

This has been changed to be "z-1".

*******************

Another teammate found an error in my councilMethod.  The error causes a mistake in
the handcount - adding an extra card to the current player and not to the other players.
The error is on line 1202, which said,

if ( i == currentPlayer )

It should say "i != currentPlayer"

********************

Another error I had added was in the feastMethod.  Line 1227 said:

  while( x != 1)

 and it should be "x == 1"
*/

/*******  Fixes in cardTest#  *********
** For all tests, if I had to add components so it could run in my teammates code, I 
made a comment about it **

cardTest1.c - This is the tests for the smithyFunction, and the major error I had in 
this file was the amounts I was testing were completely wrong.  I commented out the
original amounts and the correct amounts are above them.  Also, I deleted out affirmative
confirmations that I had to decrease the size of the .out file.  Also, I commented
out the "random" testing I had later in the file, and this was done because I was trying
to assess what was wrong with my tests originally, and I never uncommented it.  This
was also because it was, in essense, already testing what I had checked.

cardTest2.c - I did comment out the "random" testing, since there was a completely seperate
test for this.

cardTest3.c - First, I swtiched my cardTest3 with cardTest4 (meaning what I originally tested
in 3, I test in 4 and vice versa.  This was due to a mistake - I thought we were only 
suppose to test the cards we had in common.  I fixed this late, and to avoid undoing what I
did, I keep what I had started with.  

Also, I added another component to this test - I created an array which held the
amount of cards the other players had in their hands.  This was to improve my test, and you
can see it in line 68.  I also commented out the random testing for the same reasons as mentioned
in the other tests.

cardTest4.c - The only thing changed in this cardTest was the random testing was commented out.

**************************************/

/************* unitTest#  ************

There was nothing changed with these tests.

*************************************/

/************  RandomTests  **************

There was nothing significant changed in these tests.

*****************************************/