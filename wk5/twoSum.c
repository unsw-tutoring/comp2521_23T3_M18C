#include <stdbool.h>
#include <stdio.h>

#include "BST.h"

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// O(n^2) solution
bool hasTwoSum(int *arr, int n, int sum) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == sum) {
				return true;
			}
		}
	}
	return false;
}

// use a binary search tree
bool hasTwoSum(int *arr, int n, int sum) {
	// TODO
	BSTree t = BSTreeNew();  // O(1)

	// n log n
	for (int i = 0; i < n; i++) {  // n times
		BSTInsert(t, arr[i]);      // log n
	}

	// n log n
	for (int i = 0; i < n; i++) {  // n times
		int val = arr[i];
		int thingwewant = sum - val;
		if (BSTSearch(t, thingwewant)) {  // log n
			return true;
		}
	}

	return false;
}
