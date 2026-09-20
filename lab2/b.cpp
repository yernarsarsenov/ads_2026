#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

    int a;
    cin >> a;
    Node* head = new Node(a);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        cin >> a;
        current->next = new Node(a);
        current = current->next;
    }

    Node* prev = head;
    while (prev != nullptr && prev->next != nullptr) {
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        prev = prev->next; 
    }

    Node* out = head;
    while (out != nullptr) {
        cout << out->data << " ";
        Node* nextNode = out->next;
        out = nextNode;
    }

    return 0;
}
