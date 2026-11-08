#include <bits/stdc++.h>
#define ll long long
using namespace std;

int pi_build(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++) {
        int j = pi[i-1];

        while(j > 0 && s[i] != s[j])
            j = pi[j-1];

        if(s[i] == s[j]) j++;

        pi[i] = j;
    }
    return pi[n-1];
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        int k;
        cin >> s >> k;

        int p = pi_build(s);
        ll n = s.size();

        cout << n + (ll)(k-1) * (n - p) << "\n";
    }

    return 0;
}