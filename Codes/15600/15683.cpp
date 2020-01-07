#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int one[1] = {0}, two[2] = {0, 2}, three[2] = {0, 1}, four[3] = {0, 1, 2}, five[4] = {0, 1, 2, 3};
vector<pii> cctv;
vector<vector<int>> mp;
int n, m;

void mark(vector<vector<int>>& mp, int x, int y, int state);

void nextState(vector<int>& s) {
    int len = cctv.size() - 1;
    s[len]++;
    for(; len >= 0; --len) {
        if(s[len] == 4 && len != 0) {
            s[len] = 0;
            s[len - 1]++;
            if(s[len - 1] != 4) break;
        }
    }
    if(s[0] == 4) s[0] = -1;
}

bool checkRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    mp.resize(n);
    for(int i = 0; i < n; ++i) {
        mp[i].resize(m);
        for(int j = 0; j < m; ++j) {
            cin >> mp[i][j];
            if(mp[i][j] != 0 && mp[i][j] != 6)
                cctv.push_back({i, j});
        }
    }
    int len = cctv.size(), ans = 0x7fffffff;
    if(len == 0) {
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mp[i][j] == 0) cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    vector<int> state(len, 0);
    while(state[0] != -1) {
        vector<vector<int>> curr(n);
        copy(mp.begin(), mp.end(), curr.begin());
        for(int idx = 0; idx < cctv.size(); ++idx) {
            pii tv = cctv[idx];
            int x = tv.first, y = tv.second;
            int st = state[idx];
            mark(curr, x, y, st);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(curr[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        nextState(state);
    }
    cout << ans;
    return 0;
}

void mark(vector<vector<int>>& mp, int x, int y, int state) {
    switch(mp[x][y]) {
        case 1:
            for(int d : one) {
                int nx = x + dx[(d + state) % 4], ny = y + dy[(d + state) % 4];
                while(checkRange(nx, ny) && mp[nx][ny] != 6) {
                    if(mp[nx][ny] <= 0) mp[nx][ny] = -1;
                    nx += dx[(d + state) % 4];
                    ny += dy[(d + state) % 4];
                }
            }                
            break;
        case 2:
            for(int d : two) {
                int nx = x + dx[(d + state) % 4], ny = y + dy[(d + state) % 4];
                while(checkRange(nx, ny) && mp[nx][ny] != 6) {
                    if(mp[nx][ny] <= 0) mp[nx][ny] = -1;
                    nx += dx[(d + state) % 4];
                    ny += dy[(d + state) % 4];
                }
            }      
            break;
        case 3:
            for(int d : three) {
                int nx = x + dx[(d + state) % 4], ny = y + dy[(d + state) % 4];
                while(checkRange(nx, ny) && mp[nx][ny] != 6) {
                    if(mp[nx][ny] <= 0) mp[nx][ny] = -1;
                    nx += dx[(d + state) % 4];
                    ny += dy[(d + state) % 4];
                }
            }   
            break;
        case 4:
            for(int d : four) {
                int nx = x + dx[(d + state) % 4], ny = y + dy[(d + state) % 4];
                while(checkRange(nx, ny) && mp[nx][ny] != 6) {
                    if(mp[nx][ny] <= 0) mp[nx][ny] = -1;
                    nx += dx[(d + state) % 4];
                    ny += dy[(d + state) % 4];
                }
            }   
            break;
        case 5:
            for(int d : five) {
                int nx = x + dx[(d + state) % 4], ny = y + dy[(d + state) % 4];
                while(checkRange(nx, ny) && mp[nx][ny] != 6) {
                    if(mp[nx][ny] <= 0) mp[nx][ny] = -1;
                    nx += dx[(d + state) % 4];
                    ny += dy[(d + state) % 4];
                }
            }   
            break;
    }
}
