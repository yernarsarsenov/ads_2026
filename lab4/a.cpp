#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node (int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        this->root = nullptr;
    }

    Node *insert(Node *node, int data) {
        if(node == nullptr) {
            node = new Node(data);
            return node;
        }
        if(data > node->data)
            node->right = insert(node->right, data);
        else node->left = insert(node->left, data);
        return node;
    }
};

int main() {

    int n, m, val;
    string s;
    cin >> n >> m;

    BST tree;
    for(int i = 0; i < n; i++) {
        cin >> val;
        tree.root = tree.insert(tree.root, val);
    }
    Node *curr = tree.root;

    while(m--) {
        cin >> s;
        bool error = false;
        Node *temp = curr;
        for(char &ch : s) {
            if(ch == 'L')
                temp = temp->left;
            else
                temp = temp->right;
            if(temp == nullptr) {
                error = true;
                break;
            }
        }
        if(error) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}