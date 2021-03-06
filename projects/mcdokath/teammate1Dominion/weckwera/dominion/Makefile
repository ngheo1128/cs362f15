CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

refactor.o: dominion.h refactor.c rngs.o
	gcc -c refactor.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c rngs.o -g  $(CFLAGS)

playdomrefactor: refactor.o playdom.c
	gcc -o playdom playdom.c -g refactor.o rngs.o $(CFLAGS)

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

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	#gcc -o unittestresultsout dominion.o rngs.o unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c $(CFLAGS)
	echo "Results of all unit and card tests:" > unittestresults.out
	
	echo "unittest1.c" >> unittestresults.out
	#gcc -o unittest1 dominion.o unittest1.c $(CFLAGS)
	gcc -o unittest1 -g dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out	
	
	echo "unittest2.c" >> unittestresults.out
	#gcc -o unittest2 unittest2.c dominion.o $(CFLAGS)
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out	
	
	echo "unittest3.c" >> unittestresults.out
	#gcc -o unittest3 unittest3.c dominion.o $(CFLAGS)
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "unittest4.c" >> unittestresults.out
	#gcc -o unittest4 unittest4.c dominion.o $(CFLAGS)
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "cardtest1.c" >> unittestresults.out
	#gcc -o cardtest1 cardtest1.c dominion.o $(CFLAGS)
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out	
	
	echo "cardtest2.c" >> unittestresults.out
	#gcc -o cardtest2 cardtest2.c dominion.o $(CFLAGS)
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out	
	#
	#echo "cardtest3.c" >> unittestresults.out
	##gcc -o cardtest3 cardtest3.c dominion.o $(CFLAGS)
	#gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	#./cardtest3 >> unittestresults.out
	#gcov -b dominion.c >> unittestresults.out
	#
	#echo "cardtest4.c" >> unittestresults.out
	##gcc -o cardtest4 cardtest4.c dominion.o $(CFLAGS)
	#gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	#./cardtest4 >> unittestresults.out
	#gcov -b dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
