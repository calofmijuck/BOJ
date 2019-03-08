#include <bits/stdc++.h>
using namespace std;

int n, m, field[51][51], dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
bool visited[51][51];

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int clean(int x, int y, int dir) {
    int ret = 0, nx, ny;
    if(!visited[x][y]) {
        ret++;
        visited[x][y] = true;
    }
    while(true) {
        bool flag = false;
        for(int i = 0; i < 4; ++i) {
            nx = x + dx[dir % 4];
            ny = y + dy[dir % 4];
            dir--;
            if(dir < 0) dir += 4;
            if(!check(nx, ny) || field[nx][ny] == 1 || visited[nx][ny]) continue;
            else {
                flag = true;
                visited[nx][ny] = true;
                ret++;
                x = nx, y = ny;
                break;
            }
        }
        if(!flag) {
            nx = x + dx[(dir + 3) % 4];
            ny = y + dy[(dir + 3) % 4];
            if(!check(nx, ny) || field[nx][ny] == 1) return ret;
            else x = nx, y = ny;
        }
    }
}

int main() {
    int r, c, d;
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) scanf("%d", &field[i][j]);
    }
    int ans = clean(r, c, d);
    printf("%d", ans);
    return 0;
}
