#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    Node(int data) {
        this->data = data;
    }
};

Node* createGenericTree(vector<int> v) {
    Node* root = nullptr;
    stack<Node*> st;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == -1) {
            st.pop();
        }
        else {
            Node* temp = new Node(v[i]);
            if (!st.empty()) {
                st.top()->children.push_back(temp);
            }
            else {
                root = temp;
            }
            st.push(temp);
        }
    }
    return root;
}

void displayGenericTree(Node* root) {
    if (root == nullptr) return;
    string res = "";
    res += to_string(root->data) + "->";
    for (Node* child : root->children) {
        res += to_string(child->data) + ", ";
    }
    res += ".";
    cout << res << endl;

    for (Node* child: root->children) {
        displayGenericTree(child);
    }
}

void removeLeavesFromGenericTree(Node* root) {
    for (int i = root->children.size() - 1; i >= 0; i--) {
        if (root->children[i]->children.size() == 0) {
            // Use iterator to erase the element
            root->children.erase(root->children.begin() + i);
        } 
    }

    for (int i = 0; i < root->children.size(); i++) {
        Node* child = root->children[i];
        removeLeavesFromGenericTree(child);
    }
}

int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    removeLeavesFromGenericTree(tree);

    displayGenericTree(tree);
}