#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    string data;
    Node *next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {

    int n, k;
    string s;
    cin >> n >> k;
    Node *head = nullptr;
    Node *tail = nullptr;

    for(int i = 0; i < n; i++) {
        cin >> s;
        Node *newNode = new Node(s);
    
        if(!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *curr = head;
    for (int i = 1; i < k; i++) curr = curr->next;

    tail->next = head;
    head = curr->next;
    curr->next = nullptr;

    Node *out = head;
    while(out != nullptr) {
        cout << out->data << " ";
        out = out->next;
    }

    return 0;
}