#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<pair<string, string>> &arr, int l, int r) {
    string p = arr[l + (r - l) / 2].first;
    int i = l, j = r;

    while(i < j) {
        while(p > arr[i].first) i++;
        while(p < arr[j].first) j--;
    
        if(i <= j) {
            swap(arr[j], arr[i]);
            i++; j--;
        }
    }

    if(l < j) quicksort(arr, l, j);
    if(r > i) quicksort(arr, i, r);
}

int main() {

    int n;
    cin >> n;
    string old, ne;
    map<string, string> nicks;

    while(n--) {
        cin >> old >> ne;
        if(nicks.count(old)) {
            nicks[ne] = nicks[old];
            nicks.erase(old);
        }
        else nicks[ne] = old;
    }

    vector<pair<string, string>> res;

    for(auto &[ne, old] : nicks)
        res.push_back({old, ne});

    int m = res.size();
    quicksort(res, 0, m-1);
    cout << m << "\n";

    for(auto &[old, ne] : res)
        cout << old << " " << ne << "\n";

    return 0;
}