#ifndef _dict_h_
#define _dict_h_

struct list {
    char *key;
    unsigned long hash;
    void *user_data;
    struct list *next;
};

struct dict {
    struct list **bins;
    unsigned int nbins;
    unsigned long int count;    /* this line is new */
    void (*deleter)(void *user_data);
};


int dict_init(struct dict *D, void (*deleter)(void *user_data));
void dict_destroy(struct dict *D);

int dict_insert(struct dict *D, const char *key, void *user_data);
void dict_delete(struct dict *D, const char *key);

void *dict_peek(struct dict *D, const char *key);
void *dict_pop(struct dict *D, const char *key);

float dict_loadfactor(struct dict *D);

#endif /* _dict_h_ */