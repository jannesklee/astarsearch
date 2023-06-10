#include "node.h"
#include <fstream>
#include <sstream>

std::vector<Node> read_nodes(const std::string& file) {
    std::ifstream in(file);
    std::string line;
    std::vector<Node> nodes;
    while (std::getline(in, line)) {
        if (line[0] == '#') continue; // ignore comments
        std::stringstream ss(line);
        Node node;
        ss >> node.id >> node.x >> node.y >> node.h_cost;
        nodes.push_back(node);
    }
    return nodes;
}
