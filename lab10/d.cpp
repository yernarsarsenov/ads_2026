#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<int> dist;
vector<vector<int>> g;

void bfs(int v) { //
    queue<int> q;
    dist[v] = 0;
    q.push(v);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int x : g[curr]){
            if(dist[x] > dist[curr] + 1){
                dist[x] = dist[curr] + 1;
                q.push(x);
            }
        }
    }
} 

int main() {
    
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n+1);
    dist.assign(n+1, inf);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < q; i++){
        int c, v;
        cin >> c >> v;
        if(c == 1)
            bfs(v);
        else {
            if(dist[v] == inf) cout << -1 << "\n";
            else cout << dist[v] << "\n";
        } 
    }
    return 0;
}