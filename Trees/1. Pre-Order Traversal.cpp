#include <iostream>
using namespace std;

// Node structure for a binary tree
struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

// Preorder traversal function
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->key << " ";    // Visit the root
    preorderTraversal(root->left);  // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

// Driver code
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Preorder traversal
    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
