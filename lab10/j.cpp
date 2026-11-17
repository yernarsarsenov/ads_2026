#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> par(n + 1, 0), child(n + 1, 0);
    vector<bool> used(n + 1, false);
    int ans = 0;

    for(int s = 1; s <= n; s++) {
        if(used[s]) continue;

        ans++;
        used[s] = true;
        child[s] = g[s].size();

        queue<int> q;
        q.push(s);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(int u : g[v]) {
                if(used[u]) continue;

                used[u] = true;
                par[u] = v;
                child[u] = g[u].size() - 1;

                if(child[u] > child[v]) ans++;

                q.push(u);
            }
        }
    }

    cout << ans;

    return 0;
}