#include <bits/stdc++.h>
using namespace std;

vector<int> pi_build(string s) {
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

    return pi;
}

int cnt_occur(string text, string pat) {
    string s = pat + '#' + text;
    int n = s.size(), m = pat.size(), cnt = 0;

    vector<int> pi = pi_build(s);
    for(int i = m + 1; i < n; i++) {
        if(pi[i] == m) cnt++;
    }

    return cnt;
}

int main() {

    string pass, text;
    int k;
    cin >> pass >> k >> text;

    int ans = cnt_occur(text, pass);

    cout << ((ans >= k) ? "YES" : "NO");

    return 0;
}