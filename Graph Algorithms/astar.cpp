#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    double g, h;  // g: cost from start, h: heuristic (estimated cost to goal)

    Node(int x, int y, double g = 0, double h = 0) : x(x), y(y), g(g), h(h) {}

    double f() const { return g + h; }

    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

// Helper function to calculate Manhattan distance (heuristic)
double heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a point is within the grid and not an obstacle
bool isValid(int x, int y, const vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0;
}

// A* Algorithm
vector<pair<int, int>> aStar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    priority_queue<Node, vector<Node>, greater<Node>> openList;
    unordered_map<int, pair<int, int>> cameFrom;  // To reconstruct the path
    vector<vector<double>> gCost(grid.size(), vector<double>(grid[0].size(), 1e9));

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // Right, Down, Left, Up

    openList.push(Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second)));
    gCost[start.first][start.second] = 0;

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.x == goal.first && current.y == goal.second) {
            // Goal reached, reconstruct the path
            vector<pair<int, int>> path;
            for (pair<int, int> at = goal; at != start; at = cameFrom[at.first * grid[0].size() + at.second]) {
                path.push_back(at);
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto& dir : directions) {
            int nx = current.x + dir[0], ny = current.y + dir[1];

            if (isValid(nx, ny, grid)) {
                double newG = current.g + 1;  // Assume uniform cost for each move

                if (newG < gCost[nx][ny]) {
                    gCost[nx][ny] = newG;
                    cameFrom[nx * grid[0].size() + ny] = {current.x, current.y};
                    openList.push(Node(nx, ny, newG, heuristic(nx, ny, goal.first, goal.second)));
                }
            }
        }
    }

    // No path found
    return {};
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    vector<pair<int, int>> path = aStar(grid, start, goal);

    if (!path.empty()) {
        cout << "Path found:\n";
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") -> ";
        }
        cout << "Goal\n";
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
