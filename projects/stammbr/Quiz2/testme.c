/********************************
 * Author:  Brian Stamm
 * Program:  testme.c
 * Date:  10.24.15
 * Notes:  This is the completing Quiz 2.  In this program,
 * I wrote both inputChar() and inputString(), so that it will
 * "randomly" product, which is explained in randomString.c.
 * *****************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  char rArray[9] = {'[', ']', '{', '}', '(', ')', ' ', 'a', 'x'};
  int r = rand() % 9;
  return rArray[r];
}

char *inputString()
{
  char rArray[5] = {'r', 'e', 's', 't', '\0'};
  
  static char returnString[5];
  int r, i;
  for(i = 0; i < 5; i++){
    r = rand() % 5;
    returnString[i] = rArray[r];
  }
  
  return returnString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
