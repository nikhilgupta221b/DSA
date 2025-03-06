#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> letterCombinations(string digits, unordered_map<char, string>& phone_map) {
    if (digits == "") {
        return {""};
    }
    char c = digits[0];
    string remstr = digits.substr(1);
    vector<string> rres = letterCombinations(remstr, phone_map);
    vector<string> myans;
    for (char ctr : phone_map[c]) {
        for (string s: rres) {
            myans.push_back(ctr + s);
        }
    }
    return myans;
}

int main() {
    unordered_map<char, string> phone_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    
    string digits;
    cin >> digits;
    
    vector<string> result = letterCombinations(digits, phone_map);
    
    for (const string &comb : result) {
        cout << comb << " ";
    }
    cout << endl;
    
    return 0;
}
