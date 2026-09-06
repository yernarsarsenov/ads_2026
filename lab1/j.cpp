#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    deque<int> boris(5);
    deque<int> nursik(5);
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        cin >> boris[i];
    }
    for(int i = 0; i < 5; i++) {
        cin >> nursik[i];
    }
    while(!boris.empty() && !nursik.empty()) {
        if(cnt >= (int)1e6) {
            cout << "blin nichya"; return 0; 
        }
        int b = boris.front();
        int n = nursik.front();
        if(n == 0 && b == 9) {
            nursik.pop_front(); boris.pop_front();
            nursik.push_back(b); nursik.push_back(n);
        }
        else if(b == 0 && n == 9) {
            nursik.pop_front(); boris.pop_front();
            boris.push_back(b); boris.push_back(n);
        }
        else if(b > n) {
            nursik.pop_front(); boris.pop_front();
            boris.push_back(b); boris.push_back(n);
        }
        else if(n > b){
            nursik.pop_front(); boris.pop_front();
            nursik.push_back(b); nursik.push_back(n);
        }
        cnt++;
    }
    
    if(nursik.empty()) cout << "Boris";
    else cout << "Nursik";
    cout << " " << cnt;
    
    return 0;
}