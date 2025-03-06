#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int index) {
    if (index == arr.size()) return;
    cout << arr[index] << endl;
    printArray(arr, index + 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    printArray(arr, 0);

    return 0;
}
