/* Homework 6: Question 1
   Compile with: gcc -std=c89 -o Q1 Q1.c
   Then run your compiled program with: ./Q1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Your code goes here */
char *duplicate(char *phrase)
{
  int lengthofstr;
  char *copiedstr;

  lengthofstr = strlen(phrase);
  copiedstr = malloc(lengthofstr * sizeof(phrase));

  if(copiedstr == NULL)
  {
    printf("malloc() failed!\n");
    return NULL; /* Exit Failure*/
  }

  int i = 0;
  for(; i < lengthofstr; i++)
  {
    copiedstr[i] = phrase[i];
  }

  return copiedstr;

}
int main()
{
  char *dst;

  char *test = "Simplicity is the ultimate sophistication.";

  dst = duplicate(test);

  printf("%s", dst);

  free(dst);

  return 0;
}