/*
  nkr38
  Compile with: gcc -std=c89 -o reverse_linked_list reverse_linked_list.c
  I wrote this for practice and future reference. Makes a linked list, then prints each value of the list, then reverses and prints again.
*/

#include <stdlib.h>
#include <stdio.h>

struct list {
  int val;
  struct list *next;
};

void add_head(struct list **head, struct list *item)
{
  /*adds item to the list*/
  item->next = *head;
  *head = item;
}

void reverse(struct list **head)
{
  struct list *prev = NULL;
  struct list *cur = *head;
  struct list *next = NULL;

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
  *head = prev;
}

void print_list(struct list *head)
{
  int j = 1;
  struct list *item;

  for(item = head; item; item = item->next, j++)
    printf("%d: %d\n", j, item->val);
  printf("\n");
}
int main()
{
  int i = 1;
  struct list *item;
  struct list *head = NULL;

  for(; i<11; i++)
  {
    item = malloc(sizeof(*item));
    item->val = i*i;
    add_head(&head, item);
  }
  print_list(head);
  reverse(&head);
  print_list(head);
}
