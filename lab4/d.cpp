#include <bits/stdc++.h>
#define ll long long
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

int get_height(Node *node) {
    if(node == NULL)
        return 0;
    else return 1 + max(get_height(node->left), get_height(node->right));
}

void get_level_sums(Node *node, int level, vector<ll> &sums) {
    if(node == NULL) return;

    sums[level] += node->data;

    get_level_sums(node->left, level + 1, sums);
    get_level_sums(node->right, level + 1, sums);
}

int main() {

    BST* bst = new BST;
    int n, a; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        bst->root = insert(bst->root, a);
    }

    int height = get_height(bst->root);
    cout << height << "\n";

    vector<ll> level_sums(height);
    get_level_sums(bst->root, 0, level_sums);

    for(int i = 0; i < level_sums.size(); i++) {
        cout << level_sums[i] << " ";
    }

    return 0;
}