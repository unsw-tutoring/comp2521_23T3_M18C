#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

// delete the first instance of node with 'value' from the linked list
void listDelete(struct list *list, int value) {
	// edge case: if list is empty
	if (list->head == NULL) return;

	// edge case: if node to delete is first
	if (list->head->value == value) {
		struct node *tmp = list->head->next;
		free(list->head);
		list->head = tmp;
		return;
	}

	for (struct node *curr = list->head; curr->next != NULL;
	     curr = curr->next) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			return;
		}
	}
}
