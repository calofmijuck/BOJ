#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int h, w, ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<string> str;
vector<vector<pii>> doors;
vector<bool> keys;
vector<vector<bool>> visited;

inline bool checkRange(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

void bfs(int x, int y) {
    visited[x][y] = true;
    queue<pii> q;
    q.push({x, y});
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(!checkRange(nx, ny) || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            char c = str[nx][ny];
            if(c == '*') continue;
            if(c == '$') {
                ans++;
                q.push({nx, ny});
            }
            if(c == '.') q.push({nx, ny});
            if('A' <= c && c <= 'Z') {
                doors[c - 'A'].push_back({nx, ny});
                if(keys[c - 'A'])
                    q.push({nx, ny});
            } else if('a' <= c && c <= 'z') {
                keys[c - 'a'] = true;
                q.push({nx, ny});
                for(pii d : doors[c - 'a'])
                    q.push(d);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> h >> w;
        str.clear(); str.resize(h);
        doors.clear(); doors.resize(26);
        visited.clear(); visited.resize(h);
        for(int i = 0; i < h; ++i)
            visited[i].resize(w);
        for(int i = 0; i < h; ++i)
            cin >> str[i];
        string key;
        cin >> key;
        keys.clear(); keys.resize(26);
        if(key[0] != '0') {
            for(int i = 0; i < key.size(); ++i)
                keys[key[i] - 'a'] = true;
        }
        ans = 0;
        int i = 0, j = 0;
        for(; j < w; ++j) {
            if(visited[i][j] || str[i][j] == '*') continue;
            char c = str[i][j];
            if(c == '.') bfs(i, j);
            else if('A' <= c && c <= 'Z') {
                doors[c - 'A'].push_back({i, j});
                if(keys[c - 'A']) bfs(i, j);
            } else if('a' <= c && c <= 'z') {
                keys[c - 'a'] = true;
                bfs(i, j);
                for(pii d : doors[c - 'a']) bfs(d.first, d.second);
            }
            if(c == '$') {
                ans++;
                bfs(i, j);
            }
        }
        j = w - 1;
        for(; i < h; ++i) {
            if(visited[i][j] || str[i][j] == '*') continue;
            char c = str[i][j];
            if(c == '.') bfs(i, j);
            else if('A' <= c && c <= 'Z') {
                doors[c - 'A'].push_back({i, j});
                if(keys[c - 'A']) bfs(i, j);
            } else if('a' <= c && c <= 'z') {
                keys[c - 'a'] = true;
                bfs(i, j);
                for(pii d : doors[c - 'a']) bfs(d.first, d.second);
            }
            if(c == '$') {
                ans++;
                bfs(i, j);
            }
        }
        i = h - 1;
        for(; j >= 0; --j) {
            if(visited[i][j] || str[i][j] == '*') continue;
            char c = str[i][j];
            if(c == '.') bfs(i, j);
            else if('A' <= c && c <= 'Z') {
                doors[c - 'A'].push_back({i, j});
                if(keys[c - 'A']) bfs(i, j);
            } else if('a' <= c && c <= 'z') {
                keys[c - 'a'] = true;
                bfs(i, j);
                for(pii d : doors[c - 'a']) bfs(d.first, d.second);
            }
            if(c == '$') {
                ans++;
                bfs(i, j);
            }
        }
        j = 0;
        for(; i >= 0; --i) {
            if(visited[i][j] || str[i][j] == '*') continue;
            char c = str[i][j];
            if(c == '.') bfs(i, j);
            else if('A' <= c && c <= 'Z') {
                doors[c - 'A'].push_back({i, j});
                if(keys[c - 'A']) bfs(i, j);
            } else if('a' <= c && c <= 'z') {
                keys[c - 'a'] = true;
                bfs(i, j);
                for(pii d : doors[c - 'a']) bfs(d.first, d.second);
            }
            if(c == '$') {
                ans++;
                bfs(i, j);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
