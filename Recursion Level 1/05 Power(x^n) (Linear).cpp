#include <iostream>

using namespace std;

int powerlinear(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return x * powerlinear(x, n-1);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << powerlinear(x, n);
}
