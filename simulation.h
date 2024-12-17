#ifndef SIMULATION_H
#define SIMULATION_H

#include "graph.h"
#include <vector>

void simulate(int n, int route_table[][MAX_NODE_NUM],
              std::vector<int> &src_nodes, std::vector<int> &dest_nodes,
              std::vector<int> &distances);

void simulate_huffman(std::vector<int> &src_nodes, std::vector<int> &dest_nodes,
                      std::vector<int> &distances);

#endif // SIMULATION_H
