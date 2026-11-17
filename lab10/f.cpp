#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

bool sameComponent(int a, int b) {
    queue<int> q;

    visited[a] = true;
    q.push(a);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == b) return true;

        for (int u : g[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    visited.assign(n+1, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int u, v;
    cin >> u >> v;
    cout << ((sameComponent(u, v)) ? "YES" : "NO");

    return 0;
}