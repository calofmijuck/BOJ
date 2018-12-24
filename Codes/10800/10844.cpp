#include <bits/stdc++.h>
using namespace std;

int dp[10][101];

int main() {
    for(int i = 1; i <= 9; ++i) dp[i][1] = 1;
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        dp[0][i + 1] = dp[1][i];
        for(int j = 1; j < 9; ++j) dp[j][i + 1] = (dp[j - 1][i] + dp[j + 1][i]) % 1000000000;
        dp[9][i + 1] = dp[8][i];
    }
    for(int i = 0; i < 10; ++i) sum = (sum + dp[i][n]) % 1000000000;
    printf("%d", sum);
    return 0;
}
