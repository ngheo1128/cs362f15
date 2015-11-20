CFLAGS = -Wall -fpic -coverage  -fprofile-arcs -ftest-coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

teammate1results.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c cardtest5.c dominion.o rngs.o
	echo "Result for running Dominion tests:" > teammate1results.out
	
	echo "cardtest1.c:" >> teammate1results.out
	gcc -o cardtest1 dominion.o rngs.o cardtest1.c $(CFLAGS)
	cardtest1 >> teammate1results.out
	gcov dominion.c -b >> teammate1results.out
	
	echo "cardtest2.c:" >> teammate1results.out
	gcc -o cardtest2 dominion.o rngs.o cardtest2.c $(CFLAGS)
	cardtest2 >> teammate1results.out
	gcov dominion.c -b >> teammate1results.out
	
	echo "cardtest3.c:" >> teammate1results.out
	gcc -o cardtest3 dominion.o rngs.o cardtest3.c $(CFLAGS)
	cardtest3 >> teammate1results.out
	gcov dominion.c -b >> teammate1results.out	
	
	echo "cardtest4.c:" >> teammate1results.out
	gcc -o cardtest4 dominion.o rngs.o cardtest4.c $(CFLAGS)
	cardtest4 >> teammate1results.out
	gcov dominion.c -b >> teammate1results.out
	
	echo "cardtest5.c:" >> teammate1results.out
	gcc -o cardtest5 dominion.o rngs.o cardtest5.c $(CFLAGS)
	cardtest5 >> teammate1results.out
	gcov dominion.c -b >> teammate1results.out


clean:
	rm -f *.o teammate1results.out cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 *.gcov *.gcda *.gcno *.so
