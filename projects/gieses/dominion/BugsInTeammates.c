The following bugs I found in my teammates code.

1. In both of their dominion.c files, there was a bug in the discard card count. Everytime the function was called, it wasn't increasing the discard card count.

2. There was also a bug in both where the hand count never gets increased when a function calls it (in particular, the great hall/village functions that my code tested for).

3. In both teammates code, the smithy card increases the hand count, but by the wrong number. In teammate 1's code, it increases the hand by 2, not 3. Similarly, in teammate 2's code, it only increases the hand count by 1, not 3.