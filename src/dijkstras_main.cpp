#include "dijkstras.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    file_to_graph("small.txt", G);
    vector<int> previous(G.numVertices, -1);
    vector<int> shortest_path = dijkstra_shortest_path(G, 0, previous);
    for (int i : shortest_path) {
        cout << i << " ";
    }
}