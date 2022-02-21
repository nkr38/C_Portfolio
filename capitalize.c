/*********************************************************
 * Noah Robinson
 * Code takes a null-terminated string (char*), and replaces each lower-case letter with its upper-case counterpart.
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*********************************************************
 * This function takes a null-terminated string (char*), 
 * and replaces each lower-case letter with its upper-case counterpart.
 *******************************************************/
void capitalise( char *word )
{
    for(int i = 0; i < strlen(word); i++)
    {
        *(word+i) = toupper(*(word+i));
    }
    return;    
}
int main()
{
    char word[] = "fivehundred";

    capitalise(word);
    printf("word: %s\n", word);

	return 0 ;
}
