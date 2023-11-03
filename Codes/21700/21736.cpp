#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii start;
int n, m;

vector<string> campus(600);
bool visited[600][600];

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

inline bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int count_people(pii& start) {
    int count = 0;

    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        char content = campus[curr.first][curr.second];
        if (content == 'X') {
            continue;
        }

        if (content == 'P') {
            count++;
        }

        for (int i = 0; i < 4; ++i) {
            int x_next = curr.first + dx[i];
            int y_next = curr.second + dy[i];

            if (!in_range(x_next, y_next) || visited[x_next][y_next]) {
                continue;
            }

            visited[x_next][y_next] = true;
            q.push({ x_next, y_next });
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> campus[i];

        for (int j = 0; j < m; ++j) {
            if (campus[i][j] == 'I') {
                start = { i, j };
            }
        }
    }

    int count = count_people(start);
    if (count == 0) {
        cout << "TT";
    } else {
        cout << count;
    }

    return 0;
}
