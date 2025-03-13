#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

#include "dijkstras.h"

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distances(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    // pq for minimum cause default is max
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; //pair <vertex, weight>
    min_heap.push({source, 0});

    while(!min_heap.empty()) {
        int u = min_heap.top().first;
        min_heap.pop();
        if (visited[u]) continue; // skip
        visited[u] = true;
        for (Edge e : G[u]) {
            int v = e.dst;
            int weight = e.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                min_heap.push({v, distances[v]});
            }
        }
    }
    return distances;
}
