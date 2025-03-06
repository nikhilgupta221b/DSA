#include <bits/stdc++.h>
using namespace std;

int findFirstIndex(vector<int> arr, int num, int index) {
    if (index == arr.size()) return -1;
    int lastIndex = findFirstIndex(arr, num, index + 1);
    if (lastIndex != -1) return lastIndex;
    if (arr[index] == num) return index;
    return -1;

}

int main() {
    int n;
    cin >> n;

    int num;
    cin >> num;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl;
    cout << findFirstIndex(arr, num, 0);

    return 0;
}
