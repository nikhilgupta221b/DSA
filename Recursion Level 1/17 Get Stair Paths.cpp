#include <iostream>
#include <vector>
using namespace std;

vector<string> getStairPaths(int n) {
    if (n == 0) {
        return {""};
    }
    else if (n < 0) {
        return {};
    }
    vector<string> rres1 = getStairPaths(n-1);
    vector<string> rres2 = getStairPaths(n-2);
    vector<string> rres3 = getStairPaths(n-3);

    vector<string> myres;

    for (string s : rres1) {
        myres.push_back("1" + s);
    }
    for (string s : rres2) {
        myres.push_back("2" + s);
    }
    for (string s : rres3) {
        myres.push_back("3" + s);
    }

    return myres;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> result = getStairPaths(n);
    
    for (const string &path : result) {
        cout << path << " ";
    }
    cout << endl;
    
    return 0;
}