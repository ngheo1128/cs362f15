//Name: Rhett Guyer
//Class: CS 362
// Date: 11/22/15
//Assignment: Assignment 5 Bug Report

//Objective: Below contains the bugs that my tests were able to find for Adrienne Pereira and Allyce McWhorter.

List of Bugs Found - Mcwhorta

1)	The test called “cardtest1” revealed the Smithy card does not appear to be increasing the number of cards in the hand by 2 after the card is used.The Smithy card should add 3 cards to the player’s hand and remove the used smithy card so the resulting hand increase should be 2 cards.Please note that the hand does appear to have the Smithy card removed.This same error also occurred when running the test called “randomtestcard.out” however we also note that exactly 3 cards were not removed from the player’s deck as they should have been after the execution of this card.

2)	The test of the Council Room card called “cardtest3” revealed that the hand count for the player who called used the Council Room card is not correct after the card is played.Also, on a related note, the deck count for the player that played the card is also incorrect.

3)	 The test for the Adventurer card called “randomtestadventurer.out” shows that the hand count after the execution or the Adventurer card is incorrect and that an incorrect number of treasure cards were added to the player’s hand.These two bugs are likely related but I cannot say for sure.

4)	Also in the test called “randomtestadventurer.out” it appears that the deck is not correctly replaced with the set of drawn cards and shuffled when the deck count is set to 0.

5)	Finally, in the test called “randomtestadventurer.out” it looks like the adventurer card has not been removed from the deck.





List of Bugs Found - Pereiraa

1)	The test called “cardtest1” revealed the Smithy card does not appear to be increasing the number of cards in the hand by 2 after the card is used.The Smithy card should add 3 cards to the player’s hand and remove the called smithy card.Please note that the hand does appear to have the Smithy card removed.This same error also occurred when running the test called “randomtestcard.out”.

2)	The test of the Council Room card called “cardtest3” revealed that the hand count for the player who called used the Council Room card is not correct after the card is played.Also, on a related note, the deck count for the player that played the card is also incorrect.

3)	Also in the test called “cardtest3”, the number of “buys” for the player that used the card is incorrect.

4)	 The test for the Adventurer card called “randomtestadventurer.out” shows that the hand count after the execution or the Adventurer card is incorrect and that not enough treasure cards were added to the player’s hand.These two bugs are likely related but I cannot say for sure.

5)	Also in the test called “randomtestadventurer.out” it appears that the deck is not correctly replaced with the set of drawn cards and shuffled when the deck count is set to 0.

6)	Finally, in the test called “randomtestadventurer.out” it looks like the adventurer card has not been removed from the deck.
