CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out

tests.out: unittest1.c dominion.c
	echo "Result for running BST tests:" > tests.out
	
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	unittest1 >> tests.out
	gcov dominion.c >> tests.out
