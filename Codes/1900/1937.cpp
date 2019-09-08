#include <bits/stdc++.h>
using namespace std;

int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int mp[510][510], dp[510][510];

int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(mp[x][y] < mp[nx][ny]) dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cin >> mp[i][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) ans = max(ans, dfs(i, j));
    }
    cout << ans;
    return 0;
}