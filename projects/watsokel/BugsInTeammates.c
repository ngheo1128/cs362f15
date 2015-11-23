CS 362 - ASSIGNMENT 5               KELVIN WATSON 
BugsInTeammates.c                   ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
----------------------------------------------------------------------------------------------------------------------------


BUG REPORT FOR TEAMMATE 1 (Jason Flaig; onid: flaigj)
-----------------------------------------------------
After running all tests, 8 bugs were detected via tests in unittest2, cardtest1.c, cardtest2.c, cardtest3.c.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ID  DESCRIPTION                 EXPECTED OUTPUT         ACTUAL OUTPUT           SEVERITY  PRIORITY      HOW TO REPRODUCE            
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1   Number of cards in hand     pre-call handCount=5    pre-call handCount=5    High      Medium        Call smithyCard()
    is one more than expected   post-call handCount=7   post-call handCount=8                           using valid game
    after call to smithyCard().                                                                         state, player and
    Also, number of cards in                                                                            hand position. To
    deck one less than expected.                                                                        avoid input validity
    These buggy outputs are due                                                                         issues, pass in a 
    to drawCard() method being                                                                          valid hand position.
    called one too many times.  
    This bug was detected using 
    unit tests in cardtest1.c.
----------------------------------------------------------------------------------------------------------------------------
2   Number of gold treasure     gold treasure count=2   gold treasure count=0   High      High          Call the 
    cards consistently                                                                                  cardEffect() method
    computes to 0. Gold                                                         This bug causes         using the adventurer
    treasure cards are not                                                      the game to be          enumerated type as 
    counted towards the                                                         unfair to the player    an argument, which 
    hand's treasure count.                                                      playing the adventurer  in turn calls the 
    This bug was detected using                                                 card.                   adventurerCard() 
    unit tests in cardtest2.c.                                                                          method. The  
                                                                                                        drawntreasure and z
                                                                                                        parameters should be
                                                                                                        passed in with a 
                                                                                                        value of 0, or 
                                                                                                        assigned a value of
                                                                                                        0 within the 
                                                                                                        adventurerCard() method.
----------------------------------------------------------------------------------------------------------------------------
3   After a call to             expected=6              top of deck=387389207   High      Urgent        Call the sea_hag case           
    cardEffect()'s sea_hag      (enum CARD gold)                                                        in cardEffect() using 
    case, the card at the                                                       The top of the deck     the sea_hag enumerated
    top of opponent's discard                                                   is uninitalized         CARD type. Since the
    pile is not the card that                                                   (junk) data, and could  choice1, choice2 and
    was at the top of his/her                                                   result in unpredictable choice3 parameters are
    deck. This bug was detected                                                 behavior should this    not used by the sea_hag 
    using tests in cardtest3.c.                                                 card be inadvertently   case, they can be passed
                                                                                accessed.               as arguments with any
                                                                                                        value, although it is
                                                                                                        preferable to pass in 
                                                                                                        arguments of valid CARD 
                                                                                                        enumeration to prevent 
                                                                                                        any input validity 
                                                                                                        issues while debugging
                                                                                                        this particular bug.
----------------------------------------------------------------------------------------------------------------------------
4   After a call to the         expected=0              actual card=1           Medium    Medium        Call the sea_hag case
    sea_hag case of             (enum CARD curse)       (enum CARD estate)                              in cardEffect() using
    cardEffect(), the card on                                                   Although a curse is     the sea_hag enumerated
    top of the opponent's deck                                                  not added to the top    CARD type. Since the
    after distributing the                                                      of the opponent's       choice1, choice2, and
    curse is not a curse card.                                                  deck, there is no       choice3 parameters are
    On test initialization,                                                     immediate danger of     not used by the sea_hag
    the opponent's entire deck                                                  the game crashing.      case, they can be passed
    was initialized to estates                                                                          as arguments with any
    in order to detect the                                                                              value, although it is
    absence of a curse card at                                                                          preferable to pass in
    the top of the deck.                                                                                arguments of valid CARD
    This bug was detected                                                                               enumeration to prevent 
    using tests in cardtest3.c.                                                                         input validity issues
                                                                                                        while debugging this 
                                                                                                        specific bug.
----------------------------------------------------------------------------------------------------------------------------
5.  The number of curse cards   curse card(supply)=9    curse cards(supply)=10  Medium    Low           Call the sea_hag case   
    in the game supply is not                                                                           in cardEffect() using 
    decremented after the call                                                  Not decrementing the    the sea_hag enumerated
    to the sea_hag case of                                                      supply of curse cards   CARD type. Since the
    cardEffect(). This bug was                                                  means that there is an  choice1, choice2 and
    detected using tests in                                                     potentially unlimited   choice3 parameters are
    cardtest3.c.                                                                supply of curse cards   not used by the sea_hag
                                                                                in circulation during   case, they can be passed
                                                                                game play.              as arguments with any 
                                                                                                        value, although it is
                                                                                                        preferable to pass in
                                                                                                        arguments of valid CARD
                                                                                                        enumeration to prevent
                                                                                                        input validity issues
                                                                                                        while debugging this 
                                                                                                        specific bug.
