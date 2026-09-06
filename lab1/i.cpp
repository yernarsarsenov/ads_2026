#include <bits/stdc++.h>
using namespace std;

void solve(int &n) {
    deque<int> d;

    for (int i = n; i >= 1; --i) {
        d.push_front(i);

        for (int k = 0; k < i; ++k) {
            int bottom = d.back();
            d.pop_back();
            d.push_front(bottom);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main() {
    
    int t;
    
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}