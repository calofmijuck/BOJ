#include <bits/stdc++.h>
using namespace std;

int page[505], idx[505][505], dp[505][505], sum[505];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", page + i);
            sum[i] = sum[i - 1] + page[i];
            dp[i - 1][i] = 0;
            idx[i - 1][i] = i;
        }
        for(int d = 2; d <= n; ++d) {
            for(int i = 0; i + d <= n; ++i) {
                int j = i + d;
                dp[i][j] = 2147483647;
                for(int k = idx[i][j - 1]; k <= idx[i + 1][j]; ++k) {
                    int curr = dp[i][k] + dp[k][j] + sum[j] - sum[i];
                    if(dp[i][j] > curr) {
                        dp[i][j] = curr;
                        idx[i][j] = k;
                    }
                }
            }
        }
        printf("%d\n", dp[0][n]);
    }
    return 0;
}
