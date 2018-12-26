#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main() {
    int t, n;
    scanf("%d", &t);
    dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
    for(int i = 6; i <= 100; ++i) dp[i] = dp[i - 1] + dp[i - 5];
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
