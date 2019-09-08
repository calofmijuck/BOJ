#include <bits/stdc++.h>
using namespace std;

int n, h;
int mp[110][110], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool visited[110][110];

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!check(nx, ny)) continue;
        if(mp[nx][ny] > h && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cin >> mp[i][j];
    }
    int ans = 0;
    for(int k = 0; k <= 100; ++k) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && mp[i][j] > k) {
                    h = k;
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}