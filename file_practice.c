/* Homework 5: Question 3
   Compile with: gcc -std=c89 -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/

#include <stdio.h>
#include <string.h>  /* hint! */

/* structure defining a menu item
   specifically, a menu item's name and what it should do */
struct menu {
  char *cmd_name;
  void (*cmd_ptr)();
};


void file_new()
{
  printf("Created New File.\n");
}

void file_open()
{
  printf("Opened File.\n");
}

void file_close()
{
  printf("Closed File.\n");
}

void file_save()
{
  printf("File Saved.\n");
}

void file_print()
{
  printf("Printing File...\n");
}

void file_exit()
{
  printf("Goodbye.\n");
}


/* global variable 'file': array of structs */
struct menu file[] = {
  {"new",     file_new},      /* file[0] */
  {"open",    file_open},     /* file[1] */
  {"close",   file_close},    /* file[3] */
  {"save",    file_save},
  {"print",   file_print},
  {"exit",    file_exit}      /* file[5] */
};


void do_file_menu(char *name)
{
  /* Your code goes here. */

  /* This function searches the file[] array for the
   * structure with the supplied name.  If found, then
   * the corresponding function is called.  Otherwise,
   * "Invalid menu option." is printed to the screen.
   *
   * If you have done this well, more items could be added
   * to the file[] array and this function would still work
   * correctly without modification.
   *
   * Hint: This function is very short (less than 10 lines).
   */
  int i, length, found = 0; /*found true/false */

  length = sizeof file / sizeof *file;

  for(i = 0; i < length; i++)
    if(!strcmp(file[i].cmd_name, name))
    {
     file[i].cmd_ptr(); 
      found = 1;
    }
  if(found == 0)
  {
    printf("Invalid menu option.\n"); 
  }

  return;
}


int main()
{
  /* test all the menu options one by one */
  do_file_menu("new");
  do_file_menu("open");
  do_file_menu("close");
  do_file_menu("save");
  do_file_menu("print");
  do_file_menu("exit");

  /* test behavior of supplying invalid menu options */
  do_file_menu("invalid");
  do_file_menu("badmenuitem");
  
  return 0;
}