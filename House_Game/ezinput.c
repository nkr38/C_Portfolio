/* ezinput.c
 * James A. Shackleford, 2021 (C)
 *
 * This file provides the utility function ezinput(),
 * which prompts the user to enter a single character.
 *
 *   - The user is not allowed to enter more than 1 character.
 *
 *   - Once Enter is pressed, the character is accepted and
 *     is returned by ezinput().
 *
 *   - If less than one character is entered before pressing
 *     Enter, ezinput() continues to wait for input.
 *
 *   - The user may press Backspace before pressing Enter to 
 *     modify their input.
 *
 *   - Non-printable characters are suppressed and are not
 *     registered by ezinput() as valid input.
 *
 * I am providing ezinput() because scanf() can be difficult
 * to use within a looping construct. The ezinput() function
 * will make getting keyboard much easier for you!
 *
 * You do not need to know how this function works.
 * You can simply use it!
 */

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define BACKSPACE 0x7F

char ezinput()
{
  struct termios t;
  char c, ret = 0;
  static int init = 0;

  if (!init) {
    init = 1;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
  }

  while (1) {
    c = (char)getchar();
    if (!ret) {
      ret = (c < ' ' || c > '~') ? 0 : (putchar(c), c);
    } else {
      switch(c) {
      case '\n':
        putchar('\n');
        return ret;
      case BACKSPACE:
        ret = 0;
        printf("\b \b");
        fflush(stdout);
      }
    }
  }
}