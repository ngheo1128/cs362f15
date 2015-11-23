SUSAN'S REFACTORED CODE
Errors found in Susan's Code

-- BUG # 1 -- Village Card: player is supposed to get +1 card and +2 actions, but instead, player is receiving +0 cards and +1 actions.
--upon further testing with my randomtestcard in VERBOSE mode, I was able to determine that in fact her Village card actually re-sets the count of actions to 2 instead of giving the player +2 actions.
See Example Test Run Below:
 -- RANDOMIZED GAME STATE BEFORE PLAYING VILLAGE CARD -- 
numPlayers: 2
whoseTurn: 0
phase: 0
numActions: 1244083163
coins: 1905803363
numBuys: 1
handCount[0] = 5
--hand[0][0] = 14
--hand[0][1] = 14
--hand[0][2] = 7
--hand[0][3] = 14
--hand[0][4] = 13
deckCount[0] = 5
--deck[0][0] = 3
--deck[0][1] = 10
--deck[0][2] = 3
--deck[0][3] = 10
--deck[0][4] = 12
playedCardCount = 0
discardCount[0] = 0

 -- PLAYING VILLAGE CARD -- 

ERROR: player 0 did not gain 2 cards
ERROR: player 0 did not gain 2 actions
 -- GAME STATE AFTER PLAYING VILLAGE CARD -- 
numPlayers: 2
whoseTurn: 0
phase: 0
numActions: 2
coins: 1905803363
numBuys: 1
handCount[0] = 5
--hand[0][0] = 12
--hand[0][1] = 14
--hand[0][2] = 7
--hand[0][3] = 14
--hand[0][4] = 13
deckCount[0] = 4
--deck[0][0] = 3
--deck[0][1] = 10
--deck[0][2] = 3
--deck[0][3] = 10
playedCardCount = 1
playedCards[0] = 14
discardCount[0] = 0


-- BUG # 2 -- Council Room Card: Other players are supposed to draw a card when this card is played, but this does not happen.
See Example Test Run Below:
cardtest3.c --> 
 TESTING COUNCIL ROOM CARD
ERROR: player 0 able to play village card that's not in hand
ERROR: Player given 0 buys instead of 1.
ERROR: Council Room card not properly discarded.
ERROR: Player 1 did not draw a card
ERROR: Player 2 did not draw a card
ERROR: Player 3 did not draw a card
 TESTING COUNCIL ROOM CARD
ERROR: player 1 able to play village card that's not in hand
ERROR: Council Room card not properly discarded.
ERROR: Player 0 did not draw a card
ERROR: Player 2 did not draw a card
ERROR: Player 3 did not draw a card

COUNCIL ROOM CARD TEST COMPLETE with 11 ERRORS

----------------------

ERIK'S REFACTORED CODE
Errors found in Erik's Code

-- BUG # 1 -- Adventurer Card: 2 Treasure cards are never added to player's hand after card is played.
See Example Test Run Below:
 -- RANDOMIZED GAME STATE BEFORE PLAYING ADVENTURER CARD -- 
numPlayers: 3
whoseTurn: 0
phase: 0
numActions: 1820542272
coins: 344674040
numBuys: 1
handCount[0] = 5
--hand[0][0] = 7
--hand[0][1] = 14
--hand[0][2] = 21
--hand[0][3] = 4 COPPER
--hand[0][4] = 15
deckCount[0] = 10
--deck[0][0] = 5 SILVER
--deck[0][1] = 6 GOLD
--deck[0][2] = 20
--deck[0][3] = 20
--deck[0][4] = 24
--deck[0][5] = 5 SILVER
--deck[0][6] = 12
--deck[0][7] = 20
--deck[0][8] = 6 GOLD
--deck[0][9] = 4 COPPER
playedCardCount = 0
discardCount[0] = 0

 -- PLAYING ADVENTURER CARD -- 

ERROR: expected player's hand-count to be +2, but it is 0
ERROR: not +2 Treasure cards. Coins before= 1, after= 1
 -- GAME STATE AFTER PLAYING ADVENTURER CARD -- 
numPlayers: 3
whoseTurn: 0
phase: 0
numActions: 1820542272
coins: 344674040
numBuys: 1
handCount[0] = 5
--hand[0][0] = 7
--hand[0][1] = 14
--hand[0][2] = 21
--hand[0][3] = 4 COPPER
--hand[0][4] = 15
deckCount[0] = 0
playedCardCount = 0
discardCount[0] = 10
--discard[0][0] = 0
--discard[0][1] = 0
--discard[0][2] = 0
--discard[0][3] = 0
--discard[0][4] = 0
--discard[0][5] = 0
--discard[0][6] = 0
--discard[0][7] = 0
--discard[0][8] = 0
--discard[0][9] = 0


