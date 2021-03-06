CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

#unit tests
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.c rngs.c $(CFLAGS)

unittest2: unittest2.c rngs.o
	gcc -o unittest2 -g unittest2.c dominion.c rngs.c $(CFLAGS)

unittest3: unittest3.c rngs.o
	gcc -o unittest3 -g unittest3.c dominion.c rngs.c $(CFLAGS)

unittest4: unittest4.c rngs.o
	gcc -o unittest4 -g unittest4.c dominion.c rngs.c $(CFLAGS)

#card tests

cardtest1: cardtest1.c rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS)

cardtest2: cardtest2.c rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.c rngs.c $(CFLAGS)

cardtest3: cardtest3.c rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.c rngs.c $(CFLAGS)

cardtest4: cardtest4.c rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.c rngs.c $(CFLAGS)

#random tests

randomtestadventurer: randomtestadventurer.c rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)

randomtestcard: randomtestcard.c rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.c rngs.c $(CFLAGS)

#unittestresults.out

#unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion.o rngs.o
unittestresults.out: unittest1.c dominion.o rngs.o
	echo "Keenan Bishop: Unit Test Results:" >> unittestresults.out
	#test 1
	echo "Unit Test 1:" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#test 2
	echo "Unit Test 2:" >> unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#test 3
	echo "Unit Test 3:" >> unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#test 4
	echo "Unit Test 4:" >> unittestresults.out
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#card test 1
	echo "Card Test 1:" >> unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#card test 2
	echo "Card Test 2:" >> unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#card test 3
	echo "Card Test 3:" >> unittestresults.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	#card test 4
	echo "Card Test 4:" >> unittestresults.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

#random tests out
#adventurer
randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Random Card Test: Adventurer:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

#random card (village)
randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "Random Card Test: Adventurer:" >> randomtestcard.out
	gcc -o randomtestcard -g randomtestcard.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so testDrawCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtestadventurer.out randomtestadventurer randomtestcard randomtestcard.out
