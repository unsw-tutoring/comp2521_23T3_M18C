// Set Implementation by z5422179
// using a binary search tree

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

struct node {
	int elem;
	struct node *left;
	struct node *right;
};

struct set {
	struct node *root;
	int size;
};

static void nodeFree(struct node *n);
static struct node *nodeNew(int elem);
static struct node *nodeInsert(struct node *n, int elem);
static struct node *nodeDelete(struct node *n, int elem);

// Creates a new empty set
Set SetNew(void) {
	Set s = malloc(sizeof(struct set));
	s->root = NULL;
	s->size = 0;
	return s;
}

// Frees memory allocated to the set
void SetFree(Set s) {
	nodeFree(s->root);
	free(s);
}

// Inserts an element into the set
void SetInsert(Set s, int elem) {
	if (SetContains(s, elem)) return;

	s->root = nodeInsert(s->root, elem);
	s->size++;
}

// Deletes an element from the set
void SetDelete(Set s, int elem) {
	if (!SetContains(s, elem)) return;

	s->root = nodeDelete(s->root, elem);
	s->size--;
}

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem) {
	struct node *temp = s->root;
	while (temp != NULL) {
		if (elem < temp->elem) {
			temp = temp->left;
		} else if (elem > temp->elem) {
			temp = temp->right;
		} else {
			return true;
		}
	}
	return false;
}

// Returns the number of elements in the set
int SetSize(Set s) {
	return s->size;
}

static struct node *nodeNew(int elem) {
	struct node *n = malloc(sizeof(struct node));
	n->elem = elem;
	n->left = NULL;
	n->right = NULL;
	return n;
}

static struct node *nodeInsert(struct node *n, int elem) {
	if (n == NULL) return nodeNew(elem);
	if (elem < n->elem) {
		n->left = nodeInsert(n->left, elem);
	} else if (elem > n->elem) {
		n->right = nodeInsert(n->right, elem);
	}

	return n;
}

static struct node *nodeDelete(struct node *n, int elem) {
	if (n == NULL) return NULL;
	if (elem < n->elem) {
		n->left = nodeDelete(n->left, elem);
	} else if (elem > n->elem) {
		n->right = nodeDelete(n->right, elem);
	} else {
		if (n->left == NULL && n->right == NULL) {
			free(n);
			return NULL;
		} else if (n->left == NULL) {
			struct node *temp = n->right;
			free(n);
			return temp;
		} else if (n->right == NULL) {
			struct node *temp = n->left;
			free(n);
			return temp;
		} else {
			struct node *temp = n->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			n->elem = temp->elem;
			n->right = nodeDelete(n->right, temp->elem);
		}
	}
	return n;
}

static void nodeFree(struct node *n) {
	if (n == NULL) return;
	nodeFree(n->left);
	nodeFree(n->right);
	free(n);
}
