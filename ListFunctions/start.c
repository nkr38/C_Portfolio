/*
 * start.c - a test driver for the List in Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 * NOTES
 *  - you can have more than one driver, to test various functions as you implement them, if desired
 *    - Add other entries similar to `start' to your makefile
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "act8.h"

int main()
{
	int arr[] = { 37, 7, 62, 7, 40, 200, 7, 13, 15, 3 } ;
	size_t n, lol;
	sNode* new;
	List l = make_list( arr, 10 ) ;

	printList( l, stdout ) ;

	new = listRev(l);
	printf("\n");
	printList( new, stdout ) ;
	/*n = listLength(l);
	printf("\nCount: %ld\n", n);

	lol = count(l, 7);
	printf("\nOccurances: %ld\n", lol);

	List new_l = remove_first(l, 7);
	printList( new_l, stdout ) ;	*/

	return 0 ;
}
