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

    string oper, s;
    Node *head = nullptr, *tail = nullptr;

    while (cin >> oper) {
        if (oper == "add_front") {
            cin >> s;
            add_front(head, tail, s);
        } 
        else if (oper == "add_back") {
            cin >> s;
            add_back(head, tail, s);
        } 
        else if (oper == "erase_front") {
            erase_front(head, tail);
        } 
        else if (oper == "erase_back") {
            erase_back(head, tail);
        } 
        else if (oper == "front") {
            front(head);
        } 
        else if (oper == "back") {
            back(tail);
        } 
        else if (oper == "clear") {
            clear(head, tail);
        } 
        else if (oper == "exit") {
            cout << "goodbye";
            break;
        }
    }

    return 0;
}