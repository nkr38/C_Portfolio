/* Homework 6: Question 3
   Compile with: gcc -std=c89 -o Q3 Q3.c
   Then run your compiled program with: ./Q3
   Creates a linked list of size 10 and then prints each one before removing them all one by one.
*/

#include <stdlib.h>
#include <stdio.h>

struct list {
  int val;
  struct list *next;
};

void list_add_head(struct list **head, struct list *item)
{
  item->next = *head;
  *head = item;
}

struct list *list_pop_head(struct list **head)
{
  struct list *cur;

  cur = *head;
  if (cur) {
    *head = cur->next;
    cur->next = NULL;
  }

  return cur;
}

int list_count(struct list *head)
{
  int counter = 0;
  struct list *item;

  for (item = head; item; item = item->next)
  {
    counter += 1;
  }

  return counter;
}

struct list *list_pop_tail(struct list **head)
{
  struct list *item;
  struct list *current;

  if(*head == NULL)
  {
    item = NULL;
    return item;
  }
  else if((*head)->next == NULL)
  {
    item = *head;
    *head = NULL;
    /*printf("Im working %d\n", item->val);*/
    return item;
  }

  item = *head;
  current = item ->next;
  /*printf("Before while %d %d \n", item->val, current->val);*/

  while(current->next != NULL)
  {
    item = item->next;
    current = current->next;
  }
  item ->next = NULL;

  return current;
}

int main()
{
  int i;
  struct list *item;
  struct list *head = NULL;

  /* load up the list with ten items */
  for (i=0; i<10; i++) {
    item = malloc(sizeof(*item));
    item->val = i;
    list_add_head(&head, item);
    printf("Added %p (val: %d) to list.\n", item, item->val);
  }

  printf("# of items: %d\n", list_count(head));

  /* remove each item and print its value */
  while (item = list_pop_tail(&head)) {
    printf("Removed %p (val: %d)\n", item, item->val);
    free(item);
  }

  return 0;
}
