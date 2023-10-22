#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

int numOddOccurrences(int arr[], int size) {
	Set s = SetNew();

	for (int i = 0; i < size; i++) {
		if (SetContains(s, arr[i])) {
			SetDelete(s, arr[i]);
		} else {
			SetInsert(s, arr[i]);
		}
	}

	int numOdd = SetSize(s);
	SetFree(s);
	return numOdd;
}

int numSingleOccurrences(int arr[], int size) {
	Set once = SetNew();
	Set moreThanOnce = SetNew();

	for (int i = 0; i < size; i++) {
		if (SetContains(once, arr[i])) {
			SetDelete(once, arr[i]);
			SetInsert(moreThanOnce, arr[i]);
		} else if (!SetContains(moreThanOnce, arr[i])) {
			SetInsert(once, arr[i]);
		}
	}

	int count = SetSize(once);
	SetFree(once);
	SetFree(moreThanOnce);
	return count;
}

int main(void) {
	assert(numOddOccurrences((int[]){4, 3, 4, 8, 8, 4}, 6) == 2);
	assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4}, 6) == 4);
	assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3}, 7) == 3);
	assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3, 8}, 8) == 2);
	assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3, 8, 7}, 9) == 1);

	assert(numSingleOccurrences((int[]){4, 3, 4, 8, 8, 4}, 6) == 1);
	assert(numSingleOccurrences((int[]){4, 3, 4, 8, 7, 4}, 6) == 3);
	assert(numSingleOccurrences((int[]){4, 3, 4, 8, 7, 4, 3}, 7) == 2);
	return 0;
}
