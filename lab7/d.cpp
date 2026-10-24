#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) 
        L[i] = a[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    ll cnt = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else {
            a[k++] = R[j++];
            cnt += n1 - i;
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    return cnt;
}

ll mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    ll cnt = 0;
    cnt += mergeSort(a, left, mid);
    cnt += mergeSort(a, mid + 1, right);
    cnt += merge(a, left, mid, right);
    return cnt;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    cout << mergeSort(arr, 0, n - 1);

    return 0;
}