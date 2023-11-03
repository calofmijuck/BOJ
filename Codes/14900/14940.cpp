#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

typedef pair<int, int> pii;

int n, m;

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dist[MAX_N][MAX_N];

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

inline bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void process_same_distance(queue<pii>& q, int distance) {
    int size = q.size();
    for (int t = 0; t < size; ++t) {
        pii curr = q.front();
        q.pop();

        dist[curr.first][curr.second] = distance;

        for (int i = 0; i < 4; ++i) {
            int x_next = curr.first + dx[i];
            int y_next = curr.second + dy[i];

            if (!in_range(x_next, y_next) || visited[x_next][y_next]) {
                continue;
            }

            visited[x_next][y_next] = true;

            if (board[x_next][y_next] == 1) {
                q.push({ x_next, y_next });
            }
        }
    }
}

void calculate_distance(pii& start) {
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    int distance = 0;
    while (!q.empty()) {
        process_same_distance(q, distance);
        distance++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dist, -1, sizeof(dist));

    pii start;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                start = { i, j };
            } else if (board[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    calculate_distance(start);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
