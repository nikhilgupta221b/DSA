#include <bits/stdc++.h>

using namespace std;

void printMazePathsWithJumps(int sr, int sc, int dr, int dc, string psf) {
    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }
    // horizontal jumps
    for (int i = 1; i <= dc - sc; i++) {
        printMazePathsWithJumps(sr, sc + i, dr, dc, psf + "h" + to_string(i));
    }

    // vertical jumps
    for (int i = 1; i <= dr - sr; i++) {
        printMazePathsWithJumps(sr + i, sc, dr, dc, psf + "v" + to_string(i));
    }

    // diagonal jumps
    for (int i = 1; i <= dr - sr && i <= dc - sc; i++) {
        printMazePathsWithJumps(sr + i, sc + i, dr, dc, psf + "d" + to_string(i));
    }
}

int main() {
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    printMazePathsWithJumps(sr, sc, dr, dc, "");
}