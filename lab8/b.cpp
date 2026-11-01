#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll M1 = 1e9+7, M2 = 1e9+9, p = 31;
vector<ll> p1, p2;
vector<ll> build(string s, ll mod) {
    vector<ll> h(s.size()+1, 0);
    for(int i = 0; i < s.size(); i++) 
        h[i+1] = (h[i] * p + s[i] - 'a' + 1) % mod;
    return h;
}
ll get(vector<ll>& h, int l, int len, vector<ll>& pw, ll mod) {
    return (h[l + len] - h[l] * pw[len] % mod + mod) % mod;
}
int main() {
    string a, b, w; cin >> a >> b >> w;
    int n = w.size();
    int lim = min(a.size(), b.size()) - n + 1;
    p1.resize(n+1, 1);
    p2.resize(n+1, 1);
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i-1] * p % M1;
        p2[i] = p2[i-1] * p % M2;
    }
    vector<ll> a1 = build(a, M1);
    vector<ll> b1 = build(b, M1);
    vector<ll> w1 = build(w, M1);
    vector<ll> a2 = build(a, M2);
    vector<ll> b2 = build(b, M2);
    vector<ll> w2 = build(w, M2);
    ll target1 = get(w1, 0, n, p1, M1);
    ll target2 = get(w2, 0, n, p2, M2);
    int ans = 0;
    for(int i = 0; i < lim; i++) {
        if(get(a1, i, n, p1, M1) == target1 && get(b1, i, n, p1, M1) == target1&& 
           get(a2, i, n, p2, M2) == target2 && get(b2, i, n, p2, M2) == target2) ans++;
    }
    cout << ans;
}