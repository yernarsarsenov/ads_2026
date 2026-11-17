#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int main() {

    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int mushrooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
                q.push({i, j});
            else if (graph[i][j] == 1)
                mushrooms++;
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        int sz = q.size();
        bool changed = false;

        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int tx = x + dx[j];
                int ty = y + dy[j];

                if (tx >= 0 && tx < n && ty >= 0 && ty < m && graph[tx][ty] == 1) {
                    graph[tx][ty] = 2;
                    q.push({tx, ty});
                    mushrooms--;
                    changed = true;
                }
            }
        }

        if (changed)
            cnt++;
    }

    if(!mushrooms) cout << cnt;
    else cout << -1;

    return 0;
}