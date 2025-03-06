#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        return {""};
    }
    if (sr > dr || sc > dc) {
        return {};
    }
    vector<string> rightres = getMazePaths(sr, sc + 1, dr, dc);
    vector<string> downres = getMazePaths(sr + 1, sc, dr, dc);
    vector<string> myres;
    for (string s : rightres) {
        myres.push_back("R" + s);
    }
    for (string s : downres) {
        myres.push_back("D" + s);
    }
    return myres;
}

int main() {
    int sr, sc, dr, dc;
    cin >> sr;
    cin >> sc;
    cin >> dr;
    cin >> dc;

    vector<string> paths = getMazePaths(sr, sc, dr, dc);

    for (string s : paths) {
        cout << s << endl;
    }

    return 0;
}