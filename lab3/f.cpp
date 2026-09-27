#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int &n, int &h, vector<int> &arr) {
    int l = 1, r = *max_element(arr.begin(), arr.end());
    int ans = r;
    while(l <= r) {
        int mid = l + (r-l)/2;
        ll total = 0;
        for(int &a : arr) total += (a + mid - 1) / mid;
        if(total <= h) {
            ans = mid;
            r = mid-1;
        }
        else 
            l = mid+1;
    }
}

int main() {

    int n, h;
    cin >> n >> h;
    vector<int> arr(n);

    for(int &a : arr) cin >> a;
    cout << solve(n, h, arr);

    return 0;
}