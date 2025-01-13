#include <iostream>
#include <string>
using namespace std;

const int PRIME = 101; // A prime number for hashing

// Function to calculate hash value of a string
long long calculateHash(const string &str, int end) {
    long long hashValue = 0;
    for (int i = 0; i <= end; i++) {
        hashValue += (str[i] * pow(PRIME, i));
    }
    return hashValue;
}

// Function to recalculate hash by sliding the window
long long recalculateHash(const string &str, int oldIndex, int newIndex, long long oldHash, int patternLength) {
    long long newHash = oldHash - str[oldIndex];
    newHash /= PRIME;
    newHash += (str[newIndex] * pow(PRIME, patternLength - 1));
    return newHash;
}

// Rabin-Karp function for pattern searching
void rabinKarp(const string &text, const string &pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    long long patternHash = calculateHash(pattern, patternLength - 1);
    long long textHash = calculateHash(text, patternLength - 1);

    for (int i = 0; i <= textLength - patternLength; i++) {
        // If hash values match, check the actual substring to avoid hash collision
        if (patternHash == textHash && text.substr(i, patternLength) == pattern) {
            cout << "Pattern found at index " << i << endl;
        }
        
        // Recalculate hash for the next window
        if (i < textLength - patternLength) {
            textHash = recalculateHash(text, i, i + patternLength, textHash, patternLength);
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    rabinKarp(text, pattern);
    return 0;
}
