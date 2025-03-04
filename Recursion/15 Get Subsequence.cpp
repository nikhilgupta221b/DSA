#include <bits/stdc++.h>
using namespace std;

vector<string> subsequences(string str) {
    if (str == "") {
        vector<string> recvec;
        recvec.push_back(str);
        return recvec;
    }
    char c = str[0];
    string remstr = str.substr(1);
    vector<string> recres = subsequences(remstr);
    vector<string> myres;
    for (string s : recres) {
        myres.push_back(s);
    } 
    for (string s : recres) {
        myres.push_back(c + s);
    }
    return myres;
}

int main() {
    string str;
    cin >> str;

    vector<string> result = subsequences(str);

    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
