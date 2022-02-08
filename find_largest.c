/* Homework 3: Question 2
   Compile with: gcc -std=c89 -o Q2 Q2.c
   Then run your compiled program with: ./Q2
   
   Takes an array (numbers[]) filled with ints and finds which number was the largest and how many numbers were given originally.
*/

#include <stdio.h>

int *find_largest (int *a, int n)
{
  int i, index, large = 0;
  int* var;
  
  for(i=0; i < n; i++)
  {
    if(a[i] > large)
    {
      large = a[i];
      index = i;
    }
  }
  var = a + index;
  return var;
}


int main ()
{
  int *largest;
  
  int numbers[] = {10,  1, 54,  8, 78, 13,  4,
                   32, 72, 13, 43, 66, 42, 21,
                   41, 87, 23, 11, 52,  7,  2,
                    3, 33,  5,  9, 67, 12, 17};

  int n = sizeof(numbers)/sizeof(int);
  
  largest = find_largest(numbers, n);
  
  printf("Of the %d numbers passed,\n", n);
  printf("%d was the largest\n", *largest);
  
  return 0;
}
