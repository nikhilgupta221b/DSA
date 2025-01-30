#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge for Kruskal's algorithm
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph for Kruskal's algorithm
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// ======================= Kruskal's Algorithm Functions =======================
int findParent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(Graph& graph) {
    vector<Edge> result;
    int V = graph.V;

    // Sort all edges by increasing weight
    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) parent[i] = i;

    int edgeCount = 0;
    for (const auto& edge : graph.edges) {
        if (edgeCount == V - 1) break;

        int rootX = findParent(parent, edge.src);
        int rootY = findParent(parent, edge.dest);

        if (rootX != rootY) {
            result.push_back(edge);
            unionSets(parent, rank, rootX, rootY);
            edgeCount++;
        }
    }

    cout << "Edges in the MST (Kruskal's Algorithm):\n";
    for (const auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

// ======================= Prim's Algorithm Functions =======================
void primMST(int V, vector<vector<pair<int, int>>>& adjList) {
    vector<int> key(V, INT_MAX);   // Store minimum weights
    vector<bool> inMST(V, false);  // Track included nodes
    vector<int> parent(V, -1);     // Store MST structure

    // Priority queue to select the minimum weight edge at each step
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});  // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

        // Visit all adjacent vertices
        for (auto [v, weight] : adjList[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in the MST (Prim's Algorithm):\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " -- " << i << " == " << key[i] << endl;
    }
}

// ======================= Main Function =======================
int main() {
    // Graph for Kruskal's Algorithm
    Graph graph = {4, 5, {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    }};

    // Run Kruskal's algorithm
    kruskalMST(graph);

    // Graph for Prim's Algorithm (adjacency list)
    vector<vector<pair<int, int>>> adjList = {
        {{1, 10}, {2, 6}, {3, 5}},   // Node 0
        {{0, 10}, {3, 15}},          // Node 1
        {{0, 6}, {3, 4}},            // Node 2
        {{0, 5}, {1, 15}, {2, 4}}    // Node 3
    };

    // Run Prim's algorithm
    primMST(4, adjList);

    return 0;
}
