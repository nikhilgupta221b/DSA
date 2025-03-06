#include <iostream>

using namespace std;

void printzigzag(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printzigzag(n-1);
    cout << n << " ";
    printzigzag(n-1);
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;
    printzigzag(n);
}
