#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }

    int ans = 0;
    for (int i = 1; 2 * i < n; i++) {
        int t = 2 * i - p[2 * i - 1];
        if (i % t == 0) ans++;
    }
    cout << ans;
}