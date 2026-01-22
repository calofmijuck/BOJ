#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[50][50];

struct info {
    int x;
    int y;
    int dist;
};

inline bool inbound(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(vector<string>& board, int i, int j) {
    memset(visited, false, sizeof(visited));

    queue<info> q;
    q.push({ i, j, 0 });
    visited[i][j] = true;

    int max_distance = 0;
    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        max_distance = max(dist, max_distance);

        for (int k = 0; k < 4; ++k) {
            int x_next = x + dx[k], y_next = y + dy[k];
            if (!inbound(x_next, y_next) || board[x_next][y_next] == 'W' || visited[x_next][y_next]) {
                continue;
            }

            visited[x_next][y_next] = true;
            q.push({ x_next, y_next, dist + 1 });
        }
    }
    return max_distance;
}

int solve(vector<string>& board) {
    int max_distance = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] != 'L') {
                continue;
            }

            max_distance = max(max_distance, bfs(board, i, j));
        }
    }
    return max_distance;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    cout << solve(board);
    return 0;
}
