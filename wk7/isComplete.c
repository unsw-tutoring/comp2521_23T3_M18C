#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef struct graph *Graph;

bool isComplete(Graph g) {
	for (int vertex = 0; vertex < g->nV; vertex++) {
		for (int j = 0; j < g->nV; j++) {
            if (!g->adj[vertex][j] && vertex != j) {
				return false;
			}
		}
	}

    return true;
}
