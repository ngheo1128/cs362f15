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

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.c rngs.c $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.c rngs.c $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.c rngs.c $(CFLAGS)
	
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.c rngs.c $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.c rngs.c $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.c rngs.c $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.c rngs.c $(CFLAGS)

unittestresults.out: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 dominion.o rngs.o interface.o

	echo "Unit Test 1:" >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Unit Test 2:" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Unit Test 3:" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.c rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Unit Test 4:" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Card Test 1:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Card Test 2:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Card Test 3:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Card Test 4:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	cat dominion.c.gcov >> unittestresults.out
	
randomtestadventurer.out: dominion.c rngs.o interface.o
	echo "Result for random test card:" > randomtestcard.out
	
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.o interface.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
