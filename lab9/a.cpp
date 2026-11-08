#include <bits/stdc++.h>
using namespace std;

vector<int> pi_build(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];

        if(s[i] == s[j]) j++;

        pi[i] = j;
    }
    return pi;
}

bool kmp(string text, string pat) {
    string s = pat + "#" + text;
    int n = s.size(), m = pat.size();
    vector<int> pi = pi_build(s);

    for(int i = m+1; i < n; i++) {
        if(pi[i] == m) 
            return true;
    }
    return false;
}

int main() {

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int k = (m + n - 1) / n;
    string t;
    for(int i = 0; i < k; i++)
        t += a;

    vector<int> pi = pi_build(a);

    if(kmp(t, b)) {
        cout << k;
        return 0;
    }

    t += a;
    if(kmp(t, b)) {
        cout << k+1;
        return 0;
    }
    else cout << -1;

    return 0;
}