-- BUG # 2 -- Adventurer Card: After playing card, handCount will sometimes go below 0.
see Example Run Below
-- RANDOMIZED GAME STATE BEFORE PLAYING ADVENTURER CARD -- 
numPlayers: 2
whoseTurn: 0
phase: 0
numActions: 987970089
coins: 371430093
numBuys: 1
handCount[0] = 5
--hand[0][0] = 7
--hand[0][1] = 2
--hand[0][2] = 0
--hand[0][3] = 24
--hand[0][4] = 25
deckCount[0] = 10
--deck[0][0] = 15
--deck[0][1] = 6 GOLD
--deck[0][2] = 14
--deck[0][3] = 5 SILVER
--deck[0][4] = 6 GOLD
--deck[0][5] = 25
--deck[0][6] = 6 GOLD
--deck[0][7] = 24
--deck[0][8] = 4 COPPER
--deck[0][9] = 6 GOLD
playedCardCount = 0
discardCount[0] = 0

 -- PLAYING ADVENTURER CARD -- 

ERROR: expected player's hand-count to be +2, but it is -253
ERROR: not +2 Treasure cards. Coins before= 0, after= 0

 -- GAME STATE AFTER PLAYING ADVENTURER CARD -- 
numPlayers: 2
whoseTurn: 0
phase: 0
numActions: 987970089
coins: 371430093
numBuys: 1
handCount[0] = -248
deckCount[0] = 0
playedCardCount = 0
discardCount[0] = 263
--discard[0][0] = 0
--discard[0][1] = 1410293192
--discard[0][2] = 0
--discard[0][3] = 0
--discard[0][4] = 0
--discard[0][5] = -408104528
--discard[0][6] = 32764
--discard[0][7] = 1419625696
--discard[0][8] = 32684
--discard[0][9] = -408104416
--discard[0][10] = 32764
--discard[0][11] = 1419616040
--discard[0][12] = 32684
--discard[0][13] = 1
--discard[0][14] = 0
--discard[0][15] = 0
--discard[0][16] = 0
--discard[0][17] = -408104376
--discard[0][18] = 32764
--discard[0][19] = 1417419777
--discard[0][20] = 32684
--discard[0][21] = 2
--discard[0][22] = 0
--discard[0][23] = 1419616040
--discard[0][24] = 32684
--discard[0][25] = 1
--discard[0][26] = 0
--discard[0][27] = 0
--discard[0][28] = 0
--discard[0][29] = 1
--discard[0][30] = 0
--discard[0][31] = 1419624840
--discard[0][32] = 32684
--discard[0][33] = 2
--discard[0][34] = 0
--discard[0][35] = 1419616040
--discard[0][36] = 32684
--discard[0][37] = 0
--discard[0][38] = 0
--discard[0][39] = 1419625696
--discard[0][40] = 32684
--discard[0][41] = -408104560
--discard[0][42] = 32764
--discard[0][43] = 1419624840
--discard[0][44] = 1
--discard[0][45] = 1419624840
--discard[0][46] = 32684
--discard[0][47] = -408104576
--discard[0][48] = 32764
--discard[0][49] = 4196233
--discard[0][50] = 0
--discard[0][51] = -896471364
--discard[0][52] = 0
--discard[0][53] = -1
--discard[0][54] = 0
--discard[0][55] = 0
--discard[0][56] = 1
--discard[0][57] = 1410251000
--discard[0][58] = 32684
--discard[0][59] = 1419614624
--discard[0][60] = 32684
--discard[0][61] = 4196206
--discard[0][62] = 0
--discard[0][63] = 2090629905
--discard[0][64] = 0
--discard[0][65] = -1
--discard[0][66] = 0
--discard[0][67] = 0
--discard[0][68] = 0
--discard[0][69] = 1410249416
--discard[0][70] = 32684
--discard[0][71] = 4096
--discard[0][72] = 855638016
--discard[0][73] = 859058487
--discard[0][74] = 808595504
--discard[0][75] = 1410676278
--discard[0][76] = 32684
--discard[0][77] = 2049
--discard[0][78] = 0
--discard[0][79] = 0
--discard[0][80] = 0
--discard[0][81] = 4198400
--discard[0][82] = 0
--discard[0][83] = -408051168
--discard[0][84] = 32764
--discard[0][85] = 0
--discard[0][86] = 0
--discard[0][87] = 0
--discard[0][88] = 0
--discard[0][89] = -408104160
--discard[0][90] = 32764
--discard[0][91] = 1410571321
--discard[0][92] = 32684
--discard[0][93] = 0
--discard[0][94] = 0
--discard[0][95] = 24
--discard[0][96] = 48
--discard[0][97] = -408104192
--discard[0][98] = 32764
--discard[0][99] = -408104384
--discard[0][100] = 32764
--discard[0][101] = 933549443
--discard[0][102] = 0
--discard[0][103] = 0
--discard[0][104] = 0
--discard[0][105] = 0
--discard[0][106] = 0
--discard[0][107] = 2147483628
--discard[0][108] = 0
--discard[0][109] = 0
--discard[0][110] = 0
--discard[0][111] = 0
--discard[0][112] = 0
--discard[0][113] = 1414178624
--discard[0][114] = 32684
--discard[0][115] = -1
--discard[0][116] = 0
--discard[0][117] = 60
--discard[0][118] = 0
--discard[0][119] = 1410732660
--discard[0][120] = 32684
--discard[0][121] = 1414178624
--discard[0][122] = 32684
--discard[0][123] = 1410732990
--discard[0][124] = 32684
--discard[0][125] = 60
--discard[0][126] = 0
--discard[0][127] = 1414178624
--discard[0][128] = 32684
--discard[0][129] = 1
--discard[0][130] = 0
--discard[0][131] = 0
--discard[0][132] = 0
--discard[0][133] = 60
--discard[0][134] = 0
--discard[0][135] = 1410724432
--discard[0][136] = 32684
--discard[0][137] = 10
--discard[0][138] = 0
--discard[0][139] = 33
--discard[0][140] = 0
--discard[0][141] = 1414178624
--discard[0][142] = 32684
--discard[0][143] = 4235296
--discard[0][144] = 0
--discard[0][145] = -408051168
--discard[0][146] = 32764
--discard[0][147] = 0
--discard[0][148] = 0
--discard[0][149] = 0
--discard[0][150] = 0
--discard[0][151] = 1410685667
--discard[0][152] = 32684
--discard[0][153] = 0
--discard[0][154] = 0
--discard[0][155] = 314826240
--discard[0][156] = 138061208
--discard[0][157] = -408051424
--discard[0][158] = 32764
--discard[0][159] = 4202288
--discard[0][160] = 0
--discard[0][161] = 0
--discard[0][162] = 0
--discard[0][163] = 0
--discard[0][164] = 2
--discard[0][165] = 0
--discard[0][166] = 0
--discard[0][167] = 0
--discard[0][168] = 0
--discard[0][169] = 0
--discard[0][170] = 0
--discard[0][171] = 1457374715
--discard[0][172] = 0
--discard[0][173] = 7
--discard[0][174] = 8
--discard[0][175] = 9
--discard[0][176] = 10
--discard[0][177] = 11
--discard[0][178] = 12
--discard[0][179] = 13
--discard[0][180] = 14
--discard[0][181] = 15
--discard[0][182] = 17
--discard[0][183] = 0
--discard[0][184] = 0
--discard[0][185] = 2
--discard[0][186] = 10
--discard[0][187] = 8
--discard[0][188] = 8
--discard[0][189] = 8
--discard[0][190] = 45
--discard[0][191] = 38
--discard[0][192] = 23
--discard[0][193] = 10
--discard[0][194] = 10
--discard[0][195] = 10
--discard[0][196] = 8
--discard[0][197] = 10
--discard[0][198] = 10
--discard[0][199] = 10
--discard[0][200] = 10
--discard[0][201] = 10
--discard[0][202] = -1
--discard[0][203] = 10
--discard[0][204] = -1
--discard[0][205] = -1
--discard[0][206] = -1
--discard[0][207] = -1
--discard[0][208] = -1
--discard[0][209] = -1
--discard[0][210] = -1
--discard[0][211] = -1
--discard[0][212] = -1
--discard[0][213] = 0
--discard[0][214] = 0
--discard[0][215] = 0
--discard[0][216] = 0
--discard[0][217] = 0
--discard[0][218] = 0
--discard[0][219] = 0
--discard[0][220] = 0
--discard[0][221] = 0
--discard[0][222] = 0
--discard[0][223] = 0
--discard[0][224] = 0
--discard[0][225] = 0
--discard[0][226] = 0
--discard[0][227] = 0
--discard[0][228] = 0
--discard[0][229] = 0
--discard[0][230] = 0
--discard[0][231] = 0
--discard[0][232] = 0
--discard[0][233] = 0
--discard[0][234] = 0
--discard[0][235] = 0
--discard[0][236] = 0
--discard[0][237] = 0
--discard[0][238] = 0
--discard[0][239] = 0
--discard[0][240] = 0
--discard[0][241] = 0
--discard[0][242] = 0
--discard[0][243] = 0
--discard[0][244] = 987970089
--discard[0][245] = 371430093
--discard[0][246] = 1
--discard[0][247] = 7
--discard[0][248] = 2
--discard[0][249] = 0
--discard[0][250] = 24
--discard[0][251] = 25
--discard[0][252] = 15
--discard[0][253] = 0
--discard[0][254] = 0
--discard[0][255] = 0
--discard[0][256] = 0
--discard[0][257] = 0
--discard[0][258] = 0
--discard[0][259] = 0
--discard[0][260] = 0
--discard[0][261] = 0
--discard[0][262] = 0
