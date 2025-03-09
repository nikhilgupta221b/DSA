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

void levelOrderLinewiseZigzag(Node* root) {
    stack<Node*> pst;
    stack<Node*> cst;

    pst.push(root);
    int level = 1;
    while(!pst.empty()) {
        Node* node = pst.top();
        pst.pop();
        cout << node->data << " ";
        if (level % 2 == 1) {
            for (int i = 0; i < node->children.size(); i++) {
                cst.push(node->children[i]);
            }
        }
        else {
            for (int i = node->children.size() - 1; i >= 0; i--) {
                cst.push(node->children[i]);
            }
        }
        if (pst.empty()) {
            pst = cst;
            cst = stack<Node*>();
            level++;
            cout << endl;
        }
    }
}

int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    levelOrderLinewiseZigzag(tree);
}