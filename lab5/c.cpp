#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size()-1;

        while(ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if(left(i) > a.size()-1) return;

        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);

        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_val = getMax();

        swap(a[0], a[a.size()-1]);
        a.pop_back();

        if(a.size() > 0) 
            heapify(0);

        return root_val;
    }

};

int main() {

    MaxHeap *heap = new MaxHeap();

    int n, k, x;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    long long ans = 0;
    while(k--) {
        int price = heap->extractMax();
        ans += price;
        heap->insert(--price);
    }

    cout << ans;

    return 0;
}