#include <bits/stdc++.h>

using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if (sr > dr || sc > dc) return;
    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }
    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}

int main() {
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    printMazePaths(sr, sc, dr, dc, "");
}