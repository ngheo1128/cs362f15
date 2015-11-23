/*

Bugs Fixed:

Corrected bugs in smithyEffect() that were causing hand count to increase
by 4 cards instead of 3 cards and decreasing deck count by 4 cards
instead of 3 cards.

These two bugs were fixed by changing line 1235 from
  for (i = 0; i <= 3; i++)
to
  for (i = 0; i < 3; i++)
so that only 3 loop iterations were performed rather than 4.

-------------------------

Fixed bug in adventurerEffect() that was causing false positives when testing
for treasure cards.

Changed line 1215 from
  if (cardDrawn = copper || cardDrawn == silver || cardDrawn == gold)
to
  if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
so that the condition was not always true and resetting the value of cardDrawn.

*/