#include "house.h"

/* Updates the graphics for the window @ coordinates (x, y) to match the
 * `state` array.
 *
 *   This function modifies the `house` array by updating the characters
 *   inside the window located at the zero indexed coordinates (x, y) to
 *   match the window's state in the `state` array.  If the window's
 *   state is 1, then the window is filled with the '#' character.
 *   Likewise, if the window's state is 0 in the `state` array, the
 *   window is filled with the ' ' character.
 *
 * Parameters:
 *   house -- pointer to characters representing the house
 *
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update_graphics (char *house, const int *state, int x, int y)
{
  /* Step 1: Write this function! */
  int i, j;
  /* Intitialize window starting point based off parameters (Starting point is top left window)*/
  int position, xoffset = x*18 + 11, yoffset = (y*6+8) * 69;
  position = xoffset + yoffset;

  /* loop down*/
  for(i = 0; i < 3; i++)
  {
    /* loop across*/
    for(j=0; j < 11; j++)
    {
        /* Are x & y pointing to a on or off light, if so change to on characters
           or otherwise change to off characters */
        if (state[x+(y*3)] == 0)
        {
          /*row num * row length + x position + window position*/
          house[(i*69) + j + position] = ' ';
        }
        else if (state[x+(y*3)] == 1)
        {
          house[(i*69) + j + position] = '#';
        }
    }
  }
}


/* Toggles the state of the window @ coordinates (x, y) in the game
 * state array.
 *
 *   This function modifies the `state` array by toggling the value
 *   corresponding to the window at the provided coordinates (x, y).  If
 *   the current value is 1, then it will be toggled to 0.  Likewise, if
 *   the current value is 0, then it will be toggled to 1.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_toggle_state (int *state, int x, int y)
{
  /* Step 2: Write this function! */
  
  /*flip true to false or false to true*/
  if(state[x+(y*3)] == 1)
  {
    state[x+(y*3)] = 0;
  }
  else
  {
    state[x+(y*3)] = 1;
  }
}


/* Toggles the state and, correspondingly, updates the graphics for the
 * window @ coordinates (x, y).
 *
 *   Given the zero indexed coordinates (x, y) of a window, this
 *   function ensures that the corresponding element in the game state
 *   array is toggled appropriately and that the graphics corresponding
 *   to that window are updated appropriately to reflect the new state.
 *
 *   Hint: call other functions you have written to make this easier.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *   house -- pointer to characters representing the house
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update (int *state, char *house, int x, int y)
{
  /* Step 2: Write this function! */
  window_toggle_state(state, x, y);
  window_update_graphics(house, state, x, y);
}


/* Toggles the lights based on the user's window selection.
 *
 *   Given the user's choice of window number, this function updates the
 *   corresponding window's (or windows') state and graphics, as
 *   necessary.
 *
 *   Hints:
 *     -- A primary job of this function will be to convert the choice
 *        of the user into the zero indexed (x, y) coordinates of a
 *        window.
 *
 *     -- Converting between `choice` and the (x, y) coordinates will
 *        probably be easier if you internally number the windows
 *        starting at zero (i.e. 0 thru 8 instead of 1 thru 9).
 *
 *     -- This function will need to call one other function
 *        (perhaps multiple times).
 *
 *   For Step 2, this function will only toggle the window
 *   corresponding to the user's selection.
 *
 *   For Step 3, this function will toggle the selected window
 *   and its neighbors (as described above in the instructions).
 *
 * Parameters:
 *    state -- pointer to the game state array
 *
 *    house -- pointer to characters representing the house
 *
 *   choice -- integer corresponding to the user's window selection
 *             (an integer value within the range 1 to 9)
 */
void window_toggle (int *state, char *house, int choice)
{
  /* Step 2: Write this function! (for single window toggle) */
  
  int choice_x, choice_y;
  /* Change to 0-8 instead of users 1-9*/
  choice -= 1;
  /* Mod remainder gives the column and devision will give the rounded down remainder      for the row number */
  choice_x = choice % 3; choice_y = choice / 3;
  /* Update board
  window_update(state, house, choice_x, choice_y); */

  /* Step 3: Rewrite this function! (for multi-window toggle) */
  /* This is bad code I know :( */
  if (choice_x == 0 && choice_y == 0)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 0, 1);
    window_update(state, house, 1, 0);
  }
  else if (choice_x == 1 && choice_y == 0)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 0, 0);
    window_update(state, house, 2, 0);
    window_update(state, house, 1, 1);
  }
  else if (choice_x == 2 && choice_y == 0)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 1, 0);
    window_update(state, house, 2, 1);
  }
  else if (choice_x == 0 && choice_y == 1)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 0, 0);
    window_update(state, house, 1, 1);
    window_update(state, house, 0, 2);
  }
  else if (choice_x == 1 && choice_y == 1)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 1, 0);
    window_update(state, house, 0, 1);
    window_update(state, house, 2, 1);
    window_update(state, house, 1, 2);
  }
  else if (choice_x == 2 && choice_y == 1)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 2, 0);
    window_update(state, house, 1, 1);
    window_update(state, house, 2, 2);
  }
  else if (choice_x == 0 && choice_y == 2)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 0, 1);
    window_update(state, house, 1, 2);
  }
  else if (choice_x == 1 && choice_y == 2)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 1, 1);
    window_update(state, house, 0, 2);
    window_update(state, house, 2, 2);
  }
  else if (choice_x == 2 && choice_y == 2)
  {
    window_update(state, house, choice_x, choice_y);
    window_update(state, house, 1, 2);
    window_update(state, house, 2, 1);
  }
}