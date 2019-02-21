#include <bits/stdc++.h>
using namespace std;

int fac(int n) {
    int ret = 1;
    for(int i = 1; i <= n; ++i) {
        int tmp = i;
        while(tmp % 10 == 0) tmp /= 10;
        ret *= tmp;
        while(ret % 10 == 0) ret /= 10;
        ret %= 100000;
    }
    return ret % 10;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int dig = fac(n);
        printf("%5d -> %d\n", n, dig);
    }
    return 0;
}
