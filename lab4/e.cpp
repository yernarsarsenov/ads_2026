#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int get_height(Node *node) {
    if (node == nullptr) return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}

void count_nodes_for_level(Node *node, int level, vector<int> &nodes) {
    if (node == nullptr) return;

    nodes[level]++;
    count_nodes_for_level(node->left, level + 1, nodes);
    count_nodes_for_level(node->right, level + 1, nodes);
}

int main() {

    int n;
    cin >> n;

    vector<Node*> nodes_map(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes_map[i] = new Node(i);
    }

    Node *root = nodes_map[1];

    for (int i = 0; i < n - 1; i++) {
        int u, v, z;
        cin >> u >> v >> z;

        Node *parent = nodes_map[u];
        Node *child = nodes_map[v];

        if (z == 0) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    int height = get_height(root);
    vector<int> level_counts(height, 0);

    count_nodes_for_level(root, 0, level_counts);

    int max_width = 0;
    for (int count : level_counts) {
        max_width = max(max_width, count);
    }

    cout << max_width << "\n";

    return 0;
}