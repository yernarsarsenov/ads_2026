#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, k;
    cin >> n >> k;
    vector<int> sheeps;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sheeps.push_back(max({x1, x2, y1, y2}));
    }

    sort(sheeps.begin(), sheeps.end());

    cout << sheeps[k-1];

    return 0;
}