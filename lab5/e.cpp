#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MinHeap {
    public:
    vector<ll> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    ll getMin() {
        return a[0];
    }

    void insert(ll k) {
        a.push_back(k);
        int ind = a.size()-1;

        while(ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if(left(i) > a.size()-1) return;
        
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] < a[left(i)]) {
            j = right(i);
        }

        if(a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    ll extractMin() {
        ll root_val = getMin();
        swap(a[0], a[a.size()-1]);
        a.pop_back();

        if(a.size() > 0)
            heapify(0);

        return root_val;
    }
};

int main() {

    MinHeap *heap = new MinHeap();
    
    int q, k;
    string com;
    cin >> q >> k;
    ll curr = 0;

    while(q--) {
        cin >> com;
        if(com == "insert") {
            ll n;
            cin >> n;
            if (heap->a.size() < k) {
                heap->insert(n);
                curr += n;
            } 
            else if (n > heap->getMin()) {
                curr -= heap->getMin();
                heap->extractMin();
                
                heap->insert(n);
                curr += n;
            }
        }
        else
            cout << curr << "\n";
    }

    return 0;
}