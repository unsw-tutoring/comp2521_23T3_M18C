#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

// given an array of integers and a target sum S,
// determine whether the array contains two integers that sum to sum
// aim for O(n) average/expected time complexity
bool twoSum(int arr[], int size, int sum) {
	// TODO
	HashTable ht = HashTableNew();

	for (int i = 0; i < size; i++) {
		HashTableInsert(ht, arr[i], arr[i]);
	}

	for (int i = 0; i < size; i++) {
		if (HashTableContains(ht, sum - arr[i])) {
			return true;
		}
	}

	return false;
}

// given an array of integers and a target sum S,
// determine whether the array contains three integers that sum to S.
// aim for O(n^2) average/expected time complexity
bool threeSum(int arr[], int size, int sum) {
	HashTable ht = HashTableNew();

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			HashTableInsert(ht, arr[i] + arr[j], 0);
		}
	}

	for (int i = 0; i < size; i++) {
		if (HashTableContains(ht, sum - arr[i])) {
			return true;
		}
	}

	return false;
}
