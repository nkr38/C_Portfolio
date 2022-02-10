#include <stdlib.h>
#include "list.h"

void list_init(struct list *head)
{
  head->next = head;
  head->prev = head;
}

void list_add_after(struct list *cur, struct list *new)
{
  new->next = cur->next;
  new->prev = cur;
  cur->next->prev = new;
  cur->next = new;
}

void list_add_before(struct list *cur, struct list *new)
{
  new->next = cur;
  new->prev = cur->prev;
  cur->prev->next = new;
  cur->prev = new;
}

void list_remove(struct list *cur)
{
  cur->prev->next = cur->next;
  cur->next->prev = cur->prev;
  cur->prev = NULL;
  cur->next = NULL;
}