#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n) {
    ll fac = 1;
    for(int i = 2; i <= n; ++i) {
        fac *= i;
        while(fac % 5 == 0) fac /= 10;
        fac %= 1000;
    }
    return (int) fac % 10;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
