CFLAGS = -Wall -fpic -coverage  -fprofile-arcs -ftest-coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

teammate2results.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c cardtest5.c dominion.o rngs.o
	echo "Result for running Dominion tests:" > teammate2results.out
	
	echo "cardtest1.c:" >> teammate2results.out
	gcc -o cardtest1 dominion.o rngs.o cardtest1.c $(CFLAGS)
	cardtest1 >> teammate2results.out
	gcov dominion.c -b >> teammate2results.out
	
	echo "cardtest3.c:" >> teammate2results.out
	gcc -o cardtest3 dominion.o rngs.o cardtest3.c $(CFLAGS)
	cardtest3 >> teammate2results.out
	gcov dominion.c -b >> teammate2results.out	
	
	echo "cardtest4.c:" >> teammate2results.out
	gcc -o cardtest4 dominion.o rngs.o cardtest4.c $(CFLAGS)
	cardtest4 >> teammate2results.out
	gcov dominion.c -b >> teammate2results.out
	
	echo "cardtest5.c:" >> teammate2results.out
	gcc -o cardtest5 dominion.o rngs.o cardtest5.c $(CFLAGS)
	cardtest5 >> teammate2results.out
	gcov dominion.c -b >> teammate2results.out


clean:
	rm -f *.o teammate2results.out cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 *.gcov *.gcda *.gcno *.so
