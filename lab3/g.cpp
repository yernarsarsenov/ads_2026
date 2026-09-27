#include <bits/stdc++.h>
using namespace std;

double solve(int &n, int &k, vector<int> &arr) {
    double l = 0, r = (double)*max_element(arr.begin(), arr.end());
    for(int i = 0; i < 100; i++) {
        double mid = l + (r - l) / 2;
        int sum = 0;
        for(int &a : arr) sum += a/mid;
        if(sum >= k) l = mid;
        else r = mid;
    }
    return l;
}

int main() {

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int &a : arr) cin >> a;

    printf("%.9f", solve(n, k, arr));

    return 0;
}