#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, a;
    cin >> n >> m;

    map<int, int> freq1, freq2;

    for(int i = 0; i < n; i++) {
        cin >> a;
        freq1[a]++;
    }

    for(int i = 0; i < m; i++) {
        cin >> a;
        freq2[a]++;
    }

    for(auto &[num, f1] : freq1) {
        auto it = freq2.find(num);
        if(it != freq2.end()) {
            int f2 = it->second;
            int min_cnt = min(f1, f2);

            for(int k = 0; k < min_cnt; k++)
                cout << num << " ";
        }
    }

    return 0;
}