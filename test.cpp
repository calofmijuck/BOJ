#include <bits/stdc++.h>
using namespace std;

bool testPrime(int n) {
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    for(int i = 2; i <= 100; ++i) {
        if(testPrime(i)) printf("%d ", i);
    }

    return 0;
}
