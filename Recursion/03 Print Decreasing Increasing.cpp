#include <bits/stdc++.h>

using namespace std;

void printDecreasingIncreasing(int n) {
    if (n == 0) return;
    cout << n << "\n";
    printDecreasingIncreasing(n-1);
    cout << n << "\n";
}
int main() {
    int n;
    cin >> n;
    printDecreasingIncreasing(n);
    return 0;
}