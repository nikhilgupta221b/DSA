#include <bits/stdc++.h>

using namespace std;

void printStairPaths(int n, string pathtillnow) {
    if (n < 0) return;
    if (n == 0) {
        cout << pathtillnow << endl;
        return;
    }
    printStairPaths(n-1, pathtillnow + "1");
    printStairPaths(n-2, pathtillnow + "2");
    printStairPaths(n-3, pathtillnow + "3");
}

int main() {
    int n;
    cin >> n;
    printStairPaths(n, "");
}