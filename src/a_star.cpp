#include "a_star.h"
#include <fstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

// Definition of a_star
vector<int> a_star(int start_id, int goal_id, const map<int, Node>& nodes, const map<int, vector<pair<int, double>>>& adj) {
    map<int, double> g_cost;
    map<int, int> came_from;
    priority_queue<AStarState, vector<AStarState>, greater<AStarState>> pq;

    g_cost[start_id] = 0;
    pq.push({start_id, 0, nodes.at(start_id).h_cost});

    while (!pq.empty()) {
        int id = pq.top().id; pq.pop();
        if (id == goal_id) break;
        for (const auto& [nid, cost] : adj.at(id)) {
            double new_g_cost = g_cost[id] + cost;
            if (!g_cost.count(nid) || new_g_cost < g_cost[nid]) {
                g_cost[nid] = new_g_cost;
                came_from[nid] = id;
                double h_cost = nodes.at(nid).h_cost;
                pq.push({nid, new_g_cost, new_g_cost + h_cost});
            }
        }
    }

    vector<int> path;
    if (came_from.count(goal_id)) { // if the goal was reached
        int id = goal_id;
        while (id != start_id) {
            path.push_back(id);
            id = came_from[id];
        }
        path.push_back(start_id);
        reverse(path.begin(), path.end());
    } else {
        cout << "No path found from " << start_id << " to " << goal_id << endl;
        path.push_back(start_id); // return start_id as the only node in the path
    }

    return path;
}


// Definition of write_path
void write_path(const string& file, const vector<int>& path) {
    ofstream out(file);
    out << "# path.csv file for V-REP kilobot motion planning scene.\n";
    out << "# All lines beginning with a # are treated as a comment and ignored.\n";
    out << "# Below is a solution path represented as a sequence of nodes of the graph.\n";
    for (int id : path) {
        out << id << ',';
    }
    out << '\n';
}
