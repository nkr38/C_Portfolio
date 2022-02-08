/* Homework 6: Question 2
   Compile with: gcc -std=c89 -o Q2 Q2.c
   Then run your compiled program with: ./Q2
*/
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 8

/* Your code goes here */
int *create_array(int n, int initial_value)
{
  int *my_array;
  int i = 0;
  my_array = malloc(n * sizeof(my_array));

  if(my_array == NULL)
  {
    printf("malloc() failed!\n");
    return NULL; /* Exit Failure*/
  }

  for(; i < n; i++)
  {
    my_array[i] = initial_value;
  }

  return my_array;
}

int main()
{
  int i;
  int *foo;

  foo = create_array(ELEMENTS, 79);

  if (foo)
    for (i=0; i<ELEMENTS; i++)    
      printf("%d: %d\n", i, foo[i]);

  free(foo);

  return 0;
}