#include <bits/stdc++.h>
using namespace std;

int upper(vector<int> &p, int &line, int &n) {
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(p[mid] >= line) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main() {

    int n, m, line, temp = 0, a;
    cin >> n >> m;
    vector<int> blocks(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> a;
        temp += a;
        p[i] = temp;
    }

    while(m--) {
        cin >> line;
        cout << upper(p, line, n) << "\n";
    }

    return 0;
}