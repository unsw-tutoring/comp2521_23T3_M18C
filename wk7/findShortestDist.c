#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"
#include "Queue.h"

// returns an array containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
    // bfs
	bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
	int *pred = calloc(GraphNumVertices(g), sizeof(int));
	int *dist = calloc(GraphNumVertices(g), sizeof(int));

	Queue q = QueueNew();

	QueueEnqueue(q, src);
	visited[src] = true;
	pred[src] = -1; // or src
	dist[src] = 0;

	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);
		for (int w = 0; w < GraphNumVertices(g); w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
				QueueEnqueue(q, w);
				visited[w] = true;
				pred[w] = v;
				dist[w] = dist[v] + 1;
			}
		}
	}

	return dist;
}
