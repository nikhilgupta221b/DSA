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

int maxi = INT_MIN;
int mini = INT_MAX;
int tree_size = 0;
int height = 0;

void multisolver(Node* node, int depth) {
    tree_size = tree_size + 1;
    maxi = max(maxi, node->data);
    mini = min(mini, node->data);
    height = max(height, depth);

    for (Node* child : node->children) {
        multisolver(child, depth + 1);
    }
}

int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    displayGenericTree(tree);

    cout << "Multisolver Result: " << endl;

    multisolver(tree, 0);
    
    cout << "Size : " << tree_size << endl;
    cout << "Max : " << maxi << endl;
    cout << "Min : " << mini << endl;
    cout << "Height : " << height << endl;
}