add_executable(cardtest3 cardtest3.c dominion.c rngs.c)
add_executable(cardtest4 cardtest4.c dominion.c rngs.c)
add_executable(cardtest2 cardtest2.c dominion.c rngs.c)
add_executable(unittest1 unittest1.c dominion.c rngs.c)
add_executable(randomtestadventurer randomtestadventurer.c dominion.c rngs.c)
add_executable(randomtestcard.out randomtestcard.c dominion.c rngs.c)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.9)
