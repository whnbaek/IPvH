#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

const int MAX_NODE_NUM = 6301;
const int MAX_LINE_LEN = 100;

void get_graph(char adj[][MAX_NODE_NUM], int &n);
void make_permutation(int permutation[], int n);

#endif // GRAPH_H
