#include <iostream>
#include <vector>
using namespace std;

// Function to preprocess the pattern and create the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string &pattern, vector<int> &lps) {
    int length = 0;  // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0;  // lps[0] is always 0

    // Loop to calculate lps[i] for i = 1 to pattern.length() - 1
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search function
void KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    // Create LPS array to hold the longest prefix suffix values for the pattern
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Get the next position from LPS array
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Main function
int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    KMPSearch(text, pattern);

    return 0;
}
