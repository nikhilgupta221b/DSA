// Can be solved by 2 queues as well
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

// Method 1 : Using Child Queue
void levelOrderLinewiseGenericTree1(Node* root) {
    queue<Node*> pq;
    queue<Node*> cq;

    pq.push(root);

    while(!pq.empty()) {
        Node* node = pq.front();
        pq.pop();
        cout << node->data << " ";

        for (Node* child: node->children) {
            cq.push(child);
        }
        if (pq.empty()) {
            cout << endl;
            pq = cq;
            cq = queue<Node*>();
        }
    }
}

// Method 2 : Using Delimiter as a node
void levelOrderLinewiseGenericTree2(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(new Node(-1));

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->data == -1) {
            cout << endl;
            if (!q.empty()) {
                q.push(new Node(-1));
            }
        }
        else {
            cout << node->data << " ";
            for (Node* child : node->children) {
                q.push(child);
            }
        }
    }
}

// Method 3 : Using Size variable
void levelOrderLinewiseGenericTree3(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        while(size-- > 0) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            for (Node* child: temp->children) {
                q.push(child);
            }
        }
        cout << endl;
    }
}

// Using pair of {node, level}
void levelOrderLinewiseGenericTree4(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int level = 1;

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        if (level < it.second) {
            cout << endl;
            level++;
        }
        cout << it.first->data << " ";
        for (Node* child: it.first->children) {
            q.push({child, it.second+1});
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

    levelOrderLinewiseGenericTree4(tree);
}