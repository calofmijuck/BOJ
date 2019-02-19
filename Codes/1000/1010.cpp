#include <cstdio>

int dp[30][30];

int main() {
    for(int i = 0; i < 30; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i < 30; i++) {
        for(int j = 1; j < 30; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    int t, n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", dp[m][n]);
    }
}
