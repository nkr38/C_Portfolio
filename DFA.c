#include <stdio.h>
#include <ctype.h>
enum Statetype {NORMAL, INWORD};
/*------------------------------------------------------------*/
/* handleNormalState: Implement the NORMAL state of the DFA. */
/* c is the current DFA character. Return the next state. */
/*------------------------------------------------------------*/
enum Statetype handleNormalState(int c) {
  enum Statetype state;
    if (isalpha(c)) {
       putchar(toupper(c));
       state = INWORD;
    }
    else {
       putchar(c);
       state = NORMAL;
    }
    return state;
} 
/*------------------------------------------------------------*/
/* handleInwordState: Implement the INWORD state of the DFA. */
/* c is the current DFA character. Return the next state. */
/*------------------------------------------------------------*/
enum Statetype handleInwordState(int c) {
   enum Statetype state;
   putchar(c);
   if (!isalpha(c))
     state = NORMAL;
   else
     state = INWORD;
   return state;
}
/*------------------------------------------------------------*/
/* main: Read text from stdin. Convert the first character */
/* of each "word" to uppercase, where a word is a sequence of */
/* letters. Write the result to stdout. Return 0. */
/*------------------------------------------------------------*/
int main(void) {
   int c;
   enum Statetype state = NORMAL;
   /* Use a DFA approach. state indicates the state of the DFA. */
   for ( ; ; ) {
    c = getchar();
   if (c == EOF) break;
   switch (state) {
     case NORMAL:
     state = handleNormalState(c);
     break;
     case INWORD:
     state = handleInwordState(c);
     break;
   }
   }
   return 0;
}
