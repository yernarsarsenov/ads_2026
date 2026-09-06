#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll binExp(ll a, ll n, ll m) {
    ll res = 1;
    a %= m;
    while(n) {
        if(n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    res %= m;
    return res;
}

int main() {

    ll a, n, m;
    cin >> a >> n >> m;
    cout << binExp(a, n, m);

    return 0;
}