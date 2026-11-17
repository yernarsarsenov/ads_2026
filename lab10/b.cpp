#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100, vector<int>(100));
vector<int> d(100, -1);
queue<int> q;

void bfs(int x, int n) {
    q.push(x);
    d[x] = 0;

    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (d[i] == -1 && adj[x][i] == 1) {
                d[i] = d[x] + 1;
                q.push(i);
            }
        }
    }
}

int main() {

    int n, s, t;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cin >> s >> t;
    s--; t--;

    bfs(s, n);
    cout << d[t];
    return 0;
}