#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int elem;
	struct node *left;
	struct node *right;
};

typedef struct node *BSTree;

// returns the number of odd values in a binary search tree
int bstCountOdds(struct node *t) {
	if (t == NULL) return 0;

	// the number of odd nodes in the left sub tree
	return bstCountOdds(t->left) + bstCountOdds(t->right) + (t->elem % 2 == 1) ?
	           1 :
	           0;
}

// count number of internal nodes in a given tree
// an internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;

	return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1
// (when a given key is not in the binary search tree)
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
	if (t == NULL) return -1;
	if (t->elem == key) return 0;

	if (key < t->elem) {
		int result = bstNodeLevel(t->left, key);
		if (result == -1) {
			return -1;
		} else {
			return result + 1;
		}
	} else {
		int result = bstNodeLevel(t->right, key);
		if (result == -1) {
			return -1;
		} else {
			return result + 1;
		}
	}
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit
int bstCountGreater(struct node *t, int val) {
	if (t == NULL) return 0;

	if (t->elem <= val) {
		return bstCountGreater(t->right, val);
	} else {
		return 1 + bstCountGreater(t->left, val) +
		       bstCountGreater(t->right, val);
	}
}

#define NOT_HEIGHT_BALANCED -99

// returns the height of a given binary tree if it is height - balanced,
// and NOT_HEIGHT_BALANCED otherwise.
// Height-balanced tree: We say that a basic binary tree is height-balanced if,
//      for every node, the absolute difference between the height of the left
//      subtree and the height of the right subtree is one or less. In other
//      words, every node needs to satisfy the following criteria:
//      abs(height(left) - height(right)) ≤ 1
int isHeightBalanced(struct node *t) {
	if (t == NULL) return -1;

	int resultRight = isHeightBalanced(t->right);
	if (resultRight == NOT_HEIGHT_BALANCED) {
		return NOT_HEIGHT_BALANCED;
	}
	int resultLeft = isHeightBalanced(t->left);
	if (resultLeft == NOT_HEIGHT_BALANCED) {
		return NOT_HEIGHT_BALANCED;
	}

	if (abs(resultLeft - resultRight) > 1) {
		return NOT_HEIGHT_BALANCED;
	}

	return max(resultLeft, resultRight) + 1;
}

// challenging question!
// return the kth largest node in the binary search tree
int kthSmallest(struct node *t, int k) {
	// TODO
	return 0;
}
