Brian Lamere
CS362 Fall 2015
Assignment 5
11-20-2015

Bug Fixes:

1. discardCard(): never properly discards trashed cards. So this was the first bug I fixed, before anything else. It had been bothering me for awhile that that function only worked properly if the trashFlag was not set, especially considering that setting the trashFlag was one of the bugs I introduced. It's funny that a function called discardCard() doesn't even touch the discard[] array.

2. playSmithyCard(): issue with discarding. Both my teammates picked up on this, though one was able to state more specifically that the smithy card never ends up in the playedCards[] array. Which didn't happen, because I had set the trashFlag in discardCard(). 

Side note about this bug: I ended up adapting my random unit tester for the adventurer card so that it would work with the smithy card in order to check that this bug was fixed, because I was so displeased with the original unit tests that I wrote. I can't remember if I stated this in an earlier report or in an email thread to my teammates, but when I started working on that first assignment where we had to write 8 unit tests (4 for functions and 4 for cards), I had had absolutely no experience writing any, so I didn't really feel like I had a good reference point. And 8 was an overwhelming number to begin with for a rank beginner, so it felt like a mad dash to finish, never mind to finish with accuracy. Thus, I don't feel as if they work so well at illuminating anything more than the most glaring of errors. With the random-tester assignment, however, I felt like I learned from my mistakes and was able to factorize some things (like the printState() function that prints the relevant variables from the gameState structure, making the process much more streamlined and adaptable. Unfortunately, I'd only written 2 of these random testers. 

3. playAdventurerCard(): The bug I introduced here was subtle: I replaced 'silver' with 'smithy' as one of the 3 cards that is kept when drawing cards in search of 3 treasure cards. Susan's test suite was able to determine that, for some cases, the correct amount of treasure cards was not added to the player's hand, and Erik's test suite showed that sometimes the test passed and sometimes it failed, but I think that he incorrectly made the deduction that it failed for small deck sizes, when in fact is failing whenever a 'smithy' card is drawn from the deck and larger decks are more likely to have a 'smithy' card.

4. playCouncilRoomCard(): trashFlag was set when playing this card, thus (supposedly) adding to the discarded pile instead of the played pile. Susan's test was able to catch that the card was not properly discarded; Erik didn't have a unit test for this one. Thankfully, Susan and I picked 3 of the same cards to unit test, so our unit tests were pretty interchangeable.

5. playVillageCard(): an extra card is drawn (+1 instead of +2). Susan identified this bug.

One last point of note: It was helpful to see my unit testers run against the bugs introduced by my teammates, because in many ways, I suspect that I was unconsciously writing my testers to test specifically for the bugs that I introduced. Thus, seeing them run against scenarios I hadn't anticipated was illuminating.
