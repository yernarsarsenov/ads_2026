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
    Node *head1 = nullptr;
    cin >> n;
    if(n != 0) {
        cin >> a;
        head1 = new Node(a);
        Node *curr1 = head1;

        for (int i = 1; i < n; i++) {
            cin >> a;
            curr1->next = new Node(a); 
            curr1 = curr1->next;
        }
    }


    int m;
    Node *head2 = nullptr;
    cin >> m;
    if (m != 0) {
        cin >> a;
        head2 = new Node(a);
        Node *curr2 = head2;

        for (int i = 1; i < m; i++) {
            cin >> a;
            curr2->next = new Node(a);
            curr2 = curr2->next;
        }
    }

    Node dummy(0);
    Node *tail = &dummy;

    Node *p1 = head1;
    Node *p2 = head2;

    while(p1 != nullptr && p2 != nullptr) {
        if(p1->data <= p2->data) {
            tail->next = p1;
            p1 = p1->next;
        }
        else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    if(p1 != nullptr) tail->next = p1;
    else tail->next = p2;

    Node *out = dummy.next;

    while(out != nullptr) {
        cout << out->data << " ";
        out = out->next;
    }

    return 0;
}