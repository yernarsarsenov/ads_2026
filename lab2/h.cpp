#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Node {
    public:
    ll data;
    Node *next;

    Node(ll data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {

    int n;
    ll a;
    cin >> n >> a;

    Node *head = new Node(a);
    Node *curr = head;

    for (int i = 1; i < n; i++) {
        cin >> a;
        curr->next = new Node(a);
        curr = curr->next;
    }

    ll sum = head->data;
    ll ans = head->data;

    curr = head->next;
    while (curr != nullptr) {
        sum = max(curr->data, sum + curr->data);
        ans = max(ans, sum);
        curr = curr->next;
    }

    cout << ans << "\n";

    return 0;
}