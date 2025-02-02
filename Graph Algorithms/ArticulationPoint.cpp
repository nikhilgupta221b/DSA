#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_NODES = 10000;  // Maximum number of nodes (adjust as needed)

// Graph representation
vector<int> adj[MAX_NODES];  // Adjacency list
bool visited[MAX_NODES];     // To track visited nodes
int discoveryTime[MAX_NODES];  // Discovery time of each node
int lowTime[MAX_NODES];        // Lowest discovery time reachable from the node
int parent[MAX_NODES];         // Parent node in the DFS tree
set<int> articulationPoints;   // Stores all articulation points

int timeCounter = 0;  // Global time counter for DFS

// DFS function to find articulation points
void dfs(int node) {
    visited[node] = true;                 // Mark the node as visited
    discoveryTime[node] = lowTime[node] = ++timeCounter;  // Initialize discovery and low time
    int children = 0;                     // Count of children in the DFS tree

    // Explore all adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Case 1: Unvisited neighbor (forward edge)
            children++;
            parent[neighbor] = node;      // Set parent of neighbor
            dfs(neighbor);                // Recur for the neighbor

            // Update the low time of the current node
            lowTime[node] = min(lowTime[node], lowTime[neighbor]);

            // Check if the current node is an articulation point
            // Case 1: Root node with two or more children
            if (parent[node] == -1 && children > 1) {
                articulationPoints.insert(node);
            }

            // Case 2: Non-root node where no back edge bypasses this node
            if (parent[node] != -1 && lowTime[neighbor] >= discoveryTime[node]) {
                articulationPoints.insert(node);
            }
        }
        else if (neighbor != parent[node]) {
            // Case 2: Back edge found (neighbor already visited and not the parent)
            lowTime[node] = min(lowTime[node], discoveryTime[neighbor]);
        }
    }
}

// Function to find all articulation points in the graph
void findArticulationPoints(int numNodes) {
    // Initialize arrays
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
        parent[i] = -1;
        discoveryTime[i] = lowTime[i] = 0;
    }

    // Start DFS from each unvisited node (for disconnected graphs)
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print the articulation points
    cout << "Articulation Points:\n";
    for (int point : articulationPoints) {
        cout << point << endl;
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since the graph is undirected
    }

    findArticulationPoints(numNodes);

    return 0;
}
