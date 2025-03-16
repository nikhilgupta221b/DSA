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

int predecessor = NULL;
int successor = NULL;
int state = 0;

void predecessorAndSuccessor(Node* node, int n) {
    if (state == 0) {
        if (node->data == n) {
            state = 1;
        }
        else {
            predecessor = node->data;
        }
    }
    else if (state == 1) {
        successor = node->data;
        state = 2;
    }

    for (Node* child : node->children) {
        predecessorAndSuccessor(child, n);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    predecessorAndSuccessor(tree, n);

    cout << predecessor << endl;
    cout << successor << endl;
}