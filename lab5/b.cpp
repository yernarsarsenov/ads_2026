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

    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    while(heap->a.size() > 1) {
        int y = heap->extractMax();
        int x = heap->extractMax();
        if(x != y) {
            heap->insert(y - x);
        }
    }

    if(heap->a.empty()) cout << 0;
    else cout << heap->getMax();

    return 0;
}