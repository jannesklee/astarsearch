#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct Node {
    int id;
    double x, y;
    double h_cost; // heuristic cost
};

std::vector<Node> read_nodes(const std::string& file);

#endif //NODE_H
