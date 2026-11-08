#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {

    string p, x;
    int n;
    cin >> p >> n;
    vector<string> ts(n);
    vector<pair<string, int>> res;
    vector<string> ans;

    for(int i = 0; i < n; i++) {
        cin >> ts[i];
    }
    int mx = -1;
    for(string s : ts) {
        string s_copy = s;
        s_copy[0] = tolower(s_copy[0]);
        string temp = s_copy + '#' + p;
        vector<int> pi = prefix_function(temp);
        int last_ind = temp.size()-1;
        if(pi[last_ind] != 0) {
            res.push_back({s, pi[last_ind]});
            mx = max(mx, pi[last_ind]);
        }
    }

    for(auto &[s, p] : res) {
        if(p == mx)
            ans.push_back(s);
    }

    cout << ans.size() << '\n';

    for(string &s : ans) cout << s << "\n";

    return 0;
}