/****************************************************
 * Author:  Brian Stamm
 * Title:  BugFix.c
 * Assignment:  5
 * Date:  11.22.15
 * Notes:  This is in reference to my dominion.c file.
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