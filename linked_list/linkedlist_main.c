#include <stdio.h>
#include <stdint.h>
#include "linkedlist.h"

int reader(void *container, void *value)
{
	*(int *) container = (int *) value;
	return 0;
}

void ll_print(struct linked_list *list)
{
	if (list == NULL) {
		printf("list is NULL");
		return;
	}

	struct linked_list_node *curr = list->head;

	while (curr != NULL) {
		//printf("curr=%p\n", curr);
		printf("%d\n", (int *) curr->value);
		curr = curr->next;
	}
}

int main()
{
	struct linked_list *list;
	list = linked_list_create(&reader);

	/*
	linked_list_append(list, (int *) 10);
	linked_list_append(list, (int *) 11);
	linked_list_append(list, (int *) 12);
	*/

	for (int i = 0; i<10; linked_list_append(list, (int *) i), i++);

	printf("list size=%ld\n", list->length);

	size_t offset = 0;
	int *val;

	linked_list_read(list, val, offset);
	printf("val=%p\n", val);
	printf("list[%ld] = %d\n", offset, *(int *) val);

	offset++;

	linked_list_read(list, val, offset); 
	printf("list[%ld] = %d\n", offset, *(int *) val);

	ll_print(list);
	//linked_list_destroy(list);
	return 0;
}
