#include <bits/stdc++.h>
using namespace std;

int wine[10101], dp[10101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", wine + i);
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for(int i = 3; i <= n; ++i) dp[i] = max(max(dp[i - 2], dp[i - 3] + wine[i - 1]) + wine[i], dp[i - 1]);
    printf("%d", dp[n]);
    return 0;
}
