#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int board[1000][1000];
int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool visited[1000][1000], marked[1000][1000];
pii set_info[1000][1000]; // (size, no)

bool perform_search(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && board[x][y] == 0;
}

int dfs(int x, int y, int depth) {
    visited[x][y] = true;
    int ret = depth + 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!perform_search(nx, ny)) continue;
        if(visited[nx][ny]) continue;
        ret = dfs(nx, ny, ret);
    }
    return ret;
}

void mark(int x, int y, pii set) {
    marked[x][y] = true;
    set_info[x][y] = set;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!perform_search(nx, ny)) continue;
        if(marked[nx][ny]) continue;
        mark(nx, ny, set);
    }
}

int solve(int x, int y) {
    int ret = 1;
    unordered_map<int, bool> sets;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!perform_search(nx, ny)) continue;
        pii set = set_info[nx][ny];
        int set_size = set.first, idx = set.second;
        if(sets.find(idx) == sets.end()) {
            sets[idx] = true;
            ret += set_size;
        }
    }
    return ret % 10;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        for(int j = 0; j < m; ++j)
            board[i][j] = str[j] - '0';
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(visited[i][j] || board[i][j] != 0) continue;
            int cnt = dfs(i, j, 0);
            mark(i, j, {cnt, m * i + j});
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0)
                cout << 0;
            else
                cout << solve(i, j);
        }
        cout << '\n';
    }
    return 0;
}
