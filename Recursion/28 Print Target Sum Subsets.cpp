#include<bits/stdc++.h>

using namespace std;

void targetSumSubsets(vector<int> arr, int index, int sum, vector<int> curarr, int target) {
    if (index == arr.size()) {
        if (sum == target) {
            for (int n : curarr) {
                cout << n << " ";
            }
            cout << endl;
        }
        return;
    }
    curarr.push_back(arr[index]);
    targetSumSubsets(arr, index + 1, sum + arr[index], curarr, target);
    curarr.pop_back();
    targetSumSubsets(arr, index + 1, sum, curarr, target);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int target;
    cin >> target;
    targetSumSubsets(arr, 0, 0, {}, target);
}