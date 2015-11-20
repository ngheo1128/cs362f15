CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

teammate2result.out: clean
	make rngs.o
	make dominion.o
	
	echo "Result for running dominion tests:" > teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "cardtest1.c:" >> teammate2result.out
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "cardtest2.c:" >> teammate2result.out
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "cardtest3.c:" >> teammate2result.out
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "unittest1.c:" >> teammate2result.out
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "unittest2.c:" >> teammate2result.out
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "unittest3.c:" >> teammate2result.out
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "unittest4.c:" >> teammate2result.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

	echo "-----------------------------------" >> teammate2result.out
	echo "unittest4.c:" >> teammate2result.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> teammate2result.out
	gcov dominion.c >> teammate2result.out
	# cat dominion.c.gcov >> teammate2result.out

randomtestadventurer.out: clean randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out

randomtestsmithy.out: clean randomtestsmithy.c dominion.o rngs.o
	gcc -o randomtestsmithy -g randomtestsmithy.c dominion.o rngs.o $(CFLAGS)
	./randomtestsmithy >> randomtestsmithy.out

clean:
	rm -rf *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.dSYM badTestDrawCard testDrawCard teammate2result.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestadventurer.out randomtestcard randomtestsmithy.out
