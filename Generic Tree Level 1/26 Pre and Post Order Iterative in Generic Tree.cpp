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

vector<int> pre;
vector<int> post;

void preAndPostIterative(Node* node) {
    stack<pair<Node*, int>> st;
    st.push({node, -1});

    while(!st.empty()) {
        auto it = st.top();
        Node* node = it.first;
        int state = it.second;
        if (state == -1) {
            pre.push_back(node->data);
            st.top().second++;
        }
        else if (state == node->children.size()) {
            post.push_back(node->data);
            st.pop();
        }
        else {
            st.top().second++;
            st.push({node->children[state], -1});
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

    preAndPostIterative(tree);
    cout << "Pre: " << endl;
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << endl;
    cout << "Post: " << endl;
    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
}