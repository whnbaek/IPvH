# IPvH: Huffman-encoding based Variable IP Address Assignment

This project implements a simulation of IP address assignment using Huffman encoding. The simulation involves creating a routing table using the Floyd-Warshall algorithm, simulating message passing between nodes, and assigning Huffman encoding to nodes based on their communication frequency.

## Project Structure

- `main.cpp`: Contains the main function to run the simulation.
- `graph.h` and `graph.cpp`: Functions related to graph operations.
- `routing.h` and `routing.cpp`: Functions for creating the routing table using the Floyd-Warshall algorithm.
- `simulation.h` and `simulation.cpp`: Functions for simulating message passing and Huffman encoding.
- `Makefile`: Build instructions for the project.

## Download the Dataset

Download the dataset from Stanford's SNAP repository:

```sh
wget https://snap.stanford.edu/data/as-skitter.txt.gz
```

## Build Instructions

To build the project, use the provided Makefile. Ensure you have g++ installed.

```sh
make
```

This will compile the source files and generate the executable `program`.

## Run the Simulation

After building the project, run the simulation using:

```sh
make run
```

## Clean Up

To clean up the build files, use:

```sh
make clean
```

## Function Overview

### Graph Operations

- `void get_graph(char adj[][MAX_NODE_NUM], int &n)`: Reads the graph from a file and initializes the adjacency list.
- `void make_permutation(int permutation[], int n)`: Generates a random permutation of nodes.

### Routing Table

- `void make_route_table(char adj[][MAX_NODE_NUM], int n, int route_table[][MAX_NODE_NUM])`: Creates the routing table using the Floyd-Warshall algorithm.

### Simulation

- `void simulate(std::vector<int> adj[], int n, int route_table[][MAX_NODE_NUM], std::vector<int> &src_nodes, std::vector<int> &dest_nodes, std::vector<int> &distances)`: Simulates message passing between nodes and collects data.
- `void simulate_huffman(std::vector<int> &src_nodes, std::vector<int> &dest_nodes, std::vector<int> &distances)`: Assigns Huffman encoding to nodes based on their communication frequency and calculates the total bits used.
