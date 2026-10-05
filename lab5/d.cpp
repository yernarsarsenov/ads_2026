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
        if(right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

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

    int n, m;
    ll x;
    cin >> n >> m;

    MinHeap* heap = new MinHeap();

    for(int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    int ans = 0;

    while(heap->getMin() < m) {
        if(heap->a.size() < 2) {
            cout << -1;
            return 0;
        }
        ll a = heap->extractMin();
        ll b = (heap->extractMin()) * 2;
        heap->insert(a + b);
        ans++;
    }

    cout << ans;

    return 0;
}