#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// BFS (Kahn's Algorithm) for Topological Sorting
void topologicalSortBFS(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0); // To store in-degree of nodes
    for (int i = 0; i < V; i++) {
        for (auto neighbor : adj[i]) {
            inDegree[neighbor]++; // Increment in-degree for each edge
        }
    }

    queue<int> q; // Queue for BFS
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i); // Push nodes with 0 in-degree into the queue
        }
    }

    vector<int> topo; // To store the topological order
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node); // Add the node to the topological order

        for (auto neighbor : adj[node]) {
            inDegree[neighbor]--; // Decrease in-degree of neighbors
            if (inDegree[neighbor] == 0) {
                q.push(neighbor); // Push neighbors with 0 in-degree
            }
        }
    }

    // If the topological order contains all nodes, print it
    if (topo.size() == V) {
        cout << "Topological Order (BFS): ";
        for (auto node : topo) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "The graph is not a DAG (contains a cycle)." << endl;
    }
}

// DFS for Topological Sorting
void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true; // Mark the current node as visited

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st); // Recursively visit neighbors
        }
    }

    st.push(node); // Push the current node to the stack after visiting its neighbors
}

void topologicalSortDFS(int V, vector<int> adj[]) {
    vector<bool> visited(V, false); // To keep track of visited nodes
    stack<int> st; // Stack to store the topological order

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st); // Call DFS for unvisited nodes
        }
    }

    cout << "Topological Order (DFS): ";
    while (!st.empty()) {
        cout << st.top() << " "; // Print nodes in reverse order of their finishing time
        st.pop();
    }
    cout << endl;
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Example graph (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Using BFS (Kahn's Algorithm):" << endl;
    topologicalSortBFS(V, adj);

    cout << "Using DFS:" << endl;
    topologicalSortDFS(V, adj);

    return 0;
}
