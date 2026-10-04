#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Tree {
    public:
    Node *root;

    void insert_node2(int data) {
        if (this->root == NULL) {
            this->root = new Node(data);
            return;
        }
        Node *cur = root;
        while (cur != NULL) {
            if (data > cur->data) {
                if (cur->right == NULL) {
                    cur->right = new Node(data);
                    break;
                } else
                    cur = cur->right;
            } else {
                if (cur->left == NULL) {
                    cur->left = new Node(data);
                    break;
                } else 
                    cur = cur->left;
            }
        }
    }

    int countNodes(Node *node) {
        if(node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};

Node *find_val(Node *root, int val) {
        if(root == NULL || root->data == val)
            return root;
        if(val <= root->data) 
            return find_val(root->left, val);
        else return find_val(root->right, val);
}

int main() {
    Tree *tree = new Tree();
    
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        tree->insert_node2(a);
    }
    int x; cin >> x;

    Node *should = find_val(tree->root, x);
    cout << tree->countNodes(should);

    return 0;
}