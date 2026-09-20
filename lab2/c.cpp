#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    deque<string> q;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(!q.empty() && q.front() == s) continue;
        q.push_front(s);
    }

    cout << q.size() << "\n";
    
    while (!q.empty()) {
        cout << q.back() << "\n";
        q.pop_back();
    }

    return 0;
}