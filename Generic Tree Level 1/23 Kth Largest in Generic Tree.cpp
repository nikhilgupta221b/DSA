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

int floorn = INT_MIN;
int ceiln = INT_MAX;
int state = 0;

void ceilAndFloor(Node* node, int n) {
    if (node->data < n) {
        floorn = max(floorn, node->data);
    }
    else if (node->data > n) {
        ceiln = min(ceiln, node->data);
    }

    for (Node* child : node->children) {
        ceilAndFloor(child, n);
    }
}

int kthLargest(Node* tree, int k) {
    int currentFloor = INT_MAX;
    for (int i = 0; i < k; i++) {
        ceilAndFloor(tree, currentFloor);
        currentFloor = floorn;
        floorn = INT_MIN;
    }
    return currentFloor;
}

int main() {
    int k;
    cin >> k;

    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    cout << kthLargest(tree, k);
}