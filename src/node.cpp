#include "node.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


vector<Node> read_nodes(const string& file) {
    ifstream in(file);
    vector<Node> nodes;
    string line, segment;
    vector<string> seglist;

    while (getline(in, line)) {
        if (line[0] == '#') continue; // ignore comments
        stringstream ss(line);
        while(getline(ss, segment, ','))
        {
           seglist.push_back(segment);
        }

        Node node;

        // Now that we have each segment, we can convert and store them
        node.id = stoi(seglist[0]);
        node.x = stod(seglist[1]);
        node.y = stod(seglist[2]);
        node.h_cost = stod(seglist[3]);

        nodes.push_back(node);

        // clear the seglist vector before processing the next line
        seglist.clear();
    }
    return nodes;
}
