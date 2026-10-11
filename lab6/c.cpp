#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &arr, int l, int r) {
    int p = arr[l + (r - l) / 2], i = l, j = r;

    while(i < j) {
        while(p > arr[i]) i++;
        while(p < arr[j]) j--;

        if(i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if(l < j) quicksort(arr, l, j);
    if(r > i) quicksort(arr, i, r);
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &a : arr) cin >> a;

    quicksort(arr, 0, n-1);

    int min_diff = 0;

    for (int i = 0; i < n - 1; i++) {
        min_diff = min(min_diff, arr[i+1] - arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] == min_diff) {
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }

    return 0;
}