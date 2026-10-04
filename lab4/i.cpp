#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        this->root = NULL;
    }
};

Node *insert(Node *node, int data) {
    if(node == NULL) {
        node = new Node(data);
        return node;
    }

    if(data <= node->data)
        node->left = insert(node->left, data);
    else    
        node->right = insert(node->right, data);

    return node;
}

int count_leaves(Node *node) {
    if(node == NULL) return 0;
    if(node->right == NULL && node->left == NULL) {
        return 1;
    }
    return count_leaves(node->left) + count_leaves(node->right);
}

int main() {

    BST *bst = new BST();

    int n, a;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        bst->root = insert(bst->root, a);
    }

    cout << count_leaves(bst->root);

    return 0;
}