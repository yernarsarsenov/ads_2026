#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<ll> res(n);
    for (int &a : arr) cin >> a;

    int l = 0, r = n - 1, pos = n - 1;

    while (l <= r) {
        ll sl = arr[l] * arr[l];
        ll sr = arr[r] * arr[r];

        if (sl > sr) {
            res[pos--] = sl;
            l++;
        } 
        else {
            res[pos--] = sr;
            r--;
        }
    }

    for (ll x : res) cout << x << " ";

    return 0;
}