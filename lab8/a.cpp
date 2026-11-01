#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1e9 + 7;

int main() {

    int n; 
    cin >> n;
    
    vector<string> a(2 * n);
    for (string &x : a) cin >> x;
    unordered_set<string> s(a.begin(), a.end());

    for (string &x : a) {
        long long h = 0, p = 1;
        for (char c : x) {
            h = (h + (c - 47) * p) % M;
            p = p * 11 % M;
        }
        if (s.count(to_string(h))) {
            cout << "Hash of string \"" << x << "\" is " << h << "\n";
            if (--n == 0) break;
        }
    }
}