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

    vector<int> ans;

    Node *temp1 = head1, *temp2 = head2;
    while(temp1 != nullptr && temp2 != nullptr) {
        int d1 = temp1->data;
        int d2 = temp2->data;
        if(d1 < d2) {
            ans.push_back(d1);
            temp1 = temp1->next;
        }
        else if(d2 < d1) {
            ans.push_back(d2);
            temp2 = temp2->next;
        }
        else {
            ans.push_back(d1); ans.push_back(d2);
            temp1 = temp1->next; temp2 = temp2->next;
        }
    }

    while(temp1 != nullptr) {
        ans.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != nullptr) {
        ans.push_back(temp2->data);
        temp2 = temp2->next;
    }

    for(int &a : ans)
        cout << a << " ";

    return 0;
}