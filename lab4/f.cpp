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

int count_triangles(Node *node, int &cnt) {
    if(node == NULL) return 0;

    if(node->right != NULL && node->left != NULL)
        cnt++;
    count_triangles(node->left, cnt);
    count_triangles(node->right, cnt);

    return cnt;
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
    cout << count_triangles(bst->root, cnt);


    return 0;
}