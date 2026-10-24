#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll get_hash(string s) {
    ll res = 0;
    ll power = 1;
    for(char &ch : s) {
        ll val = (ch - 47) * power % MOD;
        res = (res + val) % MOD;
        power = (power * 11) % MOD;
    }
    return res % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string x;
    cin >> n;
    unordered_set<string> uniq;
    unordered_map<string, string> res;
    vector<string> order;
    

    int loop = 2*n;
    for(int i = 0; i < loop; i++) {
        cin >> x;
        order.push_back(x);
        uniq.emplace(x);
    }

    for(auto it = uniq.begin(); it != uniq.end(); it++) {
        ll temp = get_hash(*it);
        if(uniq.count(to_string(temp))) {
            res[*it] = to_string(temp);
        }
    }

    unordered_set<string> printed;
    for(string &s : order) {
        if(res.count(s)) {
            cout << "Hash of string \"" << s << "\" is " << res[s] << "\n";
            printed.emplace(s);
        }
    }

    return 0;
}