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

Node* maxNode = NULL;
int maxNodeSum = 0;

int nodeWithMaxSubtreeSum(Node* node) {
    int sum = 0;
    for (Node* child : node->children) {
        sum += nodeWithMaxSubtreeSum(child);
    }

    sum += node->data;

    if (sum > maxNodeSum) {
        maxNode = node;
        maxNodeSum = sum;
    }
    return sum;
}



int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    nodeWithMaxSubtreeSum(tree);

    cout << maxNode->data << "@" << maxNodeSum; 
}