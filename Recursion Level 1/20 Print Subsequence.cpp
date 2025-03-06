#include <bits/stdc++.h>

using namespace std;

void printSubsequence(string ques, string ans) {
    if (ques == "") {
        cout << ans << endl;
        return;
    }
    char c = ques[0];
    string rques = ques.substr(1);
    printSubsequence(rques, ans + "");
    printSubsequence(rques, ans + c);
}

int main() {
    string ques;
    cin >> ques;

    printSubsequence(ques, "");
    return 0;
}