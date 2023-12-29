/*
 * Author: Axmad Xurshetov
 * Date: 29.12.2923
 * Name: task 6
 */


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int MAX_VERTICES = 4; // Assuming the graph has 4 vertices as in the example graph

vector<pii> adj[MAX_VERTICES]; // Adjacency list for the graph

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(MAX_VERTICES, INT_MAX);
    vector<bool> visited(MAX_VERTICES, false);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    int min_time = *max_element(dist.begin(), dist.end());
    cout << "Minimum time for all nodes to receive the signal: " << min_time << endl;
}

int main() {
    // Example graph representation
    adj[0] = {{1, 2}, {2, 1}};
    adj[1] = {{0, 2}, {2, 3}, {3, 7}};
    adj[2] = {{0, 1}, {1, 3}, {3, 1}};
    adj[3] = {{1, 7}, {2, 1}};

    dijkstra(0); // Assuming the signal starts from node 0

    return 0;
}
