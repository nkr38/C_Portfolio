#ifndef _window_h_
#define _window_h_

void window_update_graphics (char *house, const int *state, int x, int y);
static void window_toggle_state (int *state, int x, int y);
void window_update (int *state, char *house, int x, int y);
void window_toggle (int *state, char *house, int choice);

#endif