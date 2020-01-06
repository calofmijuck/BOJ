#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int r, c, ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string mp[55];
bool visited[55][55], found = false;
vector<pii> water;
vector<pii> loc;

bool check(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void bfs() {
    queue<pii> q;
    for(pii v : water) {
        visited[v.first][v.second] = true;
        q.push(v);
    }
    water.clear();
    while(!q.empty()) {
        pii curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!check(nx, ny) || visited[nx][ny]) continue;
            if(mp[nx][ny] == '.') {
                mp[nx][ny] = '*';
                water.push_back({nx, ny});
            }
        }
    }

    ans++;

    queue<pii> qu;
    for(pii v : loc) {
        visited[v.first][v.second] = true;
        qu.push(v);
    }
    loc.clear();
    while(!qu.empty()) {
        pii curr = qu.front();
        qu.pop();
        int x = curr.first, y = curr.second;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!check(nx, ny) || visited[nx][ny]) continue;
            if(mp[nx][ny] == '.') {
                mp[nx][ny] = 'S';
                loc.push_back({nx, ny});
            } else if(mp[nx][ny] == 'D') {
                found = true;
                return;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; ++i) cin >> mp[i];
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(mp[i][j] == 'S') {
                loc.push_back({i, j});
            } else if(mp[i][j] == '*') {
                water.push_back({i, j});
            } else if(mp[i][j] == 'X') {
                visited[i][j] = true;
            }
        }
    }    
    while(!found && (loc.size() || water.size())) bfs();
    if(!found) cout << "KAKTUS";
    else cout << ans;
    return 0;
}
