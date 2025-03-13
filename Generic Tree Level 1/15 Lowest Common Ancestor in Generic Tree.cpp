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

vector<int> nodeToRootPath(Node* root, int n) {
    if (root->data == n) {
        return {n};
    }
    for (Node* child : root->children) {
        vector<int> childAns = nodeToRootPath(child, n);
        if (childAns.size() > 0) {
            childAns.push_back(root->data);
            return childAns;
        }
    }
    return {};
}



int main() {
    int a;
    cin >> a;
    int b;
    cin >> b;

    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    vector<int> aToRoot = nodeToRootPath(tree, a);
    vector<int> bToRoot = nodeToRootPath(tree, b);

    int i = aToRoot.size() - 1;
    int j = bToRoot.size() - 1;
    while(i >= 0 && j >= 0) {
        if (aToRoot[i] != bToRoot[j]) {
            break;
        }
        i--;
        j--;
    }
    // come back to last equal node
    i++;
    j++;
    cout << aToRoot[i];
}