/****************************************************
 * Tips:                                            *
 *  - Read & understand main.c  (!!)                *
 *  - Read & understand house.c (!!)                *
 *  - Steps 1, 2, & 3 require you to edit window.c  *
 *  - house.h contains useful #defines              *
 *  - Read the comments above each function!        *
 ****************************************************/
#include <stdio.h>
#include "ezinput.h"
#include "house.h"
#include "window.h"


/* Checks if all lights have been turned off.
 *
 *   Iterates through the game state array and returns 1 if all of the
 *   lights have been successfully turned off; otherwise returns 0.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 * Return Values:
 *   1 if all lights have been turned off; 0 otherwise.
 */
int solved (const int *state)
{
  /* Step 4: Rewrite this function! */
  int i;
  for(i = 0; i < 9; i++)
  {
    if (state[i] == 1)
    {
      return 0;
    }
  }
  return 1;
}


int main ()
{
  char choice;

  /* Note: house[] contains just one really long string.
     i.e. printf("foo" "bar"); is the same as printf("foobar"); */
  char house[] =
  "                                             ______________          "
  "                                            |______________|         "
  "      _______________________________________|            |_____     "
  "     '                                       |____________|     `    "
  "    |                                                           |    "
  "    '-----------------------------------------------------------'    "
  "    |           1                 2                 3           |    "
  "    |     +-----------+     +-----------+     +-----------+     |    "
  "    |     |           |     |           |     |           |     |    "
  "    |     |           |     |           |     |           |     |    "
  "    |     |           |     |           |     |           |     |    "
  "    |     +-----------+     +-----------+     +-----------+     |    "
  "    |           4                 5                 6           |    "
  "    |     +-----------+     +-----------+     +-----------+     |    "
  "    |     |           |     |           |     |           |     |    "
  "    |     |           |     |           |     |           |     |    "
  "  _ |     |           |     |           |     |           |     |    "
  " |#||     +-----------+     +-----------+     +-----------+     |    "
  " |_||           7                 8                 9           |    "
  "  `-|     +-----------+     +-----------+     +-----------+     |    "
  "    -     |           |     |           |     |           |     |    "
  "    '     |           |     |           |     |           |     |    "
  "    '     |           |     |           |     |           |     |    "
  "   o'     +-----------+     +-----------+     +-----------+     |    "
  "    '                                                           |    "
  "____'___________________________________________________________'____";

  
  /* This will be our initial game state (do not change this!)
   *   [ 1 = Light is ON,  0 = Light is OFF ] */
  int state[] = { 1, 1, 0,
                  1, 1, 0,
                  1, 0, 0 };


  house_init (house, state);

  /* The Game Loop */
  while (1) {
    house_display (house);

    if (solved (state)) {
      printf ("Congratulations!  You won!\n");
      break;
    }

    do {
      printf ("Choose a Window (0 to exit): ");
      choice = ezinput();
    } while (choice < '0' || choice > '9');

    if (choice == '0')
      break;

    /* convert numerical character to corresponding value
       check the ASCII table if this doesn't make sense */
    choice -= '0';

    /* update game state & graphics */
    window_toggle (state, house, choice);
  }

  printf ("Goodbye!\n");

  return 0;
}