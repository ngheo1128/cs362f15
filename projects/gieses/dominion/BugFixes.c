The bugs my teammates found in my code were:

1. My handCount wasn't increasing correctly
	-I fixed this by fixing the bugs I added in adventurer, smithy, great hall and village card. They all added the wrong amount of cards, and therefor the hand count was always off.
2. My discardCount wasn't increasing correctly
	-Went in to the discard card function and made sure it was increasing the count
3. My smithy card wasn't adding the correct amount of cards (only adding 1 card, not 3)
	-I changed this by changing the for loop back to starting at 0, and going up to 3
5. My adventurer card while loop draws 3 treasure cards instead of 2
	-Fixed this by changing the while loop back to 2 instead of 3