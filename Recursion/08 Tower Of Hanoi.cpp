#include <iostream>
using namespace std;

void toh(int d, int t1, int t2, int t3) {
    if (d == 0) return;
    toh(d - 1, t1, t3, t2);
    cout << d << " [ " << t1 << " -> " << t2 << " ] " << endl;
    toh(d-1, t3, t2, t1);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << endl;
    toh(n, 1, 2, 3);

    return 0;
}
