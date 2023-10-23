#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef struct graph *Graph;

bool hasEulerPath(Graph g) {
	// int *degree = malloc(sizeof(int) * g->nV);

    // let degree[i] == degree of vertex i
	int *degree = calloc(g->nV, sizeof(int));

	for (int i = 0; i < g->nV; i++) {
		for (int j = 0; j < g->nV; j++) {
			// degree[i] += g->adj[i][j];
			if (g->adj[i][j] && i < j) {
				degree[i]++;
				degree[j]++;
			}
		}
	}

	int numOddDegree = 0;
	for (int i = 0; i < g->nV) {
        if (degree[i] % 2 == 1) {
			numOddDegree++;
		}
	}

	return (numOddDegree == 2) || (numOddDegree == 0);
}
