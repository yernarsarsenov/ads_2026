#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    unordered_map<char, int> freq;
    queue<char> q;
    
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        
        freq[ch]++;
        q.push(ch);
        
        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if(q.empty()) cout << -1;
        else cout << q.front();
        cout << " ";
    }
    cout << "\n";
}

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}