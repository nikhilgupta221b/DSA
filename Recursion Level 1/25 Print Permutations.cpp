#include <bits/stdc++.h>

using namespace std;

void printPermutations(string ques, string asf) {
    if (ques == "") {
        cout << asf << endl;
        return;
    }
    for (int i = 0; i < ques.length(); i++) {
        char c = ques[i];
        string ls = ques.substr(0, i);
        string rs = ques.substr(i+1);
        string rques = ls + rs;
        printPermutations(rques, asf + c);
    }
}

int main() {
    string ques;
    cin >> ques;
    printPermutations(ques, "");
}