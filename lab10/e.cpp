#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(matrix[a-1][b-1] == 1 && matrix[a-1][c-1] == 1 && matrix[b-1][c-1] == 1)
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}