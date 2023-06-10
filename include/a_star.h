#ifndef A_STAR_H
#define A_STAR_H

#include "node.h"
#include <map>
#include <vector>

struct AStarState {
    int id;
    double g_cost; // actual cost
    double f_cost; // g_cost + heuristic cost

    bool operator>(const AStarState& other) const {
        return f_cost > other.f_cost;
    }
};

std::vector<int> a_star(int start_id, int goal_id, const std::map<int, Node>& nodes, const std::map<int, std::vector<std::pair<int, double>>>& adj);

void write_path(const std::string& file, const std::vector<int>& path);

#endif //A_STAR_H

