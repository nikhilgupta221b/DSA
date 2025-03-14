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

int main() {
    int n1, n2;
    cin >> n1;
    cin >> n2;

    vector<int> v1;
    vector<int> v2;
    int temp;

    for (int i = 0; i < n1; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    for (int j = 0; j < n2; j++) {
        cin >> temp;
        v2.push_back(temp);
    }

    Node* tree1 = createGenericTree(v1);
    Node* tree2 = createGenericTree(v2);

    cout << areMirror(tree1, tree2);
}