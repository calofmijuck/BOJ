#include <bits/stdc++.h>
using namespace std;

int mp[60][60];
bool visited[60][60];
int w, h, ans;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!check(nx, ny)) continue;
        if(mp[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin >> w >> h && (w != 0 || h != 0)) {
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) cin >> mp[i][j];
        }
        ans = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(mp[i][j] == 0 || visited[i][j]) continue;
                ans++;
                dfs(i, j);
            }
        }
        cout << ans << '\n';
    }
}