#include <bits/stdc++.h>
using namespace std;

int m, n, path[510][510], dp[510][510], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int dfs(int x, int y) {
    if(x == m && y == n) return 1;
    if(~dp[x][y]) return dp[x][y];
    dp[x][y] = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(path[nx][ny] && path[nx][ny] < path[x][y]) dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}


int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) scanf("%d", &path[i][j]), dp[i][j] = -1;
    }
    printf("%d", dfs(1, 1));
    return 0;
}
