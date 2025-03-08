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

int traversalOfGenericTree(Node* root) {
    cout << "Node Pre " << root->data << endl;
    for (Node* child : root->children) {
        cout << "Edge Pre " << root->data << "->" << child->data << endl;
        traversalOfGenericTree(child);
        cout << "Edge Post " << root->data << "->" << child->data << endl;
    }
    cout << "Node Post " << root->data << endl;
}

int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    cout << traversalOfGenericTree(tree);
}