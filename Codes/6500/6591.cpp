#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int n, k;
    ull prod = 1;
    while(scanf("%d %d", &n, &k) && n) {
        prod = 1;
        k = min(k, n - k);
        for(ull i = 1; i <= k; i++) {
            prod = prod * (n - k + i) / i;
        }
        printf("%llu\n", prod);
    }
    return 0;
}
