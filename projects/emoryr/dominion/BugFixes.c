/*
Fixed bugs put into code documented in refactor.c

These were in smithy, village, council_room, adventurer.

I also fixed an additional bug pointed out to me by my teammate, I was not previously discarding village
at the end of the village_play function. I had similar problems in other functions.

I also added lines of code to make sure that there were enough treasures in the deck + discard
to fulfill the drawing until you get three treasures feature of adventurer.

I had to add similar lines of code at the beginning of the adventurer_play function to make sure that there were enough cards to draw 3 cards into the players
hand for the smithy function.

*/