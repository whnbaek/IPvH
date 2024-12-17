#include "graph.h"
#include <algorithm>
#include <cstdio>
#include <random>

void get_graph(char adj[][MAX_NODE_NUM], int &n) {
    FILE *in = fopen("p2p-Gnutella08.txt", "r");
    char line[MAX_LINE_LEN];
    n = 0;
    while (fgets(line, MAX_LINE_LEN, in)) {
        if (line[0] == '#') {
            continue;
        }
        int u, v;
        sscanf(line, "%d %d", &u, &v);
        adj[u][v] = 1;
        if (n < u + 1) {
            n = u + 1;
        }
        if (n < v + 1) {
            n = v + 1;
        }
    }
    fclose(in);
}

void make_permutation(int permutation[], int n) {
    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(permutation, permutation + n, g);
}
