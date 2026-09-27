#include <bits/stdc++.h>
using namespace std;
//1 2 2 6 7 8 9
int upper(vector<int> &arr, int &n, int &power) {
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(arr[mid] > power) r = mid;
        else l = mid+1;
    }
    return l;
}

int main() {

    int n, p, power;
    cin >> n;
    vector<int> arr(n), prefix(n+1);
    for(int &a : arr) cin >> a;
    sort(arr.begin(), arr.end());

    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        prefix[i+1] = arr[i] + prefix[i];
    }

    cin >> p;
    while(p--) {
        cin >> power;
        int ind = upper(arr, n, power);
        cout << ind << " " << prefix[ind] << "\n";
    }

    return 0;
}