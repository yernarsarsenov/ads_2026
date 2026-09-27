#include <bits/stdc++.h>
using namespace std;

string binSearch(int n, vector<int> &arr, int target) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return "Yes";
        if(arr[mid] < target) l = mid+1;
        else r = mid-1; 
    }
    return "No";
}

int main() {

    int n, target;
    cin >> n;

    vector<int> arr(n);
    
    for(int &a : arr) cin >> a;

    cin >> target;

    cout << binSearch(n, arr, target); 

    return 0;
}