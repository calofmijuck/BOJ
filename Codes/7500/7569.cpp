#include <bits/stdc++.h>
using namespace std;

#define MAX_N 102

typedef struct {
    int x, y, z;
} triple;

bool visited[MAX_N][MAX_N][MAX_N];
int storage[MAX_N][MAX_N][MAX_N];
int dx[6] = {1, 0, -1, 0, 0, 0}, dy[6] = {0, 1, 0, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

int m, n, h, days = 0;

void mark_visited(triple &t) {
    visited[t.x][t.y][t.z] = true;
}

void mark_ripe(triple &t) {
    storage[t.x][t.y][t.z] = 1;
}

bool check_range(triple &t) {
    return 0 <= t.x && t.x < n && 0 <= t.y && t.y < m && 0 <= t.z && t.z < h;
}

bool can_step(triple &t) {
    return check_range(t) && !visited[t.x][t.y][t.z] && storage[t.x][t.y][t.z] == 0;
}

queue<triple> bfs(queue<triple> &ripe) {
    queue<triple> next_ripe;
    while (!ripe.empty()) {
        triple curr = ripe.front();
        ripe.pop();
        mark_visited(curr);
        int x = curr.x, y = curr.y, z = curr.z;
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            triple next = {nx, ny, nz};

            if (can_step(next)) {
                mark_visited(next);
                mark_ripe(next);
                next_ripe.push(next);
            }
        }
    }
    return next_ripe;
}

void check_ripe() {
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (storage[i][j][k] == 0) {
                    days = -1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;
    
    queue<triple> ripe;
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> storage[i][j][k];

                if (storage[i][j][k] == 1) {
                    ripe.push({i, j, k});
                }
            }
        }
    }

    do {
        ripe = bfs(ripe);
    } while (!ripe.empty() && ++days);

    check_ripe();

    cout << days;
}
