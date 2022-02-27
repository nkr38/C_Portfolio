/*
 * nodeLists.c - implementations for list functions, count and reverse
 *
 * Noah Robinson
 * FEB 27
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "act8.h"

void printList( List p, FILE* fout ) 
{
	fputs( "<", fout ) ;
	if( p!=NULL )
	{
		fprintf( fout, "%hd", p->data ) ;
		p = p->next ;
	}
	while( p!=NULL )
	{
		fprintf( fout, ", %hd", p->data ) ;
		p = p->next ;
	}
	fputs( ">", fout ) ;
}


List make_list( int a[], size_t n )
{
	List rv = NULL ;

	if( n==0 )
		return rv ;
	
	rv = make_list( a+1, n-1 ) ;

	sNode* t = (sNode*) malloc( sizeof( sNode )) ;
	if( t==NULL ) return NULL ;

	t->data = a[0] ;
	t->next = rv ;
	rv = t ;

	return rv ;
}


List rand_list( size_t n )
{
	if( n==0 )
		return NULL ;

	List rv = NULL ;
	sNode *t = NULL ;
	
	for( size_t i=0; i<n; ++i )
		;
}
/* 
*	listLength - Takes a list as parameter and returns how many elements are found before NULL
*/
size_t listLength( const sNode *L ) 
{
	size_t n = 0;

	while(L != NULL)
	{
		n++;
		L = L->next;
	}

	return n;
}

size_t count( sNode* p, int t )
{
	size_t n = 0;

	while(p != NULL)
	{
		if(p->data == t)
		{
			n++;
		}
		p = p->next;
	}

	return n;
}

List remove_first( sNode *head, int t)
{
	size_t found = 0;
  	sNode* prev = NULL;
  	sNode* current = head;

  	while (current != NULL) 
	{
    	if (current->data == t) 
		{
			if(current == head)
			{
				head = head->next;
				free(current);
				current = head;
				found = 1;
			}
			else
			{
				prev->next = current->next;
				free(current);
				current = prev->next;
				found = 1;
			}
			if(found == 1)
			{
				return head;
			}
    	}
		else
		{ 
			prev = current;
			current = current->next;
		}
  	}
  
	return head;
}

List remove_all( sNode *head, int t)
{
  	sNode* prev = NULL;
  	sNode* current = head;

  	while (current != NULL) 
	{
    	if (current->data == t) 
		{
			if(current == head)
			{
				head = head->next;
				free(current);
				current = head;
			}
			else
			{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
    	}
		else
		{ 
			prev = current;
			current = current->next;
		}
  	}
  
	return head;
}
/* 
*	listRev - Takes a list as a parameter and returns the list with reversed nodes
*/
sNode* listRev( sNode *L )
{
  sNode *prev = NULL;
  sNode *cur = L;
  sNode *next = NULL;

  while(cur != NULL)
  {
    /*store the current next*/
    next = cur->next;
    /*reverse current item*/
    cur->next = prev;
    /*move pointers one position forward*/
    prev = cur;
    cur = next;
  }
  L = prev;
  return L;
}
