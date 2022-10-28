#include <stdint.h>
#ifndef AD_LINKEDLIST_H
#define AD_LINKEDLIST_H 1

typedef	int (*reader_function)(void **, void *);

struct linked_list_node {
	void	*value;
	struct	linked_list_node *next;
};

struct linked_list {
	size_t		length;
	reader_function reader;
	struct		linked_list_node *head;
};

struct	linked_list *
linked_list_create(reader_function reader);

struct	linked_list_node *
linked_list_node_create(void *value);

int
linked_list_read(struct linked_list *list, void** container, size_t index);

int
linked_list_append(struct linked_list *list, void *value);

int
linked_list_clear(struct linked_list *list);

int
linked_list_destroy(struct linked_list *list);

#endif
