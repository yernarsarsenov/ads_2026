#include <bits/stdc++.h>
using namespace std;

int lower(vector<int>& arr, int x) {
    int l = 0, r = arr.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int upper(vector<int> &arr, int x) {
    int l = 0, r = arr.size();
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] > x)
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}

int main() {

    int n, q, l1, r1, l2, r2;
    cin >> n >> q;

    vector<int> arr(n);

    for(int &a : arr) cin >> a;
    sort(arr.begin(), arr.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int a = upper(arr, r1) - lower(arr, l1);
        int b = upper(arr, r2) - lower(arr, l2);

        int L = max(l1, l2), R = min(r1, r2);
        int inter = 0;
        if (L <= R) inter = upper(arr, R) - lower(arr, L);

        cout << a + b - inter << '\n';
    }

    return 0;
}