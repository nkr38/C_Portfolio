/**********************************************************************************
 * fsm.c
 *
 * Programmer - Noah Robinson (nkr38)
 * NOTES:
 *      Processes a stream of messages line by line (either over stdin or read 
 *      from a file). If the entire message matches any of the DFA
 *      patterns, the code will print the message, followed by a space, 
 *      followed by the text OK. If the text on the line matches none of the DFA 
 *      patterns, the code will print the message and the 
 *      text FAIL.
 * 
 * 	Make targets:   
 * 	view
 *		Lists source code
 *	fsm
 *		Compiles all source into an executable called fsm.
 *	clean
 *		Cleans up any object/intermediate files, if there are any.
 ********************************************************************************/

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Stores next state for fsm*/
void (*state)(char);

/*Dee*/
void dee1(char);
void dee2(char);
void dee3(char);
void dee4(char);
/*Dum*/
void dum1(char);
void dum2(char);
void dum3(char);
/*Cheshire*/
void chesh1(char);
void chesh2(char);
void chesh3(char);
void chesh4(char);

/* dee1: state function for E1		    */
/* takes one char input, sets the next state*/
void dee1(char c)
{
	switch(c)
	{
		case '0':
			state = dee2;
			break;
		case '1':
			state = dee1;
			break;
		case '2':
			state = dee3;
			break;
	}
	return;
}

/* dee2: state function for EF		    */
/* takes one char input, sets the next state*/
void dee2(char c)
{
	switch(c)
	{
		case '0':
			state = dee2;
			break;
		case '1':
			state = dee1;
			break;
		case '2':
			state = dee3;
			break;
	}
	return;
}

/* dee3: state function for O1		    */
/* takes one char input, sets the next state*/
void dee3(char c)
{
	switch(c)
	{
		case '0':
			state = dee3;
			break;
		case '1':
			state = dee4;
			break;
		case '2':
			state = dee1;
			break;
	}
	return;
}

/* dee4: state function for OF		    */
/* takes one char input, sets the next state*/
void dee4(char c)
{
	switch(c)
	{
		case '0':
			state = dee3;
			break;
		case '1':
			state = dee4;
			break;
		case '2':
			state = dee1;
			break;
	}
	return;
}

/* dum1: state function for state 1 in dum  */
/* takes one char input, sets the next state*/
void dum1(char c)
{
	switch(c)
	{
		case '0':
			state = dum2;
			break;
		case '1':
			state = dum1;
			break;
		case '2':
			state = dum1;
			break;
	}
	return;
}

/* dum2: state function for state 2 in dum  */
/* takes one char input, sets the next state*/
void dum2(char c)
{
	switch(c)
	{
		case '0':
			state = dum3;
			break;
		case '1':
			state = dum2;
			break;
		case '2':
			state = dum2;
			break;
	}
	return;
}

/* dum3: state function for state 3 in dum  */
/* takes one char input, sets the next state*/
void dum3(char c)
{
	switch(c)
	{
		case '0':
			state = dum1;
			break;
		case '1':
			state = dum3;
			break;
		case '2':
			state = dum3;
			break;
	}
	return;
}

/* chesh1: state function for state 1 in cheshire*/
/* takes one char input, sets the next state     */
void chesh1(char c)
{
	switch(c)
	{
		case '0':
			state = chesh1;
			break;
		case '1':
			state = chesh1;
			break;
		case '2':
			state = chesh2;
			break;
	}
	return;
}

/* chesh2: state function for state 2 in cheshire*/
/* takes one char input, sets the next state     */
void chesh2(char c)
{
	switch(c)
	{
		case '0':
			state = chesh1;
			break;
		case '1':
			state = chesh1;
			break;
		case '2':
			state = chesh3;
			break;
	}
	return;
}

/* chesh3: state function for state 3 in cheshire*/
/* takes one char input, sets the next state     */
void chesh3(char c)
{
	switch(c)
	{
		case '0':
			state = chesh4;
			break;
		case '1':
			state = chesh1;
			break;
		case '2':
			state = chesh3;
			break;
	}
	return;
}
/* chesh4: state function for state 4 in cheshire*/
/* takes one char input, sets the next state     */
void chesh4(char c)
{
	switch(c)
	{
		case '0':
			state = chesh1;
			break;
		case '1':
			state = chesh1;
			break;
		case '2':
			state = chesh2;
			break;
	}
	return;
}

/* main: Calls each state based off the chars in each line */
/* Will use stdin as input if no file is given as argument */
/* Prints each message as OK or FAIL based what state the  */
/* message ends in 					   */
int main( int argc, char **argv )
{
	FILE *fin = stdin;
	char *buff = NULL;
	size_t len;
	int pass[100];
	char msg[100][100];
	char temp[100];
	int cnt = 0;

	if( argc>1 ) 
	{
		fin = fopen( argv[1], "r" );
		if( fin == NULL ) 
		{
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] );
			exit( 1 );
		}
	}

    while( getline( &buff, &len, fin ) > 1 )
	{
        sscanf(buff, "%s", temp);
		strcpy(msg[cnt], temp);

        switch(temp[0])
		{
			case 'D':
				state = dee1;
				for (int i = 1; i < strlen(temp); i++)
				{
					state(temp[i]);
				}
				if(state == dee2 || state == dee4)
				{
					pass[cnt] = 1;
				}
				else
				{
					pass[cnt] = 0;
				}
				break;
			case 'M':
				state = dum1;
				for (int i = 1; i < strlen(temp); i++)
				{
					state(temp[i]);
				}
				if(state == dum1)
				{
					pass[cnt] = 1;
				}
				else
				{
					pass[cnt] = 0;
				}
				break;
			case 'C':
				state = chesh1;
				for (int i = 1; i < strlen(temp); i++)
				{
					state(temp[i]);
				}
				if(state == chesh4)
				{
					pass[cnt] = 1;
				}
				else
				{
					pass[cnt] = 0;
				}
				break;
			case 'T':
				if(temp[1] == '0' || temp[1] == '1' )
				{
					if(temp[2] == 'D')
					{
						state = dee1;
						for (int i = 1; i < strlen(temp); i++)
						{
							state(temp[i]);
						}
						if(state == dee2 || state == dee4)
						{
							pass[cnt] = 1;
						}
						else
						{
							pass[cnt] = 0;
						}
					}
					else if(temp[2] == 'M')
					{
						state = dum1;
						for (int i = 3; i < strlen(temp); i++)
						{
							state(temp[i]);
						}
						if(state == dum1)
						{
							pass[cnt] = 1;
						}
						else
						{
							pass[cnt] = 0;
						}
					}
					else
					{
						pass[cnt] = 0;
					}
				}
				else
				{
					pass[cnt] = 0;
				}
				break;
			case '*':
				pass[cnt] = 0;
				break;
		}
		cnt++;

	}
	for(int i = 0; i < cnt; i++)
	{
		if(pass[i] == 1)
		{
			printf("%s OK\n", msg[i]);
		}
		else
		{
			printf("%s FAIL\n", msg[i]);
		}
	}

	free(buff);

	return 0 ;
}
