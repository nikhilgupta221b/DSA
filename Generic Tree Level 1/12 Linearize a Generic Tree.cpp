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

Node* findTail(Node* node) {
    while(node->children.size() == 1) {
        node = node->children[0];
    }
    return node;
}

void linearizeGenericTree1(Node* root) {
    for (Node* child : root->children) {
        linearizeGenericTree1(child);
    }
    while(root->children.size() > 1) {
        Node* last = root->children.back();
        root->children.pop_back();
        Node* secondlast = root->children.back();
        
        Node* tailNode = findTail(secondlast);
        tailNode->children.push_back(last);
    }
}

Node* linearizeGenericTree2(Node* root) {
    if (root->children.size() == 0) return root;

    Node* lsttail = linearizeGenericTree2(root->children.back());
    while(root->children.size() > 1) {
        Node* last = root->children.back();
        root->children.pop_back();
        Node* secondLastTail = linearizeGenericTree2(root->children.back());
        secondLastTail->children.push_back(last);
    }
    return lsttail;
}


int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    linearizeGenericTree2(tree);

    displayGenericTree(tree);
}