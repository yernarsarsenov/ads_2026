#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
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

void rev_inOrder_cnt(Node *node, int &cnt) {
    if(node == NULL)
        return;
    rev_inOrder_cnt(node->right, cnt);
    cnt += node->data;
    cout << cnt << " ";
    rev_inOrder_cnt(node->left, cnt);
}

int main() {

    BST *bst = new BST;
    int n, a;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        bst->root = insert(bst->root, a);
    }

    int cnt = 0;
    rev_inOrder_cnt(bst->root, cnt);

    return 0;
}

