#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include <string>

struct Edge {
    int id1, id2;
    double cost;
};

std::vector<Edge> read_edges(const std::string& file);

#endif //EDGE_H

