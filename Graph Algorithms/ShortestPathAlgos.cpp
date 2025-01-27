#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Utility structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Bellman-Ford Algorithm
void bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int start) {
    vector<int> distance(vertices, INT_MAX);
    distance[start] = 0;

    // Relax all edges (vertices-1) times
    for (int i = 0; i < vertices - 1; i++) {
        for (const auto& edge : edgeList) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edgeList) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains a negative-weight cycle\n";
            return;
        }
    }

    // Print distances
    cout << "Bellman-Ford Distances:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

// Dijkstra's Algorithm
void dijkstra(int vertices, vector<vector<pair<int, int>>>& adjList, int start) {
    vector<int> distance(vertices, INT_MAX);
    distance[start] = 0;

    // Min-heap priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print distances
    cout << "Dijkstra's Distances:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(int vertices, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    // Dynamic programming approach to find all pairs shortest paths
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Floyd-Warshall Distances:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<Edge> edgeList;
    vector<vector<pair<int, int>>> adjList(vertices);
    vector<vector<int>> graph(vertices, vector<int>(vertices, INT_MAX));

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
        adjList[u].push_back({v, w});
        graph[u][v] = w;
    }

    for (int i = 0; i < vertices; i++) {
        graph[i][i] = 0;
    }

    int start;
    cout << "Enter start vertex for single-source algorithms: ";
    cin >> start;

    // Run Bellman-Ford Algorithm
    bellmanFord(vertices, edges, edgeList, start);

    // Run Dijkstra's Algorithm
    dijkstra(vertices, adjList, start);

    // Run Floyd-Warshall Algorithm
    floydWarshall(vertices, graph);

    return 0;
}
