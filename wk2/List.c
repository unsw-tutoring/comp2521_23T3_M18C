#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

// create a new empty list
List ListNew() {
	return NULL;
}

// add item to end of list
List ListAdd(List l, int val) {
	// malloc a new node
	List newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = val;

	// if empty list
	if (l == NULL) {
		return newNode;
	}

	// add to end of list
	List curr = l;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	return l;
}

// delete the first item with value 'val' from list -- recursively
// if 'val' is not in the list, do nothing
// returns the head of the new linked list
List ListDelete(List l, int val) {
	// base cases
	// if list is empty
	if (l == NULL) return NULL;
	// if node to delete is first value
	if (l->data == val) {
		List restOfList = l->next;
		free(l);
		return restOfList;
	}
	l->next = ListDelete(l->next, val);
	return l;
}

// delete all odd numbers from list -- recursively
List ListDeleteOdds(List l) {
	// TODO
	return NULL;
}

// delete every second node (second, fourth, sixth, etc. node)
List ListDeleteSecond(List l) {
	// TODO
	return NULL;
}

// prints out the linked list
void ListPrint(List l) {
	// TODO
}

// prints out the linked list in reverse
void ListPrintReverse(List l) {
	// TODO
}

// returns length of linked list
int ListLength(List l) {
	// TODO
	return 0;
}

// returns number of odd nodes in linked list
int ListCountEvens(List l) {
	// TODO
	return 0;
}

// check if list is sorted in non-descending order
bool ListIsSorted(List l) {
	// TODO:
	return false;
}

// ! THE FOLLOWING TWO EXAMPLES SHOW TWO COMMON TRICKS / TECHNIQUES YOU CAN
// ! USE WHEN CODING RECURSIVELY. TAKE NOTE OF THESE.

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransform(List l) {
	// TODO
	return;
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransformAlternate(List l) {
	// TODO
	return;
}
