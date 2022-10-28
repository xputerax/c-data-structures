#include <stdio.h>
#include <stdint.h>
#include "linkedlist.h"

union void_cast
{
    void *p;
    int v;
};

int void_to_int(void *p) {
    union void_cast x;
    x.p = p;
    return x.v;
}

int reader(void **container, void *value)
{
	int **ctr = (int **) container;
	int *val = (int *) value;

	//printf("*ctr = %d | val = %d\n", *ctr, val);

	*ctr = val;
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
		printf("%d\n", void_to_int(curr->value));
		curr = curr->next;
	}

	//printf("%d\n", curr->value);
}

int main()
{
	struct linked_list *list;
	list = linked_list_create(&reader);

	linked_list_append(list, (int *) 10);
	linked_list_append(list, (int *) 11);
	linked_list_append(list, (int *) 12);

	printf("list size=%ld\n", list->length);

	size_t offset = 0;
	void *val = 0;

	linked_list_read(list, &val, offset);
	printf("list[%ld] = %d\n", offset, void_to_int(val));
	offset++;

	linked_list_read(list, &val, offset);
	printf("list[%ld] = %d\n", offset, void_to_int(val));
	offset++;

	linked_list_read(list, &val, offset);
	printf("list[%ld] = %d\n", offset, void_to_int(val));


	//ll_print(list);
	//linked_list_destroy(list);
	return 0;
}
