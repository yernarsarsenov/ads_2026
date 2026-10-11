#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<vector<int>> &arr, int l, int r, int row) {
    int p = arr[l + (r - l) / 2][row], i = l, j = r;

    while(i < j) {
        while(p < arr[i][row]) i++;
        while(p > arr[j][row]) j--;

        if(i <= j) {
            swap(arr[i][row], arr[j][row]);
            i++; j--;
        }
    }

    if(l < j) quicksort(arr, l, j, row);
    if(r > i) quicksort(arr, i, r, row);
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cin >> matrix[i][j];
    }

    for(int j = 0; j < m; j++) {
        quicksort(matrix, 0, n-1, j);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}