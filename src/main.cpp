#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "node.h"
#include "edge.h"
#include "a_star.h"

using namespace std;

int main() {
    // Read nodes and edges from csv files
    vector<Node> nodes_vec = read_nodes("nodes.csv");
    vector<Edge> edges = read_edges("edges.csv");


    // Construct map from id to Node
    map<int, Node> nodes;

    for (const Node& node : nodes_vec) {
        nodes[node.id] = node;
    }

    // Construct adjacency list
    map<int, vector<pair<int, double>>> adj;
    for (const Edge& edge : edges) {
        adj[edge.id1].push_back({edge.id2, edge.cost});
        adj[edge.id2].push_back({edge.id1, edge.cost}); // assuming edges are bidirectional
    }

    // Perform A* search
    vector<int> path = a_star(1, nodes.size(), nodes, adj);

    // Write solution path to csv file
    write_path("path.csv", path);

    return 0;
}

