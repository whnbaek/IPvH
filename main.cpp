#include "graph.h"
#include "routing.h"
#include "simulation.h"

char graph[MAX_NODE_NUM][MAX_NODE_NUM];
int route_table[MAX_NODE_NUM][MAX_NODE_NUM];
int permutation[MAX_NODE_NUM];
std::vector<int> src_nodes, dest_nodes, distances;
int n;

int main() {
    get_graph(graph, n);
    make_route_table(graph, n, route_table);
    make_permutation(permutation, n);
    simulate(n, route_table, src_nodes, dest_nodes, distances);
    simulate_huffman(src_nodes, dest_nodes, distances);
    return 0;
}
