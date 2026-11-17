#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;

    const int n = 20002;
    vector<int> dist(n, -1), par(n, -1);

    queue<int> q;
    dist[a] = 0;
    q.push(a);

    while(!q.empty() && dist[b] == -1) {
        int v = q.front(); q.pop();
        int nxt[2] = {v*2, v-1};
        for(int u : nxt) {
            if(u < 1 || u > n || dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            par[u] = v;
            q.push(u);
        }
    }

    vector<int> path;
    for(int v = b; v != a; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int &u : path) cout << u << " ";

    return 0;
}