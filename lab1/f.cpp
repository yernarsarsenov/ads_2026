#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    stack<char> st1, st2;

    for(char &ch : s1) {
        if(ch == '#') {
            if(!st1.empty()) st1.pop();
        }
        else st1.push(ch);
    }

    for(char &ch : s2) {
        if(ch == '#') {
            if(!st2.empty()) st2.pop();
        }
        else st2.push(ch);
    }

    if(st1 == st2) cout << "Yes";
    else cout << "No";

    return 0;
}