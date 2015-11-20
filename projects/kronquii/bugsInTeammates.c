PoorJ
=====

By running my tests against your code I was able to find a total of 6 bugs.

1. smithyEffect: You set the trashflag.
2. remodelEffect: You forgot to return 0 at the end of the funciton.
3. gardensEffect: You added some silly extra logic.
4. adventurerEffect: You introduced two bugs. First, you did not initialize z
   to zero, which caused all sorts of segfaults, thank you very much. Second,
   you didn't chekc whether the card drawn was a silver card.
5. villageEffect: You used += instead of = when setting the number of actions.

Of course the adventurer still gets caught in that annoying infinite loop.

Omitting a return value and "forgetting" to initialize z were both especially
insidious.


GuerraJ
=======
