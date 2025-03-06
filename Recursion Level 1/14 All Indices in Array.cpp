#include <bits/stdc++.h>
using namespace std;

vector<int> findAllIndices(vector<int> &arr, int num, int index) {
    if (index == arr.size()) return {}; // Base case: return empty vector

    vector<int> result = findAllIndices(arr, num, index + 1);

    if (arr[index] == num) {
        result.insert(result.begin(), index); // Store index if it matches
    }
    return result;
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

    vector<int> ans = findAllIndices(arr, num, 0);

    for (int idx : ans) {
        cout << idx << endl;
    }

    return 0;
}
