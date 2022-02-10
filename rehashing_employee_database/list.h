#ifndef _list_h_
#define _list_h_

#include <stddef.h>

#ifndef container_of
#define container_of(_mptr, type, member) \
  (type*)((char*)_mptr - offsetof(type, member))
#endif

#define list_for(head, cur) \
  for(cur = head->next; cur != head; cur = cur->next)

#define list_safe_for(head, cur, sav)      \
  for(cur = head->next, sav = cur->next;   \
    cur != head;                           \
    cur = sav, sav = cur->next)


struct list {
  struct list *next;
  struct list *prev;
};

void list_init(struct list *head);
void list_add_after(struct list *cur, struct list *new);
void list_add_before(struct list *cur, struct list *new);
void list_remove(struct list *cur);

#endif  /* _list_h_ */