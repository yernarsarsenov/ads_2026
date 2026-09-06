#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
    if(a <= 1) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

int main() {

    int a;
    cin >> a;

    if(isPrime(a)) cout << "YES";
    else cout << "NO";

    return 0;
}