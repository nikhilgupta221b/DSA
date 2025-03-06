#include <bits/stdc++.h>

using namespace std;

void printEncodings(string ques, string asf) {
    if (ques.length() == 0) {
        cout << asf << endl;
        return;
    }
    
    // First digit case
    char c = ques[0];
    if (c == '0') return;  // Can't encode 0
    
    int num = c - '0';
    char cnum = 'a' + num - 1;
    
    // Try encoding single digit
    printEncodings(ques.substr(1), asf + cnum);
    
    // Try encoding two digits if possible
    if (ques.length() >= 2) {
        string c12 = ques.substr(0, 2);
        int num12 = stoi(c12);
        if (num12 <= 26) {
            char enc = 'a' + num12 - 1;
            printEncodings(ques.substr(2), asf + enc);
        }
    }
}

int main() {
    string ques;
    cin >> ques;
    printEncodings(ques, "");
}