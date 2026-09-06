#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    ll n;
    cin >> n;

    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            n /= i;
            cout << i << " ";
        }
    }

    if(n > 1) cout << n;

    return 0;
}