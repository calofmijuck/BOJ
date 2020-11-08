#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

bool bulb[20][20], tmp[20][20];
int n, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void copy_state() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            tmp[i][j] = bulb[i][j];
    }
}

void push(int x, int y) {
    tmp[x][y] ^= 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n)
            tmp[nx][ny] ^= 1;
    }
}

bool all_off() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(tmp[i][j])
                return false;
        }
    }
    return true;
}

int solve() {
    int cnt = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(tmp[i - 1][j]) {
                push(i, j);
                ++cnt;
            }
        }
    }
    if(all_off())
        return cnt;
    else 
        return INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            bulb[i][j] = (bool) x;
        }
    }
    int ans = INF;
    int lim = 1 << n;
    for(int mask = 0; mask < lim; ++mask) {
        copy_state();
        int e = mask, j = 0, cnt = 0;
        while(e > 0) {
            if(e & 1) {
                push(0, j);
                ++cnt;
            }
            ++j;
            e >>= 1;
        }
        ans = min(ans, cnt + solve());
    }
    cout << ((ans == INF) ? -1 : ans);
    return 0;
}