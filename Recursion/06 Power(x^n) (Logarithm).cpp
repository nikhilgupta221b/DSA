#include <iostream>

using namespace std;

int powerlogarithm(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int xnby2 = powerlogarithm(x, n/2);
    int xn = xnby2 * xnby2;
    if (n % 2 != 0) xn *= x; 
    return xn;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << powerlogarithm(x, n);
}
