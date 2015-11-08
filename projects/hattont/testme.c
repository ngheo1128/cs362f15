#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CHARS 5

char inputChar()
{
  int numChars = 9; 
  int randInt = (int)random() % (numChars);
  char allowedChars[] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
  return allowedChars[randInt];
}

char *inputString()
{
    int randInt = 0;
    char allowedChars[] = {'r', 'e', 's', 'e', 't'};
    int i = 0;
    static char returnString[NUM_CHARS + 1];
    
    for (i = 0; i < NUM_CHARS; i++) {
      randInt = (int)random() % (NUM_CHARS);
      returnString[i] = allowedChars[randInt];
    }
    returnString[NUM_CHARS] = '\0';
    char *returnStringAddress = returnString;
    return returnStringAddress;
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
