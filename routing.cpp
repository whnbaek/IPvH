#include "routing.h"
#include "graph.h"
#include <climits>
#include <iostream>

int dist[MAX_NODE_NUM][MAX_NODE_NUM];
int next[MAX_NODE_NUM][MAX_NODE_NUM];

void make_route_table(char adj[][MAX_NODE_NUM], int n,
                      int route_table[][MAX_NODE_NUM]) {
    // Initialize distances and next hops
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
                next[i][j] = j;
            } else {
                dist[i][j] = INT_MAX;
                next[i][j] = -1;
            }
        }
    }

    // Set initial distances based on adjacency list
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] == 1) {
                dist[u][v] = 1; // Assuming edge weight of 1
                next[u][v] = v;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        // print the progress in one line
        std::cout << "Progress: " << k * 100 / n << "%\r";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Build the route table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (next[i][j] == -1) {
                route_table[i][j] = -1; // No path exists
            } else {
                route_table[i][j] = next[i][j];
            }
        }
    }
}
