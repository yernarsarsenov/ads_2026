#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* curr = head;
    while (--p) {
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head) return nullptr;
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1; i++) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (!head) return head;

    Node* curr = head;
    int val = 0;
    if (p1 == 0) {
        val = head->val;
    } else {
        for (int i = 0; i < p1 - 1; i++) {
            curr = curr->next;
        }
        val = curr->next->val;
    }

    head = remove(head, p1);
    head = insert(head, new Node(val), p2);
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << "\n";
        return;
    }
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int getLength(Node* head) {
    int len = 0;
    Node* curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }
    return len;
}

Node* cyclic_left(Node* head, int x) {
    int len = getLength(head);
    if (len <= 1) return head;
    x %= len;
    if (x == 0) return head;

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;

    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    int len = getLength(head);
    if (len <= 1) return head;
    x %= len;
    if (x == 0) return head;

    return cyclic_left(head, len - x);
}

int main() {

    Node* head = nullptr;
    int command;

    while (true) {
        cin >> command;
        if (command == 0) {
            break;
        } 
        else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        } 
        else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } 
        else if (command == 3) {
            print(head);
        } 
        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } 
        else if (command == 5) {
            head = reverse(head);
        } 
        else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } 
        else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    return 0;
}