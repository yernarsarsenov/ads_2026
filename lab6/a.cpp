#include <bits/stdc++.h>
using namespace std;

bool isVowel(char &ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {

    int n;
    string s;
    cin >> n >> s;

    int cnt[26] = {};
    for(char &ch : s)
        cnt[ch - 'a']++;

    int pos = 0;

    for(char c = 'a'; c <= 'z'; c++) {
        if(!isVowel(c)) continue;
        for(int k = 0; k < cnt[c - 'a']; k++) s[pos++] = c;
    }

    for(char c = 'a'; c <= 'z'; c++) {
        if(isVowel(c)) continue;
        for(int k = 0; k < cnt[c - 'a']; k++) s[pos++] = c;
    }

    cout << s;

    return 0;
}