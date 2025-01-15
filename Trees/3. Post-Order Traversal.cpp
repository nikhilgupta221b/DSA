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

// Postorder traversal function
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);   // Traverse left subtree
    postorderTraversal(root->right);  // Traverse right subtree
    cout << root->key << " ";         // Visit the root
}

// Driver code
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Postorder traversal
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
