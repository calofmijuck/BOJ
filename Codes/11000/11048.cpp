#include <bits/stdc++.h>
using namespace std;

int maze[1010][1010], dp[1010][1010];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) scanf("%d", &maze[i][j]);
    }
    dp[0][0] = maze[0][0];
    for(int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + maze[0][j];
    for(int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + maze[i][0];
        for(int j = 1; j < m; ++j) dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + maze[i][j];
    }
    printf("%d", dp[n - 1][m - 1]);
    return 0;
}
