/*
 * act8.h - interface for list functions, Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 */

#ifndef __KS_ACT_8_H_
#define __KS_ACT_8_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct sNode sNode ;

struct sNode
{
   int data ;
   sNode* next ;
};

typedef sNode* List ;

	// make_list - creates list, given sequence of n elements in a
	// Note, returned list must be returned to the heap
List make_list( int a[], size_t n ) ;

	// rand_list - return random list of size n
	// TODO (kurt)
List rand_list( size_t n ) ;

	/* TODO together */
void printList( List, FILE* ) ;
void freeList( List ) ;

	/* TODO */
size_t listLength( const sNode *L ) ;
size_t count( List, int t ) ;
List remove_first( List, int t ) ;
List remove_all( List, int t ) ;
sNode* listRev( sNode *L ) ;

#endif  // __KS_ACT_8_H_

