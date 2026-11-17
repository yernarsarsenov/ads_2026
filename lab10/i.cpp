#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> was, in_path;
vector<int> ans;
bool cycle = false;

void top_sort(int u) {
    if(cycle) return;
    was[u] = true;
    in_path[u] = true;
    for(int v : g[u]) {
        if(in_path[v])
            cycle = true;
        if(!was[v]) {
            top_sort(v);
        }
    }
    ans.push_back(u);
    in_path[u] = false;
}

int main() {

    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    was.resize(n + 1, false);
    in_path.resize(n + 1, false);

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);     
    }

    for(int i = n; i > 0; i--)
        if(!was[i]) top_sort(i);

    reverse(ans.begin(), ans.end());

    if(cycle)
        cout << "Impossible";
    else {
        cout << "Possible\n";
        for(int &a : ans)
            cout << a << " ";
    }

    return 0;
}