#include <bits/stdc++.h>
using namespace std;

int num[501][501], dp[501][501];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) scanf("%d", &num[i][j]);
    }
    dp[0][0] = num[0][0];
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            dp[i][j] = max(dp[i - 1][j] + num[i][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i - 1][j] + num[i][j + 1], dp[i][j + 1]);
        }
    }
    for(int i = 0; i < n; ++i) ans = max(ans, dp[n - 1][i]);
    printf("%d", ans);
    return 0;
}
