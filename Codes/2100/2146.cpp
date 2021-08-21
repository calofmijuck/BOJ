#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n;
int world[100][100];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool visited[100][100];
bool beach[100][100];

inline bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

inline bool is_beach(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny) && world[nx][ny] == 0) {
            return true;
        }
    }
    return false;
}

void bfs(int x, int y, int islands) {
    visited[x][y] = true;
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        world[curr.first][curr.second] = islands;
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (!check(nx, ny) || visited[nx][ny]) {
                continue;
            }
            if (world[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void group_islands() {
    int islands = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (world[i][j] == 0) {
                continue;
            }

            if (!visited[i][j]) {
                islands++;
                bfs(i, j, islands);
            }

            if (is_beach(i, j)) {
                beach[i][j] = true;
            }
        }
    }
}

int calculate(int x, int y, int min_length) {
    int ret = min_length;
    for (int i = x; i <= min(n - 1, x + min_length); ++i) {
        for (int j = max(0, y - min_length); j <= min(n - 1, y + min_length); ++j) {
            if (!beach[i][j] || world[x][y] == world[i][j]) {
                continue;
            }

            ret = min(ret, abs(i - x) + abs(j - y) - 1);
        }
    }
    return ret;
}

int min_bridge_length() {
    int min_length = 200;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!beach[i][j]) {
                continue;
            }

            int length = calculate(i, j, min_length);
            min_length = min(min_length, length);
        }
    }
    return min_length;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> world[i][j];
        }
    }

    group_islands();
    cout << min_bridge_length();
    return 0;
}
