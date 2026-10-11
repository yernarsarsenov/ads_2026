#include <bits/stdc++.h>
using namespace std;

int lower(vector<char> &arr, char &x) {
    int l = 0, r = arr.size()-1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] > x) r = mid;
        else l = mid+1;
    }
    return l;
}

int main() {

    int n;
    char k;
    cin >> n;
    vector<char> chs(n);

    for(char &ch : chs) cin >> ch;

    cin >> k;

    int ind = lower(chs, k);

    if(chs[ind] > k) cout << chs[ind];
    else cout << chs[0];

    return 0;
}