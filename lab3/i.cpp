#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool canPartition(vector<ll> &a, int n, int k, ll max_sum) {
    int blocks = 1;
    ll curr_sum = 0;

    for(ll &x : a) {
        if(x > max_sum)
            return false;
        if(curr_sum + x <= max_sum) 
            curr_sum += x;
        else {
            blocks++;
            curr_sum = x;
        }
    }

    return blocks <= k;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll low = 0, high = 0;

    for(ll &x : a) {
        cin >> x;
        low = max(low, x);
        high += x;
    }

    ll ans = high;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(canPartition(a, n, k, mid)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    cout << ans;

    return 0;
}