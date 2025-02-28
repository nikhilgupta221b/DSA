#include <bits/stdc++.h>

using namespace std;

void backtrack(int n) {
    if (n == 0) return;
    cout << n << "\n";
    backtrack(n-1);
}
int main() {
    int n;
    cin >> n;
    backtrack(n);
    return 0;
}