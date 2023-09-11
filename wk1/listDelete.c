#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

// delete the first instance of node with 'value' from the linked list
// returns the head of the linked list after this is complete
struct node *listDelete(struct node *list, int value) {
	// edge case: empty list
	if (list == NULL) return NULL;

	// edge case: if node to delete is first node
	if (list->value == value) {
		struct node *tmp = list->next;
		free(list);  // free the head
		return tmp;
	}

	struct node *curr = list;

	while (curr->next != NULL) {
		// if curr->next is the value we want to delete
		if (curr->next->value == value) {
			struct node *tmp = curr->next;
			curr->next = curr->next->next;
			free(tmp);
			return;
		}

		curr = curr->next;
	}

	return list;
}
