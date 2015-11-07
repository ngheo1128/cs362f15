I feel that one of the greatest advantages of this assignment was looking over the solution to assignment three and while doing so thinking in terms of this assignment.  Initially going into assignment three was somewhat difficult as I had learn about what I was supposed to do but I had yet to implement any type of solution.  We did have some examples but to see the solution to assignment three it was evident to me that a test need not be large or overly complex in order to be effective.  The solution was very succinct and efficient.  I did my best to follow suit in this assignment and follow the ‘pattern’ so to speak that I saw in the solution to assignment three.

A big lesson that took me a lot of time to learn was that I did not have to set up every scenario in order to know the values that I should be comparing against.  If a game is initialized into a ‘sane’ state then the state could be captured piece by piece (only the pieces that needed to be captured in order to be compared later.  In other word the relevant pieces), saved off, and then used later in comparisons in the assert statements.

However, randomizing the state of the game into a ‘sane’ but yet ‘random’ stated proved to be the hardest part of the task for me.  It took a lot of ‘refining the fuzzer’ to gain a state with reasonable randomness and also expected values.  There was a lot of guessing and googling with a healthy dose of experiencing a lot of segmentation faults.  However, once this was accomplished the rest was straight forward.  I felt that I had moved out of the ‘how to test’ and into ‘the what to test’.  For me the former was much more difficult than the latter. 

One simple move that increased my test coverage was to simply extract the capturing and asserting pieces into a separate function that was called from within main().  I know that this does not sound like much, but it really helped me draw the line between what I was initializing and setting up verses the state that I wanted to capture and assert later.  For me this was the big lesson on separation of concerns.  Not only that but it helped with the reading and flow of the code.  When they were together in main it seemed so grey, and at times I lost focus of what I was doing precociously.  I would catch myself thinking, ‘now… am I setting up here, capturing or comparing… what makes the most sense.’  Well, what made the most sense was to implement a degree of separation of concerns, and I most readily did this by extracting the capturing and asserting pieces away from the initialization piece into a separate function.  This was a very good move for the way that I was thinking about this random set of tests.

All in all this was a very effective learning exercise that has more solidly driven home the principles of effective, useful, and meaningful testing for me.