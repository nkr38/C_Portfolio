/* Homework 5: Question 2
   Compile with: gcc -std=c89 -o Q2 Q2.c
   Then run your compiled program with: ./Q2
   
   This code is practice for using scructs. Each struct is used to store a numerator and denominator of a fraction. The code can 
   reduce, add, subtract, multiply and divide fractions.
*/

#include <stdio.h>

/* fraction struct init */
struct fraction {
  int numerator;
  int denominator;
};


void reduce(struct fraction *f)
{
  int a, b, temp;
  a = f->numerator;
  b = f->denominator;
  
  while(b != 0)
  {
      temp = b;
      b = a % b;
      a = temp;
  }
  f->numerator = f->numerator / a;
  f->denominator = f->denominator / a;

}


void add(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  result->numerator = f1->numerator * f2->denominator + f2->numerator * f1->denominator;
  result->denominator = f1->denominator * f2->denominator;
  reduce(result);
}


void subtract(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  result->numerator = f1->numerator * f2->denominator - f2->numerator * f1->denominator;
  result->denominator = f1->denominator * f2->denominator;
  reduce(result);
}


void multiply(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  result->numerator = f1->numerator * f2->numerator;
  result->denominator = f1->denominator * f2->denominator;
  reduce(result);
}


void divide(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  result->numerator = f1->numerator * f2->denominator;
  result->denominator = f1->denominator * f2->numerator;
  reduce(result);
}

int main()
{
  struct fraction result; 
  
  struct fraction f1 = {20, 15}; 
  struct fraction f2 = {22, 12}; 
  struct fraction f3 = { 4, 12}; 

  reduce(&f1);
  printf("Reduce f1: %d/%d\n", f1.numerator, f1.denominator);

  add(&result, &f2, &f3);
  printf("  f2 + f3: %d/%d\n", result.numerator, result.denominator);

  subtract(&result, &f2, &f3);
  printf("  f2 - f3: %d/%d\n", result.numerator, result.denominator);

  multiply(&result, &f2, &f3);
  printf("  f2 * f3: %d/%d\n", result.numerator, result.denominator);

  divide(&result, &f2, &f3);
  printf("  f2 / f3: %d/%d\n", result.numerator, result.denominator);

  return 0;
}
