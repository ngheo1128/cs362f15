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

By running my tests against your code I was able to find a total of 6 bugs.

1. callSmithyCard: The loop counter i was initialized to 1, not 0.
2. callCouncilRoom: Condition was backwards, greater than sign should have been less than.
3. callGreatHall: Remember to add one action.
4. callAdventureCard: The amount of treasure drawn should be 2, not 4. If the deck is empty, the discard pile needs to be reshuffled.
5. callVillageCard: Only draw one card.

Setting to loop counter to 1 was a bit annoying.
