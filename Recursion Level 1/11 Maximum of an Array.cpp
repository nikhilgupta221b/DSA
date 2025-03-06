#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr, int index) {
    if (index == arr.size() - 1) return arr[index];
    return max(arr[index], findMax(arr, index + 1));
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    cout << findMax(arr, 0);

    return 0;
}
