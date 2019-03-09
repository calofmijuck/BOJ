#include <bits/stdc++.h>
using namespace std;

int n, m, board[505][505], ans, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool visited[505][505];

void dfs(int x, int y, int cnt, int sum) {
    if(cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 > nx || nx >= n || 0 > ny || ny >= m || visited[nx][ny]) continue;
        dfs(nx, ny, cnt + 1, sum + board[nx][ny]);
    }
    visited[x][y] = false;
}

void solve(int x, int y) {
    int sum = board[x][y], mi = 5000, cnt = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
        cnt++;
        mi = min(mi, board[nx][ny]);
        sum += board[nx][ny];
    }
    if(cnt == 4) ans = max(ans, sum - mi);
    else if(cnt == 3) ans = max(ans, sum);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) scanf("%d", &board[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dfs(i, j, 1, board[i][j]);
            solve(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}
