#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    long long ans = 1;
    for(int i = 1; i <= k; i++) {
        ans = ans * (n + 1 - i) / i;
    }
    printf("%lld", ans);
    return 0;
}
