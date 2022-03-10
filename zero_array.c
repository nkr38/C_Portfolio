/*
   Compile with: gcc -std=c89 -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/

#include <stdio.h>

void zero_array (int *a, int n)
{
  int *var;
  
  for(var = a; var < (a + n); var++)
  {
    *var = 0;
  }

  return;
}


void print_contents (int *a, int n)
{
  int i;
  
  for (i=0; i<n; i++) {
    printf("%2d ", a[i]);
    
    if (!((i+1) % 7))
      printf("\n");
  }
}


int main ()
{
  int numbers[] = {10,  1, 54,  8, 78, 13,  4,
                   32, 72, 13, 43, 66, 42, 21,
                   41, 87, 23, 11, 52,  7,  2,
                    3, 33,  5,  9, 67, 12, 17};
  
  int n = sizeof(numbers)/sizeof(int);
  
  printf("Contents of numbers[] BEFORE:\n");
  print_contents(numbers, n);
  
  zero_array(numbers, n);
  
  printf("\nContents of numbers[] AFTER:\n");
  print_contents(numbers, n);
    
  return 0;
}
