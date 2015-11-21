CFLAGS = -Wall -fpic -coverage -lm -std=c99
TEAM = Jody
NUM = 6

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

testrun: cardTest1.c cardTest2.c cardTest3.c cardTest4.c unitTest1.c unitTest2.c unitTest3.c unitTest4.c randomtestadventurer.c randomtestcard.c dominion.o rngs.o
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
	echo "cardTest4.c:" >> tests$(TEAM)$(NUM).out
	gcc -o cardTest4 -g cardTest4.c dominion.o rngs.o $(CFLAGS)
	./cardTest4 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "unitTest1.c:" >> tests$(TEAM)$(NUM).out
	gcc -o unitTest1 -g unitTest1.c dominion.o rngs.o $(CFLAGS)
	./unitTest1 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "unitTest2.c:" >> tests$(TEAM)$(NUM).out
	gcc -o unitTest2 -g unitTest2.c dominion.o rngs.o $(CFLAGS)
	./unitTest2 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "unitTest3.c:" >> tests$(TEAM)$(NUM).out
	gcc -o unitTest3 -g unitTest3.c dominion.o rngs.o $(CFLAGS)
	./unitTest3 >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "unitTest4.c:" >> tests$(TEAM)$(NUM).out
	gcc -o unitTest4 -g unitTest4.c dominion.o rngs.o $(CFLAGS)
	./unitTest4 >> tests$(TEAM)$(NUM).out
	
	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "Result for running random tests.\nAdventurer:\n " >> tests$(TEAM)$(NUM).out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> tests$(TEAM)$(NUM).out

	echo "\n ***************************** \n" >> tests$(TEAM)$(NUM).out
	echo "Result for running randomtestcard: " >> tests$(TEAM)$(NUM).out
	gcc -o randomtestcard randomtestcard.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard >> tests$(TEAM)$(NUM).out

cleantest:
	rm tests$(TEAM)$(NUM).out

cleanall: 
	rm cardTest1 cardTest2 cardTest3 cardTest4 unitTest1 unitTest2 unitTest3 unitTest4 randomtestadventurer randomtestcard dominion rngs *.gcda *.gcno *.gcov *.o
