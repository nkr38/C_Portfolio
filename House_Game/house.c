#include <stdio.h>
#include "house.h"
#include "window.h"

/* Prints the characters in the house array to the screen
 *
 * Parameters:
 *   house -- pointer characters representing the house
 */
void house_display (const char *house)
{
  int x, y;

  for (y=0; y<HOUSE_HEIGHT; y++, printf("\n"))
    for (x=0; x<HOUSE_WIDTH; x++)
      printf ("%c", house[HOUSE_WIDTH * y + x]);
}


/* Initializes the graphics for each of the 9 windows.
 *
 *   Cycles through the 9 windows and fills each window in the `house`
 *   array of chars with either ' ' or '#' characters depending on the
 *   current state of the window in the state array by calling
 *   `window_update_graphics()` for each window individually.
 *
 * Parameters:
 *   house -- pointer to characters representing the house
 *
 *   state -- pointer to the game state array
 */
void house_init (char *house, const int *state)
{
  int x, y;

  for (y=0; y<3; y++)
    for (x=0; x<3; x++)
      window_update_graphics (house, state, x, y);
}