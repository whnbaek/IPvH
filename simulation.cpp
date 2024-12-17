#include "simulation.h"
#include "graph.h"
#include <functional>
#include <iostream>
#include <queue>
#include <random>
#include <unordered_map>

void simulate(int n, int route_table[][MAX_NODE_NUM],
              std::vector<int> &src_nodes, std::vector<int> &dest_nodes,
              std::vector<int> &distances) {
    double lambda = 0.000731;    // For n = 6301
    int num_simulations = 10000; // Set the number of simulations

    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(lambda);

    long long total_bits = 0;

    for (int i = 0; i < num_simulations; i++) {
        int src = static_cast<int>(distribution(generator));
        if (src >= n)
            continue;

        int dest = static_cast<int>(distribution(generator));
        if (dest >= n || dest == src)
            continue;

        if (route_table[src][dest] == -1)
            continue;

        int distance = 0;
        int current = src;
        while (current != dest) {
            current = route_table[current][dest];
            distance++;
        }

        total_bits += distance * 64;
        src_nodes.push_back(src);
        dest_nodes.push_back(dest);
        distances.push_back(distance);
    }
    std::cout << "Total bits used without Huffman encoding: " << total_bits
              << std::endl;
}

void simulate_huffman(std::vector<int> &src_nodes, std::vector<int> &dest_nodes,
                      std::vector<int> &distances) {
    // Step 1: Collect frequencies of all nodes
    std::unordered_map<int, int> freq_map;
    for (int node : src_nodes) {
        freq_map[node]++;
    }
    for (int node : dest_nodes) {
        freq_map[node]++;
    }

    // Step 2: Assign code lengths using Huffman's algorithm
    struct HuffmanNode {
        int frequency;
        int node_id; // -1 for internal nodes
        HuffmanNode *left;
        HuffmanNode *right;
        HuffmanNode(int freq, int id)
            : frequency(freq), node_id(id), left(nullptr), right(nullptr) {}
    };

    auto cmp = [](HuffmanNode *left, HuffmanNode *right) {
        return left->frequency > right->frequency;
    };
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>,
                        decltype(cmp)>
        min_heap(cmp);

    for (const auto &entry : freq_map) {
        min_heap.push(new HuffmanNode(entry.second, entry.first));
    }

    while (min_heap.size() > 1) {
        HuffmanNode *left = min_heap.top();
        min_heap.pop();
        HuffmanNode *right = min_heap.top();
        min_heap.pop();
        HuffmanNode *parent =
            new HuffmanNode(left->frequency + right->frequency, -1);
        parent->left = left;
        parent->right = right;
        min_heap.push(parent);
    }

    std::unordered_map<int, int> code_lengths;
    std::function<void(HuffmanNode *, int)> assignCodeLengths =
        [&](HuffmanNode *node, int length) {
            if (!node)
                return;
            if (node->node_id != -1) {
                code_lengths[node->node_id] = length;
                return;
            }
            assignCodeLengths(node->left, length + 1);
            assignCodeLengths(node->right, length + 1);
        };

    HuffmanNode *root = min_heap.top();
    assignCodeLengths(root, 0);

    // Step 3: Calculate the total bits used
    long long total_bits = 0;
    for (size_t i = 0; i < src_nodes.size(); ++i) {
        int src_length = code_lengths[src_nodes[i]];
        int dest_length = code_lengths[dest_nodes[i]];
        int distance = distances[i];
        total_bits += (src_length + dest_length) * distance;
    }

    std::cout << "Total bits used with Huffman encoding: " << total_bits
              << std::endl;

    // Clean up the Huffman tree
    std::function<void(HuffmanNode *)> deleteTree = [&](HuffmanNode *node) {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);
}