#ifndef _house_h_
#define _house_h_

/* Helpful Constants:
 *   -- The house is 69 characters wide
 *   -- The house is 26 characters high
 *   -- Each window interior is 11 characters wide
 *   -- Each window interior is 3 character high
 */
#define HOUSE_WIDTH   69
#define HOUSE_HEIGHT  26
#define WINDOW_WIDTH  11
#define WINDOW_HEIGHT  3


void house_display (const char *house);
void house_init (char *house, const int *state);

#endif