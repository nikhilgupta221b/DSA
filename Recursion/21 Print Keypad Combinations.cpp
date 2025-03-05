#include <bits/stdc++.h>

using namespace std;

void printKeypadCombinations(string ques, string ans, unordered_map<char, string>& phone_map) {
    if (ques == "") {
        cout << ans << endl;
        return;
    }
    char c = ques[0];
    string rques = ques.substr(1);
    for (char ch : phone_map[c]) {
        printKeypadCombinations(rques, ans + ch, phone_map);
    }
}

int main() {
    string ques;
    cin >> ques;

    unordered_map<char, string> phone_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    printKeypadCombinations(ques, "", phone_map);
    return 0;
}