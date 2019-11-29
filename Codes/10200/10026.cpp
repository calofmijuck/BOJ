#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
string str[110];
bool visited[110][110];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int x, int y) {
    queue<pii> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(!check(nx, ny)) continue;
            if(visited[nx][ny]) continue;
            if(str[x][y] == str[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; ++i) cin >> str[i];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!visited[i][j]) {
                bfs(i, j);
                ans1++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(str[i][j] == 'G') str[i][j] = 'R';
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!visited[i][j]) {
                bfs(i, j);
                ans2++;
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
