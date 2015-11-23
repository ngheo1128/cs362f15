    The first bug that was featured over several test was that the discardcard function
was not discarding the card but adding them to played pile which was never added back in.
to fix this I changed it so they are added to the discard instead of the played pile. The
next few bugs was when the adventurer card not being discarded. To fix this bug I hand the
hand position of the card added the parameters and used it to discard the card with the updated
discardcard function. The bug reported in council room was also fixed with the discardcard function fix.

    The other item of note is that he reported that in his cardtest2.c with test 2 that the adventurer
card was not getting any treasure cards. Looking into his test he is sending it a gamestate with the
current player not having anything in the discard and after seting deckcount to 0. Meaning that the suffle
in the draw card step will add an emtpy discard to whats considered an emtpy deck. This would mean it could
never draw any cards. On a side note the first deck is emtpy check in the adventurer card effect does nothing
it does a proper add discard to deck and shuffle in draw card that makes it look like that if(deckcount < 1) then
shuffle is doing something when it is not. I removed that part of the code and just let the draw card handle the
shuffling.

    I also fixed the bugs I by undoing the changes I made to them which you can read about in the refactor.c.
The only bug he did not find for a methond he had tested was the smithly bug were I drew 4 card and discarded the
second one and the smithy card itself. to give the same effect.
