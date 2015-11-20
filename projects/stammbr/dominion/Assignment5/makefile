CFLAGS = -Wall -fpic -coverage -lm -std=c99
TEAM = Wisam
NUM = 3

default: teamtests$(TEAM)2.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

testrun: cardTest1.c cardTest2.c cardTest3.c randomtestadventurer.c dominion.o rngs.o
	echo "Result for running tests for $(TEAM):" > tests$(TEAM)$(NUM).out

	echo "cardTest1.c:" >> tests$(TEAM)$(NUM).out
	gcc -o cardTest1 -g cardTest1.c dominion.o rngs.o $(CFLAGS)
	./cardTest1 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "cardTest2.c:" >> tests$(TEAM)$(NUM).out
	gcc -o cardTest2 -g cardTest2.c dominion.o rngs.o $(CFLAGS)
	./cardTest2 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "cardTest3.c:" >> tests$(TEAM)$(NUM).out
	gcc -o cardTest3 -g cardTest3.c dominion.o rngs.o $(CFLAGS)
	./cardTest3 >> tests$(TEAM)$(NUM).out
	
	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "Result for running random tests: " >> tests$(TEAM)$(NUM).out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> tests$(TEAM)$(NUM).out

test1:  cardTest1.c dominion.o rngs.o
	echo "cardTest1.c Trial Test for $(TEAM)" > trial$(TEAM)$(NUM).out
	gcc -o cardTest1 -g cardTest1.c dominion.o rngs.o $(CFLAGS)
	./cardTest1 >> trial$(TEAM)$(NUM).out

test2:  cardTest2.c dominion.o rngs.o
	echo "cardTest2.c Trial Test for $(TEAM)" > trial$(TEAM)$(NUM).out
	gcc -o cardTest2 -g cardTest2.c dominion.o rngs.o $(CFLAGS)
	./cardTest2 >> trial$(TEAM)$(NUM).out

test3:  cardTest3.c dominion.o rngs.o
	echo "cardTest3.c Trial Test for $(TEAM)" > trial$(TEAM)$(NUM).out
	gcc -o cardTest3 -g cardTest3.c dominion.o rngs.o $(CFLAGS)
	./cardTest3 >> trial$(TEAM)$(NUM).out

test4:  randomtestadventurer.c dominion.o rngs.o
	echo "Random Trial Test for $(TEAM)" > trial$(TEAM)$(NUM).out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> trial$(TEAM)$(NUM).out

clean:
	rm tests$(TEAM)$(NUM).out trial$(TEAM)$(NUM).out

cleanall: 
	rm cardTest1 cardTest2 cardTest3 randomtestadventurer dominion rngs *.gcda *.gcno *.gcov
