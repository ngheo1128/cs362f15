#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// Get a random ASCII character from #32-126
    char c = rand() % (126 - 32 + 1) + 32;  

    return c;
}


char *inputString()
{
    
    int a = 97;
    int z = 122;
    int i = 0;
    
    char *sRand = malloc(sizeof(char) * 5);
    char cRand;
   
    //Get 5 random letters from the range of ASCII characters 97-122
    for (i=0; i<5; i++){
        cRand = z + rand() / (RAND_MAX / (a - z + 1) +1);
		sRand[i] = cRand;
    }

    return sRand;
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