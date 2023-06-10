#include "edge.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


vector<Edge> read_edges(const string& file) {
    ifstream in(file);
    vector<Edge> edges;
    string line, segment;
    vector<string> seglist;

    while (getline(in, line)) {
        if (line[0] == '#') continue; // ignore comments
        stringstream ss(line);
        while(getline(ss, segment, ','))
        {
           seglist.push_back(segment);
        }

        Edge edge;

        // Now that we have each segment, we can convert and store them
        edge.id1 = stoi(seglist[0]);
        edge.id2 = stoi(seglist[1]);
        edge.cost = stod(seglist[2]);

        edges.push_back(edge);

        // clear the seglist vector before processing the next line
        seglist.clear();
    }
    return edges;
}

