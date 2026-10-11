#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    vector<int> chs(26, 0);

    for(char &ch : s) {
        chs[ch - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < chs[i]; j++) {
            cout << (char)(i + 'a');
        }
    }

    return 0;
}