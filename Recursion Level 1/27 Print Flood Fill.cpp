#include<bits/stdc++.h>

using namespace std;

void printFloodFill(vector<vector<int>>& grid, int r, int c, string psf, vector<vector<bool>>& vis) {
    if (r == grid.size() - 1 && c == grid[0].size() - 1) {
        cout << psf << endl;
        return;
    }
    if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 1 || vis[r][c] == true) {
        return;
    }
    vis[r][c] = true;
    printFloodFill(grid, r + 1, c, psf + "d", vis);
    printFloodFill(grid, r - 1, c, psf + "t", vis);
    printFloodFill(grid, r, c + 1, psf + "r", vis);
    printFloodFill(grid, r, c - 1, psf + "l", vis);
    vis[r][c] = false;
}

int main() {
    int m, n;

    cin >> m;
    cin >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    printFloodFill(grid, 0, 0, "", visited);
}