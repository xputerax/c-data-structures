#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "linkedlist.h"

struct linked_list *
linked_list_create(reader_function reader)
{
	struct linked_list *ll = malloc(sizeof(struct linked_list));

	if (ll == NULL) {
		printf("Failed to allocate memory\n");
		return NULL;
	}

	ll->length = 0;
	ll->head = NULL;
	ll->reader = reader;

	return ll;
}

struct linked_list_node *
linked_list_node_create(void *value)
{
	struct linked_list_node *node = malloc(sizeof(struct linked_list_node));

	if (node == NULL) {
		printf("Failed to allocate memory for node\n");
		return NULL;
	}

	node->value = value;
	node->next = NULL;

	return node;
}

int
linked_list_append(struct linked_list *list, void* value)
{
	if (list == NULL) {
		return -1;
	}

	struct linked_list_node *curr = list->head;
	struct linked_list_node *new_node = linked_list_node_create(value);

	// case 1: list is empty
	if (list->length == 0) {
		list->head = new_node;
	}
       	else {
	// case 2: list is not empty
		while (curr->next != NULL) {
			curr++;
		}

		// arrived at tail
		curr->next = new_node;
	}

	list->length++;
	return 0;
}


int
linked_list_clear(struct linked_list *list)
{
	if (list == NULL) {
		return -1;
	}

	struct linked_list_node *curr = list->head;

	while (curr != NULL) {
		struct linked_list_node *next = curr->next;
		free(curr);
		curr = next;
		list->length--;
	}

	list->head = NULL;
	return 0;
}

int
linked_list_destroy(struct linked_list *list)
{
	if (list == NULL) {
		return -1;
	}

	linked_list_clear(list);
	free(list);

	return 0;
}

int
linked_list_read(struct linked_list *list, void *container, size_t offset)
{
	if (list == NULL || offset >= list->length) {
		return -1;
	}

	struct linked_list_node *curr = list->head;

	for (size_t i=0; i<offset; i++)
	{
		curr = curr->next;
	}

	(list->reader)(container, curr->value);

	return 0;
}
