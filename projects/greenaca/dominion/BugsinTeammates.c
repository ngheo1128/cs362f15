In the directory teammate1Dominion, I found a few bugs.

1. There is a bug in smithyCard() 
When I ran my cardtest1, I found that the following tests failed, checking
handCount, discardCount, and deckCount.

I believe it is because the for loop, that gives the player three new cards,
starts at 1 instead of 0.  But then the for loop only goes until <2. Which means 
it only adds one new card to the hand, not three.  Also, discardCount = 0, when it 
should be 1, since the smithy card should have been discarded.  This is because 
in the dominion.c code the count for the discarded cards never increases.  Then 
deckCount = 5, when it should be 2 because the for loop only added one new card. 
Therefore there are more cards that are actually in the deck than there should be.

2. There is a bug in villageCard()
When I ran my cardtest3, I found that the following tests failed, checking
discardCount and deckCount. 

For the first step, it doesn't draw two cards, it draws one, increases the
number of actions and discards a card. DeckCount will always be one
more than it should be since it only draws one card, instead of 2.
DiscardCount should be one but since the code is broken it doesn't 
increment discardCount, so it says zero.

In the directory teammate2Dominion, I found a few bugs.

1. There is a bug in smithyCard() 
When I ran my cardtest1, I found that the following tests failed, checking
handCount, discardCount, and deckCount.

I believe it is because the for loop, that gives the player three new cards,
starts at 1 instead of 0.  There for it only adds two new cards to the hand,
rather than three.  Also, discardCount = 0, when it should be 1, since the
smithy card should have been discarded.  This is because in the dominion.c code
the count for the discarded cards never increases.  Then deckCount = 3, when 
it should be 2 because the for loop only added two new cards, rather than 3.
Therefore there is one more card that is actually in the deck than there
should be.

2. There is a bug in villageCard()
When I ran my cardtest3, I found that the following tests failed, checking
handCount, discardCount and deckCount. 

For the first step, it doesn't draw two cards, it draws one, increases the
number of actions and then draws another card and discards a card.  The 
handCount is always one more, than it should be, deckCount is always one
less than it should be, and discardCount should be one but since the code
is broken it doesn't increment discardCount, so it says zero.