----------------------------------------------------------------------------------------------------------------------------
6.  The deck count after        deckCount=10            deckCount=7             High        High        Call the sea_hag case
    discarding the top of the                                                                           in cardEffect() using
    opponents' deck is                                                          The deck count is       the sea_hag enumerate
    erroneously decremented                                                     used to decide when a   CARD type. Since the
    three times, when the                                                       shuffle is necessary.   choice1, choice2, and 
    overall deck count should                                                   This bug can            choice3 parameters are
    not have changed. Note that                                                 potentially limit       not used by the sea_hag
    the deck count should have                                                  a player's access to    case, they can be passed
    only been decremented once                                                  his/her cards by        as arguments with any 
    when the top of the deck                                                    recording an            value, although it is 
    was discarded, then                                                         erroneously low         preferable to pass in
    incremented once when the                                                   deck count.             arguments of valid CARD
    curse card as added to the                                                                          enumeration to prevent
    top of the deck. This bug                                                                           input validity issues
    was detected using tests in                                                                         while fixing this
    cardtest3.c.                                                                                        specific bug.

----------------------------------------------------------------------------------------------------------------------------
7.  After a call to             discardCount=1          discardCount=0          High        High        Call discardCard()
    discardCard(), the discard                                                                          using a valid hand
    count remains the same,                                                     If the discard count    position, player and
    i.e. the discard count                                                      does not increase on    state. To avoid input
    does not incremented as                                                     discarding of a card,   validity issues while
    expected. This bug was                                                      then methods that       fixing this bug, 
    detected using unit tests                                                   manipulate the          pass in a valid hand 
    from unittest2.c.                                                           discard pile and count  position.
                                                                                could run into issue 
                                                                                such as array 
                                                                                out-of-bound errors
                                                                                (invalid array indices)
                                                                                or accessing junk data.
----------------------------------------------------------------------------------------------------------------------------
8.  After a call to             discardedCard=6         discardedCard=387389207 High        High        Call discardCard()
    discardCard(). the top of                                                                           using a valid hand
    the discard pile is a                                                       If cards are not        position, player and
    garbage value, even                                                         discarded               state. To avoid input
    though the discarded card                                                   appropriately, it is    validity issues while
    should have been a gold                                                     uncertain if cards      fixing this particular
    card in this test. This                                                     are ever returned to    bug, pass in a valid
    bug was detected using                                                      the player's discard    hand position.
    unit tests from unittest2.c.                                                pile to allow correct 
                                                                                recirculation into 
                                                                                the player's hand for 
                                                                                game play.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



BUG REPORT FOR TEAMMATE 2 (Dustin Dinh; onid: dinhd)
----------------------------------------------------
After running all tests, 8 bugs were detected via tests in unittest2, cardtest1.c, cardtest2.c, cardtest3.c

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ID  DESCRIPTION                 EXPECTED OUTPUT         ACTUAL OUTPUT           SEVERITY  PRIORITY      HOW TO REPRODUCE            
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1   Number of cards in hand     pre-call handCount=5    pre-call handCount=5    High      Urgent        Call smithyCard()
    is two less than expected   post-call handCount=7   post-call handCount=5                           using valid game
    after call to smithyCard().                                                                         state, player and
    Note that cardtest1.c                                                                               hand position.
    forces the user to draw 
    from a deck containing only 
    gold treasure cards as a 
    second check to verify that 
    the drawn cards were indeed 
    placed in the hand. As a 
    result of the bug, the number 
    of gold cards drawn is
    incorrect as well. This is a 
    side effect of the card being
    immediately discarded after 
    being drawn. These buggy 
    outputs are due to the 
    discardCard() method being 
    enclosed inside the for loop
    where cards are being drawn.
    Bug detected using unit tests 
    in cardtest1.c.
----------------------------------------------------------------------------------------------------------------------------
2   The player's discard card   discardCount=5          discardCount=6      High        Urgent          Call adventurerCard()
    count is consistently one                                                                           using valid game
    more than the expected                                                  If left unfixed,            state, player, and hand
    discard card count. This is                                             subsequent attempts         position. Check discard
    due to a bug causing an extra                                           to use discard pile         count against a oracle  
    card (actually uninitialized                                            may result in invalid       after card draws and 
    junk data) from the temphand                                            (junk data) being           discard of temphand.
    being added to the discard                                              accessed.
    pile due to accessing data                          
    outside of the temphand
    array bounds (data at invalid 
    array index -1 is being 
    accessed). Bug detected using
    unit tests in cardtest2.c.
----------------------------------------------------------------------------------------------------------------------------
3   After a call to             expected=6              top of deck=387389207   High      Urgent        Call the sea_hag case           
    cardEffect()'s sea_hag      (enum CARD gold)                                                        in cardEffect() using 
    case, the card at the                                                       The top of the deck     the sea_hag enumerated
    top of opponent's discard                                                   is uninitalized         CARD type. Since the
    pile is not the card that                                                   (junk) data, and could  choice1, choice2 and
    was at the top of his/her                                                   result in unpredictable choice3 parameters are
    deck. This bug was detected                                                 behavior should this    not used by the sea_hag 
    using tests in cardtest3.c.                                                 card be inadvertently   case, they can be passed
                                                                                accessed.               as arguments with any
                                                                                                        value, although it is
                                                                                                        preferable to pass in 
                                                                                                        arguments of valid CARD 
                                                                                                        enumeration to prevent 
                                                                                                        any input validity 
                                                                                                        issues while debugging
                                                                                                        this particular bug.
