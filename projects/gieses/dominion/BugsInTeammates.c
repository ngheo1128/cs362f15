The bugs I found in my teammates code are:

Teammate 1:
1. The first bug I noticed was in your great hall function. When it gets to the point to discard a card, it never increases the discard count. If one was to check the pre discard count and the post discard count, the number would be the exact same. This means that in the discard function, it never actually increases the count.

2. The second bug I found, I noticed it happening in a lot of the different card functions (in particular, the village card function). The hand count is not increasing whenever you try to add cards. Both the village card, and the great hall card adds 1 card to the players hand, however one would not know this when they check the hand count after they are added.
	
Teammate 2:
1. The first bug I noticed was in your great hall function. When it gets to the point to discard a card, it never increases the discard count. If one was to check the pre discard count and the post discard count, the number would be the exact same. This means that in the discard function, it never actually increases the count.

2. The second bug I found was in your smithy card function. It only adds one card to the players hand, instead of 3.