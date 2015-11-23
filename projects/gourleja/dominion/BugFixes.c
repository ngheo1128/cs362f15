/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 5 - BugFixes.c
 * Description : Description of bug fixes made
 */


/*
-------------------------------------------------------------------------------

Smithy Card:

    The bug that I had originally introduced into the Dominion code was caught
    by my teammates test suites.  I corrected the for loop condition from "i <= 3"
    back to the correct condition of "i < 3".  This cleared the error from occuring
    in my own test suite as well.

-------------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------------

Adventurer Card:

    The bugs that I had originally introduced into the Dominion code was caught
    by my teammates test suites as well as some others I did not realize were
    in the prexisting code.

    The adventurer card was failing on a new test that I had not had where
    the adventurer card was not being discarded from the players hand and
    not being added to the discard pile.  In order to verify that I was passing this
    new test I copied over my teammates test and added it to my own test suite
    and make file to ensure that I was testing exactly as they had been.

    A quick look at the tests, results, and source code I noticed that there
    looked to be a missing call to the discard method for this particular card.
    I used GDB to verify this on the Adventurer card and then also ran through
    GDB tracking the Smithy card in my existing test to follow when and how
    the discard was actually supposed to be occuring.  This verified that
    I was missing the correct call to discard the adventure card from the player's
    hand.  Looking back at the repsitory history I believe this was an error
    in the original source code that I had not caught, though it could have
    occured easily when I was refactoring the card code into its own method call.
    Either way I had not thought of this case and reviewing my teammates test
    cases also gave me a better understanding of test cases that I had not been
    thinking of previouly.

    I altered my code to revert the shuffle condition I alterted from
    "state->deckCount[currentPlayer] <= 1" to "state->deckCount[currentPlayer] < 1".
    I also changed back the increment of the z variable to be post-increment.

    I still was reporting an error from my test suite for testing the card
    without having any tresure cards in the player's deck or discard pile.  I
    had been confident in my test previously however digging into GDB and tracking
    the cards in the player's hand, deck and discard pile I realized that
    I had made an incorrect assumption based upon my knowledge of how the code worked.
    I was not actually creating a full set of cards missing treasure cards.  They
    were still being added to my set of cards and I found through the use of GDB
    that my test was actually the point of the failure and my understanding of
    how the full sets of cards were being built.

-------------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------------

playCard():

    The tests I had created for the playCard method were still returning an
    incorrect value for coin increases after the call.  Using GDB to step through
    code quite a few times and tracking variables I recognized that the additional
    coins were being tracked and then zeroed out prior to when the value of coins was
    actually updated into the game state. I altered the code to correctly get additional
    coin_bonus value to pass to updateCoins method where previously this variable was
    never being updated so it was always dropping the increase in coins that were made.

-------------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------------

Baron:

    The bug I introduced into the Dominion code was not a part of my teammates
    test suites so it was not caught.  I reversed my changes that introduced the
    bug by adding back in the missing statement "state->supplyCount[estate]--;".

-------------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------------

Salvager:

    The bug I introduced into the Dominion code was not a part of my teammates
    test suites so it was not caught.  I reversed my changes that introduced the
    bug by changing the increment from "state->numActions++" back to "state->numBuys++;".

-------------------------------------------------------------------------------
*/
