/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 100

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person* a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a[], size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[CAP] = { NULL } ; /* rest are initialised to 0 */

	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] ) ;
			exit( 1 ) ;
		}
	}

	readPeople( team, fin ) ;
	//print
	int i = 0;
	while(team[i] != NULL)
	{
		printf("%s, %s, %d\n",team[i]->last,team[i]->first,team[i]->age);
		i++;
	}
	//free
	freePeople( team, CAP ) ;
	
	return 0 ;
}
/*
* readPeople - Takes array of struct people and a file to read from
* 	Function does the following:
*	Reads a last name 
*	continues and gets memory for person if that last name exists
*	reads first name and age and puts it into the array 
*/
void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;

	while( getline( &buff, &len, f ) > 1 ) 
	{
		buff[ strlen(buff)-1 ] = '\0' ; 
        sscanf(buff, "%s", buff) ;

		if(strcmp(buff, "\0") != 0)
		{
			/*last name*/
			a[cnt] = malloc(sizeof(person));
			strcpy(a[cnt]->last, buff);

			/*first name*/
			getline( &buff, &len, f );
			buff[ strlen(buff)-1 ] = '\0' ; 
			sscanf(buff, "%s", a[cnt]->first) ;

			/*age*/
			getline( &buff, &len, f );
			sscanf(buff, "%s", buff) ;
			a[cnt]->age = atoi(buff);
			
		}
		++cnt ;
	}

	free( buff ) ;
}

/*
* 	freePeople - Takes array of struct people and the number of max elements
* 	Function frees each element
*/
void freePeople( person* a[], size_t n ) 
{
	// Do NOT assume array is dense.  Check every element for a non-NULL pointer
	for(int i = 0; i < n; i++)
	{
		//for a non-NULL pointer
		if(a[i] != NULL)
		{
			free(a[i]);
			a[i]=NULL;
		}
	}
	
	return;
}
