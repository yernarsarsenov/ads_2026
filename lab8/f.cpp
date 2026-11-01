#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<ull> get_h(string s) {
    int n = s.size();
    vector<ull> h(n);

    h[0] = s[0];
    ull p = 29, p_pow = 29;

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;
    int n = s.size();

    vector<ull> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] * 29;

    vector<ull> h = get_h(s);

    vector<ull> all;
    all.reserve((size_t)n * (n + 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ull hash = h[j];
            if (i > 0)
                hash = hash - h[i - 1];
            all.push_back(hash * p[n - 1 - i]);
        }
    }

    sort(all.begin(), all.end());

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        ull hash = h[r];
        if (l > 0)
            hash = hash - h[l - 1];
        hash = hash * p[n - 1 - l];

        int cnt = upper_bound(all.begin(), all.end(), hash) - lower_bound(all.begin(), all.end(), hash);
        cout << cnt << "\n";
    }

    return 0;
}