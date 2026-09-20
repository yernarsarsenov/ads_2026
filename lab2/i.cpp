#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node *next;
    Node *prev;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void add_front(Node *&head, Node *&tail, string &a) {
    Node *node = new Node(a);
    if (head == nullptr)
        head = tail = node; 
    else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    cout << "ok\n";
}

void add_back(Node *&head, Node *&tail, string &a) {
    Node *node = new Node(a);
    if (tail == nullptr)
        head = tail = node;
    else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    cout << "ok\n";
}

void erase_front(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "error\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    else head->prev = nullptr;
    cout << temp->data << "\n";
    delete temp;
}

void erase_back(Node *&head, Node *&tail) {
    if (tail == nullptr) {
        cout << "error\n";
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail == nullptr) head = nullptr;
    else tail->next = nullptr;
    cout << temp->data << "\n";
    delete temp;
}

void front(Node *head) {
    if (head == nullptr) cout << "error\n";
    else cout << head->data << "\n";
}

void back(Node *tail) {
    if (tail == nullptr) cout << "error\n";
    else cout << tail->data << "\n";
}

void clear(Node *&head, Node *&tail) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    cout << "ok\n";
}

int main() {

    string com, s;
    Node *head = nullptr, *tail = nullptr;

    while (cin >> com) {
        if (com == "add_front") {
            cin >> s;
            add_front(head, tail, s);
        } 
        else if (com == "add_back") {
            cin >> s;
            add_back(head, tail, s);
        } 
        else if (com == "erase_front") {
            erase_front(head, tail);
        } 
        else if (com == "erase_back") {
            erase_back(head, tail);
        } 
        else if (com == "front") {
            front(head);
        } 
        else if (com == "back") {
            back(tail);
        } 
        else if (com == "clear") {
            clear(head, tail);
        } 
        else if (com == "exit") {
            cout << "goodbye";
            break;
        }
    }

    return 0;
}