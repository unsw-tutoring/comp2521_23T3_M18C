#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

int main(void) {
	Set s = SetNew();

	SetInsert(s, 5);
	SetInsert(s, 3);
	SetInsert(s, 7);
	SetInsert(s, 2);
	SetInsert(s, 4);
	SetInsert(s, 6);

	assert(SetContains(s, 5));
	assert(SetContains(s, 3));
	assert(SetContains(s, 7));
	assert(SetContains(s, 2));
	assert(SetContains(s, 4));
	assert(SetContains(s, 6));
	assert(!SetContains(s, 1));
	assert(!SetContains(s, 0));
	assert(!SetContains(s, 8));

	assert(SetSize(s) == 6);

	SetDelete(s, 5);
	SetDelete(s, 3);

	assert(!SetContains(s, 5));
	assert(!SetContains(s, 3));
	assert(SetContains(s, 7));
	assert(SetContains(s, 2));
	assert(SetContains(s, 4));
	assert(SetContains(s, 6));

	assert(SetSize(s) == 4);

	SetFree(s);
}
