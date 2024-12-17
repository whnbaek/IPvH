#ifndef ROUTING_H
#define ROUTING_H

#include "graph.h"
#include <vector>

void make_route_table(char adj[][MAX_NODE_NUM], int n,
                      int route_table[][MAX_NODE_NUM]);

#endif // ROUTING_H
