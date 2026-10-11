#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<tuple<int, int, int>> &arr, int l , int r) {
    tuple<int, int, int> p = arr[l + (r - l) / 2];
    int i = l, j = r;

    while(i < j) {
        while(p < arr[j]) j--;
        while(p > arr[i]) i++;

        if(i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if(l < j) quicksort(arr, l, j);
    if(r > i) quicksort(arr, i, r);
}

int main() {

    int n;
    cin >> n;

    vector<tuple<int, int, int>> dates(n);

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        get<2>(dates[i]) = stoi(s.substr(0, 2));
        get<1>(dates[i]) = stoi(s.substr(3, 2));
        get<0>(dates[i]) = stoi(s.substr(6, 4));
    }

    quicksort(dates, 0, n-1);

    for(auto &[y, m, d] : dates)
        printf("%02d-%02d-%04d\n", d, m, y);

    return 0;
}