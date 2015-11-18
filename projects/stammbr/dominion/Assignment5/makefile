CFLAGS = -Wall -fpic -coverage -lm -std=c99
TEAM = Wisam

default: teamtests$(TEAM)2.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

testrun: cardTest1.c cardTest2.c cardTest3.c randomtestadventurer.c dominion.o rngs.o
	echo "Result for running tests for $(TEAM):" > teamtests$(TEAM)2.out

	echo "cardTest1.c:" >> teamtests$(TEAM)2.out
	gcc -o cardTest1 -g cardTest1.c dominion.o rngs.o $(CFLAGS)
	./cardTest1 >> teamtests$(TEAM)2.out

	echo "\n ***************************** \n" >> teamtests$(TEAM)2.out
	echo "cardTest2.c:" >> teamtests$(TEAM)2.out
	gcc -o cardTest2 -g cardTest2.c dominion.o rngs.o $(CFLAGS)
	./cardTest2 >> teamtests$(TEAM)2.out

	echo "\n ***************************** \n" >> teamtests$(TEAM)2.out
	echo "cardTest3.c:" >> teamtests$(TEAM)2.out
	gcc -o cardTest3 -g cardTest3.c dominion.o rngs.o $(CFLAGS)
	./cardTest3 >> teamtests$(TEAM)2.out
	
	echo "\n ***************************** \n" >> teamtests$(TEAM)2.out
	echo "Result for running random tests: " >> teamtests$(TEAM)2.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> teamtests$(TEAM)2.out

clean:
	rm teamtests$(TEAM)2.out

cleanall: 
	rm cardTest1 cardTest2 cardTest3 randomtestadventurer dominion rngs *.gcda *.gcno *.gcov
