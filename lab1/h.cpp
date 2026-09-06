#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> ages(n);
    for(int &a : ages) cin >> a;

    stack<int> temp;
    
    for(int &a : ages) {
        bool found = false;
        while(!temp.empty()) {
            if(temp.top() < a) {
                cout << temp.top() << " ";
                found = true;
                break;
            }
            temp.pop();
        }
        if(!found) cout << -1 << " ";
        temp.push(a);
    }

    return 0;
}