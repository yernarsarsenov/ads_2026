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
        this->root = root;
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

void kth_min(Node *node, int &cnt) {
    if(node == NULL)
        return;
    kth_min(node->left, cnt);
    cnt--;
    if(!cnt) cout << node->data;
    int ans = 0;
    kth_min(node->right, cnt);
}

int main() {

    BST *bst = new BST();

    int n, k, a;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a;
        bst->root = insert(bst->root, a);
    }

    kth_min(bst->root, k);
    if(k > 0) cout << -1;

    return 0;
}