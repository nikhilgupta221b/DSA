#include <iostream>

using namespace std;

int powerlogarithm(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int powercal = powerlogarithm(x, n/2) * powerlogarithm(x, n/2);
    if (n % 2 != 0) powercal *= x; 
    return powercal;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << powerlogarithm(x, n);
}
