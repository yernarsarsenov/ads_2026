#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {

    int n, a;
    cin >> n >> a;

    Node *head = new Node(a);
    Node *curr = head;

    for(int i = 1; i < n; i++) {
        cin >> a;
        curr->next = new Node(a);
        curr = curr->next;
    }

    Node *out = nullptr;

    while(head != nullptr) {
        Node *temp = head->next;
        head->next = out;
        out = head;
        head = temp;
    }

    while(out != nullptr) {
        cout << out->data << " ";
        out = out->next;
    }

    return 0;
}