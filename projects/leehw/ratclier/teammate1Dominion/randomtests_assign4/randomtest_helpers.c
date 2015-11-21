//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      November 22, 2015
// Project:   Assignment 5 - Random Tests (teammates)
// Filename:  randomtest_helpers.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdlib.h>

// Influenced by code from the following webpage:
// http://stackoverflow.com/questions/9571738/picking-random-number-between-two-points-in-c
//
int randomByRange(int min, int max)
{
    int diff = max - min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + min);
}


