#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n;
    ll temp;
    cin >> n;
    vector<ll> a(n);

    for(ll &x : a) cin >> x;

    cout << char((a[0]>>0) + 97);
    for(int i = 1; i < n; i++) {
        ll temp = a[i] - a[i-1];
        cout << char((temp>>i) + 97);
    }

    return 0;
}