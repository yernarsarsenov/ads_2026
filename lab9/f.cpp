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

void kmp(string text, string pat) {
    string s = pat + '#' + text;
    vector<int> pi = pi_build(s), ans;
    int n = s.size(), m = pat.size();

    for(int i = m + 1; i < n; i++) {
        if(pi[i] == m)
            ans.push_back(i - 2 * m);
    }
    cout << ans.size() << "\n";
    for(int &a : ans) cout << a + 1 << " ";
}

int main() {

    string a, b;
    cin >> a >> b;

    kmp(a, b);

    return 0;
}