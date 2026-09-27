#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    long long sum = 0;
    int l = 0, best = n;

    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (l <= r && sum >= k) {
            best = min(best, r - l + 1);
            sum -= a[l++];
        }
    }

    cout << best << "\n";
    return 0;
}