----------------------------------------------------------------------------------------------------------------------------
4   After a call to the         expected=0              actual card=1           Medium    Medium        Call the sea_hag case
    sea_hag case of             (enum CARD curse)       (enum CARD estate)                              in cardEffect() using
    cardEffect(), the card on                                                   Although a curse is     the sea_hag enumerated
    top of the opponent's deck                                                  not added to the top    CARD type. Since the
    after distributing the                                                      of the opponent's       choice1, choice2, and
    curse is not a curse card.                                                  deck, there is no       choice3 parameters are
    On test initialization,                                                     immediate danger of     not used by the sea_hag
    the opponent's entire deck                                                  the game crashing.      case, they can be passed
    was initialized to estates                                                                          as arguments with any
    in order to detect the                                                                              value, although it is
    absence of a curse card at                                                                          preferable to pass in
    the top of the deck.                                                                                arguments of valid CARD
    This bug was detected                                                                               enumeration to prevent 
    using tests in cardtest3.c.                                                                         input validity issues
                                                                                                        while debugging this 
                                                                                                        specific bug.
----------------------------------------------------------------------------------------------------------------------------
5.  The number of curse cards   curse card(supply)=9    curse cards(supply)=10  Medium    Low           Call the sea_hag case   
    in the game supply is not                                                                           in cardEffect() using 
    decremented after the call                                                  Not decrementing the    the sea_hag enumerated
    to the sea_hag case of                                                      supply of curse cards   CARD type. Since the
    cardEffect(). This bug was                                                  means that there is an  choice1, choice2 and
    detected using tests in                                                     potentially unlimited   choice3 parameters are
    cardtest3.c.                                                                supply of curse cards   not used by the sea_hag
                                                                                in circulation during   case, they can be passed
                                                                                game play.              as arguments with any 
                                                                                                        value, although it is
                                                                                                        prefereable to pass in
                                                                                                        arguments of valid CARD
                                                                                                        enumeration to prevent
                                                                                                        input validity issues
                                                                                                        while debugging this 
                                                                                                        specific bug.
----------------------------------------------------------------------------------------------------------------------------
6.  The deck count after        deckCount=10            deckCount=7             High        High        Call the sea_hag case
    discarding the top of the                                                                           in cardEffect() using
    opponents' deck is                                                          The deck count is       the sea_hag enumerate
    erroneously decremented                                                     used to decide when a   CARD type. Since the
    three times, when the                                                       shuffle is necessary.   choice1, choice2, and 
    overall deck count should                                                   This bug can            choice3 parameters are
    not have changed. Note that                                                 potentially limit       not used by the sea_hag
    the deck count should have                                                  a player's access to    case, they can be passed
    only been decremented once                                                  his/her cards by        as arguments with any 
    when the top of the deck                                                    recording an            value, although it is 
    was discarded, then                                                         erroneously low         preferable to pass in
    incremented once when the                                                   deck count.             arguments of valid CARD
    curse card as added to the                                                                          enumeration to prevent
    top of the deck. This bug                                                                           input validity issues
    was detected using tests in                                                                         while fixing this
    cardtest3.c.                                                                                        specific bug.

----------------------------------------------------------------------------------------------------------------------------
7.  After a call to             discardCount=1          discardCount=0          High        High        Call discardCard()
    discardCard(), the discard                                                                          using a valid hand
    count remains the same,                                                     If the discard count    position, player and
    i.e. the discard count                                                      does not increase on    state. To avoid input
    does not incremented as                                                     discarding of a card,   validity issues while
    detected using unit tests                                                   manipulate the          pass in a valid hand 
    expected. This bug was                                                      then methods that       fixing this bug, 
    from unittest2.c.                                                           discard pile and count  position.
                                                                                could run into issue 
                                                                                such as array 
                                                                                out-of-bound errors
                                                                                (invalid array indices)
                                                                                or accessing junk data.
----------------------------------------------------------------------------------------------------------------------------
8.  After a call to             discardedCard=6         discardedCard=387389207 High        High        Call discardCard()
    discardCard(). the top of                                                                           using a valid hand
    the discard pile is a                                                       If cards are not        position, player and
    garbage value, even                                                         discarded               state. To avoid input
    though the discarded card                                                   appropriately, it is    validity issues while
    should have been a gold                                                     uncertain if cards      fixing this particular
    card in this test. This                                                     are ever returned to    bug, pass in a valid
    bug was detected using                                                      the player's discard    hand position.
    unit tests from unittest2.c.                                                pile to allow correct 
                                                                                recirculation into 
                                                                                the player's hand for 
                                                                                game play.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++