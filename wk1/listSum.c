#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

// return the sum of nodes in a linked list, given its head
// ! use a while loop
int listSum(struct node *list) {
	int sum = 0;

	struct node *curr = list;

	while (curr != NULL) {
		sum += curr->value;
		curr = curr->next;
	}

	return sum;
}

// return the sum of nodes in a linked list, given its head
// ! use a for loop
int listSum(struct node *list) {
	int sum = 0;

	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		sum += curr->value;
	}

	return sum;
}
