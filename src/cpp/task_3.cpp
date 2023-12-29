/*
 * Author: Axmad Xurshetov
 * Date: 29.12.2923
 * Name: task 3
 */


#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int MAX_VERTICES = 4; // Number of vertices in the graph

vector<pii> adj[MAX_VERTICES]; // Adjacency list for the graph

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(MAX_VERTICES, INT_MAX);
    vector<bool> visited(MAX_VERTICES, false);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < MAX_VERTICES; ++i)
        cout << "Vertex " << i << " Distance from Source " << src << ": " << dist[i] << endl;
}

int main() {
    // Graph representation
    adj[0].push_back(make_pair(1, 100));
    adj[0].push_back(make_pair(3, 100));
    adj[1].push_back(make_pair(0, 100));
    adj[1].push_back(make_pair(2, 100));
    adj[1].push_back(make_pair(3, 600));
    adj[2].push_back(make_pair(1, 100));
    adj[2].push_back(make_pair(3, 200));
    adj[3].push_back(make_pair(0, 100));
    adj[3].push_back(make_pair(1, 600));
    adj[3].push_back(make_pair(2, 200));

    dijkstra(0); // Calling dijkstra for source vertex 0

    return 0;
}
