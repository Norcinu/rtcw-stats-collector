#include "linked_list.h"

struct list_node * list_alloc (void * data) {
	struct list_node* node = (struct list_node*)malloc(sizeof(struct list_node));
	if (node != NULL) {
		node->next = NULL;
		node->previous = NULL;
		node->data = data;
	}
	return node;
}
