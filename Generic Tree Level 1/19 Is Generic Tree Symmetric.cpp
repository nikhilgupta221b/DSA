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

bool areMirror(Node* tree1, Node* tree2) {
    if (tree1->children.size() != tree2->children.size()) {
        return false;
    }
    for (int i = 0; i < tree1->children.size(); i++) {
        int j = tree1->children.size() - 1 - i;
        bool childans = areMirror(tree1->children[i], tree2->children[j]);
        if (childans == false) return false;
    }
    return true;
}

bool isSymmetric(Node* tree) {
    return areMirror(tree, tree);
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    cout << isSymmetric(tree);
}