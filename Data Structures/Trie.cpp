#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    // Constructor
    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            // If the character is not present, create a new node
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        // Mark the end of the word
        currentNode->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            // If the character is not found, the word doesn't exist
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        // Check if the last node marks the end of a word
        return currentNode->isEndOfWord;
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            // If the character is not found, the prefix doesn't exist
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        // If we successfully traverse the prefix, return true
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << (trie.search("apple") ? "Found apple\n" : "Did not find apple\n");  // Output: Found apple
    cout << (trie.search("app") ? "Found app\n" : "Did not find app\n");        // Output: Did not find app
    cout << (trie.startsWith("app") ? "Prefix app exists\n" : "Prefix app does not exist\n"); // Output: Prefix app exists
    trie.insert("app");
    cout << (trie.search("app") ? "Found app\n" : "Did not find app\n");        // Output: Found app
    return 0;
}
