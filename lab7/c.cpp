#include <bits/stdc++.h>
#define ll long long
using namespace std;

void merge(vector<vector<int>>& matrix, vector<ll>& sum, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> Lm(n1);
    vector<ll> Ls(n1);
    vector<vector<int>> Rm(n2);
    vector<ll> Rs(n2);

    for (int i = 0; i < n1; i++) {
        Lm[i] = matrix[left + i];
        Ls[i] = sum[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Rm[j] = matrix[mid + 1 + j];
        Rs[j] = sum[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (Ls[i] > Rs[j] || (Ls[i] == Rs[j] && Lm[i] <= Rm[j])) {
            matrix[k] = Lm[i];
            sum[k] = Ls[i];
            i++;
        } else {
            matrix[k] = Rm[j];
            sum[k] = Rs[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        matrix[k] = Lm[i];
        sum[k] = Ls[i];
        i++;
        k++;
    }

    while (j < n2) {
        matrix[k] = Rm[j];
        sum[k] = Rs[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& matrix, vector<ll>& sum, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(matrix, sum, left, mid);
    mergeSort(matrix, sum, mid + 1, right);
    merge(matrix, sum, left, mid, right);
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<ll> sum(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            sum[i] += matrix[i][j];
        }
    }

    if (n > 1)
        mergeSort(matrix, sum, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}