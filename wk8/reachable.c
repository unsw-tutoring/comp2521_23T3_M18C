#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef int Vertex;
typedef struct graph *Graph;

Set reachable(Graph g, Vertex src) {
	Set s = SetNew();

	doReachable(src, g, s);

	return s;
}

void doReachable(Vertex v, Graph g, Set s) {
	for (int i = 0; i < g->nV; i++) {
        if (g->adj[v][i] && !SetContains(s, i)) {
			SetInsert(s, i);
			doReachable(i, g, s);
		}
	}
}
