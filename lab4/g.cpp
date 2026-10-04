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

    if(data == node->data) return node;
    if(data < node->data) 
        node->left = insert(node->left, data);
    else    
        node->right = insert(node->right, data);

    return node;
}

int get_height(Node *node) {
    if(node == NULL) return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}

int get_max_path(Node *node) {
    if(node == NULL) return 0;

    int main_path = get_height(node->left) + get_height(node->right) + 1;

    int left_path = get_max_path(node->left);
    int right_path = get_max_path(node->right);

    return max({main_path, left_path, right_path});
}

int main() {

    BST *bst = new BST();

    int n, a;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        bst->root = insert(bst->root, a);
    }

    cout << get_max_path(bst->root);

    return 0;
}
