#ifndef SEG_LINKED_LIST_H
#define SEG_LINKED_LIST_H

typedef struct list_node {
	list_node * next;
	list_node * previous;
	void * data;
};

struct list_node * list_add_front(struct list_node * root, void * data);
struct list_node * list_add_back(struct list_node * root, void * data);
struct list_node * list_find(struct list_node * root, struct list_node * element);
struct list_alloc(void * data);

void list_traverse(struct list_node * root);
void list_update_key(struct list_node * root, void new_key);
void list_get_size(struct list_node * root);
void list_free(struct list_node * root);

#endif

