#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;

bool can_sort(int skip) {
    vector<int> deg = indeg;
    if(skip) deg[skip]--;

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    int cnt = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cnt++;

        for(int u : g[v]) {
            deg[u]--;
            if(deg[u] == 0) q.push(u);
        }
    }

    return cnt == n;
}

int main() {

    cin >> n >> m;

    g.resize(n + 1);
    indeg.assign(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    if(can_sort(0)) {
        cout << "YES";
        return 0;
    }

    for(int v = 1; v <= n; v++) {
        if(indeg[v] > 0 && can_sort(v)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}