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

int patt_in_rot(string text, string pat) {
    string doubled = text + text, s = pat + '#' + doubled;
    vector<int> pi = pi_build(s);
    int n = s.size(), m = pat.size();

    for(int i = m + 1; i < n; i++) {
        if(pi[i] == m)
            return i-2*m;
    }

    return -1;
}

int main() {

    string a, b;
    cin >> a >> b;

    cout << patt_in_rot(b, a);

    return 0;
}