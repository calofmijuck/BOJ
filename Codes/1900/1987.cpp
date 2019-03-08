#include <bits/stdc++.h>
using namespace std;

char board[25][25];
int r, c, ans, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool check(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

bool exist(int visited, char c) {
    int offset = 1 << (c - 'A');
    return (visited & offset) > 0;
}

void dfs(int x, int y, int visited, int cnt) {
    ans = max(ans, cnt);
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!check(nx, ny) || exist(visited, board[nx][ny])) continue;
        int next = 1 << (board[nx][ny] - 'A');
        dfs(nx, ny, visited | next, cnt + 1);
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; ++i) scanf("%s", board[i]);
    dfs(0, 0, 1 << (board[0][0] - 'A'), 1);
    printf("%d", ans);
    return 0;
}
