#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    // Constructor to initialize DSU with 'n' elements
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initially, all elements have rank 0
        
        // Every element is its own parent initially (single element sets)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) { // If they are not already in the same set
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach smaller rank tree under the larger rank tree
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX; // If ranks are equal, choose one as root and increment its rank
                rank[rootX]++;
            }
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 7; // Example with 7 elements
    DSU dsu(n);
    
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(5, 6);
    dsu.unite(4, 5);
    
    cout << "Are 2 and 0 connected? " << (dsu.isConnected(2, 0) ? "Yes" : "No") << endl;
    cout << "Are 3 and 6 connected? " << (dsu.isConnected(3, 6) ? "Yes" : "No") << endl;
    cout << "Are 0 and 5 connected? " << (dsu.isConnected(0, 5) ? "Yes" : "No") << endl;
    
    return 0;
}