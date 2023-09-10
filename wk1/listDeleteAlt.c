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
	// TODO
	return;
}
