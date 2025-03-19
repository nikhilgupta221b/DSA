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

int maxdia = 0;

int diameterOfGenericTree(Node* node) {
    int maxheight = -1;
    int secondmaxheight = -1;
    for (Node* child: node->children) {
        int childresult = diameterOfGenericTree(child);
        if (childresult > maxheight) {
            secondmaxheight = maxheight;
            maxheight = childresult;
        }
        else if (childresult > secondmaxheight) {
            secondmaxheight = childresult;
        }
    }

    maxdia = max(maxdia, maxheight + secondmaxheight + 2);
    maxheight++;
    return maxheight;
}



int main() {
    vector<int> v;
    int temp;
    
    while (cin >> temp) {
        v.push_back(temp);
    }

    Node* tree = createGenericTree(v);

    diameterOfGenericTree(tree);

    cout << maxdia;
}