#include <bits/stdc++.h>

using namespace std;

vector<string> getMazePathsWithJump(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        return {""};
    }
    vector<string> myres;

    for (int i = 1; i <= dc - sc; i++) {
        vector<string> hrres = getMazePathsWithJump(sr, sc + i, dr, dc);
        for (string s : hrres) {
            myres.push_back("H" + to_string(i) + s);
        }
    }

    for (int i = 1; i <= dr - sr; i++) {
        vector<string> vrres = getMazePathsWithJump(sr + i, sc, dr, dc);
        for (string s : vrres) {
            myres.push_back("V" + to_string(i) + s);
        }
    }

    for (int i = 1; i <= dr - sr && i <= dc - sc; i++) {
        vector<string> drres = getMazePathsWithJump(sr + i, sc + i, dr, dc);
        for (string s : drres) {
            myres.push_back("D" + to_string(i) + s);
        }
    }
    return myres;
}

int main() {
    int sr, sc, dr, dc;
    cin >> sr;
    cin >> sc;
    cin >> dr;
    cin >> dc;

    vector<string> paths = getMazePathsWithJump(sr, sc, dr, dc);

    for (string s : paths) {
        cout << s << endl;
    }

    return 0;
}