#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, was;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    was[x][y] = true;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if(graph[tx][ty] == 1 && !was[tx][ty]) {
                was[tx][ty] = 1;
                q.push({tx, ty});
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    graph.assign(n+2, vector<int> (m+2, 0));
    was.assign(n+2, vector<int> (m+2, 0));

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            graph[i][j] = s[j-1] - '0';
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(graph[i][j] == 1 && !was[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}