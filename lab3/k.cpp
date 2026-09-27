#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    vector<int> queries(t);
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    unordered_map<int, pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pos[matrix[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < t; i++) {
        int val = queries[i];
        auto it = pos.find(val);
        if (it != pos.end()) {
            cout << it->second.first << " " << it->second.second << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}