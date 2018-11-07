#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Answer: Cn = Binom(2n, n) / (n + 1)
ll ans[31] = {1, 1};

int main() {
    int n;
    for(ll i = 2; i <= 30; ++i)
        ans[i] = (4 * i - 2) * ans[i - 1] / (i + 1);
    while(scanf("%d", &n) && n) {
        printf("%lld\n", ans[n]);
    }
    return 0;
}
