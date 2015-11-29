/*Bugs found in teammates Dominion Code
**Wilson Chan
**CS362 Assignment 5


**Tests**
Unit Tests: isGameOver(), updateCoins(), scoreFor(), getCost()
Card Tests: Smithy, Adventurer, Village, Council Room
Random Tests: Adventurer, Smithy

**Bugs Found**

Teammate1: Rachael McConnell

isGameOver()
-Treasure map card stack is empty but did not count as one of three empty stacks to end the game.

scoreFor()
-Victory cards in deck are calculated incorrectly.

Smithy Card
-Two cards instead of three were drawn from deck to the hand.
-Discard count not updated correctly after card was played.

Adventurer Card
-Card is not discarded from hand after it was played.
-Discard count not updated correctly after card was played.

Village Card
-Discard count not updated correctly after card was played. Count was not incremented by 1.


Teammate2: Jeff Moss

isGameOver()
-Treasure map card stack is empty but did not count as one of three empty stacks to end the game.

scoreFor()
-Victory cards in deck are calculated incorrectly.

Smithy Card
-Four cards instread of three were drawn from deck to the hand.
-Discard count not updated correctly after card was played. Count was not incremented by 1.

Adventurer Card
-Card is not discarded from hand after it was played.
-Discard count not updated correctly after card was played.

Village Card
-Discard count not updated correctly after card was played. Count was not incremented by 1.

Council Room Card
-Discard count not updated correctly after card was played. Count was not incremented by 1.

*/