#include <bits/stdc++.h>
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
    
    if(n == 1) {
        int a;
        cin >> a;
        cout << "";
        return 0;
    }

    int a;
    cin >> a;
    Node *head = new Node(a);
    Node *curr = head;

    for(int i = 1; i < n; i++) {
        cin >> a;
        curr->next = new Node(a);
        curr = curr->next;
    }

    Node *prev = head;

    int cnt = (n>>1)-1;
    while(cnt && prev->next != nullptr) {
        prev = prev->next;
        cnt--;
    }

    if(prev->next != nullptr) {
        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }

    Node* out = head;
    while (out != nullptr) {
        cout << out->data << " ";
        Node* nextNode = out->next;
        out = nextNode;
    }

    return 0;
}