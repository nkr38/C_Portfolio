#include <stdio.h>
#include "strlib.h"

void check_compare(char *a, char *b)
{
  int diff = my_strcmp(a, b);

  if (!diff)
    printf("Strings match!");
  else
    printf("Strings DONT'T match!");
      
  printf(" (%d)\n", diff); 
}


int main()
{
  char foo[] = "";
  char empty[] = "Foo";
  char str1[] = "Drexel Programmers are the best!";
  char str2[] = "Dryxel Programmers are the best!";

  printf("  length of foo: %d\n", my_strlen(foo));
  printf("length of empty: %d\n", my_strlen(empty));
  printf(" length of str1: %d\n", my_strlen(str1));
  printf(" length of str2: %d\n", my_strlen(str2));
  printf("---------------------\n");
  
  printf("Comparing foo to empty: ");
  check_compare(foo, empty);
  
  printf("Comparing str1 to str2: ");
  check_compare(str1, str2);

  printf("Comparing str1 to  foo: ");
  check_compare(str1, foo);
  
  printf("Comparing empty to empty: ");
  check_compare(empty, empty);

  return 0;
}