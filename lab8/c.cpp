#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull MOD  = (1ULL << 61) - 1;
const ull BASE = 29;

ull mul(ull a, ull b) {
    return (__int128)a * b % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<string> pattern(n);
        for (int k = 0; k < n; k++) cin >> pattern[k];

        string text;
        cin >> text;
        int len = text.size();

        vector<ull> pref(len + 1, 0), pw(len + 1, 1);
        for (int i = 0; i < len; i++) {
            pref[i + 1] = (mul(pref[i], BASE) + text[i]) % MOD;
            pw[i + 1]   = mul(pw[i], BASE);
        }

        vector<int> freq(n, 0);
        int best = 0;

        for (int k = 0; k < n; k++) {
            int m = pattern[k].size();

            ull patHash = 0;
            for (char c : pattern[k])
                patHash = (mul(patHash, BASE) + c) % MOD;

            for (int i = 0; i + m <= len; i++) {
                ull winHash = (pref[i + m] + MOD - mul(pref[i], pw[m])) % MOD;
                if (winHash == patHash) freq[k]++;
            }
            best = max(best, freq[k]);
        }

        cout << best << "\n";
        for (int k = 0; k < n; k++)
            if (freq[k] == best) cout << pattern[k] << "\n";
    }
    return 0;
}